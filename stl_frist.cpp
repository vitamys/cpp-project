//Write a program that creates a vector<char> which stores the letters a-z in ascending order (Tip:
//std::iota). Print the elements in the vector to cout in normal order and in reverse order using
//std::copy combined with the ostream_Iterator.

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <set>
#include <string>


int one(){
    std::string funcname = "------------------\n exercise 1\n------------------";
    std::cout << funcname << "\n";
    std::vector<char> v(26);
    std::iota(v.begin(), v.end(), 'a');
    std::copy(v.begin(), v.end(), std::ostream_iterator<char>(std::cout, " "));
    std::cout << std::endl;
    std::copy(v.rbegin(), v.rend(), std::ostream_iterator<char>(std::cout, " "));
    std::cout << std::endl; //prints new line to console
    return 0;
}

int two(){
    std::string funcname = "------------------\n exercise 2\n------------------";
    std::cout << funcname << "\n";
    //read from file to vector
    std::ifstream doc("cars.txt");
    std::istream_iterator<std::string> start(doc), end;
    std::vector<std::string> v(start, end);
    std::sort(v.begin(), v.end());
    std::copy(v.begin(), v.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
    std::cout << std::endl;

    return 0;

}

int three(){
    //Same as before, but use the appropriate container to sort at insertion and print the result using
//std::copy
std::string funcname = "------------------\n exercise 3\n------------------";
    std::cout << funcname << "\n";
std::ifstream doc("cars.txt");
    std::istream_iterator<std::string> start(doc), end;
    
    std::set<std::string> sortedSet(start, end); // Use a set for sorting at insertion
    
    std::copy(sortedSet.begin(), sortedSet.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
    std::cout << std::endl;

    
    return 0;

}

int four_loop(char letter){
    std::string funcname = "------------------\n exercise 4 with ordinary loop\n------------------";
    std::cout << funcname << "\n" << "for letter " << letter << "\n";
    /*Rewrite exercise 2. Instead of printing all cars using std::copy(), construct a loop for printing all
car brands in the list in exercise 2, which begins with a certain letter, e.g all car brands beginning
with ’A’. Try both
a) the ordinary for loop, with iterators:
for (auto it = cars.cbegin(); it != cars.cend(); ++it){…}*/
    std::ifstream doc("cars.txt");
    std::istream_iterator<std::string> start(doc), end;
    std::vector<std::string> v(start, end);
    std::sort(v.begin(), v.end());
    for (auto it = v.cbegin(); it != v.cend(); ++it){
           if ((*it)[0] == letter) {
            std::cout << *it << "\n";
        }
    }
    std::cout << std::endl;

    return 0;
}

int four_range_loop(char letter){

    std::string funcname = "------------------\n exercise 4 with range loop\n------------------";
    std::cout << funcname << "\n" << "for letter " << letter << "\n";
    std::ifstream doc("cars.txt");
    std::istream_iterator<std::string> start(doc), end;
    std::vector<std::string> v(start, end);
    std::sort(v.begin(), v.end());
    

    for (const std::string& car : v) {
        if (car.front() == letter){
            std::cout << car << "\n";
        }
    }
        return 0;

}

int five(std::string allowedChars)
{

    std::string funcname = "------------------\n exercise 5\n------------------";
    std::cout << funcname << "\n"<< "for predicate " << allowedChars << "\n";
    std::ifstream doc("cars.txt");
    std::istream_iterator<std::string> start(doc), end;
    std::vector<std::string> carBrands(start, end);
    std::sort(carBrands.begin(), carBrands.end());


    std::copy_if(carBrands.begin(), carBrands.end(), std::ostream_iterator<std::string>(std::cout, "\n"),
                 [&allowedChars](const std::string& brand) {
                     char firstChar = std::tolower(brand.front()); // Convert to lowercase for case-insensitive comparison
                     return std::any_of(allowedChars.begin(), allowedChars.end(),
                                        [firstChar](char c) {
                                            return std::tolower(c) == firstChar;
                                        });
                 });

    std::cout << std::endl;

    return 0;
}
int main()
{
    one();
    two();
    three();
    four_loop('A');
    four_range_loop('A');
    five("ABC");
    return 0;
}

