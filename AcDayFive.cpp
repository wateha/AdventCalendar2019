#include "AcDayFive.h"

AcDayFive::AcDayFive()
{
    std::cout << "--- Day 5: Sunny with a Chance of Asteroids ---" << std::endl;

    intCode = &fileReader.getData("data_day_5", ',')[0];
    std::cout << "Solution A: " << intCodeHandler.executeOC(intCode, 1) << std::endl;
    intCode = &fileReader.getData("data_day_5", ',', true)[0];
    std::cout << "Solution B: " << intCodeHandler.executeOC(intCode, 5) << std::endl;

}