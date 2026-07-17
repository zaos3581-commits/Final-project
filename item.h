#include<string>
#include<vector>
#include<iostream>
using namespace std;
#ifndef item_h
#define item_h

class item {
    private:
    int value;
    string name;
    public:
    item();
    item(string n, int v);

    string getname();

    int getvalue();

    void setname(string n);
    void setvalue(int v);
};


#endif