//
// Created by arttu on 07/10/2021.
//

#ifndef MYGOAP_BRAIN_H
#define MYGOAP_BRAIN_H

#include "Action.h"
#include "Eat.h"
#include "GatherFood.h"
#include "Sleep.h"
#include "BuildWeapons.h"
#include <vector>

class Brain {

private:
    // Goal of our worker is to make as weapons many as possible in given actions.
    int given_actions, hunger, energy, weapons, food;
    // std::vector<Action*> available_actions;

    Eat * eat;
    Sleep* sleep;
    BuildWeapons* build_weapons;
    GatherFood* gather_food;
    std::vector<Action*> agents_plan;

private:
    void Create_World();

public:
    Brain(int, int, int, int, int);
    ~Brain();

    std::vector<Action*> Plan();
    void Print_Resources();
    void Execute_Plan();
};


#endif //MYGOAP_BRAIN_H
