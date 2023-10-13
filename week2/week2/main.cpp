#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>
#include "billionaire.h"

using namespace std;

void phoneBook(){
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

        while (true) {
            std::cout << "Enter name (or Exit): ";

            std::string input;
            std::getline(std::cin, input);

            if (input == "Exit" || input == "exit") {
                       break;
                   }

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
        }
        // Clear the terminal screen (OS-specific command)
        #ifdef _WIN32
        system("cls");
        #else
        system("clear");
        #endif
}

int main()
{
    phoneBook();
    BillionaireLoader loader;
    loader.processBillionairesFile("../Forbes2018.txt");
    return 0;
}
