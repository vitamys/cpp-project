#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
vector<int> vec = {9,60,69,90,8,45,87,90,69,69,55,7};
int factor = 10;
transform(vec.begin(), vec.end(), vec.begin(), [&factor](int x){return x*factor};)

copy(vec.begin(), vec.end(), ostream_iterator(cout,"\n"));

vector<int> vec2;
transform(vec.begin(), vec.end(), back_inserter(vec2), [](int x, int y){return x*y;});

replace(vec.begin(), vec.end(), 690, 0);
vector<int>::iterator itr =remove(vec.begin(), vec.end(), 0); // return itr pointing to first element of the values moved to end
erase(itr, vec.end()); // erases all values in the range [itr, vec.end())

rotate(vec.begin(), vec.begin()+3, vec.end()); // rotate vector, such that it start with the 3rd element. elements from start are moved to the end.
//alternatively: dont find value by hand
auto itr = find(vec.begin(), vec.end(), 45);
rotate(vec.begin(), itr, vec.end()); 

stable_partition(vec.begin(), vec.end(), [](int x ){return x<450})

copy(vec.begin(), vec.end(),ostream_iterator(cout, "\n"));
return 0;
}