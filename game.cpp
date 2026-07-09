#ifndef game_h
#define game_h
#include "game.h"
#include<string>
using namespace std

    game::game();
    game::game(vector<villager> v, farmer p, bool go);

    game::loadchar(){
        ifstream inFile("characters.txt");
        if(inFile.is_open){
            string line;
            while(getline(inFile,line)){
                int delim = line.find(',');
                string charName = line.substr(0,delim+1);
                string charloc = line.substr(delim+1, line.length()-charName.length()+1);
            }
            inFile.close();
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
        else if(calloc==2){
            beginDialogue();
        }
        else if(c==3){
            return -1;
        }
        else{
            cout << "bad choice" << endl;
        }
    }
    void game::handlemove();
    void game::run(){
        cout << "start game" << endl;
        int choice =-1;
        while(choice!=3 || gameover=false){
            displaymenu();
            cin >> choice;
            processchoice(choice);
            
        }
    }
