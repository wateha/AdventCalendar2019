#include "AcDayThree.h"

AcDayThree::AcDayThree()
{
    std::cout << "--- Day 3: Crossed Wires ----" << std::endl;
    makePointPath(fileReader.getData("data_day_3", ',')[0], pointPathA);
    makePointPath(fileReader.getData("data_day_3", ',')[1], pointPathA, pointPathB);
    std::cout << "Solution A: " << minCrossingDistance << std::endl;
    std::cout << "Solution B: " << shortestPath << std::endl << std::endl;
}

void AcDayThree::makePointPath(std::vector<std::string> &pathData, std::vector<AcDayThree::wirePoint> &outPath)
{
    for (int i = 0; i < pathData.size(); i++) {
        outPath.push_back(addWirePoints(outPath[i], makePathVector(pathData[i])));
    }
}

void AcDayThree::makePointPath(std::vector<std::string>& pathData, std::vector<AcDayThree::wirePoint>& crossingPath, std::vector<AcDayThree::wirePoint>& outPath)
{
    for (int i = 0; i < pathData.size(); i++) {
        outPath.push_back(addWirePoints(outPath[i], makePathVector(pathData[i])));
        for (int j = 1; j < crossingPath.size(); j++) {
            wirePoint tmp{ checkCrossing(outPath[i], outPath[i + 1], crossingPath[j - 1], crossingPath[j]) };
            if (tmp.x != 0 || tmp.y != 0) {
                findShortestPath(tmp, i, j-1);
                int tmpClose{ ((tmp.x >= 0) ? tmp.x : -tmp.x) + ((tmp.y >= 0) ? tmp.y : -tmp.y) };
                if (tmpClose < minCrossingDistance) {
                    minCrossingDistance = tmpClose;
                    closestCross = tmp;
                }
            }
        }
    }
}

// The method takes steps encoded in X### format and translates it to two-dimensional, mathematical vector.
AcDayThree::wirePoint AcDayThree::makePathVector(std::string &codedPath)
{
    wirePoint pathPoint{ {},{} };
    switch (codedPath.front()) {
    case 'R':
       pathPoint.x = 1;
        break;
    case 'L':
        pathPoint.x = -1;
        break;
    case 'U':
        pathPoint.y = 1;
        break;
    case 'D':
        pathPoint.y = -1;
        break;    
    default:
        break;
    }
    codedPath.erase(codedPath.begin());
    pathPoint.x *= stoi(codedPath);
    pathPoint.y *= stoi(codedPath);
    return pathPoint;
}

AcDayThree::wirePoint AcDayThree::addWirePoints(wirePoint pointA, wirePoint pointB)
{
    AcDayThree::wirePoint outPoint{};
    outPoint.x = pointA.x + pointB.x;
    outPoint.y = pointA.y + pointB.y;
    return outPoint;
}

AcDayThree::wirePoint AcDayThree::checkCrossing(wirePoint startA, wirePoint endA, wirePoint startB, wirePoint endB)
{
    if ((endA.x - startA.x) == 0 && (endB.y - startB.y) == 0) {
        if (isBetween(startA.x, startB.x, endB.x) && isBetween(startB.y, startA.y, endA.y)) {
            return wirePoint{ startA.x, startB.y };
        }
    }
    if ((endA.y - startA.y) == 0 && (endB.x - startB.x) == 0){
        if (isBetween(startB.x, startA.x, endA.x) && isBetween(startA.y, startB.y, endB.y)) {
            return wirePoint{ startB.x, startA.y };
        }
    }
    return wirePoint{};
}

bool AcDayThree::isBetween(int i, int a, int b)
{
    if ((i >= a) && (i <= b)) {
        return true;
    }
    if ((i >= b) && (i <= a)) {
        return true;
    }
    return false;
}

int AcDayThree::countSteps(wirePoint start, wirePoint end)
{
    int out{ end.x - start.x + end.y - start.y };
    return (out >= 0) ? out : -out;
}

void AcDayThree::findShortestPath(wirePoint crossing, int indexB, int indexA)
{
    int count{};
    count = countSteps(pointPathA[indexA], crossing);
    for (; indexA > 0; indexA--) {
        count += countSteps(pointPathA[indexA - 1], pointPathA[indexA]);
    }
    count += countSteps(pointPathB[indexB], crossing);
    for (; indexB > 0; indexB--) {
        count += countSteps(pointPathB[indexB - 1], pointPathB[indexB]);
    }
    if (shortestPath > count) {
        shortestPath = count;
    }
}