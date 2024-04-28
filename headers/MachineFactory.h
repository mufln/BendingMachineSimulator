//
// Created by MuFln on 28.04.2024.
//

#ifndef KURSACH_MACHINEFACTORY_H
#define KURSACH_MACHINEFACTORY_H
#include "Essential.h"
class IMachineFactory {
protected:
    static Machine* machine;
    static std::vector<Machine::IPiston*> generatePistons(){
        std::vector<Machine::IPiston*> Pistons = std::vector<Machine::IPiston*>();
        for(int i=0;i<3;i++){
            Pistons.push_back(new Piston());
        }
        return Pistons;
    }


    static std::vector<Machine::IShaft*> generateShaftC(){
        std::vector<Machine::IShaft*> ShaftC = std::vector<Machine::IShaft*>();
        for(int i=0;i<5;i++){
            ShaftC.push_back(new Shaft(180-90*(float(i+1)/10)));
        }
        for(int i=0;i<5;i++){
            ShaftC.push_back(new Shaft(180-90*(float(i+1)/10)));
        }
        return ShaftC;
    }


    static std::vector<IMachine::IShaft*> generateShaftP(){
        std::vector<IMachine:: IShaft*> ShaftP = std::vector<IMachine:: IShaft*>();
        for(int i=0;i<10;i++){
            ShaftP.push_back(new Shaft(180-90*(float(i)/10)));
        }
        return ShaftP;
    }


    static std::vector<Machine:: ISensor*> generateSensors(){
        std::vector<Machine:: ISensor*> Sensors = std::vector<Machine:: ISensor*>();
        for(int i = 0;i<3;i++){
            Sensors.push_back(new Sensor());
        }
        return Sensors;
    }

public:
    static void prepareMachine(bool mode, int speed, int accuracy){
        Machine::regenerateMachine(mode,speed,accuracy);
        cout<<"Инициализировано тело машины"<<endl;
        machine = Machine::getInstance();
        cout<<"Получена сущность машины"<<endl;
        machine->prepareShafts(IMachineFactory::generateShaftP(),IMachineFactory::generateShaftC());
        cout<<"Установлены валы проката С- и П- образного профиля"<<endl;
        machine->preparePistons(IMachineFactory::generatePistons());
        cout<<"Установлены поршни"<<endl;
        machine->prepareSensors(IMachineFactory::generateSensors());
        cout<<"Установлены фотодатчики"<<endl;
        cout<<"Генерация станка завершена"<<endl;
    }
};
Machine* IMachineFactory::machine = nullptr;

#endif //KURSACH_MACHINEFACTORY_H
