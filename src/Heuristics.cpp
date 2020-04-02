#include "../inc/Heuristics.h"

void Heuristics::addToFrontierDFS(Table state) {
    this->frontier.push(state);
}

Table Heuristics::popFromFrontierDFS() {
    Table table = this->frontier.top();
    frontier.pop();
    return table;
}

void Heuristics::addToFrontierBFS(Table state) {
    this->frontierQ.push(state);
}

Table Heuristics::popFromFrontierBFS() {
    Table table = this->frontierQ.front();
    frontierQ.pop();
    return table;
}

void Heuristics::addToVisited(Table currentState) {
    visited.push_back(currentState);
}

void Heuristics::addToFrontierBestFirst(Table state) {
    this->evaluatedChildren.push_back(state);
}

Table Heuristics::popFromFrontierBestFirst() {
    Table bestNextState;
    int score = 1000;
    int positionOfBest;
    int position = 0;
    for (Table table : evaluatedChildren) {
        if (table.evaluationScore <= score) {
            score = table.evaluationScore;
            positionOfBest = position;
            bestNextState = table;
        }
        position++;
    }
    evaluatedChildren.erase(evaluatedChildren.begin()+positionOfBest);
    return bestNextState;
}

int Heuristics::evaluateStateBestFirst(Table currentState) {
    int distance = 0;
    int number = 0;
    for(int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (currentState.table[i][j].getNumber()  != ' ') {
                number = currentState.table[i][j].getNumber() - '0';
                distance += (abs(i - (number-1)/3) + abs(j - (number-1)%3) ) ;
            }
        }
    }
    return distance;
}

int Heuristics::evaluateStateAstar(Table currentState) {
    int distance = 0;
    Table initialTable = Table();
    int number = 0;
    for(int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (currentState.table[i][j].getNumber()  != ' ') {
                number = currentState.table[i][j].getNumber() - '0';
                distance += (abs(i - (number-1)/3) + abs(j - (number-1)%3) ) ;
            }
            distance += (abs(i - (number-1)/3) + abs(j - (number-1)%3) ) ;
        }
    }
    for(int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (currentState.table[i][j].getNumber()  != ' ') {
                number = currentState.table[i][j].getNumber() - '0';
                distance += (abs(i - (number-1)/3) + abs(j - (number-1)%3) ) ;
            }
            distance += (abs(i - (number-1)/3) + abs(j - (number-1)%3) ) ;
        }
    }
    return distance;
}

bool Heuristics::existsInVisited(Table possibleState) {
    for (auto table : this->visited) {
        if(table.equals(possibleState)){
            return true;
        }
    }
    return false;
}
