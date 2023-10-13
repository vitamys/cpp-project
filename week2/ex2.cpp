/*
Create
a simple phone book with the content given in a vector. Choose the appropriate container.
The program should ask the user to enter a name and present the number if exists and warn otherwise.
Leave the phone book with Exit
TODO: feedback: while loop to be able to ask multiple names, and test fo rexti input to exit
cmakelists.txt: copy forbes to correct location
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>

using namespace std;

int main(){
    vector<pair<string, string>>
    vec{make_pair("Homer", "1111"),
    make_pair("Marge", "2222 "),
    make_pair("Lisa", "3333"),
    make_pair("Magy", "4444"),
    make_pair("Bart", "5555")};

    //create map
    multimap<string, string> phoneBook;

    // Iterate through the vector and insert each pair into the map
    for (const auto& pair : vec) {
        phoneBook.insert(pair);
    }

    //adding second phone number
    phoneBook.insert(make_pair("Bart", "5225"));
    phoneBook.insert(make_pair("Martin", "9999"));
    phoneBook.insert(make_pair("Martin", "0001"));

    std::cout << "Enter name (or Exit): ";

    std::string input;
    std::getline(std::cin, input);

    // Find the range of elements with the specified key
    auto range = phoneBook.equal_range(input);

    if (range.first != phoneBook.end()) {
        std::cout << "Phone numbers for " << input << ":" << std::endl;
        for (auto it = range.first; it != range.second; ++it) {
            std::cout << it->second << std::endl;
        }
    } else {
        std::cout << "Name not found in the phone book." << std::endl;
    }
   return 0;
}