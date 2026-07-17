#include<string>
#include<iostream>
#include"villager.h"
#include"character.h"
using namespace std;
villager::villager(){
    name = "      ";
    location = "The other side of the lake";
    friendship = 666;
}
    villager::villager(string n, string l, int f):character(n,l){
        friendship = f;
    }
    int villager::getFriend(){
        return friendship;
    }
    void villager::changeFriend(int f){
        friendship += -f;
    }
    void villager::setFriend(int f){
        friendship = f;
    }