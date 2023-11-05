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

    //alternative: use jthread. calls join automatically
    //but: main might terminate without t having terminated -> function not finishing properly
    jthread t(counting, 1000);

    return 0;
}
