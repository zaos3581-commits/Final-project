#include<string>
#include"item.h"
#include<iostream>
using namespace std;

item::item(string n, int v){
name = n;
value = v;
}

 string item::getname(){
    return name;
 }

int item::getvalue(){
    return value;
}

void item::setname(string n){
    name = n;
}
    void item::setvalue(int v){
        value = v;
    }