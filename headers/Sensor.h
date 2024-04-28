//
// Created by MuFln on 28.04.2024.
//
#include "Machine.h"

#ifndef KURSACH_SENSOR_H
#define KURSACH_SENSOR_H

class Sensor: public Machine::ISensor{
public:
    Sensor(){
    }
    bool Check(Machine::IBar bar) override{

    };
};


#endif //KURSACH_SENSOR_H
