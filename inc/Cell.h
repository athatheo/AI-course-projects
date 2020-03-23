#ifndef AI_COURSE_PROJECTS_CELL_H
#define AI_COURSE_PROJECTS_CELL_H
#include <iostream>


class Cell {
protected:
    int number;
public:
    Cell() = default;
    explicit Cell (int number) {
        this->number = number;
    }
    void setNumber(int number);
    int getNumber();

};


#endif //AI_COURSE_PROJECTS_CELL_H
