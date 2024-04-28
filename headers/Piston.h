//
// Created by MuFln on 28.04.2024.
//
#include "Machine.h"

#ifndef KURSACH_PISTON_H
#define KURSACH_PISTON_H
class Piston: public Machine::IPiston{
public:
    void PullOut(Machine::IBar bar, std::vector<Machine:: IBar> a) override{

    };
};


#endif //KURSACH_PISTON_H
