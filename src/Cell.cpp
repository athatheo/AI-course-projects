#include "/inc/cell.h"
#include "../inc/cell.h"


void cell::getNumber() {
    return number;
}

void cell::setNumber(int number) {
    if (number > 0 && number < 9) {
        this.number = number;
    } else {
        cout << "Number is out of range"
    }
}
