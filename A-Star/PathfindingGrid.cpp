//
// Created by arttu on 07/10/2021.
//

#include "PathfindingGrid.h"

PathfindingGrid::PathfindingGrid(){

    width = 13;
    height = 9;

    CreateGrid();
}

PathfindingGrid::PathfindingGrid(int w, int h) : width(w), height(h){

    CreateGrid();
}

PathfindingGrid::~PathfindingGrid() = default;

void PathfindingGrid::CreateGrid() {

    int amount_of_nodes = height * width;

    for (int i = 0; i < amount_of_nodes; ++i) {

        nodes_on_grid.push_back(new Node(i, i, true, nullptr));
    }
}

std::vector<Node*> PathfindingGrid::Get_Neighbors(Node id){

    std::vector<Node*> results;
    Node* prev_node = nullptr;

    for(Node dir : directions){

        Node* next = new Node(id.location_x + dir.location_x, id.location_y + dir.location_y, true, prev_node);

        if(next->In_Bounds(width, height) && next->Walkable()){

            results.push_back(next);
            prev_node = next;
        }
    }

    if((id.location_x + id.location_y) % 2 == 0){

        std::reverse(results.begin(), results.end());
    }

    return results;
}

void PathfindingGrid::PrintGrid() {

    for (auto node : nodes_on_grid) {

        printf("(%d, %d)", node->location_x, node->location_y);
    }
}

int PathfindingGrid::Get_Width() {
    return width;
}

int PathfindingGrid::Get_Height() {
    return height;
}

std::vector<Node*> PathfindingGrid::Return_Nodes() {
    return nodes_on_grid;
}

std::vector<Node*> PathfindingGrid::Return_Unwalkable_Nodes() {
    return unwalkable_nodes;
}




