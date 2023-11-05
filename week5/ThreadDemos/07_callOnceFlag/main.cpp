#include <iostream>
#include <string>
#include <thread>
#include <mutex>

using namespace std;

mutex mu;
once_flag flag;

void sharedPrint(string msg, int value)
{
    call_once(flag, []{ cout << " --- HEADER --- " << endl;});
    lock_guard<mutex> coutGuard(mu);
    cout << msg << value << endl;
}

void print()
{
    for (int i = 0; i > -10; --i)
        sharedPrint("From child: " , i);
}

int main()
{
    thread t{print};

    for (int i = 0; i < 10; ++i)
        sharedPrint("From main: ", i);

    t.join();

    return 0;
}




//call_once(flag, []{cout << " --- HEADER --- " << endl;});
