//
// Created by arttu on 08/10/2021.
//

#include "Eat.h"

Eat::Eat(int _hunger_cost, int _energy_cost, int _hunger_gain, int _action_ID, std::string _action_name) :
        Action(_hunger_cost, _energy_cost, _action_ID, _action_name), hunger_gain(_hunger_gain){

}

int Eat::Get_Hunger_Gain() {
    return hunger_gain;
}

Eat::~Eat() = default;
