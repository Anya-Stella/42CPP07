#include <iostream>
#include <string>
#include "../include/iter.hpp"

template <typename T>
void print(const T &x)
{
    std::cout << x << " ";
}

void increment(int &x)
{
    ++x;
}

void shout(const std::string &s)
{
    std::cout << s << "!" << std::endl;
}

void changeTo42(std::string &s)
{
     s = "42";
}

int main()
{
    // int array
    {
        int arr[] = {1, 2, 3, 4, 5};
        std::size_t len = sizeof(arr) / sizeof(arr[0]);

        std::cout << "=== int array: before increment ===" << std::endl;
        iter(arr, len, print<int>);
        std::cout << std::endl;

        iter(arr, len, increment);

        std::cout << "=== int array: after increment ===" << std::endl;
        iter(arr, len, print<int>);
        std::cout << std::endl << std::endl;
    }

    // const int array(read only)
    {
        const int arr[] = {10, 20, 30};
        std::size_t len = sizeof(arr) / sizeof(arr[0]);

        std::cout << "=== const int array ===" << std::endl;
        iter(arr, len, print<int>);
        std::cout << std::endl << std::endl;
    }

	// std::string
    {
        std::string words[] = {"hello", "iter", "world"};
        std::size_t len = sizeof(words) / sizeof(words[0]);

        std::cout << "=== before changeHelloTo42 ===" << std::endl;
        iter(words, len, print<std::string>);
        std::cout << std::endl;

        iter(words, len, changeTo42);

        std::cout << "=== after changeHelloTo42 ===" << std::endl;
        iter(words, len, print<std::string>);
        std::cout << std::endl;
    }

    // const std::string(read only)
    {
        const std::string words[] = {"const", "array", "test"};
        std::size_t len = sizeof(words) / sizeof(words[0]);

        std::cout << "=== const std::string array ===" << std::endl;
        iter(words, len, shout);
        std::cout << std::endl;
    }

    return 0;
}
