#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>
#include "Billionaire.h"

using namespace std;


int main(){

    std::ifstream stream("Forbes2018.txt");
    if(!stream){
        cout << "WARNING: File not found!" << endl;
    }
    
    vector<Billionaire> billionaires;
    copy(istream_iterator<Billionaire>(stream), istream_iterator<Billionaire>(), back_inserter(billionaires));
    //uncomment to have whole list of billionaires printed to terminal
    //copy(billionaires.begin(), billionaires.end(), ostream_iterator<Billionaire>(cout, "\n"));

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