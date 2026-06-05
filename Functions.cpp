#include <iostream>

// __cdeclcall calling convention
int __cdecl cdeclAdd(int a, int b)
{
    int c = a + b;
    return c;
}

// __stdcall calling convention
int __stdcall stdcallAdd(int a, int b)
{
    int c = a + b;
    return c;
}

int main()
{
    int result;

    // Function calls and output
    result = cdeclAdd(1, 2);
    std::cout << "Result: " << result << std::endl;

    result = stdcallAdd(3, 4);
    std::cout << "Result: " << result << std::endl;
}
