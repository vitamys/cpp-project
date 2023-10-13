#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono_literals;

// Write a program calling 3 functions simulating busy time. t3,t4,t5 are waiting for t=3s,4s,5s.
// 1) Measure the time for the program execution
// 2) Launch all three functions in threads and measure time again

void t3()
{
    this_thread::sleep_for(3s);
    cout << "t3" << endl;
}
void t4()
{
    this_thread::sleep_for(4s);
    cout << "t4" << endl;
}
void t5()
{
    this_thread::sleep_for(5s);
    cout << "t5" << endl;
}

void nonThreaded()
{
    t3();
    t4();
    t5();
}
void threaded()
{
    thread t1(t3);
    thread t2(t4);
    thread t3(t5);
    t1.join();
    t2.join();
    t3.join();
}


int main()
{


    cout << "Start" << endl;
    auto start =  chrono::high_resolution_clock::now();

    nonThreaded();

    auto stop =  chrono::high_resolution_clock::now();

    auto start1 =  chrono::high_resolution_clock::now();

    threaded();

    auto stop1 =  chrono::high_resolution_clock::now();

    cout << "Total time for non threaded execution: " << chrono::duration_cast<chrono::seconds>(stop-start).count() << endl;
    cout << "Total time for threaded execution: " << chrono::duration_cast<chrono::seconds>(stop1-start1).count() << endl;

    return 0;
}
