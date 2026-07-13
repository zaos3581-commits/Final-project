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

public:
    game();
    game(vector<villager> v, farmer p, bool go);

    void loadchar();
    void displaymenu();
    int processchoice(int c);
    void handlemove();
    void beginDialogue();
    void run();

};
#endif