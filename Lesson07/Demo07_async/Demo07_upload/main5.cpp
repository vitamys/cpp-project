// Dem0 07 Async - Promise
#include <iostream>
#include <thread>
#include <future>

using namespace std;

int factorial(int N)
{
    this_thread::sleep_for(chrono::seconds(2));
    int res = 1;
    for (int i=N; i>1; i--)
        res *= i;

    return res;
}

int main()
{
    // Record start time
    auto start = std::chrono::high_resolution_clock::now();

    // Blocking call!
    future<int> fu1 = async(factorial,4);
    auto fu2 = async(factorial,5);

    cout << fu1.get() << fu2.get() << endl;
    // Record end time
    auto finish = std::chrono::high_resolution_clock::now();
    cout << "Elapsed time: " << (finish-start).count()*1e-9 << endl;

    return 0;
}
