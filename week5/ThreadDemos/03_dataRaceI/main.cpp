#include <iostream>
#include <thread>

using namespace std;

void setX(int& x, int value)
{
    x = value;
}

int main()
{
    int x = 1;
    thread setX1{setX, ref(x), 100};
    thread setX2{setX, ref(x), 200};

    setX1.join();
    setX2.join();

    cout << x << " ";
    return 0;
}
