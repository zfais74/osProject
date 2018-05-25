//
//  SystemConfig.cpp
//  os
//
//  Created by Zeke on 5/12/18.
//  Copyright © 2018 Zeke. All rights reserved.
//

#include "SystemConfig.hpp"
#include <iostream>
#include <string>
using namespace std;
SystemConfig::SystemConfig(){
    
}
SystemConfig::SystemConfig(int arrivalTime, int memSize, int devices, int quantum){
    this->arrivalTime = arrivalTime;
    this->devices = devices;
    this->availableDevices = devices;
    this->memSize = memSize;
    this->availableMem = memSize;
    this->quantum = quantum;
    this->currentTime = arrivalTime;
    this->quantumCounter = 0;
    this->cq = vector<Job*>();
    this->rq = vector<Process*>();
}

int SystemConfig::getTime(){
    return this->quantum;
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
    availableDevices+=devicesFreed;
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

string SystemConfig::toString(){
    return to_string(this->arrivalTime) + " " + to_string(this->availableDevices) + " " + to_string(this->availableMem);
}

int SystemConfig::getAvailableMem(){
    return availableMem;
}

int SystemConfig::getAvailableDevices(){
    return availableDevices;
}

void SystemConfig::increseTime(){
    currentTime++;
}

int SystemConfig::getMemSize(){
    return memSize;
}

int SystemConfig::getQuantum(){
    return quantum;
}

bool SystemConfig::runProcess(Process *process){
    //returns true if the job is complete
    process->job->decUnitsOfTime();
    quantumCounter++;
    if(process->job->getUnitsOfTime() == 0){
        return true;
    } else {
        return false;
    }
}

void SystemConfig::updateSystem(int updatedTime){
    int previousTime = currentTime;
    currentTime = updatedTime;
    int timeAtTheMoment = previousTime;
    if(updatedTime == 9999){
        return;
    }
    int timeDifference = currentTime - previousTime;
    int timeDifferenceCounter =0;
    while(timeDifferenceCounter < timeDifference){
        timeAtTheMoment++;
        bool completedJob = runProcess(rq.at(0));
        if(completedJob){//if the job is completed, throw the job into the completed array and pop that job from the queue
                         //and queue a job from the hold queue
            quantumCounter = 0;
            freeMem(rq.at(0)->job->getUnitsOfMem());
            freeDevices(rq.at(0)->job->getMaxDevices());
            cq.push_back(rq.at(0)->job);
            rq.erase(rq.begin() + 0);
            if(hq1->getSize() > 0){//hold q1 first because it's the highest priority
                Process *process = new Process(hq1->popJob(), timeAtTheMoment);
                rq.push_back(process);
            } else if(hq2->getSize() > 0){//
                Process *process = new Process(hq2->popJob(), timeAtTheMoment);
                rq.push_back(process);
            } else {
                //nothing
            }
        } else if(quantumCounter == quantum){//Since the job scheduling is RR, switch the job process
            quantumCounter = 0;
            if(rq.size() > 1) {
                //grab the process in the front
                Process *processToTheBack = rq.at(0);
                rq.erase(rq.begin() + 0);
                //push the process to the back
                rq.push_back(processToTheBack);
            }
        } else {
            //nothing
        }
        running = rq.at(0);
        timeDifferenceCounter++;
    }
    
    
    
}
