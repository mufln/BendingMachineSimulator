//
// Created by MuFln on 28.04.2024.
//

#ifndef KURSACH_SHAFT_H
#define KURSACH_SHAFT_H
#include "Machine.h"
#include "random"

class Shaft:public IMachine::IShaft {
public:
    Shaft(float angle, int affectedPoint1, int affectedPoint2) {
        this->POSTANGLE = angle;
        this->AFFECTEDPOINT1 = affectedPoint1;
        this->AFFECTEDPOINT2 = affectedPoint2;
    };
    void Bend(Machine::IBar::ISegment* segment) override{
        std::random_device rd; // obtain a random number from hardware
        std::mt19937 gen(rd()); // seed the generator
        std::uniform_int_distribution<> distr(-5, 5); // define the range
        segment->points[AFFECTEDPOINT1]->setAngle(POSTANGLE+(float)(distr(gen))/10);
        segment->points[AFFECTEDPOINT2]->setAngle(POSTANGLE+(float)(distr(gen))/10);
    };
};


#endif //KURSACH_SHAFT_H
