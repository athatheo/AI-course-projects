#include <iostream>
#include "inc/Table.h"
#include "inc/Heuristics.h"

void DFS(){
    Table currentState = Table();
    Table possibleState;
    Heuristics heuristics = Heuristics();
    heuristics.addToFrontierDFS(currentState);
    int row;
    int col;
    int counter = 0;
    while ((!currentState.equals(heuristics.targetState)) && !heuristics.frontier.empty()){
        currentState = heuristics.popFromFrontierDFS();
        while(!heuristics.frontier.empty() && heuristics.existsInVisited(currentState)) {
            currentState = heuristics.popFromFrontierDFS();
        }
        if (!heuristics.frontier.empty() && heuristics.existsInVisited(currentState)){
            std::cout << "No solution" << std::endl;
            break;
        }
        heuristics.visited.push_back(currentState);
        row = currentState.current_row;
        col = currentState.current_col;
        if (row - 1 >= 0) {
            possibleState = currentState.move(Table::up, row, col);
            heuristics.addToFrontierDFS(possibleState);
        }
        if (row + 1 < 3) {
            possibleState = currentState.move(Table::down, row, col);
            heuristics.addToFrontierDFS(possibleState);
        }
        if (col - 1 >= 0) {
            possibleState = currentState.move(Table::left, row, col);
            heuristics.addToFrontierDFS(possibleState);
        }
        if (col + 1 < 3) {
            possibleState = currentState.move(Table::right, row, col);
            heuristics.addToFrontierDFS(possibleState);
        }
        counter++;
    }
    std::cout << "Different states visited: " << counter << std::endl;
}

void BFS() {
    Table currentState = Table();
    Table possibleState;
    Heuristics heuristics = Heuristics();
    heuristics.addToFrontierBFS(currentState);
    int row;
    int col;
    int counter = 0;
    while ((!currentState.equals(heuristics.targetState)) && !heuristics.frontierQ.empty()){
        currentState = heuristics.popFromFrontierBFS();
        while(!heuristics.frontierQ.empty() && heuristics.existsInVisited(currentState)) {
            currentState = heuristics.popFromFrontierBFS();
        }
        if (!heuristics.frontierQ.empty() && heuristics.existsInVisited(currentState)){
            std::cout << "No solution" << std::endl;
            break;
        }
        heuristics.addToVisited(currentState);
        row = currentState.current_row;
        col = currentState.current_col;
        if (row - 1 >= 0) {
            possibleState = currentState.move(Table::up, row, col);
            heuristics.addToFrontierBFS(possibleState);
        }
        if (row + 1 < 3) {
            possibleState = currentState.move(Table::down, row, col);
            heuristics.addToFrontierBFS(possibleState);
        }
        if (col - 1 >= 0) {
            possibleState = currentState.move(Table::left, row, col);
            heuristics.addToFrontierBFS(possibleState);
        }
        if (col + 1 < 3) {
            possibleState = currentState.move(Table::right, row, col);
            heuristics.addToFrontierBFS(possibleState);
        }
        counter++;
    }
    std::cout << "Different states visited: " << counter << std::endl;
}

void BestFirst() {
    Table currentState = Table();
    Table possibleState;
    Heuristics heuristics = Heuristics();
    heuristics.addToFrontierBestFirst(currentState);
    int row;
    int col;
    int counter = 0;
    while ((!currentState.equals(heuristics.targetState)) && !heuristics.evaluatedChildren.empty()){
        currentState = heuristics.popFromFrontierBestFirst();
        while(!heuristics.evaluatedChildren.empty() && heuristics.existsInVisited(currentState)) {
            currentState = heuristics.popFromFrontierBestFirst();
        }
        if (!heuristics.evaluatedChildren.empty() && heuristics.existsInVisited(currentState)){
            std::cout << "No solution" << std::endl;
            break;
        }
        heuristics.addToVisited(currentState);
        row = currentState.current_row;
        col = currentState.current_col;
        if (row - 1 >= 0) {
            possibleState = currentState.move(Table::up, row, col);
            possibleState.evaluationScore = heuristics.evaluateStateBestFirst(possibleState);
            heuristics.addToFrontierBestFirst(possibleState);
        }
        if (row + 1 < 3) {
            possibleState = currentState.move(Table::down, row, col);
            possibleState.evaluationScore = heuristics.evaluateStateBestFirst(possibleState);
            heuristics.addToFrontierBestFirst(possibleState);
        }
        if (col - 1 >= 0) {
            possibleState = currentState.move(Table::left, row, col);
            possibleState.evaluationScore = heuristics.evaluateStateBestFirst(possibleState);
            heuristics.addToFrontierBestFirst(possibleState);
        }
        if (col + 1 < 3) {
            possibleState = currentState.move(Table::right, row, col);
            possibleState.evaluationScore = heuristics.evaluateStateBestFirst(possibleState);
            heuristics.addToFrontierBestFirst(possibleState);
        }
        counter++;
    }
    std::cout << "Different states visited: " << counter << std::endl;
}

void Astar() {
    Table currentState = Table();
    Table possibleState;
    Heuristics heuristics = Heuristics();
    heuristics.addToFrontierBestFirst(currentState);
    int row;
    int col;
    int counter = 0;
    while ((!currentState.equals(heuristics.targetState)) && !heuristics.evaluatedChildren.empty()){
        currentState = heuristics.popFromFrontierBestFirst();
        while(!heuristics.evaluatedChildren.empty() && heuristics.existsInVisited(currentState)) {
            currentState = heuristics.popFromFrontierBestFirst();
        }
        if (!heuristics.evaluatedChildren.empty() && heuristics.existsInVisited(currentState)){
            std::cout << "No solution" << std::endl;
            break;
        }
        heuristics.addToVisited(currentState);
        row = currentState.current_row;
        col = currentState.current_col;
        if (row - 1 >= 0) {
            possibleState = currentState.move(Table::up, row, col);
            possibleState.evaluationScore = heuristics.evaluateStateAstar(possibleState);
            heuristics.addToFrontierBestFirst(possibleState);
        }
        if (row + 1 < 3) {
            possibleState = currentState.move(Table::down, row, col);
            possibleState.evaluationScore = heuristics.evaluateStateAstar(possibleState);
            heuristics.addToFrontierBestFirst(possibleState);
        }
        if (col - 1 >= 0) {
            possibleState = currentState.move(Table::left, row, col);
            possibleState.evaluationScore = heuristics.evaluateStateAstar(possibleState);
            heuristics.addToFrontierBestFirst(possibleState);
        }
        if (col + 1 < 3) {
            possibleState = currentState.move(Table::right, row, col);
            possibleState.evaluationScore = heuristics.evaluateStateAstar(possibleState);
            heuristics.addToFrontierBestFirst(possibleState);
        }
        counter++;
    }
    std::cout << "Different states visited: " << counter << std::endl;

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


