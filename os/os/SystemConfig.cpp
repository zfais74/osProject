//
//  SystemConfig.cpp
//  os
//
//  Created by Zeke on 5/12/18.
//  Copyright © 2018 Zeke. All rights reserved.
//

#include "SystemConfig.hpp"
#include <iostream>
using namespace std;
SystemConfig::SystemConfig(int arrivalTime, int memSize, int devices, int time){
    this->arrivalTime = arrivalTime;
    this->devices = devices;
    this->availableDevices = devices;
    this->memSize = memSize;
    this->availableMem = memSize;
    this->time = time;
}

int SystemConfig::getTime(){
    return this->time;
};

int SystemConfig::getDevices(){
    return this->availableDevices;
}

bool SystemConfig::useDevices(int devicesUsed){
    if(this->availableDevices - devicesUsed > 0){
        availableDevices -= devicesUsed;
        return true;
    } else {
        
        return false;
    }
}

void SystemConfig::freeDevices(int devicesFreed){
    availableMem+=devicesFreed;
}

bool SystemConfig::useMem(int memUsed){
    if(this->availableMem - memUsed > 0){
        availableMem -= memUsed;
        return true;
    } else {
        return false;
    }
}

void SystemConfig::freeMem(int memFreed){
    availableMem+=memFreed;
}
