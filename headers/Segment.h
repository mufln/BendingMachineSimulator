//
// Created by MuFln on 28.04.2024.
//
#include "Machine.h"
#ifndef KURSACH_SEGMENT_H
#define KURSACH_SEGMENT_H

class Segment: public Machine::IBar::ISegment{
public:
    Segment(std::vector<Machine::IBar::ISegment::IPoint*> points){
        this->points = points;
    };
};


#endif //KURSACH_SEGMENT_H
