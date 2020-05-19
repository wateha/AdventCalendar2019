#ifndef ACDAYFIVE
#define ACDAYFIVE

    #include "AcIntCodeD5.h"
    #include "QQDataFileReader.h"   
    #include <iostream>


class AcDayFive {
public:
    AcDayFive();

private:
    std::vector<int>* intCode{};
    AcIntCodeD5 intCodeHandler{};
    QQDataFileReader<int> fileReader{};
};
#endif // !ACDAYFIVE