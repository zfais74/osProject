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
using namespace std;

class SystemConfig{
private:
    int arrivalTime;
    int devices;
    int availableDevices;
    int memSize;
    int availableMem;
    int time;
public:
    SystemConfig();
    SystemConfig(int arrivalTime, int memSize, int devices, int time);
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
};

#endif /* SystemConfig_hpp */
