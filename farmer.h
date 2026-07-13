#ifndef farmer_h
#define farmer_h
#include<string>
#include"character.h"
using namespace std;

class farmer : public character {
private:
    int nrg;
public:
    farmer();
    farmer(int n, string na, string l);

    int getnrg();

    void setnrg(int n);

};
#endif