#include "AcIntCodeD5.h"
#include <iostream>

int AcIntCodeD5::executeOC(std::vector<int>* opCode, int inputValue)
{
    ocData = opCode;
    int pos{ 0 };
    int addr{ 0 };
    inputData = inputValue;
    outputData = 0;
    do {
        addr = pos;
        pos = getInstruction((*ocData)[pos], pos);
        ocInstructionValues.clear();
        //  Stop execution in case of unexpected behaviour
        if (pos < 0) {
            std::cout << "Something went wrong at index " << addr << std::endl;
            break;
        }
    } while ((*ocData)[getAddress(pos)] != 99);
    return  outputData;
}

int AcIntCodeD5::getInstruction(int instruction, int index)
{
    splitInstruction(instruction);

    switch ((Instruction)ocInstructionValues[0]) {
    case Add:
        if (!checkAddressValidity(index + 4)) {
            return -1;
        }
        add(index);
        return index + 4;
    case Multiply:
        if (!checkAddressValidity(index + 4)) {
            return -1;
        }
        multiply(index);
        return index + 4;
    case Write:
        if (!checkAddressValidity(index + 1)) {
            return -1;
        }
        write(index);
        return index + 2;
    case Read:
        if (!checkAddressValidity(index)) {
            return -1;
        }
        outputData = read(index);
        return index + 2;
    case JumpIfTrue:
        //if (!checkAddressValidity(index + 2)) {
        //    return -1;
        //}
        return jumpIfTrue(index);
    case JumpIfFalse:
        //if (!checkAddressValidity(index + 2)) {
        //    return -1;
        //}
        return jumpIfFalse(index);
    case LessThan:
        if (!checkAddressValidity(index + 4)) {
            return -1;
        }
        lessThan(index);
        return index + 4;
    case Equals:
        if (!checkAddressValidity(index + 4)) {
            return -1;
        }
        equals(index);
        return index + 4;
    default:
        return -1;
    }
}

int AcIntCodeD5::getAddress(int index, int mode)
{
    bool immediate{ (mode < ocInstructionValues.size()) ? (bool)ocInstructionValues[mode] : false };
    return (immediate) ? index : (*ocData)[index];
}

int AcIntCodeD5::getAddress(int index, bool immediate)
{
    return (immediate) ? index : (*ocData)[index];
}

bool AcIntCodeD5::checkAddressValidity(int newIndex)
{
    return (newIndex < (*ocData).size());
}

void AcIntCodeD5::add(int index)
{
    (*ocData)[getAddress(index + 3, 3)] = (*ocData)[getAddress(index + 1, 1)] + (*ocData)[getAddress(index + 2, 2)];
}

void AcIntCodeD5::multiply(int index)
{
    (*ocData)[getAddress(index + 3, 3)] = (*ocData)[getAddress(index + 1, 1)] * (*ocData)[getAddress(index + 2, 2)];
}

void AcIntCodeD5::write(int index)
{
    (*ocData)[getAddress(index + 1, false)] = inputData;
}

int AcIntCodeD5::read(int index)
{
    return (*ocData)[getAddress(index + 1, 1)];
}

int AcIntCodeD5::jumpIfTrue(int index)
{
    return ((*ocData)[getAddress(index + 1, 1)] != 0) ? (*ocData)[getAddress(index + 2, 2)] : (index + instructionLength);
}

int AcIntCodeD5::jumpIfFalse(int index)
{
    return ((*ocData)[getAddress(index + 1, 1)] != 0) ? (index + instructionLength) : (*ocData)[getAddress(index + 2, 2)];
}

void AcIntCodeD5::lessThan(int index)
{
    (*ocData)[getAddress(index + 3, 3)] = ((*ocData)[getAddress(index + 1, 1)] < (*ocData)[getAddress(index + 2, 2)]) ? 1 : 0;
}

void AcIntCodeD5::equals(int index)
{
    (*ocData)[getAddress(index + 3, 3)] = ((*ocData)[getAddress(index + 1, 1)] == (*ocData)[getAddress(index + 2, 2)]) ? 1 : 0;
}

void AcIntCodeD5::splitInstruction(int instruction)
{
    instructionLength = 1;
    ocInstructionValues.push_back(instruction % 100);
    instruction = (instruction - instruction % 100) / 100;
    while (instruction > 0) {
        ocInstructionValues.push_back(instruction % 10);
        instruction = (instruction - instruction % 10) / 10;
        instructionLength++;
    }
}