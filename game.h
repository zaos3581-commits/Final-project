#ifndef game_h
#define game_h
#include<string>
using namespace std

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
    int processchoice();
    void handlemove();
    void run();

};
#endif