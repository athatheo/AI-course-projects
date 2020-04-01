#include "../inc/Heuristics.h"

void Heuristics::addToFrontier(Table state) {
    this->frontier.push(state);
}

Table Heuristics::popFromFrontier() {
    Table table = this->frontier.top();
    this->visited.push_back(&table);
    frontier.pop();
    std::cout << "Next one is in pop" << frontier.size();
    this->visited[0]->printState();
    return table;
}

int Heuristics::evaluateStateBestFirst(Table state) {
    return 0;
}

bool Heuristics::existsInVisited(Table possibleState) {
    for (auto table : this->visited) {
        if(table->equals(possibleState)){
            std::cout << "REACHED PREVIOUS" << std::endl;
            return true;
        }
    }
    return false;
}
