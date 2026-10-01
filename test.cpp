#include <iostream>
#include <thread>
#include <chrono>

int main()
{
    std::cout << "Hello" << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(3));

    std::cout << "World" << std::endl;

    return 0;
}