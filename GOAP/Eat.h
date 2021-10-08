//
// Created by arttu on 08/10/2021.
//

#ifndef MYGOAP_EAT_H
#define MYGOAP_EAT_H

#include "Action.h"

class Eat : public Action{

private:
    const int hunger_gain;

public:
    Eat(int, int, int, int, std::string);
    ~Eat();

    int Get_Hunger_Gain();
};

#endif //MYGOAP_EAT_H
