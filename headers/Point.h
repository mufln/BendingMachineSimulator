//
// Created by MuFln on 28.04.2024.
//

#ifndef KURSACH_POINT_H
#define KURSACH_POINT_H
#include "Machine.h"


class Point: public Machine::IBar::ISegment::IPoint{
protected:
    float nextPointAngle = 180 ;
public:
    Point(){};
    void setAngle(float angle) override{
        nextPointAngle -= angle;
    };
    float getAngle() override{
        return nextPointAngle;
    };

};


#endif //KURSACH_POINT_H
