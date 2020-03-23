//
// Created by athanasios on 23/03/2020.
//

#include "/inc/cell.h"

void setNumber(int number) {
    if (number > 0 && number < 9) {
        this.number = number;
    } else {
        cout << "Number is out of range"
    }
}
