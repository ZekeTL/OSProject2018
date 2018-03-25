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
            LD0 = 0,
            LD1,
            ST0,
            ST1,
            INCREASE,
            DECREASE
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

        void ld0(const vector<byte> &currentProgram) {
            reg0 = currentProgram[counter];
            counter++;
        }

        void ld1(const vector<byte> &currentProgram) {
            reg1 = currentProgram[counter];
            counter++;
        }

        void st0(vector<byte> &currentProgram) {
            currentProgram[counter] = reg0;
            counter++;
        }

        void st1(vector<byte> &currentProgram) {
            currentProgram[counter] = reg1;
            counter++;
        }


        void increase() {
            currentTmpValue = reg0 + reg1;
            if (currentTmpValue > MAX) {
                isOverflow = true;
                currentTmpValue = MAX;
            }
            reg0 = static_cast<byte>(currentTmpValue);
        }

        void decrease() {
            currentTmpValue = reg0 - reg1;
            if (currentTmpValue < 0) {
                isUnderflow = true;
                currentTmpValue = 0;
            }
            reg0 = static_cast<byte>(currentTmpValue);
        }

        cpu() {
            cpuReset();
        }

        ~cpu() = default;

        void Execute(vector<byte> &currentProgram, const bool &isOverflow = true,
                     const bool &isUnderflow = true) {
            cpuReset();

            if (currentProgram.size() > MAX) {
                cout << "Error! Program Counter overload. Max instruction: 255" << endl;
            } else {
                while (counter < currentProgram.size()) {
                    regInstruction = currentProgram[counter];
                    counter++;

                    switch (regInstruction) {
                        case LD0:
                            ld0(currentProgram);
                            break;
                        case LD1:
                            ld1(currentProgram);
                            break;
                        case ST0:
                            st0(currentProgram);
                            break;
                        case ST1:
                            st1(currentProgram);
                            break;
                        case INCREASE:
                            increase();
                            break;
                        case DECREASE:
                            decrease();
                            break;
                        default:
                            Fault();
                            return;
                    }

                    if (isOverflow != 0) {
                        cout << "isOverflow - Halt" << endl;
                        return;
                    }

                    if (isUnderflow != 0) {
                        cout << "isUnderflow - Halt" << endl;
                        return;
                    }
                }
            }
        }

    };
}

#endif
