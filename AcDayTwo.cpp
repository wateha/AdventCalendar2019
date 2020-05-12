#include "AcDayTwo.h"

AcDayTwo::AcDayTwo()
{
    std::cout << "--- Day 2: 1202 Program Alarm ---" << std::endl;
    
    opCode = &fileReader.getData("data_day_2", ',')[0];
    opCodeCache = *opCode;
    (*opCode)[1] = 12;
    (*opCode)[2] = 2;
    opCodeHandler.executeOC(opCode);

    std::cout << "Solution A: " << (*opCode)[0] << std::endl;

    int a{}, b{};
    
    for (a = 0; a < 100; a++) {
        for (b = 0; b < 100; b++) {
            *opCode = opCodeCache;  // Expensive, but necessary to restore original opcode values
            (*opCode)[1] = a;
            (*opCode)[2] = b;
            opCodeHandler.executeOC(opCode);
            if ((*opCode)[0] == 19690720) {
                break;
            }
        }
        if ((*opCode)[0] == 19690720) {
            break;
        }
    }

    std::cout << "Solution B: " << 100 * a + b << std::endl << std::endl;
}