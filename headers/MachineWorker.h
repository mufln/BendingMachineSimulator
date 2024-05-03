//
// Created by MuFln on 28.04.2024.
//

#ifndef KURSACH_MACHINEWORKER_H
#define KURSACH_MACHINEWORKER_H
#include "MachineFactory.h"
#include "BarFactory.h"
#include "MainMenu.h"
#include <unistd.h>
class MachineWorker{
protected:
    static int accuracy;
    static Machine* machine;
    static void loop(){
        std::vector<Machine::IBar*> bars = std::vector<Machine::IBar*>();
        for(int i=0;i<1000;i++){
            bars.push_back(IBarFactory::generateBar(accuracy));
        }
        machine->fillContainer(bars);
        machine->render->Start();
        for(int i = 0; i<500;i++){
            machine->processP();
            machine->processC();
        }
        machine->render->Stop();
        cout<<"Смена закончена, непрокатанных листов больше нет"<<endl;
    }
public:
    static void prepare(){
        Menu *menu = Menu::getInstance(); // Поулчаем объект главного мен
        menu->handleActions();
        IMachineFactory::prepareMachine(menu->getMode(),menu->getSpeed(),menu->getAccuracy());
        machine = Machine::getInstance();
        loop();
    }
};
Machine* MachineWorker::machine = nullptr;
int MachineWorker:: accuracy = 2;
#endif //KURSACH_MACHINEWORKER_H
