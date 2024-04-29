//
// Created by MuFln on 28.04.2024.
//

#ifndef KURSACH_BARFACTORY_H
#define KURSACH_BARFACTORY_H
#include "Point.h"
#include "Segment.h"
#include "Bar.h"
#include "Machine.h"


class IBarFactory{
protected:
    static Bar* bar;
    static Point* generatePoint(){
        return new Point();
    }


    static Segment* generateSegment(){
        std::vector<Machine::IBar::ISegment::IPoint*> points = std::vector<Machine::IBar::ISegment::IPoint*>();
        for(int i = 0; i<5;i++){
            points.push_back(generatePoint());
        }
        return new Segment(points);
    }
public:
    static Bar* generateBar(int accuracy){
        std::vector<Machine::IBar::ISegment*> segments = std::vector<Machine::IBar::ISegment*>();
        for(int i = 0; i<accuracy;i++){
            segments.push_back(generateSegment());
        }
        return new Bar(segments);
    }
};
#endif //KURSACH_BARFACTORY_H
