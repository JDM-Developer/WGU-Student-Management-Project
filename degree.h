#pragma once

#include <string>
using namespace std;

enum DegreeType {  //Enumerator for the three types of degrees
   
    SECURITY,
    NETWORK,
    SOFTWARE
    
};

// Array for mapping enumeration to strings for output.
static const string DegreeTypeStrings[] = {"SECURITY","NETWORK","SOFTWARE"}; 

