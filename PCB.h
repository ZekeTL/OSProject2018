//
// Created by:
// colton teefy, noah holcombe, zeke lawal, chidi azuh, andrew sweitzer
//

#ifndef OSPROJECT_PCB_H
#define OSPROJECT_PCB_H

#include <string>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class PCB {

    int ID;
    int dataStartPoint;
    int dataEndPoint;
    int processStartPoint;
    int processEndPoint;
    int priorityLevel;
    int numOfCycles;
    int currentSize;
    string statusChange;


    //not ready yet
    
    int taskDiskAddress;
    int taskMemoryAddress;
    int taskInstructionCount;
    int dataDiskAddress;
    int dataMemoryAddress;
    int pageTableStartingIndex;
    int pagesNeeded;
    int inputBuffer;
    int outputBuffer;
    int tempBuffer;
    int cacheSize;
    int programCounter;
    bool IObound;
    bool taskInMemory;
    bool hasTaskRun;

    string instruction;

    vector<int> allocatedVirtualPages;
    vector<string> cache;

    int registers[16] = {};

public:
    PCB() {
        ID = -1;
        dataStartPoint = 0;
        dataEndPoint = 0;
        processStartPoint = 0;
        processEndPoint = 0;
        priorityLevel = 0;
        numOfCycles = -1;
        currentSize = 0;
        statusChange = "new";
    }


    void setID(int processId) {
        ID = processId;
    }


    int getID() {
        return ID;
    }

    void setPriorityLevel(int pLevel) {
        priorityLevel = pLevel;
    }

    int getPriorityLevel() {
        return priorityLevel;
    }


    void setNumOfCycles(int numCycle) {
        numOfCycles = numCycle;
    }

    int getNumOfCycles() {
        return numOfCycles;
    }


    void setcurrentSize(int size) {
        currentSize = size;
    }


    int getcurrentSize() {
        return currentSize;
    }

    void setProcessStartPoint(int procStart) {
        processStartPoint = procStart;
    }

    int getProcessStartPoint() {
        return processStartPoint;
    }

    void setProcessEndPoint(int procEnd) {
        processEndPoint = procEnd;
    }

    int getProcessEndPoint() {
        return processEndPoint;
    }

    void setDataStartPoint(int dataStart) {
        dataStartPoint = dataStart;
    }

    int getDataStartPoint() {
        return dataStartPoint;
    }

    void setDataEndPoint(int dataEnd) {
        dataEndPoint = dataEnd;
    }

    int getDataEndPoint() {
        return dataEndPoint;
    }

    string getChangeStatus() {
        return statusChange;
    }

    void setChangeStatus(string status) {
        statusChange = std::move(status);
    }

    void cycleAdd() {
        numOfCycles++;
    }

    void changeStatus(string change) {
        transform(change.begin(), change.end(), change.begin(), ::tolower);
        if (change == "new")
            statusChange = change;
        else if (change == "ready")
            statusChange = change;
        else if (change == "waiting")
            statusChange = change;
        else if (change == "terminate")
            statusChange = change;
        else
            cout << "Error! " + change + " is not a valid state";
    }

    void tostring() {
        cout << "process ID: " << ID << endl
             << "priority level:" << priorityLevel << endl
             << "cycles:" << numOfCycles << endl
             << "current size:" << currentSize << endl
             << "process start:" << processStartPoint << endl
             << "process end" << processEndPoint << endl
             << "data start:" << dataStartPoint << endl
             << "data end:" << dataEndPoint << endl
             << "current status: " << statusChange << endl;
    }
};


#endif //OSPROJECT_PCB_H
