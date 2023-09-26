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
#include "billionaire.h"

using namespace std;



int main(){

    std::ifstream stream("Forbes2018.txt");
    if(!stream){
        cout << "WARNING: File not found!" << endl;
    }
    
    vector<Billionaire> billionaires;
    copy(istream_iterator<Billionaire>(stream), istream_iterator<Billionaire>(), back_inserter(billionaires));
    copy(billionaires.begin(), billionaires.end(), ostream_iterator<Billionaire>(cout, "\n"));
}