//
// Created by MuFln on 28.04.2024.
//
#ifndef KURSACH_SENSOR_H
#define KURSACH_SENSOR_H
#include "Machine.h"

class Sensor: public Machine::ISensor{

public:
    Sensor(int checkingPoint1,int checkingPoint2){
        this->CHECKINGPOINT1=checkingPoint1;
        this->CHECKINGPOINT2=checkingPoint2;
    }
    bool check(Machine::IBar::ISegment* segment) override{
        if(90-segment->points[CHECKINGPOINT1]->getAngle()>ACCURACY){
            return false;
        }
        if(90-segment->points[CHECKINGPOINT1]->getAngle()>ACCURACY){
            return false;
        }
        return true;
    };
};


#endif //KURSACH_SENSOR_H
