#ifndef ACINTCODED2
#define ACINTCODED2
    #include <vector>
/*
    Class responsible for interpreting and executing provided opcode.
    Available instructions list will be expanded as development progresses.
*/
class AcIntCodeD2 {
public:
    // Instruction enumeration, for easier reading
    enum Instruction {
        Zero,       // To keep with int representation (Add instruction is defined as 1)
        Add,
        Multiply
    };

    // Get opcode data and process it.
    // *opCode is a pointer instead of const&, because vector data wil be modified
    int executeOC(std::vector<int>* opCode);

private:
    // Opcode data handler
    std::vector<int>* ocData{};

    // Translate opcode to actual instruction, then return index of the next instruction
    int getInstruction(int instruction, int index);

    // Return value under passed index if immediate.
    // Otherwise, treat the value stored under passed index as a new index.
    // Return the value stored under that new index
    int getAddress(int index, bool immediate = false);

    // Check, if trying to access new index will result in index out of bounds exception
    bool checkAddressValidity(int newIndex);

    // Instructions will be performed on a block starting with passed index
    void add(int index);
    void multiply(int index);
};
#endif // !ACINTCODED2