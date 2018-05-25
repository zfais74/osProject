//
//  Process.hpp
//  os
//
//  Created by Zeke on 5/23/18.
//  Copyright © 2018 Zeke. All rights reserved.
//

#ifndef Process_hpp
#define Process_hpp

#include <stdio.h>
#include "Job.hpp"
#include <string>
using namespace std;
class Process{
private:
    int jobId;
    int arrivalTime;
    int cpuBurst;
    int timeRemaining;
    int completionTime;
public:
    Job *job;
    Process(Job *job, int arrivalTime);
    ~Process();
    int getArrivalTime();
    int getBurst();
    int getTimeRemaining();
    int getCompletionTime();
    int getJobId();
    void decrementTimeRemaining(int quantum);
    string toString();
    
};

#endif /* Process_hpp */
