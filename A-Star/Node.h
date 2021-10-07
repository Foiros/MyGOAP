//
// Created by arttu on 07/10/2021.
//

#ifndef MYGOAP_NODE_H
#define MYGOAP_NODE_H

#include <iterator>
#include <algorithm>


class Node {

public:
    int location_x, location_y;
    bool walkable;
    Node* prev_node;

public:
    Node();
    Node(int, int, bool, Node*);
    ~Node();

    [[nodiscard]] float Get_G() const;
    float Get_H(Node*) const;
    float Get_F(Node*) const;
    bool In_Bounds(int, int);
    bool Walkable();
};


#endif //MYGOAP_NODE_H
