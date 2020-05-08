#include "AcOpCode.h"

int AcOpCode::executeOC(std::vector<int> *opCode)
{
    ocData = opCode;
    int pos{0};
    do {
        pos = getInstruction((*ocData)[pos], pos);
        //  Stop execution in case of unexpected behaviour
        if (pos < 0) {
            break;
        }
    } while ((*ocData)[getAddress(pos, true)] != 99);
    return  0;
}

int AcOpCode::getInstruction(int instruction, int index)
{
    switch ((Instruction)instruction) {
    case Add:
        if (!checkAddressValidity(index + 3)) {
            return -1;
        }
        add(index);
        return index + 4;
    case Multiply:
        if (!checkAddressValidity(index + 3)) {
            return -1;
        }
        multiply(index);
        return index + 4;
    default:
        return -1;
    }
}

int AcOpCode::getAddress(int index, bool immediate)
{
    return (immediate) ? index : (*ocData)[index];
}

bool AcOpCode::checkAddressValidity(int newIndex)
{
    return (newIndex < (*ocData).size());
}

void AcOpCode::add(int index)
{
    (*ocData)[getAddress(index + 3)] = (*ocData)[getAddress(index + 1)] + (*ocData)[getAddress(index + 2)];
}

void AcOpCode::multiply(int index)
{
    (*ocData)[getAddress(index + 3)] = (*ocData)[getAddress(index + 1)] * (*ocData)[getAddress(index + 2)];
}