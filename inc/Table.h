#ifndef AI_COURSE_PROJECTS_TABLE_H
#define AI_COURSE_PROJECTS_TABLE_H
#define HEIGHT 3
#define WIDTH 3

#include "Cell.h"
class Table {
public:
    bool flag = false;

    Cell table[HEIGHT][WIDTH];
    int current_row = 1;
    int current_col = 1;
    Table() {
        table[0][0] = Cell('1');
        table[0][1] = Cell('3');
        table[0][2] = Cell('6');
        table[1][0] = Cell('4');
        table[1][1] = Cell(' ');
        table[1][2] = Cell('2');
        table[2][0] = Cell('7');
        table[2][1] = Cell('5');
        table[2][2] = Cell('8');
    }
    enum DIRECTION{
        up = 1,
        down = 2,
        left = 3,
        right = 4
    };
    void printState();
    Table move(DIRECTION, int row, int col);
    bool equals(Table b);
    Table assign();
};


#endif //AI_COURSE_PROJECTS_TABLE_H
