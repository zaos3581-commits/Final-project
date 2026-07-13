#ifndef villager_h
#define villager_h
#include<string>
#include"character.h"
using namespace std;

class villager : public character {
protected:
    int friendship;
public:
    villager();
    villager(string f);
    string getFriend();

    void setFriend(string f);

};
#endif