#ifndef AI_COURSE_PROJECTS_HEURISTICS_H
#define AI_COURSE_PROJECTS_HEURISTICS_H

#include <unordered_map>
#include <stack>
#include <queue>
#include "vector"
#include "../inc/Table.h"
class Heuristics {
public:
    std::vector<Table> visited;
    std::stack<Table> frontier;
    std::queue<Table> frontierQ;
    std::vector<Table> evaluatedChildren;
    Table targetState = Table();
    Heuristics(){
        targetState.table[0][0] = Cell('1');
        targetState.table[0][1] = Cell('2');
        targetState.table[0][2] = Cell('3');
        targetState.table[1][0] = Cell('4');
        targetState.table[1][1] = Cell('5');
        targetState.table[1][2] = Cell('6');
        targetState.table[2][0] = Cell('7');
        targetState.table[2][1] = Cell('8');
        targetState.table[2][2] = Cell(' ');
    }
    void addToFrontierDFS(Table state);
    Table popFromFrontierDFS();
    void addToFrontierBFS(Table state);
    Table popFromFrontierBFS();
    void addToFrontierBestFirst(Table state);
    Table popFromFrontierBestFirst();
    bool existsInVisited(Table possibleState);
    void addToVisited(Table currentState);
    int evaluateStateBestFirst(Table state);
    int evaluateStateAstar(Table state);
};


#endif //AI_COURSE_PROJECTS_HEURISTICS_H
