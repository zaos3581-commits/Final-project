#include "character.h"
#include<string>
using namespace std;


    character::character(){
        name = "unknowable";
        location = "nowhere";
    }
    character::character(string n,string l){
        name = n;
        location = l;
    }
    string character::getName(){
        return name;
    }
    string character::getLocation(){
        return location;
    }

    void character::setLocation(string l){
        location = l;
    }