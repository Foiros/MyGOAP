//
// Created by arttu on 08/10/2021.
//

#include "Sleep.h"


Sleep::Sleep(int _hunger_cost, int _energy_cost, int _energy_gain, int _action_ID, std::string _action_name) :
Action(_hunger_cost, _energy_cost, _action_ID, _action_name), energy_gain(_energy_gain){

}

int Sleep::Get_Energy_Gain() {
    return energy_gain;
}

Sleep::~Sleep() = default;
