#ifndef ACDAYONE
#define ACDAYONE

#include "QQDataFileReader.h"
#include <iostream>
#include <string>
#include <vector>

class AcDayOne {
public:
    AcDayOne();
    int getTotalFuel();

private:
    int totalFuel{};
    QQDataFileReader<int> fileReader{};
    int computeBasicFuel(const std::vector<std::vector<int>>& modules);
    int computeAdvancedFuel(const std::vector<std::vector<int>>& modules);
    int computeFuelForModule(int mass);
};

#endif // !ACDAYONE


