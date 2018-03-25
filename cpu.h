//
// Created by: 
// colton teefy, noah holcombe, zeke lawal, chidi azuh, andrew sweitzer
//
#ifndef cpu_HEADER
#define cpu_HEADER

#include <iostream>
#include <vector>
#include <string>


namespace Simulation {
    using namespace std;

    typedef unsigned char byte;

    class cpu {
    public:

        static const byte MAX = 255;

        enum InstructionSet {
            LOAD0 = 0,
            LOAD1,
            ADD,
            SUBTRACT,
            STORE0,
            STORE1
        };

        byte reg0{};
        byte reg1{};
        byte counter{};
        byte regInstruction{};

        bool currentStatus{};
        bool isOverflow{};
        bool isUnderflow{};

        int currentTmpValue{};

        cpu(const cpu &) {}

        void cpuReset() {
            currentTmpValue = 0;
            reg0 = 0;
            reg1 = 0;
            currentStatus = true;
            isOverflow = false;
            isUnderflow = false;
            counter = 0;
        }

        void Fault() {
            currentStatus = false;
            cout << "Instruction Fault at: " << counter << endl;
            registerRelease();
        }

        void registerRelease() {
            cout << "cpu Registers:" << endl
                 << "reg0 [" << reg0 << "]" << endl
                 << "reg1 [" << reg1 << "]" << endl
                 << "Status [" << currentStatus << "]" << endl
                 << "isOverflow [" << isOverflow << "]" << endl
                 << "isUnderflow [" << isUnderflow << "]" << endl
                 << "Program Counter [" << counter << "]" << endl
                 << "Instruction Register [" << regInstruction << "]" << endl
                 << "Temp Value [" << currentTmpValue << "]" << endl;
        }

        void load0(const vector<byte> &p_Program) {
            reg0 = p_Program[counter];
            counter++;
        }

        void load1(const vector<byte> &p_Program) {
            reg1 = p_Program[counter];
            counter++;
        }

        void add() {
            currentTmpValue = reg0 + reg1;
            if (currentTmpValue > MAX) {
                isOverflow = true;
                currentTmpValue = MAX;
            }
            reg0 = static_cast<byte>(currentTmpValue);
        }

        void subtract() {
            currentTmpValue = reg0 - reg1;
            if (currentTmpValue < 0) {
                isUnderflow = true;
                currentTmpValue = 0;
            }
            reg0 = static_cast<byte>(currentTmpValue);
        }

        void store0(vector<byte> &p_Program) {
            p_Program[counter] = reg0;
            counter++;
        }

        void store1(vector<byte> &p_Program) {
            p_Program[counter] = reg1;
            counter++;
        }

        cpu() {
            cpuReset();
        }

        ~cpu() = default;

        void Execute(vector<byte> &p_Program, const bool &p_HaltOnIsOverflow = true,
                     const bool &p_HaltOnIsUnderflow = true) {
            cpuReset();

            if (p_Program.size() > MAX) {
                cout << "Error! Program Counter overload. Max instruction: 255" << endl;
            } else {
                while (counter < p_Program.size()) {
                    regInstruction = p_Program[counter];
                    counter++;

                    switch (regInstruction) {
                        case LOAD0:
                            load0(p_Program);
                            break;
                        case LOAD1:
                            load1(p_Program);
                            break;
                        case ADD:
                            add();
                            break;
                        case SUBTRACT:
                            subtract();
                            break;
                        case STORE0:
                            store0(p_Program);
                            break;
                        case STORE1:
                            store1(p_Program);
                            break;
                        default:
                            Fault();
                            return;
                    }

                    if (isOverflow && p_HaltOnIsOverflow) {
                        cout << "isOverflow - Halt" << endl;
                        return;
                    }

                    if (isUnderflow && p_HaltOnIsUnderflow) {
                        cout << "isUnderflow - Halt" << endl;
                        return;
                    }
                }
            }
        }

    };
}

#endif
