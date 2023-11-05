#include <iostream>
#include <thread>
using namespace std;
using namespace chrono_literals; //C++ 14

void threadWithParam(int threadNbr)
{
    this_thread::sleep_for(1ms * threadNbr);
    cout << "Hello from thread " << threadNbr << '\n';

    this_thread::sleep_for(1s * threadNbr);
    cout << "Bye from thread " << threadNbr << '\n';
}

int main()
{
    cout << thread::hardware_concurrency() << " concurrent threads are supported.\n";
    thread t1{threadWithParam, 1};
    thread t2{threadWithParam, 2};
    thread t3{threadWithParam, 3};

    t1.join();
    t2.join();
    t3.detach();

    cout << "Threads joined.\n";
}
