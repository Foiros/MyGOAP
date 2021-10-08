//
// Created by arttu on 08/10/2021.
//

#ifndef MYGOAP_BUILDWEAPONS_H
#define MYGOAP_BUILDWEAPONS_H

#include "Action.h"

class BuildWeapons : public Action{

private:
    const int gain_weapons;

public:
    BuildWeapons(int, int, int, int, std::string);
    ~BuildWeapons();

    int Get_Gain_Weapons();
};

#endif //MYGOAP_BUILDWEAPONS_H
