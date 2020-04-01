#include <iostream>
#include "inc/Cell.h"
#include "inc/Table.h"
#include "inc/Heuristics.h"
#include <bits/stdc++.h>

void DFS(){
    Table currentState = Table();
    Table possibleState;
    Heuristics heuristics = Heuristics();
    heuristics.addToFrontier(currentState);
    int row;
    int col;
    int counter = 0;
    currentState.flag = true;
    while (counter < 100 && !currentState.equals(heuristics.targetState)) {
        currentState = heuristics.popFromFrontier();
        row = currentState.current_row;
        col = currentState.current_col;
        counter++;
        std::cout << "Size: " << heuristics.frontier.size() << " " << row << " " << col << std::endl;
        if (row - 1 >= 0) {
            possibleState = currentState.move(Table::up, row, col);
            currentState.printState();
            if (!heuristics.visited[0]->equals(currentState)){
                std::cout << "WHY IS THIS SHIT DIFFERENT";//->printState();
            }
            possibleState.printState();
            if (!heuristics.existsInVisited(possibleState)) {
                heuristics.addToFrontier(possibleState);
            }
        }
        if (row + 1 < 3) {
            possibleState = currentState.move(Table::down, row, col);
            if (!heuristics.existsInVisited(possibleState)) {
                heuristics.addToFrontier(possibleState);
            }
        }
        if (col - 1 >= 0) {
            possibleState = currentState.move(Table::left, row, col);
            if (!heuristics.existsInVisited(possibleState)) {
                heuristics.addToFrontier(possibleState);
            }
        }
        if (col + 1 < 3) {
            possibleState = currentState.move(Table::right, row, col);
            if (!heuristics.existsInVisited(possibleState)) {
                heuristics.addToFrontier(possibleState);
            }
        }
        if (heuristics.frontier.empty()){
            std::cout << "No solution" << std::endl;
            break;
        }
    }
}

void BFS() {

}

void BestFirst() {

}

void Astar() {

}
int main() {
    int choice = 0;
    std::cout << "Welcome! Please choose one of the various algorithms implemented:" << std::endl;
    while (choice != 5) {
        std::cout << "1. DFS \n 2. BFS \n 3. Best First Search \n 4. A* \n";
        std::cin >> choice;
        if (choice == 1) {
            DFS();
        } else if (choice == 2) {
            BFS();
        } else if (choice == 3) {
            BestFirst();
        } else if (choice == 4) {
            Astar();
        }
    }
    return 0;
}


