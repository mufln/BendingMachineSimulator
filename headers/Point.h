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
};


#endif //KURSACH_POINT_H
