//
//  Job.hpp
//  os
//
//  Created by Zeke on 5/12/18.
//  Copyright © 2018 Zeke. All rights reserved.
//

#ifndef Job_hpp
#define Job_hpp

#include <stdio.h>
class Job{
private:
    int id;
    int arrivalTime;
    int unitsOfMem;
    int unitsOfTime;
    int maxDevices;
    int priority;
public:
    Job(int arrivalTime, int id, int unitsOfMem, int maxDevices, int unitsOfTime, int priority);
    
    
};
#endif /* Job_hpp */
