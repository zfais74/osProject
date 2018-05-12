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

class SystemConfig{
private:
    int startTime;
    int devices;
    int availableDevices;
    int memSize;
    int availableMem;
    int time;
public:
    SystemConfig(int startTime, int memSize, int devices, int time);
    int getStartTime();
    int getMemSize();
    int getDevices();
    int getTime();
    void useMem(int memUsed);
    void useDevices(int devicesUsed);
    void freeMem(int memFreed);
    void freeDevices(int devicesFreed);
    
};

#endif /* SystemConfig_hpp */
