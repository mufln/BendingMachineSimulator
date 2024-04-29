//
// Created by MuFln on 28.04.2024.
//
#include <iostream>
#include "Machine.h"

#ifndef KURSACH_BAR_H
#define KURSACH_BAR_H


class Bar: public IMachine::IBar{
public:
    Bar(std::vector<ISegment*> segments){
        this->segments=segments;
    };

};


#endif //KURSACH_BAR_H
