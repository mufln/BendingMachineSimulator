#include "headers/MainMenu.h"
#include "MachineFactory.h"
int main() {
    Menu *menu = Menu::getInstance(); // Поулчаем объект главного мен
    menu->handleActions();
    IMachineFactory::prepareMachine(menu->getMode(),menu->getSpeed(),menu->getAccuracy());
//    menu.handleActions();//переходим в цепочку главного меню
    return 0;
}
