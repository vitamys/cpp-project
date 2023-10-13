#ifndef EX2_H
#define EX2_H
#include <iostream>
#include <vector>
#include <numeric>
#include <fstream>
#include <iterator>
#include <string>
#include <sstream>
#include <set>
#include <algorithm>
#include <ex1.h>

using namespace std;



bool isPunctuation(char c) {
    return ispunct(static_cast<unsigned char>(c));
}
void uniqueWords(){

        std::cout << "Please enter some text: ";


        std::string input;
        std::getline(std::cin, input);

        std::istringstream iss(input);
        std::set<std::string> uniqueWords;
        std::string word;

        while (iss >> word) {
            // Remove punctuation or other unwanted characters from the word
            // Here, we're removing common punctuation characters like '.', ',', '!', '?'
            word.erase(remove_if(word.begin(), word.end(), isPunctuation), word.end());

            uniqueWords.insert(word);
        }
        //sort unique words alphabetically
        //std::sort(uniqueWords.begin(), uniqueWords.end());


        std::cout << "The unique word list contains:" << std::endl;
        for (const std::string& uniqueWord : uniqueWords) {
            std::cout << uniqueWord << " ";
        }
        std::cout << std::endl;



}
#endif // EX2_H
