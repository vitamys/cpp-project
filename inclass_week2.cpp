#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    vector<int> vec = {9,60,69,90,8,45,87,90,69,69,55,7};

// Non−modifying
// 1 . Counting all values 69, cout how many
int values = count(vec.begin(), vec.end(), 69);


cout << "\n1)\nCount is: " << values << endl;
// 2. Count values larger than thres , cout how many
int thres = 50;

int count_above_thres = count_if(vec.begin(), vec.end(), [&thres](auto x) { return x > thres; });




// 3.
//Find f i r s t min , l a s t max and f i r s t max in vector , cout value and position ( distance )

auto min_element_it = min_element(vec.begin(), vec.end());
auto max_element_it = max_element(vec.begin(), vec.end());
auto minMaxItr = minmax_element(vec.begin(), vec.end()); // alternative, then access with minMaxItr.first and minMaxItr.second

cout << "3)" << endl;
cout << "First minimum value: " << *min_element_it << " at position: " << distance(vec.begin(), min_element_it) << endl;
cout << "First maximum value: " << *max_element_it << " at position: " << distance(vec.begin(), max_element_it) << endl;
cout << "Last maximum value: " << *max_element_it << " at position: " << distance( max_element_it, vec.end()) << endl;

// 4) Mutliply each element with f a c t o r ( transform ) , cout vector ( copy )
int factor = 10;

// 7 items
vector<int> vec2 = {0,0,0,0,0,0,0,0,0,0,0,0}; // 11 items
vector<int>::iterator itr, itr2;

transform(vec.begin(), vec.end(),
vec2.begin(), [&factor](int x){ return x*factor;});
//transform(vec, vec.begin(), [&factor](int x){ return x*factor;}); // to overwrite vec
copy(vec2.begin(), vec2.end(), std::ostream_iterator<int>(std::cout, " "));
std::cout << std::endl;


// 5) Calculate elementwise product and save in r e s u l t and cout r e s u l t
vector<int> result;

ranges::transform(vec2,vec2, back_inserter(result),[](auto x, auto y){return x*y;})
ranges::copy(vec,ostream_iterator<int>{cout, " "})
cout << endl



// 6) Replace a l l 690’s in vec with 0 and cout
replace(vec2.begin(), vec2.end(),690,0);
copy(vec2.begin(), vec2.end(), std::ostream_iterator<int>(std::cout, " "));
std::cout << std::endl;


// 7) Remove a l l 0 ’ s from vec and cout
//remove moves 0 to end, to new logical end. just restructers vector

vec.erase(remove(vec2.begin(), vec2.end(), 0),vec.end());
copy(vec2, std::ostream_iterator<int>(cout, " "));
cout << endl;

// 8) Rotate such that vector s t a r t s with max value 450 and cout
rotate(vec2.begin(), vec2.begin()+4, vec.end());

//by patrick
auto itr450{ranges::find(vec2,450)};
ranges::rotate(vec2, itr450);
copy(vec2, std::ostream_iterator<int>(cout, " "));
cout << endl;

// 9) P a r t i t i o n elements such that values l e s s than 450 appear f i r s t preseving the o r i g i n a l
//order and cout

ranges::stable_partition(vec2,[](auto e){return e<450;});
copy(vec2, std::ostream_iterator<int>(cout, " "));
cout << endl;

return 0;
}