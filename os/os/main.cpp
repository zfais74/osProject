//Zeke Faison && Andrew Rajic

#include <iostream>
#include <string>
#include <fstream>
#include "projectRunner.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    cout << "Test"<<endl;
    ProjectRunner pr;
    string result = pr.readFile("input.txt");
    return 0;
}
