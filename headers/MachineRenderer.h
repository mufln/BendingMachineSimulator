//
// Created by MuFln on 30.04.2024.
//

#ifndef KURSACH_MACHINERENDERER_H
#define KURSACH_MACHINERENDERER_H
#include "Machine.h"
#include <ncurses.h>
#include "SegmentStates.h"
class MahineRenderer: public IMachine::IMachineRenderer{
protected:
    static MahineRenderer* renderer;
    MahineRenderer(){

    }
    void renderSegment(std::string state []){
        for(int i = 0;i<5;i++){
            move(i+1,40);
            clrtoeol();
            mvprintw(i+1,40,state[i].c_str());
        }
        refresh();
    }
    
    
public:
    static MahineRenderer* getInstance(){
        if(renderer == nullptr){
            renderer = new MahineRenderer();
        };
        return renderer;
    }
    void drawAnalytics(int brokenBars, int remainingBars, int Pbars, int Cbars) override{
        move(1,0);
        clrtoeol();
        mvprintw(1,0,("Statistics"));
        move(2,0);
        clrtoeol();
        mvprintw(2,0,("Remaining    (D container): "+to_string(remainingBars)).c_str());
        move(3,0);
        clrtoeol();
        mvprintw(3,0,("P-bars       (A container): "+to_string(Pbars)).c_str());
        move(4,0);
        clrtoeol();
        mvprintw(4,0,("C-bars       (B container): "+to_string(Cbars)).c_str());
        move(5,0);
        clrtoeol();
        mvprintw(5,0,("Waste        (C container): "+to_string(brokenBars)).c_str());
        refresh();
    }
    void drawSegment(int state) override{
        switch (state) {
            case 0:
                renderSegment(SegmentStates::state0);
                break;
            case 1:
                renderSegment(SegmentStates::state1);
                break;
            case 2:
                renderSegment(SegmentStates::state2);
                break;
            case 3:
                renderSegment(SegmentStates::state3);
                break;
            case 4:
                renderSegment(SegmentStates::state4);
                break;
            case 5:
                renderSegment(SegmentStates::state5);
                break;
            case 6:
                renderSegment(SegmentStates::state6);
                break;
            case 7:
                renderSegment(SegmentStates::state7);
                break;
            case 8:
                renderSegment(SegmentStates::state8);
                break;
            case 9:
                renderSegment(SegmentStates::state9);
                break;
            case 10:
                renderSegment(SegmentStates::state10);
                break;
            case 11:
                renderSegment(SegmentStates::state11);
                break;
            case 12:
                renderSegment(SegmentStates::state12);
                break;
            case 13:
                renderSegment(SegmentStates::state13);
                break;
            case 14:
                renderSegment(SegmentStates::state14);
                break;
            
        }

    };
    void drawText(string text) override{
        move(0,0);
        clrtoeol();
        mvprintw(0,0,text.c_str());
        refresh();
    }
    void Start() override{
        initscr();
        curs_set(0);
        drawAnalytics(0,1000,0,0);
    }
    void Stop() override{
        endwin();
    }

};
MahineRenderer* MahineRenderer::renderer = nullptr;
#endif //KURSACH_MACHINERENDERER_H
