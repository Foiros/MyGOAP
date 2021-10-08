//
// Created by arttu on 08/10/2021.
//

#ifndef MYGOAP_GATHERFOOD_H
#define MYGOAP_GATHERFOOD_H

#include "Action.h"

class GatherFood : public Action{

private:
    const int food_gain;

public:
    GatherFood(int, int, int, int, std::string);
    ~GatherFood();

    int Get_Food_Gain();
};

#endif //MYGOAP_GATHERFOOD_H
