// Demo 06 - Producer-Consumer Example without condition variables
#include <iostream>
#include <queue> // FIFO Buffer
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;
using namespace std::chrono_literals;

static deque<int> q;
static mutex mu;
static bool finished{false};

void produce(size_t nbrItems)
{
    for(size_t count{0}; count < nbrItems; ++count)
    {
        std::this_thread::sleep_for(100ms); // Simulate producing time
        std::lock_guard<mutex> qLocker{mu};
        q.push_front(count);
    }
    std::lock_guard<mutex> flagLocker{mu};
    finished = true;
}

void consume()
{
    size_t pollCount{0};
    while (!finished)
    {
        while(!q.empty())
        {
            std::lock_guard<mutex> qLocker{mu};
            cout << "Got " << q.back() << " from Queue" << endl;
            q.pop_back();
        }
        std::this_thread::sleep_for(100ms); // Reduce CPU cycle burns
        pollCount++;
    }
    cout << " Number polls: " <<  pollCount << endl;
}


int main()
{
    size_t nbrItems{10};
    std::thread t1{produce, nbrItems};
    std::thread t2{consume};
    t1.join();
    t2.join();
    cout << "Finished!"<< endl;
    return 0;
}
