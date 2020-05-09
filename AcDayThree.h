#ifndef ACDAYTHREE
#define ACDAYTHREE
    #include "QQDataFileReader.h"
    #include <iostream>
    #include <vector>

class AcDayThree {
public:
    AcDayThree();
private:
    QQDataFileReader<int> fileReader{};
    
};
#endif // !ACDAYTHREE
