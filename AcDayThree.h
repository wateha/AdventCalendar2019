#ifndef ACDAYTHREE
#define ACDAYTHREE
    #include "QQDataFileReader.h"
    #include <cmath>
    #include <iostream>
    #include <string>
    #include <vector>

class AcDayThree {
public:
    AcDayThree();
private:
    struct wirePoint {
        int x{};
        int y{};
    };

    QQDataFileReader<std::string> fileReader{};
    std::vector<wirePoint> pointPathA{ {0,0} };
    std::vector<wirePoint> pointPathB{ {0,0} };
    int minCrossingDistance{ INT_MAX };
    int shortestPath{ INT_MAX };
    wirePoint closestCross{};

    void makePointPath(std::vector<std::string>& pathData, std::vector<wirePoint> &outPath);
    void makePointPath(std::vector<std::string>& pathData, std::vector<wirePoint> &crossingPath, std::vector<wirePoint> &outPath);
    wirePoint makePathVector(std::string &codedPath);
    wirePoint addWirePoints(wirePoint pointA, wirePoint pointB);
    wirePoint checkCrossing(wirePoint startA, wirePoint endA, wirePoint startB, wirePoint endB);
    bool isBetween(int i, int a, int b);
    int countSteps(wirePoint A, wirePoint B);
    void findShortestPath(wirePoint crossing, int indexB, int indexA);
};
#endif // !ACDAYTHREE
