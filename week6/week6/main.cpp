#include <iostream>

using namespace std;

// Demo 06 - Producer-Consumer Example without condition variables
#include <iostream>
#include <queue> // FIFO Buffer
#include <thread>
#include <mutex>
#include <condition_variable>
#include "DataQueue.h"

using namespace std;
using namespace std::chrono_literals;

const int BufferSize = 10; // Set your desired buffer size

DataQueue<size_t, BufferSize> q; // Create a DataQueue with the specified buffer size
bool finished{false};
void produce(size_t nbrItems)
{
    for (size_t count{0}; count < nbrItems; ++count)
        {
            std::this_thread::sleep_for(100ms); // Simulate producing time
            q.add(count);
            cout << "Producing --> item " << count << endl;

        }
    finished = true;
    cout<< "--- Producer done ---" <<endl;
}

void consume()
{
    size_t count{0};
        while (!finished || !q.isEmpty())
        {
            std::this_thread::sleep_for(200ms); // Simulate consuming time

            size_t data = q.get();
            cout << "item " << data << " --> consumed" << endl;
            count++;
        }
        cout<< "--- Consumer done ---" <<endl;
        cout << "number count: " << count << endl;


}


int main()
{
    size_t nbrItems{20};
    std::thread t1{produce, nbrItems};
    std::thread t2{consume};
    t1.join();
    t2.join();
    cout << "Finished!"<< endl;
    return 0;
}

