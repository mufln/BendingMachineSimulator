//
// Created by MuFln on 30.04.2024.
//

#ifndef KURSACH_RENDERER_H
#define KURSACH_RENDERER_H
#include "Machine.h"

class MahineRenderer: public IMachine::IMachineRenderer{
protected:
    static MahineRenderer* renderer;
    MahineRenderer(){

    }
public:
    static MahineRenderer* getInstance(){
        if(!renderer){
            renderer = new MahineRenderer();
        };
        return renderer;
    }
    static void drawAnalytics(int brokenBars, int remainingBars, int Pbars, int Cbars){

    }
    static void drawSegment(IMachine::IBar::ISegment* segment){

    };
};
MahineRenderer* MahineRenderer::renderer = nullptr;
#endif //KURSACH_RENDERER_H
