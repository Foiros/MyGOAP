//
// Created by arttu on 07/10/2021.
//

#include "Node.h"

Node::Node() = default;

Node::Node(int x, int y, bool _walkable, Node* _prev_node) :
location_x(x), location_y(y), walkable(_walkable), prev_node(_prev_node){
}

Node::~Node() = default;

void Node::Determine_Neighbors(int id) {

    int first_neighbor = 0;
    int second_neighbor = 0;

    if(id == 0){

        first_neighbor = 233 ;
        second_neighbor = id + 1;
    }
    else if (id == 233){

        first_neighbor = 0;
        second_neighbor = id - 1;
    }
    else{

        first_neighbor = id - 1;
        second_neighbor = id + 1;
    }

    neighbors.push_back(first_neighbor);
    neighbors.push_back(second_neighbor);
}


std::vector<int> Node::Get_Neighbors() const{

    return neighbors;
}

float Node::Get_G() const{
    // Just compute previous nodes and return cost to travel from start to this node
    float res = 0.0f;
    const Node* scan = this;
    while (scan->prev_node) {
        res += 1.0f;
        scan = scan->prev_node;
    }
    return res;
}

float Node::Get_H(Node* end_node) const{
    // For heuristic, use euclidean length of the vector from this node to end position.
    auto dx = float(end_node->location_x - location_x);
    auto dy = float(end_node->location_y - location_y);
    return sqrtf((dx * dx) + (dy * dy));
}

float Node::Get_F(Node* end_node) const{
    // F = G + H
    return Get_G() + Get_H(end_node);
}

bool Node::In_Bounds(int width, int height){

    if(location_x <= width && location_x>= -width && location_y <= height && location_y >= -height)
        return true;

    else
        return false;

    //return 0 <= id.locationX && id.locationX < width && 0 <= id.locationY && id.locationY < height;
}

bool Node::Walkable(){

    return walkable;
}