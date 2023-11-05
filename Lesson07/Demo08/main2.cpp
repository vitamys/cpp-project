#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
#include <execution>

using namespace std;

bool odd(int n) { return n % 2; }

int main()
{
    // Record start time
    auto start = std::chrono::high_resolution_clock::now();

    vector<int> d(50000000);

    mt19937 gen;
    uniform_int_distribution<int> dis(0, 100000);
    auto randNum ([=] () mutable { return dis(gen); });
    generate( execution::par, begin(d), end(d), randNum);

    sort(execution::par, begin(d), end(d));

    auto odds(count_if(execution::par, begin(d), end(d), odd));

    cout << 100.0*odds/d.size() << "% of the numbers are odd.\n";
    // --> 50.4% of the numbers are odd.
    // Record end time
    auto finish = std::chrono::high_resolution_clock::now();
    cout << "Elapsed time: " << (finish-start).count()*1e-9 << endl;
}
