#include "farmer.h"
#include<string>
#include"character.h"
#include"item.h"
#include<iostream>
#include<vector>
using namespace std;


    farmer::farmer():character(){
        nrg = 666;
    }
    farmer::farmer(int n,string na, string l):character(na,l){
        nrg = n;
    }
    int farmer::inventorysize(){
        return static_cast<int>(inventory.size());
    }
    string farmer::getItem(int n){
        return inventory[n].getname();
    }
    int farmer::getnrg(){
        return nrg;
    }
    void farmer::addInventory(item n){
        inventory.push_back(n);
    }
    bool farmer::removeInventory(item n){
        string name = n.getname();
        for(int i = 0;i<static_cast<int>(inventory.size());i++){
            if(inventory[i].getname()==name){
                inventory.erase(inventory.begin()+i);
                return true;
            }
        }
        return false;
    }
    void farmer::setnrg(int n){
        nrg = n;
    }
    void farmer::printInventory(){
        if(static_cast<int>(inventory.size())<1){
            cout << "No items!";
        }
        else{
            for(int i=0; i<static_cast<int>(inventory.size());i++){
                cout << inventory[i].getname() << endl;
            }
        }
    }