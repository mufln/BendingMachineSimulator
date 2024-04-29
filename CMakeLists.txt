cmake_minimum_required(VERSION 3.26)
project(Kursach)

set(CMAKE_CXX_STANDARD 23)

add_executable(Kursach
        main.cpp
#        headers/Sensor.h
#        headers/Analyzer.h
#        headers/Bar.h
#        headers/Machine.h
#        headers/Piston.h
#        headers/Point.h
#        headers/Segment.h
#        headers/Shaft.h
#        headers/MainMenu.h
)
target_include_directories(Kursach PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/headers")
