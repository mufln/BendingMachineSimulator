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
        public:
            class IPoint {
            };
            std::vector<IPoint*> points = std::vector<IPoint*>();
        };
        std::vector<ISegment*> segments = std::vector<ISegment*>();
    };

    class IShaft {
    protected:
        float POSTANGLE;
    public:
        virtual void Bend(IBar::ISegment* segment) = 0;
    };

    class ISensor {
    protected:
        const float ACCURACY = 1.5;
    public:
        virtual bool check(IBar::ISegment* segment) = 0;
    };

    class IPiston {
    public:
        virtual void pullOut(IBar* bar, std::vector<IBar*> container) = 0;
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
//    std::vector<IBar*> D = std::vector<IBar*>();
    std::vector<IShaft*> ShaftsP;
    std::vector<IShaft*> ShaftsC;
    IPiston* P0;
    IPiston* P1;
    IPiston* P2;
    ISensor* F0;
    ISensor* F1;
    ISensor* F2;
    bool Cready = true;
    bool Pready = true;
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
};


class Machine:public IMachineAssignments{
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


    void processP(IBar* bar){
        cout<<"Гнем стенки..."<<endl;
        for(IShaft* shaft: ShaftsP){
            for(IBar::ISegment* segment: bar->segments){
                usleep(absoluteDelay/SPEED);
                shaft->Bend(segment);
            }
        }
        bool res;
        cout<<"Проверяем качество стенок..."<<endl;
        for(IBar::ISegment* segment: bar->segments){
            usleep(absoluteDelay/SPEED);
            res = F0->check(segment);
            if(!res){
                break;
            }
        }
        if(!res){
            cout<<"Выкидываем брак..."<<endl;
            usleep(absoluteDelay/SPEED);
            P0->pullOut(bar, C);
        } else{
            cout<<"Отправляем профиль в контейнер..."<<endl;
            usleep(absoluteDelay/SPEED);
            A.push_back(bar);
        }
    }


    void processC(IBar* bar){
        cout<<"Производим C- профиль..."<<endl;
        usleep(absoluteDelay/SPEED);
        cout<<"Гнем стенки и полки..."<<endl;
        for(IShaft* shaft: ShaftsC){
            for(IBar::ISegment* segment: bar->segments){
                usleep(absoluteDelay/SPEED);
                shaft->Bend(segment);
            }
        }
        bool res;
        cout<<"Проверяем качество стенок..."<<endl;
        for(IBar::ISegment* segment: bar->segments){
            usleep(absoluteDelay/SPEED);
            res = F1->check(segment);
            if(!res){
                break;
            }
        }
        if(!res){
            cout<<"Выкидываем брак..."<<endl;
            usleep(absoluteDelay/SPEED);
            P1->pullOut(bar, C);
            return;
        }
        cout<<"Проверяем качество полок..."<<endl;
        for(IBar::ISegment* segment: bar->segments){
            usleep(absoluteDelay/SPEED);
            res = F2->check(segment);
            if(!res){
                break;
            }
        }
        if(!res){
            cout<<"Выкидываем брак..."<<endl;
            usleep(absoluteDelay/SPEED);
            P2->pullOut(bar, C);
            return;
        } else{
            cout<<"Отправляем профиль в контейнер..."<<endl;
            usleep(absoluteDelay/SPEED);
            B.push_back(bar);
        }
    }
};
Machine* Machine::instance = nullptr;


#endif //KURSACH_MACHINE_H

