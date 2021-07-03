#include <iostream>
#include "my-complex.h"

int main()
{
    const complex c1(1.2, 3.2);
    std::cout << c1.real() << std::endl;
    system("pause");
    return 0;
}