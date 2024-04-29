//
// Created by MuFln on 28.04.2024.
//
#include "Machine.h"

#ifndef KURSACH_SHAFT_H
#define KURSACH_SHAFT_H


class Shaft:public IMachine::IShaft {
public:
    Shaft(float angle) {
        this->POSTANGLE = angle;
    };
    void Bend(Machine::IBar::ISegment* bar) override{

    };
};


#endif //KURSACH_SHAFT_H
