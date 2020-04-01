#ifndef AI_COURSE_PROJECTS_CELL_H
#define AI_COURSE_PROJECTS_CELL_H
#include <iostream>


class Cell {
protected:
    char number;
public:
    Cell() = default;
    explicit Cell (char number) {
        this->number = number;
    }
    void setNumber(char number);
    char getNumber();

};


#endif //AI_COURSE_PROJECTS_CELL_H
