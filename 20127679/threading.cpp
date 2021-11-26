//C++ program demonstrating how to implement thread
#include <string>
#include <iostream>
#include <thread>
using namespace std;

// functions that have to be executed on the thread
class th_obj {
public:
    void operator()(int num)
    {
        cout << "Parameter countdown . . . ";
        for (int i = 0; i < num; i++)
            cout << i << " ";
        cout << endl;
    }
};
void func(string txt)
{
    cout << " Function func displays : " << txt;
}

int main()
{
    // A new thread is created and executed: display func
    thread th(func, "Oh man func is working wow . . . \n");
    
    // Thread starts by using function object as callable
    thread t2(th_obj(), 4);

    // Waiting for finishing of thread t2 and th (they are doing both)
    t2.join(); //countdown

    th.join(); //func display

    // Main thread waits for the new threads to stop execution and as a result, its own execution gets blocked
    cout << "This is the end of the thread. " << endl;
}