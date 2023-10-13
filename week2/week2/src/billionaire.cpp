#include "billionaire.h"
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>

void BillionaireLoader::processBillionairesFile(const std::string& filename) {
    std::ifstream stream(filename);
    if (!stream) {
        std::cout << "WARNING: File not found!" << std::endl;
        return;
    }

    std::vector<Billionaire> billionaires;
    std::copy(std::istream_iterator<Billionaire>(stream), std::istream_iterator<Billionaire>(), std::back_inserter(billionaires));

    std::map<std::string, std::pair<Billionaire, size_t>> countryToBillionaire;

    for (const Billionaire& billionaire : billionaires) {
        auto result = countryToBillionaire.try_emplace(billionaire.country, billionaire, 1);
        if (!result.second) {
            result.first->second.second++;
            if (billionaire.dollars > result.first->second.first.dollars) {
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
}
