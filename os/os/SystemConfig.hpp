//
//  SystemConfig.hpp
//  os
//
//  Created by Zeke on 5/12/18.
//  Copyright © 2018 Zeke. All rights reserved.
//

#ifndef SystemConfig_hpp
#define SystemConfig_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include "Process.hpp"
#include "HoldQ1.hpp"
#include "HoldQ2.hpp"
using namespace std;

class SystemConfig{
private:
    int arrivalTime;
    int devices;
    int availableDevices;
    int memSize;
    int availableMem;
    int quantum;
    int currentTime;
    int quantumCounter;
public:
    HoldQ1 *hq1;
    HoldQ2 *hq2;
    vector<Process*>rq;
    vector<Job*>cq;
    Process *running;
    SystemConfig();
    SystemConfig(int arrivalTime, int memSize, int devices, int quantum);
    int getArrivalTime();
    int getMemSize();
    int getDevices();
    int getTime();
    bool useMem(int memUsed);
    bool useDevices(int devicesUsed);
    void freeMem(int memFreed);
    void freeDevices(int devicesFreed);
    string toString();
    int getAvailableMem();
    int getAvailableDevices();
    void increseTime();
    int getQuantum();
    bool runProcess(Process *process);
    void updateSystem(int updatedTime);
};

#endif /* SystemConfig_hpp */
