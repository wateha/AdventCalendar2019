#ifndef ACDAYTWO
#define ACDAYTWO
    #include "AcIntCodeD2.h"
    #include "QQDataFileReader.h"  
    #include <iostream>
    #include <vector>

class AcDayTwo {
public:
    AcDayTwo();
private:
    AcIntCodeD2 opCodeHandler{};
    QQDataFileReader<int> fileReader{};
    std::vector<int>* opCode{};
    std::vector<int> opCodeCache{}; // Cache is needed, as the original vector will be overwritten
};
#endif //!ACDAYTWO