// Demo 07 Async - Promise
#include <iostream>
#include <thread>
#include <future>

using namespace std;

// Asynchronously provide data with promise
// If promise is distroyed, exception:
// std::future_errc::broken_promise
int factorial(future<int>& f)
{
    // do something else
    cout << "waiting for promised data...\n";
    this_thread::sleep_for(chrono::seconds(2));

    int N = f.get();
    cout << "Got from main thread: " << N << endl;
    int res = 1;
    for (int i=N; i>1; i--)
        res *= i;

    return res;
}

int main()
{
    // Record start time
    auto start = std::chrono::high_resolution_clock::now();

    promise<int> p; //need promise to get a future. to make sure that this value will be set at sometime
    future<int> f = p.get_future();

    future<int> fu = async(std::launch::async, factorial, ref(f)); //starts thread, waits on future until it is set by main
    //deferred: main runs until fu.get(), then executes the async function.

    // Do something else
    std::this_thread::sleep_for(chrono::seconds(2));
    p.set_value(4);
    //p.set_value(28);  // It can only be set once

    cout << "Got from child thread: " << fu.get() << endl;

    if(fu.valid())
        fu.get();
    else
        cout << "Future invalid\n";

    // Record end time
    auto finish = std::chrono::high_resolution_clock::now();
    cout << "Elapsed time: " << (finish-start).count()*1e-9 << endl;
    return 0;
}
