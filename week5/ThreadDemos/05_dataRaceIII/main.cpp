#include <iostream>
#include <string>
#include <thread>
#include <mutex>

using namespace std;

mutex mu;

void sharedPrint(string msg, int value)
{
    // RAII - lock_guard
//    mu.lock(); // only one thread can enter!
    lock_guard<mutex> guard{mu};
    cout << msg << value << endl;
//    mu.unlock();
}

void print()
{
    for (int i = 0; i > -100; --i)
        sharedPrint("From child: " , i);
}

int main()
{
    thread t{print};

    for (int i = 0; i < 100; ++i)
        sharedPrint("From main: ", i);

    t.join(); 

    return 0;
}
