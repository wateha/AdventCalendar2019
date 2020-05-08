#include "AcDayOne.h"

AcDayOne::AcDayOne()
{
    std::cout << "--- Day 1: The Tyranny of the Rocket Equation ---" << std::endl;
    std::cout << "Solution A: " << computeBasicFuel(fileReader.getData("data_day_1", '\n')) << std::endl;
    std::cout << "Solution B: " << computeAdvancedFuel(fileReader.getData("data_day_1", '\n')) << std::endl << std::endl;
}

int AcDayOne::getTotalFuel()
{
    return totalFuel;
}

int AcDayOne::computeFuelForModule(int mass)
{
    return (mass / 3) - 2;
}

int AcDayOne::computeBasicFuel(const std::vector<std::vector<int>> &modules)
{
    int totalMass{};
    for (int i{}; i < modules.size(); i++) {
        totalMass += computeFuelForModule(modules[i][0]);
    }
    return totalMass;
}

int AcDayOne::computeAdvancedFuel(const std::vector<std::vector<int>> &modules)
{
    int totalMass{};
    for (int i{}; i < modules.size(); i++) {
        int partialFuelMass{ computeFuelForModule(modules[i][0]) };
        while (partialFuelMass >= 0) {
            totalMass += partialFuelMass;
            partialFuelMass = computeFuelForModule(partialFuelMass);
        }
    }
    return totalMass;
}