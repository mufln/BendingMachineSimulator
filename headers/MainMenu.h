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
    std::string startupLines[5] = {"Осмотреть станину на наличие трещин и деформаций",
                                   "Проверить люфт валов",
                                   "Откалибровать фотодатчики" ,
                                   "Запустить станок на холостом ходу на время не менее 5 минут",
                                   "Приступить к работе"
                                   };
    virtual void listHelp() = 0;
    virtual int setAccuracy(int) = 0;
    virtual bool changeMode() = 0;
    virtual void startup() = 0;
};


class MenuSettings : public IMenu {
protected:
    void listGuide(){
        cout << "Перед началом работы необходимо:" << endl;
        for(int i=0;i<5;i++){
            cout<<startupLines[i]<<endl;
        }
    }

    void listInfo(){
        cout << "Перед запуском симуляции вы можете назначить такие переменные, как:" << endl;
        cout << "количество симулируемых сегментов (по умолчанию 2)" << endl;
        cout << "скорость симуляции (по умолчанию 1x)" << endl;
        cout << "режим работы (по умолчанию автоматический)" << endl;
        cout << "В ручном режиме работы вам будет необходимо нажимать на любую клавишу(кроме функциональных) ";
        cout << "для разрешения следующей операции" << endl;
        cout << "\nВо время работы программы вы увидите" << endl;
        cout << "операцию, которая производится над заготовкой в данный момент на первой строке" << endl;
        cout << "Блок статистики, начинающийся со второй строки, "<<endl;
        cout << "включающий в себя информацию о произведенных профилях " << endl;
        cout << "Remaining (D container) - кол-во заготовок, находящихся в контейнере D" << endl;
        cout << "P-bars (A container) - кол-во произведенных П-профилей в контейнере А" << endl;
        cout << "C-bars (B container) - кол-во произведенных С-профилей в контейнере B" << endl;
        cout << "Waste (C container) - кол-во отбракованных профилей" << endl;

    }
    void listHelp() override {
        cout << "Список команд" << endl;
        cout << "setaccuracy VALUE[2-256] - устанавливает количество симулируемых программой сегментов" << endl;
        cout << "setspeed VALUE[1-8] - устанаваливает множитель скорости симуляции" << endl;
        cout << "chmod - меняет режим  с ручного на автоматический и обратно" << endl;
        cout << "start - начинает процедуру запуска машины" << endl;
        cout << "guide - техника безопасности" << endl;
        cout << "info - пояснения к работе программы" << endl;
    };


    void startup() override{
        string ans;
        int i = 0;
        while(i<4){
            cout <<startupLines[i] + "? (Y/N)? " << endl;
            cin>>ans;
            if(ans=="N" || ans == "n"){
                cout<<"Без прохождения ТБ нельзя начать работу";
                exit(0);
            } else if(ans == "Y" || ans == "y") {
                i+=1;
            }
        }
    }


    int setAccuracy(int a) override {
        _accuracy = a;
        return _accuracy;
    };

    bool changeMode() override{
        _mode = !_mode;
        return _mode;
    };
};


class MenuHandle : public MenuSettings {
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
                if(value<2 || value>256){
                    cout<<"Неверное значение"<<endl;
                    continue;
                }
                _accuracy = value;
                cout<<"Установлено количество сегментов профиля - " << value<<endl;
                //дописать присвоение в объект mainmenu
            } else if (action == "setspeed") {
                cout << "Введите целое значение множителя скорости от 1 до 100 "<<endl;
                cin >> value;
                if(value<1 || value>100){
                    cout<<"Неверное значение"<<endl;
                    continue;
                }
                _simulationSpeed = value;
                cout << "Установлен множитель скорости " << _simulationSpeed<<endl;
                //дописать присвоение в объект mainmenu
            } else if (action == "chmod") {
                this->changeMode();
                cout << "Режим изменен на " << (_mode?"автоматический":"ручной")<<endl;//дописать терарный оператор
            } else if (action == "start") {
                startup();
                break;
                //напистаь процедуру запуска
            } else if (action == "help") {
                this->listHelp();
            } else if (action == "guide") {
                this->listGuide();
            } else if (action == "info") {
                this->listInfo();
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
