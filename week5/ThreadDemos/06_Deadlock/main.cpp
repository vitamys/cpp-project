#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
using namespace chrono_literals;

mutex mutA;
mutex mutB;

void deadlockFunc1()
{
    cout << "bad f1 acquiring mutex A..." << endl;
    lock_guard<mutex> la{mutA};
    this_thread::sleep_for(100ms);
    cout << "bad f1 acquiring mutex B..." << endl;
    lock_guard<mutex> lb{mutB};
    cout << "bad f1 got both mutexes." << endl;
}

void deadlockFunc2()
{
    cout << "bad f2 acquiring mutex B..." << endl;
    lock_guard<mutex> lb{mutB};
    this_thread::sleep_for(100ms);
    cout << "bad f2 acquiring mutex A..." << endl;
    lock_guard<mutex> la{mutA};
    cout << "bad f2 got both mutexes." << endl;
}

void saneFunc1()
{
    scoped_lock l{mutA, mutB};
    cout << "sane f1 got both mutexes." << endl;
}
void saneFunc2()
{
    scoped_lock l{mutB, mutA};
    cout << "sane f2 got both mutexes." << endl;}


int main()
{
    {
        thread t1{saneFunc1};
        thread t2{saneFunc2};
        t1.join();
        t2.join();
    }

    {
        thread t1{deadlockFunc1};
        thread t2{deadlockFunc2};
        t1.join();
        t2.join();
    }
}
