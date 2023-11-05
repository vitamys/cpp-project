#include <iostream>
#include <string>
#include <thread>

using namespace std;

void print()
{
    for (int i = 0; i > -100; --i)
        cout << "From child: " << i << endl;
}

int main()
{
    thread t{print};

    for (int i = 0; i < 100; ++i)
        cout << "From main: " << i << endl;

    t.join();

    return 0;
}
