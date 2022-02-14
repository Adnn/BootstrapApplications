#include <chrono>
#include <iostream>
#include <thread>


int main()
{
    std::cout << "I am a console application with an icon." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds{3});
    return 0;
}
