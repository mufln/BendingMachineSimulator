//
// Created by MuFln on 02.05.2024.
//

#ifndef KURSACH_SEGMENTSTATES_H
#define KURSACH_SEGMENTSTATES_H
#include <iostream>
class SegmentStates{
public:
    static std::string state0 [5];
    static std::string state1 [5];
    static std::string state2 [5];
    static std::string state3 [5];
    static std::string state4 [5];
    static std::string state5 [5];
    static std::string state6 [5];
    static std::string state7 [5];
    static std::string state8 [5];
    static std::string state9 [5];
    static std::string state10[5];
    static std::string state11[5];
    static std::string state12[5];
    static std::string state13[5];
    static std::string state14[5];

};
std::string SegmentStates::state0[5]=
        {"                 ",
         "                 ",
         "                 ",
         "                 ",
         "  #############  "};
std::string SegmentStates::state1[5]=
        {"                 ",
         "                 ",
         "                 ",
         "  ####     ####  ",
         "      #####      "};
std::string SegmentStates::state2[5]=
        {"                 ",
         "                 ",
         "  #            #   ",
         "   ###     ###      ",
         "      #####  "};
std::string SegmentStates::state3[5]=
        {"                 ",
         "                 ",
         "  ##         ##   ",
         "    ##     ##      ",
         "      #####  "};
std::string SegmentStates::state4[5]=
        {"                 ",
         "                 ",
         "  ###       ###   ",
         "     #     #      ",
         "      #####  "};
std::string SegmentStates::state5[5]=
        {"                 ",
         "  #           #   ",
         "   ##       ##   ",
         "     #     #      ",
         "      #####  "};
std::string SegmentStates::state6[5]=
        {"                 ",
         "  ##          ##   ",
         "    #       #   ",
         "     #     #      ",
         "      #####  "};
std::string SegmentStates::state7[5]=
        {" #             #  ",
         "   #          #   ",
         "    #       #   ",
         "     #     #      ",
         "      #####  "};
std::string SegmentStates::state8[5]=
        {"   #         #  ",
         "   #         #   ",
         "    #       #   ",
         "     #     #      ",
         "      #####  "};
std::string SegmentStates::state9[5]=
        {"     #     #  ",
         "     #     #  ",
         "     #     #  ",
         "     #     #  ",
         "     #######  "};
std::string SegmentStates::state10[5]=
        {"      #   #   ",
         "     #     #  ",
         "     #     #  ",
         "     #     #  ",
         "     #######  "};
std::string SegmentStates::state11[5]=
        {"      #   #   ",
         "      #   #   ",
         "     #     #  ",
         "     #     #  ",
         "     #######  "};
std::string SegmentStates::state12[5]=
        {"       # #    ",
         "      #   #   ",
         "     #     #  ",
         "     #     #  ",
         "     #######  "};
std::string SegmentStates::state13[5]=
        {"              ",
         "      ## ##   ",
         "     #     #  ",
         "     #     #  ",
         "     #######  "};
std::string SegmentStates::state14[5]=
        {"              ",
         "              ",
         "     ### ###  ",
         "     #     #  ",
         "     #######  "};


//std::vector<std::string[5]> SegmentStates::States= std::vector<std::string[5]>();
#endif //KURSACH_SEGMENTSTATES_H
