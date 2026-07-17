#ifndef farmer_h
#define farmer_h
#include<string>
#include"character.h"
#include"item.h"
#include<vector>
using namespace std;

class farmer : public character {
private:
    int nrg;
    vector<item> inventory;
public:
    farmer();
    farmer(int n, string na, string l);
    int getnrg();
    void printInventory();
    string getItem(int n);
    int inventorysize();
    void addInventory(item n);
    bool removeInventory(item n);
    void setnrg(int n);

};
#endif