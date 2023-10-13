#ifndef BILLIONAIRE_H
#define BILLIONAIRE_H
#include <iostream>
#include <string>

 class Billionaire {
public:
//Data members
std::string name;
    double dollars;
    std::string country;
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
    //! there is a whitespace after the double so we need to ignore it
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

 class BillionaireLoader {
 public:
     void processBillionairesFile(const std::string& filename);
 };
#endif // BILLIONAIRE_H
