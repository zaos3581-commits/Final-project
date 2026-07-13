#include <string>
#include <iostream>
#include <vector>
using namespace std;
#ifndef character_h
#define character_h

class character {
protected:
    string name;
    string location;
public:
    character();
    character(string n,string l);
    string getName();
    string getLocation();

    void setLocation(string l);

};
#endif