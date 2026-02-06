#include "src/axis.h"
#include "src/point3D.h"
#include <array>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

int func1()
{
    std::cout << "Hello world\n";
    return 0;
}

void func2(int n)
{
    std::cout << ("Your number is {}\n", n);
}

int main()
{
    // // std::thread thread1(func1);
    // // std::thread thread2(func2, 5);

    // std::array<std::thread, 5> arr_thread;
    // for (int i =0; i<5; i++) {
    //     arr_thread.at(i) = std::thread {[](double n) { std::cout << "\nNumber = \n" << n; }, i};
    // }

    // for (int i = 0; i < 5; i++)
    // {
    //     arr_thread.at(i).detach();
    // }

    // // std::condition_variable a;
    // // std::mutex mut;
    // // std::lock_guard<std::mutex> fg(mut);

    // std::cout << "\nMain thread\n";

    Point3D<int> a {1, 2, 3};
    a.set(Axis::X, 3);
    std::cout << a << "\n";

    return 0;
}
