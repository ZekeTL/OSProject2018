//
// Created by:
// colton teefy, noah holcombe, zeke lawal, chidi azuh, andrew sweitzer
//

#ifndef OSPROJECT_PCB_H
#define OSPROJECT_PCB_H

#include <string>
#include <iostream>
#include <utility>

using namespace std;

class PCB {
    int ID;
    int priorityLevel;
    int numOfCycles;
    int processStartPoint;
    int processEndPoint;
    int dataStartPoint;
    int dataEndPoint;
    int currentSize;
    string statusChange;

public:
    PCB() {
        ID = -1;
        priorityLevel = 0;
        numOfCycles = -1;
        currentSize = 0;
        processStartPoint = 0;
        processEndPoint = 0;
        dataStartPoint = 0;
        dataEndPoint = 0;
        statusChange = "";
    }


    void setID(int pid) {
        ID = pid;
    }


    int getID() {
        return ID;
    }

    void setPriorityLevel(int pr) {
        priorityLevel = pr;
    }

    int getPriorityLevel() {
        return priorityLevel;
    }


    void setNumOfCycles(int noc) {
        numOfCycles = noc;
    }

    int getNumOfCycles() {
        return numOfCycles;
    }


    void setcurrentSize(int s) {
        currentSize = s;
    }


    int getcurrentSize() {
        return currentSize;
    }

    void setProcessStartPoint(int ps) {
        processStartPoint = ps;
    }

    int getProcessStartPoint() {
        return processStartPoint;
    }

    void setProcessEndPoint(int pe) {
        processEndPoint = pe;
    }

    int getProcessEndPoint() {
        return processEndPoint;
    }

    void setDataStartPoint(int ds) {
        dataStartPoint = ds;
    }

    int getDataStartPoint() {
        return dataStartPoint;
    }

    void setDataEndPoint(int de) {
        dataEndPoint = de;
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
        if (change == "running")
            statusChange = change;
        else if (change == "ready")
            statusChange = change;
        else if (change == "waiting")
            statusChange = change;
        else if (change == "exited")
            statusChange = change;
        else
            cout << "Error! " + change + " is not a valid state";
    }

    void tostring() {
        cout << "process ID: " + ID << endl
             << "priorityLevel:" + priorityLevel << endl
             << "cycles:" + numOfCycles << endl
             << "currentSize:" + currentSize << endl
             << "process start:" + processStartPoint << endl
             << "process end" + processEndPoint << endl
             << "data start:" + dataStartPoint << endl
             << "data end:" + dataEndPoint << endl
             << "change status: " + statusChange << endl;
    }
};


#endif //OSPROJECT_PCB_H
