//
// Created by arttu on 07/10/2021.
//

#include "Worker.h"

Worker::Worker() {

    brain = new Brain(30, 2, 5, 0, 1);
}

Worker::~Worker() = default;
