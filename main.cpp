#include <iostream>
#include <vector>
#include "cpu.h"

using namespace std;
using namespace Emulation;

int main() {
    cpu *cpu = new class cpu();

    vector<byte> inst;
    inst.push_back(cpu::LOAD0);
    inst.push_back(0);
    inst.push_back(cpu::LOAD1);
    inst.push_back(7);
    inst.push_back(cpu::ADD);
    inst.push_back(cpu::STORE0);
    inst.push_back(255);

    cout << inst.size() << endl;

    cout << "cpu & Instructions Ready" << endl;
    cpu->Execute(inst);

    cout << "Execution Complete" << endl;

    vector<byte>::const_iterator itr = inst.begin();
    for (; itr != inst.end(); itr++) {
        cout << "[" << static_cast<int>((*itr)) << "]" << endl;
    }

    cout << "Complete" << endl;

    delete cpu;

    return 0;
}