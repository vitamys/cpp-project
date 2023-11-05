#ifndef THREADLOGFILE_H
#define THREADLOGFILE_H

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <mutex>


using namespace std;

std::once_flag flag;
std::mutex mu;

class ThreadLogFile{
private:
    std::string filename;
    std::ofstream fileStream;

public:

    //constructor: opens file stream
    ThreadLogFile() : filename("../threadLog.txt") {
         fileStream.open(filename);
            if (!fileStream.is_open()) {
                std::cout << "WARNING: File not found!" << std::endl;
                return;
            }
        }

   // destructor
    ~ThreadLogFile() {
            if (fileStream.is_open()) {
                fileStream.close();
            }
        }


    //member function print
    void print(std::thread::id id, int value){
        if (fileStream.is_open()) {
            call_once(flag,[this]{fileStream << std::string(4, '-')
            << " HEADER " << std::string(4, '-')
            << endl;});

        //write to file after obtaining lock
        lock_guard<mutex> coutGuard(mu);

                fileStream << "Log from thread: "<< id <<" with value "<< value << std::endl;
            } else {
                std::cerr << "Error: File " << filename << " is not open for writing." << std::endl;
            }
    }
};

#endif // THREADLOGFILE_H
