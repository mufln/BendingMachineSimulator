//
// Created by MuFln on 27.04.2024.
//

#ifndef KURSACH_MAINMENU_H
#define KURSACH_MAINMENU_H
//
// Created by MuFln on 26.04.2024.
//
#include <iostream>
using namespace std;
class IMenu {
protected:
    int _accuracy = 8;
    int _simulationSpeed = 1;
    bool _mode = true;

    virtual void listHelp() = 0;
    virtual int setAccuracy(int) = 0;
    virtual bool changeMode() = 0;
    virtual void startup() = 0;
};


class MenuSettings : public IMenu {
protected:
    void listHelp() override {
        cout << "Список команд" << endl;
        cout << "setaccuracy VALUE[2-256] - устанавливает количество симулируемых программой сегментов" << endl;
        cout << "setspeed VALUE[1-8] - устанаваливает множитель скорости симуляции" << endl;
        cout << "chmod - меняет режим  с ручного на автоматический и обратно" << endl;
        cout << "start - начинает процедуру запуска машины" << endl;
    };

    int setAccuracy(int a) override {
        _accuracy = a;
        return _accuracy;
    };

    bool changeMode() override{
        _mode = !_mode;
        return _mode;
    };
};


class MenuStartup : public MenuSettings {
protected:
    void startup() override{

    };
};


class MenuHandle : public MenuStartup {
public:
    bool getMode(){
        return _mode;
    }
    int getSpeed(){
        return _simulationSpeed;
    }
    int getAccuracy(){
        return _accuracy;
    }
    void handleActions() {
        cout << "Введите действие, помощь - help "<<endl;
        string action;
        int value;
        while (true) {//core-loop программы
            cin >> action;
            if (action == "setaccuracy") {
                cout << "Введите целое значение от 2 до 256 "<<endl;
                cin >> value;
                _accuracy = value;
                cout<<"Установлено количество сегментов профиля - " << value<<endl;
                //дописать присвоение в объект mainmenu
            } else if (action == "setspeed") {
                cout << "Введите целое значение множителя скорости от 1 до 8 "<<endl;
                cin >> value;
                _simulationSpeed = value;
                cout << "Установлен множитель сокрости " << _simulationSpeed<<endl;
                //дописать присвоение в объект mainmenu
            } else if (action == "chmod") {
                this->changeMode();
                cout << "Режим изменен на " << (_mode?"автоматический":"ручной")<<endl;//дописать терарный оператор
            } else if (action == "start") {
                break;
                //напистаь процедуру запуска
            } else if (action == "help") {
                this->listHelp();
            }
        }
    }
};


class Menu : public MenuHandle {
private:
    static Menu *menu;
    Menu(){};
//    Menu(const Menu&);
//    Menu& operator=(Menu&);
public:
    static Menu * getInstance()
    {
        if (menu == nullptr) {
            menu = new Menu();
        }
        return menu;
    };
};
Menu* Menu::menu = nullptr;
#endif //KURSACH_MAINMENU_H
