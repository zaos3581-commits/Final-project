#include "farmer.h"
#include<string>
#include"character.h"
#include<iostream>
using namespace std;


    farmer::farmer():character(){
        nrg = 666;
    }
    farmer::farmer(int n,string na, string l):character(na,l){
        nrg = n;
    }

    int farmer::getnrg(){
        return nrg;
    }

    void farmer::setnrg(int n){
        nrg = n;
    }