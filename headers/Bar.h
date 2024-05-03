//
// Created by MuFln on 28.04.2024.
//

#ifndef KURSACH_BAR_H
#define KURSACH_BAR_H
#include <iostream>
#include "Machine.h"


class Bar: public IMachine::IBar{
public:
    Bar(std::vector<ISegment*> segments){
        this->segments=segments;
    };

};


#endif //KURSACH_BAR_H
