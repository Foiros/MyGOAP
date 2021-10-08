//
// Created by arttu on 08/10/2021.
//

#ifndef MYGOAP_SLEEP_H
#define MYGOAP_SLEEP_H

#include "Action.h"

class Sleep : public Action{

protected:
    const int energy_gain;

public:
    Sleep(int, int, int, int, std::string);
    ~Sleep();

    int Get_Energy_Gain();
};

#endif //MYGOAP_SLEEP_H
