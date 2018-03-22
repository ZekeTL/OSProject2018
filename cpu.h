#ifndef cpu_HEADER
#define cpu_HEADER

#include <iostream>
#include <vector>

/*
 * https://www.classes.cs.uchicago.edu/archive/2013/spring/12300-1/labs/lab6/
 * http://megalomaniacbore.blogspot.com/2012/05/write-your-own-virtual-cpu-in-c-code.html
 * http://www.c-jump.com/bcc/c155c/MemAccess/MemAccess.html#W12_0180_cc_memory_access_d
 * */

namespace Emulation {
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

    public:

        byte register0{};
        byte register1{};
        byte counter{};
        byte regInstruction{};

        bool currentStatus{};
        bool overflow{};
        bool underflow{};

        int currentTmp{};

        cpu(const cpu &) {}

        void cpuReset() {
            currentTmp = 0;
            register0 = 0;
            register1 = 0;
            currentStatus = true;
            overflow = false;
            underflow = false;
            counter = 0;
        }

        void Fault() {
            currentStatus = false;
            cout << "Instruction Fault at: " << counter << endl;
            registerRelease();
        }

        void registerRelease() {
            cout << "cpu Registers:" << endl
                 << "Register0 [" << register0 << "]" << endl
                 << "Register1 [" << register1 << "]" << endl
                 << "Status [" << currentStatus << "]" << endl
                 << "Overflow [" << overflow << "]" << endl
                 << "Underflow [" << underflow << "]" << endl
                 << "Program Counter [" << counter << "]" << endl
                 << "Instruction Register [" << regInstruction << "]" << endl
                 << "Temp [" << currentTmp << "]" << endl;
        }

        void load0(const vector<byte> &p_Program) {
            register0 = p_Program[counter];
            counter++;
        }

        void load1(const vector<byte> &p_Program) {
            register1 = p_Program[counter];
            counter++;
        }

        void add() {
            currentTmp = register0 + register1;
            if (currentTmp > MAX) {
                overflow = true;
                currentTmp = MAX;
            }
            register0 = static_cast<byte>(currentTmp);
        }

        void subtract() {
            currentTmp = register0 - register1;
            if (currentTmp < 0) {
                underflow = true;
                currentTmp = 0;
            }
            register0 = static_cast<byte>(currentTmp);
        }

        void store0(vector<byte> &p_Program) {
            p_Program[counter] = register0;
            counter++;
        }

        void store1(vector<byte> &p_Program) {
            p_Program[counter] = register1;
            counter++;
        }

    public:

        cpu() {
            cpuReset();
        }

        ~cpu() = default;

        void
        Execute(vector<byte> &p_Program, const bool &p_HaltOnOverflow = true, const bool &p_HaltOnUnderflow = true) {
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

                    if (overflow && p_HaltOnOverflow) {
                        cout << "Overflow - Halt" << endl;
                        return;
                    }

                    if (underflow && p_HaltOnUnderflow) {
                        cout << "Underflow - Halt" << endl;
                        return;
                    }
                }
            }
        }

    };

}

#endif
