//
// Created by MuFln on 28.04.2024.
//

#ifndef KURSACH_MACHINE_H
#define KURSACH_MACHINE_H

#include <iostream>
#include "unistd.h"
using namespace std;
class IMachine {
public:
    class IBar {
    public:
        class ISegment {
        protected:
            float nextPointAngle = 180 ;
        public:
            class IPoint {
            public:
                virtual void setAngle(float angle) = 0;
                virtual float getAngle() = 0;
            };
            std::vector<IPoint*> points = std::vector<IPoint*>();
        };
        std::vector<ISegment*> segments = std::vector<ISegment*>();
    };


    class IShaft {
    protected:
        int AFFECTEDPOINT1;
        int AFFECTEDPOINT2;
        float POSTANGLE;
    public:
        virtual void Bend(IBar::ISegment* segment) = 0;
    };


    class ISensor {
    protected:
        int CHECKINGPOINT1;
        int CHECKINGPOINT2;
        const float ACCURACY = 90*0.02;
    public:
        virtual bool check(IBar::ISegment* segment) = 0;
    };


    class IPiston {
    public:
        virtual std::vector<IBar*> pullOut(IBar* bar, std::vector<IBar*> container) = 0;
    };


    class IMachineRenderer{
    public:
        virtual void drawAnalytics(int brokenBars, int remainingBars, int Pbars, int Cbars) = 0;
        virtual void drawSegment(int state) = 0;
        virtual void drawText(string text)= 0;
        virtual void Start() = 0;
        virtual void Stop() = 0;
    };
};

class IMachineVariables:public IMachine {
protected:
    bool MODE;
    int SPEED;
    int ACCURACY;
    int absoluteDelay = 100000;
    std::vector<IBar*> A = std::vector<IBar*>();
    std::vector<IBar*> B = std::vector<IBar*>();
    std::vector<IBar*> C = std::vector<IBar*>();
    std::vector<IBar*> D = std::vector<IBar*>();
//    std::vector<IBar*> D = std::vector<IBar*>();
    std::vector<IShaft*> ShaftsP;
    std::vector<IShaft*> ShaftsC;
    IPiston* P0;
    IPiston* P1;
    IPiston* P2;
    ISensor* F0;
    ISensor* F1;
    ISensor* F2;
public:
    IMachineRenderer* render;
};
class IMachineAssignments: public IMachineVariables{
public:
    void prepareShafts(std::vector<IShaft*> shaftsP, std::vector<IShaft*> shaftsC){
        ShaftsP = shaftsP;
        ShaftsC = shaftsC;
    }


    void prepareSensors(std::vector<ISensor*> sensors){
        this->F2 = sensors.back();
        sensors.pop_back();
        this->F1 = sensors.back();
        sensors.pop_back();
        this->F0 = sensors.back();
        sensors.pop_back();
    }


    void preparePistons(std::vector<IPiston*> pistons){
        this->P2 = pistons.back();
        pistons.pop_back();
        this->P1 = pistons.back();
        pistons.pop_back();
        this->P0 = pistons.back();
        pistons.pop_back();
    }


    void prepareRenderer(IMachineRenderer* renderer){
        this->render = renderer;
    }
};


class MachineProcessing:public IMachineAssignments{
protected:
    void bendSide(std::vector<IShaft*> shafts, IBar* bar, bool isP){
        string out = isP?"Bending sides... ":"Bending sides and shelves... ";
        char a;
        if(!MODE){out+="operation access required";}
        render->drawText(out);
        if(!MODE){cin>>a;}
        int state = 0;

        for(IShaft* shaft: shafts){
            for(IBar::ISegment* segment: bar->segments){
                usleep(absoluteDelay/SPEED);
                shaft->Bend(segment);
            }
//            render->drawText(out + "state:" + to_string(state));
            render->drawSegment(state);
            state+=isP?1:state>=10?1:2;

        }
    }


    bool checkQuality(IBar* bar,ISensor* F){
        bool res;
        char a;
        string out = "Checking quality...";
        if(!MODE){out+="operation access required";}
        render->drawText(out);
        if(!MODE){cin>>a;}
        for(IBar::ISegment* segment: bar->segments){
            usleep(absoluteDelay/SPEED);
            res = F->check(segment);
            if(!res){
                break;
            }
        }
        return res;
    }


    std::vector<IBar*> throwAway(IBar* bar, IPiston* piston, std::vector<IBar*> container){
        string out = "Throwing away waste...";
        if(!MODE){out+="operation access required";}
        char a;
        render->drawText(out);
        if(!MODE){cin>>a;}
        usleep(absoluteDelay/SPEED);
        return piston->pullOut(bar, container);
    }


    std::vector<IBar*> putIn(IBar* bar, std::vector<IBar*> container){
        string out = "Sending to container...";
        if(!MODE){out+="operation access required";}
        char a;
        render->drawText(out);
        if(!MODE){cin>>a;}
        usleep(absoluteDelay/SPEED);
        container.push_back(bar);
        return container;
    }

public:
    void fillContainer(std::vector<IBar*> bars){
        D = bars;
    }
    void processP(){
        IBar* bar = D.back(); D.pop_back();
        render->drawText("Producing P- profile...");
        bendSide(ShaftsP, bar, true);
        bool res = checkQuality(bar, F0);
        if(!res){
            C = throwAway(bar,P0,C);
        } else{
            A = putIn(bar, A);
        }
        render->drawAnalytics(C.size(),D.size(),A.size(),B.size());
    }


    void processC(){
        IBar* bar = D.back(); D.pop_back();
        render->drawText("Producing C- profile...");
        bendSide(ShaftsC,bar,false);
        bool res = checkQuality(bar, F1);
        if(!res){
            C = throwAway(bar,P1,C);
        } else{
            res = checkQuality(bar,F2);
            if(!res){
                throwAway(bar,P2, C);
            } else{
                B = putIn(bar,B);
            }
        }
        render->drawAnalytics(C.size(),D.size(),A.size(),B.size());
    }
};


class Machine: public MachineProcessing{
protected:
    Machine(bool MODE, int SPEED, int ACCURACY){
        this->MODE = MODE;
        this->SPEED = SPEED;
        this->ACCURACY = ACCURACY;
    };
    static Machine* instance;
public:
    static void regenerateMachine(bool MODE, int SPEED, int ACCURACY){
        instance = new Machine(MODE, SPEED, ACCURACY);
    };
    static Machine* getInstance(){
        return instance;
    };
};
Machine* Machine::instance = nullptr;


#endif //KURSACH_MACHINE_H

