#include<string>
#include<iostream>
#include"villager.h"
#include"character.h"
using namespace std;
villager::villager(){

}
    villager::villager(string n, string l, int f):character(n,l){
        friendship = f;
    }
    int villager::getFriend(){
        return friendship;
    }

    void villager::setFriend(int f){
        friendship = f;
    }