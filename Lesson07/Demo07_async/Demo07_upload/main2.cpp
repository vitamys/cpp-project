// Dem0 07 Async - std::ref
#include <iostream>
#include <thread>

using namespace std;

// Return value with shared resources
void factorial(int N, int& result)
{
    int res = 1;
    for (int i=N; i>1; i--)
        res *= i;

    result = res;
    cout << "Child - Result is: " << res << endl;
}

int main()
{
    int result{0};
    thread t{factorial, 4, ref(result)};
    t.join();
    cout << "Main - Result is: " << result << endl;
    return 0;
}
