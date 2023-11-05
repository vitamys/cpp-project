// Demo 07 Async - No return value
#include <iostream>
#include <thread>

using namespace std;

// For threads to return values:
void factorial(int N) {
    int res = 1;
    for (int i=N; i>1; i--)
        res *= i;

    cout << "Factorial of " << N << " is " << res << endl;
}

int main()
{
    thread t{factorial,4};
    t.join();
    return 0;
}
