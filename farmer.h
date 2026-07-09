#ifndef farmer_h
#define farmer_h
#include<string>
using namespace std

class farmer : public character {
private:
    int nrg;
public:
    farmer();
    farmer(int n);

    int getnrg();

    void setnrg(int n);

};
#endif