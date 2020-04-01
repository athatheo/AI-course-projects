#include <vector>
#include "../inc/Table.h"

void Table::printState() {
    for (int i = 0; i < HEIGHT; i++) {
        std::cout << "|";
        for (int j = 0; j < WIDTH; j++) {
            std::cout << table[i][j].getNumber() << "|";
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < 2*HEIGHT; i++) {
        std::cout << "-";
    }
    std::cout << std::endl;
}

Table Table::move(Table::DIRECTION dir, int row, int col) {
    Table table = Table();
    for (int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < WIDTH; j++) {
            table.table[i][j] = this->table[i][j];
        }
    }
    table.current_row = this->current_row;
    table.current_col = this->current_col;
    if (dir == 1) {
        table.table[row][col].setNumber(this->table[row-1][col].getNumber());
        table.table[row-1][col].setNumber(' ');
        table.current_row =-1;
    } else if (dir == 2) {
        table.table[row][col].setNumber(this->table[row+1][col].getNumber());
        table.table[row+1][col].setNumber(' ');
        table.current_row =+1;
    } else if (dir == 3){
        table.table[row][col].setNumber(this->table[row][col-1].getNumber());
        table.table[row][col-1].setNumber(' ');
        table.current_col =-1;
    } else {
        table.table[row][col].setNumber(this->table[row][col+1].getNumber());
        table.table[row][col+1].setNumber(' ');
        table.current_col =+1;
    }
    return table;
}

bool Table::equals(Table b) {
    for (int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < WIDTH; j++) {
            if (this->table[i][j].getNumber() != b.table[i][j].getNumber()) {
                return false;
            }
        }
    }
    return true;
}

Table Table::assign() {
    Table table = Table();
    for (int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < WIDTH; j++) {
            table.table[i][j] = this->table[i][j];
        }
    }
    return table;
}
