#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
#include <future>

using namespace std;

int calcStats(int nbrElelements)
{
    vector<int> d(nbrElelements);
    random_device r;
    mt19937 gen{r()};
    uniform_int_distribution<int> dis(1, nbrElelements);
    auto rand_num ([=] () mutable { return dis(gen); });
    generate(begin(d), end(d), rand_num);
    return count_if(begin(d), end(d), [&nbrElelements](int val){return val > nbrElelements/2;});
}

int main()
{
    auto nbrElements{500000};
    vector<future<int>> v;
    int numberOfThreads = thread::hardware_concurrency();
    for (size_t count =0; count < numberOfThreads; ++count)
    {
            v.emplace_back(async(calcStats,nbrElements));
    }

    for (auto& f:v){
        if(f.valid())
            cout << 100.0*f.get()/nbrElements <<"% of Elements are odd" <<endl;
    }

    return 0;
}
