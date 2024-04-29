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
//реализовать метод который принимает bar и полную цепочку машины, сделать цикл while с счетчиком i
//счетчик указывает на сколько шагов продивнулся bar -> при i=0 первый сегмент находится в первом вале
//при i=n первый сегмент находится в n вале(датчике/поршне и так далее, если выходит за индекс - переходит в следущий тип)
//
protected:
    static int accuracy;
    static Machine* machine;
    static void loop(){
        Bar* bar = IBarFactory::generateBar(accuracy);
        machine->processP(bar);
        bar = IBarFactory::generateBar(accuracy);
        machine->processC(bar);
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
