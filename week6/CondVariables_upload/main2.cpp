// Demo 06 - Producer-Consumer Example without condition variables
#include <iostream>
#include <queue> // FIFO Buffer
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;
using namespace std::chrono_literals;

deque<size_t> q;
mutex mu;
condition_variable cv;
bool finished{false};


void produce(size_t nbrItems)
{
    for(size_t count{0}; count < nbrItems; ++count)
    {
        std::this_thread::sleep_for(100ms); // Simulate producing time
        {
            std::lock_guard<mutex> qLocker{mu};
            q.push_front(count);
        }
        cv.notify_one(); // Notify: new element
    }

    {
        std::lock_guard<mutex> flagLocker{mu};
        finished = true;
    }
    cv.notify_one(); // Notify: production finished
}

void consume()
{
    size_t count{0};
    while (!finished)
    {

        std::unique_lock<mutex> qLocker{mu};
        cv.wait(qLocker, []{return !q.empty() || finished; }); // wait for notify event and check conditions - spurious wakeups

        while(!q.empty())
        {
            cout << "Got " << q.back() << " from Queue" << endl;
            q.pop_back();
        }
        count++;
    }
    cout << "number count:"  << count;

}


int main()
{
    size_t nbrItems{200};
    std::thread t1{produce, nbrItems};
    std::thread t2{consume};
    t1.join();
    t2.join();
    cout << "Finished!"<< endl;
    return 0;
}
