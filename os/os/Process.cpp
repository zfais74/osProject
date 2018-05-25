//
//  Process.cpp
//  os
//
//  Created by Zeke on 5/23/18.
//  Copyright © 2018 Zeke. All rights reserved.
//

#include "Process.hpp"
#include <string>
using namespace std;
Process::Process(Job *job, int arrivalTime){
    this->arrivalTime = arrivalTime;
    this->job = job;
    this->timeRemaining = job->getUnitsOfTime();
    cpuBurst = job->getUnitsOfTime();
}

void Process::decrementTimeRemaining(int quantum){
    timeRemaining-=quantum;
}

string Process::toString(){
    return job->toString();
}


