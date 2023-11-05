// Dem0 07 Async - Promise
#include <iostream>
#include <thread>
#include <future>

using namespace std;

int factorial(future<int>& f)
{
    this_thread::sleep_for(chrono::seconds(2));

    int N = f.get(); // blocking until we get a value
    int res = 1;
    for (int i=N; i>1; i--)
        res *= i;

    return res;
}

int main()
{
    // Record start time
    auto start = std::chrono::high_resolution_clock::now();

    promise<int> p;
    auto f = p.get_future();
    // Blocking call!
    future<int> fu = async(launch::async, factorial,ref(f));

    p.set_value(5); // factorial can start

    cout << fu.get() << endl;
    // Record end time
    auto finish = std::chrono::high_resolution_clock::now();
    cout << "Elapsed time: " << (finish-start).count()*1e-9 << endl;

    return 0;
}
