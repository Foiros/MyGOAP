//
// Created by arttu on 07/10/2021.
//

#include "Pathfinder.h"

Pathfinder::Pathfinder() = default;

Pathfinder::~Pathfinder() = default;

void Pathfinder::FindPath(PathfindingGrid *grid, Node *start, Node *goal, std::unordered_map<Node *, Node *> &cameFrom,
                          std::unordered_map<Node *, double> &costSoFar) {

    PriorityQueue<Node*, double> frontier;
    frontier.put(start, 0);{}

    cameFrom[start] = start;
    costSoFar[start] = 0;

    while(!frontier.empty()){

        Node* current = frontier.get();
        printf("Current node: %d, %d\n", current->location_x, current->location_y);

        if(current == goal){

            break;
        }

        for(Node* next : grid->Return_Specific_Nodes(current->Get_Neighbors())){

            double newCost = costSoFar[current] + current->Get_F(next);

            if(costSoFar.find(next) == costSoFar.end() || newCost < costSoFar[next]){

                costSoFar[next] = newCost;
                double priority = newCost + Heuristic(next, goal);
                frontier.put(next, priority);
                cameFrom[next] = current;
            }
        }
    }
}

std::vector<Node *> Pathfinder::ReconstructPath(Node *start, Node *goal, std::unordered_map<Node *, Node *> cameFrom) {

    std::vector<Node*> _path;
    Node* current = goal;

    while(current != start){

        path.push_back(current);
        current = cameFrom[current];
    }

    path.push_back(start);
    std::reverse(path.begin(), path.end());

    return _path;
}

void Pathfinder::FollowPath(std::vector<Node *> _path) {

    for (auto node : _path)
        printf("%d, %d\n", node->location_x, node->location_y);

    printf("Path has been traversed!");
}
