//
// Created by arttu on 08/10/2021.
//

#include "GatherFood.h"

GatherFood::GatherFood(int _hunger_cost, int _energy_cost, int _food_gain, int _action_ID, std::string _action_name) :
        Action(_hunger_cost, _energy_cost, _action_ID, _action_name), food_gain(_food_gain){

}

int GatherFood::Get_Food_Gain() {
    return food_gain;
}

GatherFood::~GatherFood() = default;
