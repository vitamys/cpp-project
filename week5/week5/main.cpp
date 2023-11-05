#include <iostream>
#include <thread>
#include <vector>

#include "ThreadLogFile.h"

using namespace std;


void logToFile(ThreadLogFile& log, int value){
    log.print(this_thread::get_id(), value);

}

int main()
{

    ThreadLogFile log;

    vector<thread> logThreads;
    for(size_t i = 0; i< thread::hardware_concurrency()*10; ++i)
    {
        logThreads.push_back(thread(logToFile,ref(log),i)); //pass reference, otherwise is copy and not concurrent
    }
    for(auto& th:logThreads){
        th.join();
    }
    return 0;
}
