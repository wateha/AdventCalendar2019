#ifndef ACINTCODED5
#define ACINTCODED5
#include <vector>
/*
    Class responsible for interpreting and executing provided opcode.
    Available instructions list will be expanded as development progresses.
*/
class AcIntCodeD5 {
public:
    // Instruction enumeration, for easier reading
    enum Instruction {
        Zero,       // To keep with int representation (Add instruction is defined as 1)
        Add,
        Multiply,
        Write,
        Read,
        JumpIfTrue,
        JumpIfFalse,
        LessThan,
        Equals
    };

    // Get opcode data and process it.
    // *opCode is a pointer instead of const&, because vector data wil be modified
    int executeOC(std::vector<int>* opCode, int inputValue = 0);

private:
    // Opcode data handler
    std::vector<int>* ocData{};

    int inputData{};
    int outputData{};
    int instructionLength{};

    // Container for split opcode instruction
    std::vector<int> ocInstructionValues{};

    // Translate opcode to actual instruction, then return index of the next instruction
    int getInstruction(int instruction, int index);

    void splitInstruction(int instruction);
    
    // Return value under passed index if immediate.
    // Otherwise, treat the value stored under passed index as a new index.
    // Return the value stored under that new index
    int getAddress(int index, int mode);
    int getAddress(int index, bool immediate = true);

    // Check, if trying to access new index will result in index out of bounds exception
    bool checkAddressValidity(int newIndex);

    // Instructions will be performed on a block starting with passed index
    void add(int index);
    void multiply(int index);
    void write(int index);
    int read(int index);
    int jumpIfTrue(int index);
    int jumpIfFalse(int index);
    void lessThan(int index);
    void equals(int index);
};
#endif //!ACINTCODED5