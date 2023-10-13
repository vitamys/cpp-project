#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    vector<int> vec = {9,60,69,90,8,45,87,90,69,69,55,7};
    // 1 . Counting a l l values 69, cout how many
    int values = count(vec.begin(), vec.end(), 69);
    cout << "\n1)\nCount is: " << values << endl;

    // 2. Count values larger than thres , cout how many
    int thres = 50;
    int m = count_if(vec.begin(), vec.end(),
    [&thres](int x){return x>thres;});

    cout << "\n2)\nCount is: " << m << endl;

    // 3.
    //Find f i r s t min , l a s t max and f i r s t max in vector , cout value and position ( distance )
    auto pair_of_itr = minmax_element(vec.begin(), vec.end());

    //int itr = find(vec.begin(), vec.end(), pair_of_itr.first());

    //int min = max_element(vec.begin(), vec.end());

    // 4) Mutliply each element with f a c t o r ( transform ) , cout vector ( copy )
    int factor = 10;
    vector<int> vec2( vec.size());
    transform(vec.begin(), vec.end(),
    vec2.begin(),
    [&factor](int x){ return x*factor;});

    copy(vec2.begin(), vec2.end(),std::ostream_iterator<char>(std::cout, " ") );

    // 5) Calculate elementwise product and save in r e s u l t and cout r e s u l t
    vector<int> result;


    return 0;
}
