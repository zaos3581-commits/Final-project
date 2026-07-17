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
    villager(string n, string l, int f);
    int getFriend();
    void changeFriend(int f);
    void setFriend(int f);

};
#endif