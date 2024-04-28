//
// Created by MuFln on 28.04.2024.
//

#ifndef KURSACH_MACHINE_H
#define KURSACH_MACHINE_H

#include <iostream>
using namespace std;
class IMachine {
public:
    class IBar {
        class ISegment {
            class IPoint {

            };
        };
    };

    class IShaft {
    protected:
        float POSTANGLE;
    public:
        virtual void Bend(IMachine::IBar bar) = 0;
    };

    class ISensor {
    private:
        const float ACCURACY = 1.5;
    public:
        virtual bool Check(IBar bar) = 0;
    };

    class IPiston {
    public:
        virtual void PullOut(IBar bar, std::vector<IBar> a) = 0;
    };
};

class IMachineVariables:public IMachine {
protected:
    bool MODE;
    int SPEED;
    int ACCURACY;
    std::vector<IBar*> A = std::vector<IBar*>();
    std::vector<IBar*> B = std::vector<IBar*>();
    std::vector<IBar*> C = std::vector<IBar*>();
    std::vector<IBar*> D = std::vector<IBar*>();
    std::vector<IShaft*> ShaftsP;
    std::vector<IShaft*> ShaftsC;
    IPiston* P0;
    IPiston* P1;
    IPiston* P2;
    ISensor* F0;
    ISensor* F1;
    ISensor* F2;
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
private:
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

