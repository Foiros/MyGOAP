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

    for (int i = -amount_of_nodes; i < amount_of_nodes; ++i)
        nodes_on_grid.push_back(new Node(i, i, true, nullptr));

    for (int i = 0; i < nodes_on_grid.size(); ++i)
        nodes_on_grid[i]->Determine_Neighbors(i);
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

std::vector<Node *> PathfindingGrid::Return_Specific_Nodes(std::vector<int> node_ids) {

    std::vector<Node*> nodes;
    nodes.reserve(node_ids.size());

    for (int node_id : node_ids)
        nodes.push_back(nodes_on_grid.at(node_id));


    return nodes;
}


std::vector<Node*> PathfindingGrid::Return_Unwalkable_Nodes() {
    return unwalkable_nodes;
}



