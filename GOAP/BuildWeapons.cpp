//
// Created by arttu on 08/10/2021.
//

#include "BuildWeapons.h"


BuildWeapons::BuildWeapons(int _hunger_cost, int _energy_cost, int _weapon_gain, int _action_ID, std::string _action_name) :
        Action(_hunger_cost, _energy_cost, _action_ID, _action_name), gain_weapons(_weapon_gain){

}

int BuildWeapons::Get_Gain_Weapons() {
    return gain_weapons;
}

BuildWeapons::~BuildWeapons() = default;
