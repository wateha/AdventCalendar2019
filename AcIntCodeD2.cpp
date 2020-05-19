 #include "AcIntCodeD2.h"

int AcIntCodeD2::executeOC(std::vector<int> *opCode)
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

int AcIntCodeD2::getInstruction(int instruction, int index)
{
    switch (instruction) {
    case Add:
        if (!checkAddressValidity(index)) {
            return -1;
        }
        add(index);
        return index;
    case Multiply:
        if (!checkAddressValidity(index)) {
            return -1;
        }
        multiply(index);
        return index;
    default:
        return -1;
    }
}

int AcIntCodeD2::getAddress(int index, bool immediate)
{
    return (immediate) ? index : (*ocData)[index];
}

bool AcIntCodeD2::checkAddressValidity(int newIndex)
{
    return (newIndex < (*ocData).size());
}

void AcIntCodeD2::add(int index)
{
    (*ocData)[getAddress(index + 3)] = (*ocData)[getAddress(index + 1)] + (*ocData)[getAddress(index + 2)];
}

void AcIntCodeD2::multiply(int index)
{
    (*ocData)[getAddress(index + 3)] = (*ocData)[getAddress(index + 1)] * (*ocData)[getAddress(index + 2)];
}