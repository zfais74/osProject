//
//  Job.cpp
//  os
//
//  Created by Zeke on 5/12/18.
//  Copyright © 2018 Zeke. All rights reserved.
//

#include "Job.hpp"
#include <string>
using namespace std;
Job::Job(int arrivalTime, int id, int unitsOfMem, int maxDevices, int unitsOfTime, int priority){
    this->arrivalTime = arrivalTime;
    this->id = id;
    this->unitsOfMem = unitsOfMem;
    this->maxDevices = maxDevices;
    this->unitsOfTime = unitsOfTime;
    this->priority = priority;
}

string Job::toString(){
    string s;
    s = "Arrival Time: ";
    s += to_string(arrivalTime);
    s+=" ";
    s+= "Id: ";
    s+= to_string(id);
    s+=" ";
    s+= "Mem";
    s+= to_string(unitsOfMem);
    return  s;
}

int Job::getPriority(){
    return priority;
}

int Job::getId(){
    return id;
}

int Job::getUnitsOfTime(){
    return unitsOfTime;
}

int Job::getUnitsOfMem(){
    return unitsOfMem;
}

int Job::getMaxDevices(){
    return maxDevices;
}

void Job::decUnitsOfTime(){
    unitsOfTime--;
}
