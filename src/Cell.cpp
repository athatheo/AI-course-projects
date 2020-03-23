#include "../inc/Cell.h"

int Cell::getNumber() {
    return number;
}
void Cell::setNumber(int number) {
    if (number > 0 && number < 9) {
        this->number = number;
    } else {
        std::cout << "Number is out of range" << std::endl;
    }
}
