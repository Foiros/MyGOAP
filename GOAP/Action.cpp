//
// Created by arttu on 08/10/2021.
//

#include "Action.h"

Action::Action(int _hunger_cost, int _energy_cost, int _action_ID, std::string _action_name) :
hunger_cost(_hunger_cost), energy_cost(_energy_cost), action_id(_action_ID), action_name(_action_name)  {

}

Action::~Action() = default;


int Action::Get_Hunger_Cost() {
    return hunger_cost;
}

int Action::Get_Energy_Cost() {
    return energy_cost;
}

int Action::Get_Action_ID() {
    return action_id;
}

void Action::Print_Action() {

    printf("%s\n", action_name.c_str());
}
