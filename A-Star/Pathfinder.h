//
// Created by arttu on 07/10/2021.
//

#ifndef MYGOAP_PATHFINDER_H
#define MYGOAP_PATHFINDER_H

#include <iostream>
#include <vector>
#include <queue>
#include "Node.h"
#include "PathfindingGrid.h"

template<typename T, typename priority_t>
struct PriorityQueue{

    typedef std::pair<priority_t, T> PQElement;
    std::priority_queue<PQElement, std::vector<PQElement>, std::greater<PQElement>> elements;

    inline bool empty() const{

        return elements.empty();
    }

    inline void put(T item, priority_t priority){

        elements.emplace(priority, item);
    }

    T get(){

        T best_item = elements.top().second;
        elements.pop();
        return best_item;
    }
};


class Pathfinder {

public:
    std::vector<Node*> path;
    Node* destination{};

public:
    Pathfinder();
    ~Pathfinder();

    void FindPath(PathfindingGrid* grid, Node* start, Node* goal,std::unordered_map<Node*, Node*>& cameFrom, std::unordered_map<Node*, double>& costSoFar);
    std::vector<Node*> ReconstructPath(Node* start, Node* goal, std::unordered_map<Node*, Node*> cameFrom);
    void FollowPath(std::vector<Node*> path);
};

inline double Heuristic(Node* a, Node* b){

    return std::abs(a->location_x - b->location_x) + std::abs(a->location_y - b->location_y);
}


#endif //MYGOAP_PATHFINDER_H
