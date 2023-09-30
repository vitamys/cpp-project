// Billionaire.h
#ifndef BILLIONAIRE_H
#define BILLIONAIRE_H

#include <iostream>
#include <string>

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
    private:
    std::string name;
    double dollars;
    std::string country;
 };

#endif // BILLIONAIRE_H
