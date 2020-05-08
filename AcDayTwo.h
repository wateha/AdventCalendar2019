#ifndef ACDAYTWO
#define ACDAYTWO

#include "AcOpCode.h"
#include "QQDataFileReader.h"
#include <iostream>
#include <vector>

class AcDayTwo {
public:
    AcDayTwo();
private:
    AcOpCode opCodeHandler{};
    QQDataFileReader<int> fileReader{};
    std::vector<int>* opCode{};
    std::vector<int> opCodeCache{}; // Cache is needed, as the original vector will be overwritten
};
#endif //!ACDAYTWO