#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>

class Billionaire {
public:
    std::string name;
    double dollars;
    std::string country;

    Billionaire() = default;
    Billionaire(const std::string& name, double dollars, const std::string& country)
        : name(name), dollars(dollars), country(country) {}

    friend std::ostream& operator<<(std::ostream& os, const Billionaire& billionaire) {
        os << "Name: " << billionaire.name << "\tDollars: " << billionaire.dollars << "B\tCountry: " << billionaire.country;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Billionaire& billionaire) {
    // Read data from the input stream, assuming it is in the format: name, dollars, country
    is >> std::ws; // Skip leading whitespace
    getline(is, billionaire.name, '\t'); // Read the name until the next tab
    is >> billionaire.dollars; // Read the dollars as a double
    is.ignore(); // Ignore the space after the double
    getline(is, billionaire.country); // Read the country until the end of the line
    return is;
}
};

int main() {
    std::ifstream stream("Forbes2018.txt");
    if (!stream) {
        std::cout << "WARNING: File not found!" << std::endl;
        return 1;
    }

    std::vector<Billionaire> billionaires;
    std::copy(std::istream_iterator<Billionaire>(stream), std::istream_iterator<Billionaire>(), std::back_inserter(billionaires));

    if (billionaires.empty()) {
        std::cerr << "ERROR: No data read from the file." << std::endl;
        return 1;
    }

    // Create a map to store billionaires and their counts
    std::map<std::string, std::pair<Billionaire, size_t>> countryToBillionaire;

    for (const Billionaire& billionaire : billionaires) {
        auto result = countryToBillionaire.try_emplace(billionaire.country, billionaire, 1);
        if (!result.second) {
            // Country already exists in the map, update the count
            result.first->second.second++;
            if (billionaire.dollars > result.first->second.first.dollars) {
                // If this billionaire is richer, update the richest billionaire
                result.first->second.first = billionaire;
            }
        }
    }

    for (const auto& pair : countryToBillionaire) {
        const std::string& country = pair.first;
        const Billionaire& richestBillionaire = pair.second.first;
        size_t billionaireCount = pair.second.second;

        std::cout << country << " : " << billionaireCount << " billionaires. Richest is " << richestBillionaire.name
                  << " with " << richestBillionaire.dollars << " B$" << std::endl;
    }

    return 0;
}
