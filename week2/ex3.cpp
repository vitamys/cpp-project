/*
Read the file containing the name, dollars in billions and the country which are separated by tabs.
Create a class Billionaire and overload the ostream and istream operators to conveniently read
the file into a vector and write the content to the output as shown in the code snippet.
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>
//#include "Billionaire.h"

using namespace std;

class Billionaire {
public:
    // Constructors
    Billionaire() = default;
    Billionaire(const std::string& name, double dollars, const std::string& country)
        : name(name), dollars(dollars), country(country) {}

    // Overload the output stream operator (<<) to display a billionaire
    friend std::ostream& operator<<(std::ostream& os, const Billionaire& billionaire) {
        os << "Name: " << billionaire.name << "\tDollars: " << billionaire.dollars << "B\tCountry: " << billionaire.country;
        return os;
    }

    // Overload the input stream operator (>>) to read a billionaire from input
    friend std::istream& operator>>(std::istream& is, Billionaire& billionaire) {
        // Read data from the input stream, assuming it is in the format: name, dollars, country
        is >> billionaire.name >> billionaire.dollars >> billionaire.country;
        return is;
    }


    std::string name;
    double dollars;
    std::string country;
};


int main(){

    // std::ifstream stream("Forbes2018.txt");
    // if(!stream){
    //     cout << "WARNING: File not found!" << endl;
    // }
    
    // vector<Billionaire> billionaires;
    // copy(istream_iterator<Billionaire>(stream), istream_iterator<Billionaire>(), back_inserter(billionaires));
    // copy(billionaires.begin(), billionaires.end(), ostream_iterator<Billionaire>(cout, "\n"));

    // Create a map to store billionaires and their counts
    std::map<std::string, std::pair<Billionaire, size_t>> countryToBillionaire;

    // Sample data: billionaires vector as streamoverloading is not working
    std::vector<Billionaire> billionaires = {
        Billionaire("Mikhail Fridman", 15.1, "Russia"),
        Billionaire("Rupert Murdoch", 15, "United States"),
        Billionaire("Dhanin Chearavanont", 14.9, "Thailand"),
        // Add more billionaires from various countries
    };

    // Populate the map with the first billionaire from each country
    for (const Billionaire& billionaire : billionaires) {
        // Check if the country already exists in the map
        if (countryToBillionaire.find(billionaire.country) == countryToBillionaire.end()) {
            // If the country is not in the map, add the billionaire and set the count to 1
            countryToBillionaire[billionaire.country] = std::make_pair(billionaire, 1);
        } else {
            // If the country is already in the map, increment the count
            countryToBillionaire[billionaire.country].second++;
        }
    }

    // Print the map contents
    for (const auto& pair : countryToBillionaire) {
        const std::string& country = pair.first;
        const Billionaire& firstBillionaire = pair.second.first;
        size_t billionaireCount = pair.second.second;

        std::cout << "Country: " << country << std::endl;
        std::cout << "First Billionaire: " << firstBillionaire << std::endl;
        std::cout << "Number of Billionaires: " << billionaireCount << std::endl;
        std::cout << std::endl;
    }

    return 0;
}