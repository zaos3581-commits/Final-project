#ifndef game_h
#define game_h
#include<vector>
#include<string>
#include"villager.h"
#include"farmer.h"
#include"character.h"

using namespace std;

class game {
private:
    vector<villager> villagers;
    farmer player;
    bool gameovere;
    vector<string> loca;
public:
    game();
    game(farmer p, bool go);
    void addlocation(string n);
    character loadchar();
    void displaymenu();
    void processchoice(int c);
    void handlemove();
    void performAction();
    void checkList();
    void beginDialogue();
    void run();

};
#endif