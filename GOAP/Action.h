//
// Created by arttu on 08/10/2021.
//

#ifndef MYGOAP_ACTION_H
#define MYGOAP_ACTION_H

#include <string>
#include <iostream>


class Action {

protected:
    const int hunger_cost;
    const int energy_cost;
    const int action_id;
    const std::string action_name;

public:
    Action(int, int, int, std::string);
    ~Action();

    int Get_Hunger_Cost();
    int Get_Energy_Cost();
    int Get_Action_ID();

    void Print_Action();
};


#endif //MYGOAP_ACTION_H
