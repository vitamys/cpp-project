/*Write a program that reads user input from the command line and prints the unique words to the con-
sole. The program flow might look similar to:
Please enter some text: a a b only unique words are are stored
The unique word list contains:
a are b only stored unique words*/
#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <algorithm>

int main() {
    std::cout << "Please enter some text: ";

    std::string input;
    std::getline(std::cin, input);

    std::istringstream iss(input);
    std::set<std::string> uniqueWords;
    std::string word;

    while (iss >> word) {
        // Remove punctuation or other unwanted characters from the word
        // Here, we're removing common punctuation characters like '.', ',', '!', '?'
        word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());

        uniqueWords.insert(word);
    }
    //sort unique words alphabetically
    //std::sort(uniqueWords.begin(), uniqueWords.end());


    std::cout << "The unique word list contains:" << std::endl;
    for (const std::string& uniqueWord : uniqueWords) {
        std::cout << uniqueWord << " ";
    }
    std::cout << std::endl;

    return 0;
}

