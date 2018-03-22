//
// Created by colton teefy on 3/22/18.
//

#ifndef OSPROJECT_PCB_H
#define OSPROJECT_PCB_H

#include <string>
#include <iostream>
#include <utility>

using namespace std;

class PCB {
    int process_ID;
    int priority;
    int numOfCycles;
    int process_start;
    int process_end;
    int data_start;
    int data_end;
    int size;
    string change_status;

public:
    PCB() {
        process_ID = -1;
        priority = 0;
        numOfCycles = -1;
        size = 0;
        process_start = 0;
        process_end = 0;
        data_start = 0;
        data_end = 0;
        change_status;
    }

public:
    void setProcessID(int pid) {
        process_ID = pid;
    }

public:
    int getProcessID() {
        return process_ID;
    }

public:
    void setPriority(int pr) {
        priority = pr;
    }

public:
    int getPriority() {
        return priority;
    }

public:
    void setNumOfCycles(int noc) {
        numOfCycles = noc;
    }

public:
    int getNumOfCycles() {
        return numOfCycles;
    }

public:
    void setSize(int s) {
        size = s;
    }

public:
    int getSize() {
        return size;
    }

public:
    void setProcessStart(int ps) {
        process_start = ps;
    }

public:
    int getProcessStart() {
        return process_start;
    }

public:
    void setProcessEnd(int pe) {
        process_end = pe;
    }

public:
    int getProcessEnd() {
        return process_end;
    }

public:
    void setDataStart(int ds) {
        data_start = ds;
    }

public:
    int getDataStart() {
        return data_start;
    }

public:
    void setDataEnd(int de) {
        data_end = de;
    }

public:
    int getDataEnd() {
        return data_end;
    }

public:
    string getChangeStatus() {
        return change_status;
    }

public:
    void setChangeStatus(string status) {
        change_status = std::move(status);
    }

public:
    void incrementNumOfCycle() {
        numOfCycles++;
    }

public:
    void changeStatus(string newState) {
        transform(newState.begin(), newState.end(), newState.begin(), ::tolower);
        if (newState.compare("running"))
            change_status = newState;
        else if (newState.compare("ready"))
            change_status = newState;
        else if (newState.compare("waiting"))
            change_status = newState;
        else if (newState.compare("exited"))
            change_status = newState;
        else
            cout << "ERROR bitch: " + newState + " is not a valid state";
    }

public:
    string tostring() {
        cout << "process ID: " + process_ID << endl
             << "priority:" + priority << endl
             << "number of cycles:" + numOfCycles << endl
             << "size:" + size << endl
             << "process start:" + process_start << endl
             << "process end" + process_end << endl
             << "data start:" + data_start << endl
             << "data end:" + data_end << endl
             << "change status: " + change_status << endl;
    }
};


#endif //OSPROJECT_PCB_H
