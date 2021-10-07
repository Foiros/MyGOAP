//
// Created by arttu on 07/10/2021.
//

#ifndef MYGOAP_PATHFINDINGGRID_H
#define MYGOAP_PATHFINDINGGRID_H

#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include "Node.h"

template <> struct ::std::hash<Node>{

    typedef Node argument_type;

    typedef std::size_t _type;

    std::size_t operator()(const Node& id) const noexcept{

        return std::hash<int>()(id.location_x ^ (id.location_y << 4));
    }
};


class PathfindingGrid {

private:
    int width, height;

    // East, west, north, south
    const std::vector<Node> directions = {Node{1, 0, true, nullptr},
                                         Node{-1, 0, true, nullptr},
                                         Node{0, -1, true, nullptr},
                                         Node{0, 1,true, nullptr}};
    std::vector<Node*> nodes_on_grid;
    std::vector<Node*> unwalkable_nodes;


private:
    void CreateGrid();

public:
    PathfindingGrid();
    PathfindingGrid(int, int);
    ~PathfindingGrid();

    void PrintGrid();

    std::vector<Node*> Get_Neighbors(Node);
    int Get_Width();
    int Get_Height();
    std::vector<Node*> Return_Nodes();
    std::vector<Node*> Return_Unwalkable_Nodes();
};

inline bool operator == (Node a, Node b) {

    return a.location_x == b.location_x && a.location_y == b.location_y;
}

inline bool operator != (Node a, Node b) {

    return !(a == b);
}

inline bool operator < (Node a, Node b) {

    return ::std::tie(a.location_x, a.location_y) < ::std::tie(b.location_x, b.location_y);
}


#endif //MYGOAP_PATHFINDINGGRID_H
