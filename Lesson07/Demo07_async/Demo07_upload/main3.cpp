// Dem0 07 Async - Future
#include <iostream>
#include <thread>
#include <future>

using namespace std;

int factorial(int N)
{
    int res = 1;
    for (int i=N; i>1; i--)
        res *= i;

    return res;
}

int main()
{
    future<int> fu = async(launch::async, factorial, 4); //launch::async: launch in different tthreads.
    //launch::deferred => only created when variable is used.
    // Do something else
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Got from child thread: " << fu.get() << endl;
//    fu.get();  // crash!
    return 0;
}
















