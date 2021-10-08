//
// Created by arttu on 07/10/2021.
//

#include "Brain.h"

Brain::Brain(int _given_actions, int _hunger, int _energy, int _weapons, int _food) :
given_actions(_given_actions), hunger(_hunger), energy(_energy), weapons(_weapons), food(_food) {

    Create_World();
}

Brain::~Brain() = default;

void Brain::Create_World() {

    eat = new Eat(0, 0, 2, 0, "Eating");
    sleep = new Sleep(0, 0, 2, 1, "Sleeping");
    build_weapons = new BuildWeapons(1, 0, 1, 2, "Building weapons");
    gather_food = new GatherFood(0, 1, 1, 3, "Gathering food");

    // available_actions.push_back(eat);
    // available_actions.push_back(sleep);
    // available_actions.push_back(build_weapons);
    // available_actions.push_back(gather_food);
}

std::vector<Action*> Brain::Plan() {

    // int action_priority = 2;
    int amount_of_weapons_ordered = 10;

    while (weapons < amount_of_weapons_ordered) {
        while (given_actions > 0) {

            // Build a weapon
            if (hunger >= 2 && energy >= 2) {

                agents_plan.push_back(build_weapons);
                hunger -= build_weapons->Get_Hunger_Cost();
                energy -= build_weapons->Get_Energy_Cost();
                weapons += build_weapons->Get_Gain_Weapons();
            }
                // Gather food
            else if (food <= 1 && energy >= 2) {

                agents_plan.push_back(gather_food);
                hunger -= gather_food->Get_Hunger_Cost();
                energy -= gather_food->Get_Energy_Cost();
                food += gather_food->Get_Food_Gain();
            }
                // Eat
            else if (hunger <= 1 && food >= 2) {

                agents_plan.push_back(eat);
                hunger += eat->Get_Hunger_Gain();
                food -= eat->Get_Hunger_Gain();
            }
                // Sleep
            else if (energy <= 1) {

                agents_plan.push_back(sleep);
                energy += sleep->Get_Energy_Gain();
                hunger -= sleep->Get_Hunger_Cost();
            }

            Print_Resources();
            given_actions--;

            if(weapons >= amount_of_weapons_ordered)
                break;
        }
    }

    return agents_plan;
}

void Brain::Execute_Plan() {

    for (int i = 0; i < agents_plan.size(); ++i) {

        printf("Action %d: ", i);
        agents_plan.at(i)->Print_Action();
    }
}

void Brain::Print_Resources() {

    printf("Hunger: %d\n", hunger);
    printf("Energy: %d\n", energy);
    printf("Weapons: %d\n", weapons);
    printf("Food: %d\n", food);
    printf("\n");
}
