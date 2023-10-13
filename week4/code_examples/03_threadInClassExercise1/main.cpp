#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;

mutex mu;
void printMe(int ID)
{
    lock_guard<mutex> guard(mu);
    cout << "Message from Thread :" << ID
         << " from thread: " << this_thread::get_id()<< endl;
}

int main()
{
    // 1) Call print from main
        printMe(0);


        // 2) Call print from thread
        thread t1(printMe, 1);


        // 3) Create vector of threads according to available cores on your machine
        vector<thread> threads;
        for (int i = 0; i < thread::hardware_concurrency(); ++i)
        {
            threads.push_back(thread(printMe, i));
        }

        // 4 Join threads
        t1.join();
        for (auto& t : threads)
        {
            t.join();


        }
    return 0;
}
