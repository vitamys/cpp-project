#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;

bool odd(int n) { return n % 2; }

int main()
{
    // Record start time
    auto start = std::chrono::high_resolution_clock::now();

    vector<int> d(50000000);

    mt19937 gen;
    uniform_int_distribution<int> dis(0, 100000);
    auto rand_num ([=] () mutable { return dis(gen); });
    generate(begin(d), end(d), rand_num);

    sort(begin(d), end(d));

    auto odds(count_if(begin(d), end(d), odd));

    cout << 100.0*odds/d.size() << "% of the numbers are odd.\n";
    // --> 50.4% of the numbers are odd.

    // Record end time
    auto finish = std::chrono::high_resolution_clock::now();
    cout << "Elapsed time: " << (finish-start).count()*1e-9 << endl;
}
