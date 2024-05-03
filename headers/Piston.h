//
// Created by MuFln on 28.04.2024.
//
#include "Machine.h"

#ifndef KURSACH_PISTON_H
#define KURSACH_PISTON_H
class Piston: public Machine::IPiston{
public:
    std::vector<Machine::IBar*> pullOut(Machine::IBar* bar, std::vector<Machine:: IBar*> a) override{
        a.push_back(bar);
        return a;
    };
};


#endif //KURSACH_PISTON_H
