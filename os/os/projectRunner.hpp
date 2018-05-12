//
//  projectRunner.hpp
//  os
//
//  Created by Zeke on 5/12/18.
//  Copyright © 2018 Zeke. All rights reserved.
//

#ifndef projectRunner_hpp
#define projectRunner_hpp

#include <stdio.h>
#include <string>
using namespace std;
class ProjectRunner{
public:
    ProjectRunner();
    string readFile(string fileName);
};

#endif /* projectRunner_hpp */
