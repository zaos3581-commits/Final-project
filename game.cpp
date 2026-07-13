
#include "game.h"
#include<string>
#include"character.h"
#include"farmer.h"
#include"villager.h"
#include<vector>
#include<iostream>
#include<fstream>
using namespace std;

    game::game(){

    }
    game::game(vector<villager> v, farmer p, bool go){

    }

    void game::loadchar(){
        ifstream inFile("characters.txt");
        if(inFile.is_open()){
            string line;
            while(getline(inFile,line)){
                int delim = line.find(',');
                string charName = line.substr(0,delim+1);
                string charloc = line.substr(delim+1, line.length()-charName.length()+1);
                character(charName,charloc);
            }
            inFile.close();
        }
        else{
            cerr << "File not found.";
        }
    }
    void game::displaymenu(){
        cout << "what do 1-3" << endl;
        cout << "1. loc" << endl;
        cout << "2. talk to" << endl;
        cout << "3. quit" << endl;
    }
    int game::processchoice(int c){
        if(c==1){
            handlemove();
        }
        else if(c==2){
            beginDialogue();
        }
        else if(c==3){
            return -1;
        }
        else{
            cout << "bad choice" << endl;
        }
    }
    void game::handlemove(){

    }
    void game::beginDialogue(){

    }
    void game::run(){
        cout << "start game" << endl;
        int choice =-1;
        while(choice!=3 || gameovere==false){
            displaymenu();
            cin >> choice;
            processchoice(choice);
        }
    }
