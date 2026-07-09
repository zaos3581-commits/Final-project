#ifndef character_h
#define character_h
#include<string>
using namespace std

class character {
protected:
    string name;
    string location;
public:
    character();
    character(string n,stringl);
    string getName();
    string getLocation();

    void setLocation(string l);

};
#endif