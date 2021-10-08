#include <iostream>
#include "A-Star/PathfindingGrid.h"
#include "A-Star/Pathfinder.h"
#include "GOAP/Worker.h"
#include <unordered_map>

int main() {

//    auto grid = new PathfindingGrid(13, 9);
//    auto pathfinder = new Pathfinder();
//    grid->PrintGrid();
//    printf("%d", grid->Return_Nodes().size());
//
//    Node* start = grid->Return_Nodes().at(0);
//    Node* goal = grid->Return_Nodes().at(100);
//    std::unordered_map<Node*, Node*> came_from;
//    std::unordered_map<Node*, double> cost_so_far;
//
//    pathfinder->FindPath(grid, start, goal, came_from, cost_so_far);
//    pathfinder->path = pathfinder->ReconstructPath(start, goal, came_from);
//    pathfinder->FollowPath(pathfinder->path);

    auto* worker = new Worker();
    worker->brain->Plan();
    worker->brain->Execute_Plan();

    return 0;
}
