#include <iostream>
#include <string>
#include "../include/Array.hpp"

int main()
{
    std::cout << "=== Test 1: default constructor ===" << std::endl;
    Array<int> a;
    std::cout << "a.size() = " << a.size() << std::endl;

	// exception
    try {
        std::cout << "a[0] = " << a[0] << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Caught exception on a[0]: " << e.what() << std::endl;
    }




    std::cout << std::endl << "=== Test 2: constructor with size ===" << std::endl;
    Array<int> b(5);
    std::cout << "b.size() = " << b.size() << std::endl;

    for (unsigned int i = 0; i < b.size(); ++i)
        b[i] = static_cast<int>(i * 10);

    for (unsigned int i = 0; i < b.size(); ++i)
        std::cout << "b[" << i << "] = " << b[i] << std::endl;



		


    std::cout << std::endl << "=== Test 3: copy constructor (deep copy) ===" << std::endl;
    Array<int> c(b);
    std::cout << "c.size() = " << c.size() << std::endl;

    for (unsigned int i = 0; i < c.size(); ++i)
        std::cout << "c[" << i << "] = " << c[i] << std::endl;

    if (b.size() > 0)
        b[0] = 999;

    std::cout << "After modifying b[0] = 999:" << std::endl;
    std::cout << "b[0] = " << b[0] << std::endl;
    std::cout << "c[0] = " << c[0] << " (should NOT be 999)" << std::endl;





    std::cout << std::endl << "=== Test 4: copy assignment (deep copy) ===" << std::endl;
    Array<int> d;
    d = b;

    std::cout << "d.size() = " << d.size() << std::endl;
    for (unsigned int i = 0; i < d.size(); ++i)
        std::cout << "d[" << i << "] = " << d[i] << std::endl;

    if (d.size() > 1)
        d[1] = 555;

    std::cout << "After modifying d[1] = 555:" << std::endl;
    std::cout << "d[1] = " << d[1] << std::endl;
    std::cout << "b[1] = " << b[1] << " (should NOT be 555)" << std::endl;





    std::cout << std::endl << "=== Test 5: const Array and const operator[] ===" << std::endl;
    const Array<int> e(b);
    std::cout << "e.size() = " << e.size() << std::endl;
    for (unsigned int i = 0; i < e.size(); ++i)
        std::cout << "e[" << i << "] = " << e[i] << std::endl;

    // e[0] = 123; // ← これはコンパイルエラー

    std::cout << std::endl << "=== Test 6: Array<std::string> ===" << std::endl;
    Array<std::string> s(3);
    s[0] = "hello";
    s[1] = "world";
    s[2] = "!";

    for (unsigned int i = 0; i < s.size(); ++i)
        std::cout << "s[" << i << "] = " << s[i] << std::endl;

    try {
        std::cout << "Access s[10]..." << std::endl;
        std::cout << s[10] << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Caught exception on s[10]: " << e.what() << std::endl;
    }

    return 0;
}
