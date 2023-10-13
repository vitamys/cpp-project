#include <iostream>
#include <thread>

using namespace std;

void counting(size_t count)
{
    for (size_t i = 0; i < count; ++i)
        cout << i << endl;
}

int main()
{
    thread t(counting, 1000);
    t.join();

    return 0;
}
