#ifndef DATAQUEUE_H
#define DATAQUEUE_H

#include <fstream>
#include <string>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>



using namespace std;


template<typename Data, int Buffersize = 1000>
class DataQueue{
private:

    std::mutex mu;
    std::queue<Data> queue;
    condition_variable cv_consumer;
    condition_variable cv_producer;





public:
    DataQueue(){};

     void add(const Data& data)
          {
         {
         std::unique_lock<mutex> qLocker{mu};
         cv_producer.wait(qLocker, [this]{return !isFull()/*|| !isEmpty()*/; }); //to make sure not both threads wait to be notified

             queue.push(data);
         }// lock gets unlocked at end of scope, so make scope here to unlock before notification.
         //however, cannot lock mutex as long as it not free -> waiting on mutex instead of cv
             cv_consumer.notify_one();
          }

    Data get(){

        std::unique_lock<mutex> qLocker{mu};
        cv_consumer.wait(qLocker, [this]{return !isEmpty(); });
        Data data = queue.front();
        queue.pop();
        cv_producer.notify_one(); // Notify: consumption finished
        return data;

    }

    bool isFull(){
        return queue.size()==Buffersize;
    }

    bool isEmpty(){
        return queue.empty();

    }
    };

#endif // DATAQUEUE_H
