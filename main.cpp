#include <iostream>
#include "inc/Cell.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Cell cell(1);
    std::cout << cell.getNumber() << std::endl;

    return 0;
}
