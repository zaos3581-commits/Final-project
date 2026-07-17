
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
        player = farmer(60,"MC","Nowhere");
        gameovere =false;
        villagers.push_back(villager("Shopkeep","Shop",5));
    }
    game::game(farmer p, bool go){
        player = p;
        gameovere = go;
        villagers.push_back(villager("Shopkeep","Shop",5));
    }
    void game::addlocation(string n){
        loca.push_back(n);
    }
    character game::loadchar(){
        ifstream inFile("characters.txt");
        if(inFile.is_open()){
            string line;
            while(getline(inFile,line)){
                int delim = line.find(',');
                string charName = line.substr(0,delim);
                string charloc = line.substr(delim+1, line.length()-charName.length()+1);
                inFile.close();
                return character(charName,charloc);
            }
        }
        cerr << "File not found.";
        return character();
    }
    void game::displaymenu(){
        cout << "What would you like to do?" << endl;
        cout << "1. Move" << endl;
        cout << "2. Talk" << endl;
        cout << "3. Check Inventory" << endl;
        cout << "4. Check Checklist" << endl;
        cout << "5. Action" << endl;
        cout << "6. Quit Game  ";
    }
   
    void game::handlemove(){
        int choice;
        if(player.getLocation()=="Shop"){
            cout << "Returned to the Town";
            player.setLocation("Town");
        }
        else if(player.getLocation()=="Town"){
            cout << "Where to?";
            cout << "1. Forest 2. Community Center 3. Shop";
            cin >> choice;
            if(choice==1){
                player.setLocation("Forest");
                cout << "Moved to Forest";
            }
            else if(choice==2){
                player.setLocation("Community Center");
                cout << "Moved to Community Center";
            }
            else if(choice==3){
                player.setLocation("Shop");
                cout << "Moved to Shop";
            }
            else{
                cout << "Invalid Option.";
            }
        }
        else if(player.getLocation()=="Community Center"){
            cout << "Where to?";
            cout << "1. Town 2. Lake";
            cin >> choice;
            if(choice==1){
                cout << "Moved to Town";
                player.setLocation("Town");
            }
            else if(choice==2){
                cout << "Moved to the Lake";
                player.setLocation("Lake");
            }
        }
        else if(player.getLocation()=="Forest"){
            cout << "Returned to the Town";
            player.setLocation("Town");
        }
        else if(player.getLocation()=="Lake"){
            
            if(player.removeInventory(item("Egg",0))){
                player.addInventory(item("Egg",0));
                cout << "Moved to Community Center";
                player.setLocation("Community Center");
            }
            else{
                cout << "Where to?" << endl;
                cout << "1. Community Center 2. Somewhere Else";
                cin >> choice;
                if(choice==1){
                    cout << "Moved to Community Center";
                player.setLocation("Community Center"); 
                }
                else if(choice==2){
                    cout << "You find yourself on a beach with a lone tree.";
                    player.setLocation("The Other Side");
                }
                else{
                    cout << "Invalid Choice.";
                }
            }
        }
        else if(player.getLocation()=="The Other Side"){
            player.setLocation("Lake");
            cout << "You say goodbye, but who are you speaking to?";
        }
        else{
            cout << "You've become lost deep in the woods" << endl;
            cout << "Somehow you begin to recognise your surroundings again";
            player.setLocation("Lake");
        }

    }
    void game::checkList(){
        cout << "You Need:" << endl;
        cout << "1. Egg, 2. Glass 3. Rope 4. Oil 5. Conch" << endl;
        cout << "Not necessarily in that order!";
    }
    void game::performAction(){
        if(player.getLocation()=="Lake"){
            if(player.removeInventory(item("Rod",25))){
                player.addInventory(item("Rod",25));
                cout << "You went fishing....." << endl;
                cout << ".........." << endl;
                cout << "You Caught 1 fish";
                player.addInventory(item("Fish",10));
            }
            else{
                cout << "Missing something...";
            }
        }
        else if(player.getLocation()=="Forest"){
            cout << "You dig through the leaves." << endl;
            if(player.removeInventory(item("Glass",0))){
                cout << "But you couldn't find anything.";
                player.addInventory(item("Glass",0));
            }
            else{
                cout << "..! Your finger snagged on something sharp." << endl;
                cout << "(You got Glass.)";
                player.addInventory(item("Glass",0));
            }
        }
        else if(player.getLocation()=="Community Center"){
            if(player.removeInventory(item("Glass",0))){
                if(player.removeInventory(item("Egg",0))){
                    if(player.removeInventory(item("Rope",10))){
                        if(player.removeInventory(item("Oil",10))){
                            if(player.removeInventory(item("Conch",0))){
                                cout << "You've collected every item!" << endl;
                                cout << "You donated each item." << endl;
                                cout << "(You got the CompletionToken)" << endl;
                                player.addInventory(item("Complete",999));
                            }
                            else{
                    player.addInventory(item("Oil",0));
                    player.addInventory(item("Rope",0));
                    player.addInventory(item("Egg",0));
                    player.addInventory(item("Glass",0));
                }
                        }
                        else{
                    player.addInventory(item("Rope",0));
                    player.addInventory(item("Egg",0));
                    player.addInventory(item("Glass",0));
                }
                    }
                    else{
                    player.addInventory(item("Egg",0));
                    player.addInventory(item("Glass",0));
                }
                }
                else{
                    player.addInventory(item("Glass",0));
                }
            }
        }
    }
    void game::beginDialogue(){
       int choice;
       
           if(player.getLocation()=="Lake"){
            if(player.removeInventory(item("Rod",25))){
                if(!player.removeInventory(item("Conch",0))){
                cout << "I found this lying here." << endl;
                cout << "It seems silly but..." << endl;
                cout << "I think you should have it." << endl;
                cout << "(You recieved the Conch.)";
                player.addInventory(item("Conch",0));
                player.addInventory(item("Rod",25));
                }
                else{
                    cout << "There's nothing left for you on this side.";
                    player.addInventory(item("Rod",25));
                }
            }
            else{
            cout << "Well, I heard you could fish here if you have a Rod!";
            }
           }
           else if(player.getLocation()=="Shop"){
            if(villagers[0].getFriend()>=5){
            cout << "Howdy! Pick anything you'd like to buy, then bring it back up here!" << endl;
            cout << "1. Rope  2. Oil 3. Bombs 4. Leave";
            cin >> choice;
            if(choice == 1){
                player.addInventory(item("Rope",20));
                cout << "What?" << endl;
                cout << "You can't pay?" << endl;
                cout << "Well, just bring back a fish and we'll call it even";
                villagers[0].setFriend(0);
            }
            if(choice == 2){
                player.addInventory(item("Oil",50));
                cout << "What?" << endl;
                cout << "You can't pay?" << endl;
                cout << "Well, just bring back a fish and we'll call it even";
                villagers[0].setFriend(0);
            }
            if(choice == 3){
                player.addInventory(item("Bomb",80));
                cout << "What?" << endl;
                cout << "You can't pay?" << endl;
                cout << "Well, just bring back a fish and we'll call it even";
                villagers[0].setFriend(0);
            }
            if(choice == 4){
                cout << "well have a nice day then." << endl;
                villagers[0].changeFriend(1);
            }
        }
        else{
            cout << "Well do you have my Fish?";
            if(player.removeInventory(item("Fish",10))){
               cout << "Well then I guess you can buy something now";
                villagers[0].setFriend(5);
            }
            else{
                cout << "scram!";
            }
        }
           }
           else if(player.getLocation()=="Town"){
            cout << "It's quiet here, somehow." << endl;
            cout << "Who do you wish to speak with?" << endl;
            cout << "1. The Hermit 2. The Spindler 3. John";
            cin >> choice;
            if(choice == 1){
                cout << "You've come again to this wonderful place," << endl;
                if(player.removeInventory(item("Glass",0))){
                    cout << "but there's nothing here!" << endl;
                cout << "no..." << endl;
                cout << "in fact, " << endl;
                cout << "why dont we end this game here?" << endl;
                cout << "(You got the EndToken.)" << endl;
                cout << "Also my name is Joja because this is stardew valley" << endl;
                player.addInventory(item("End",999));
                }
                else{
                cout << "come back when you can see through our charade!" << endl;
                cout << "if things go south I may be your only option...";
                }
            }
            else if(choice == 2){
                cout << "She regards you coldly for a moment." << endl;
                if(player.removeInventory(item("Rod",25))){
                    cout << "... it doesnt seem like she wants to talk anymore.";
                    player.addInventory(item("Rod",25));
                }
                else{
                    cout << "Here, maybe this will help you get a job" << endl;
                    cout << "(You got the Rod.)";
                    player.addInventory(item("Rod",25));
                }
            }
            else if(choice==3){
                cout << "Noone really ever wants to talk to John";
            }
            else{
                cout << "But who is that, anyways?";
            }
           }
           else if(player.getLocation()=="The Other Side"){
            cout << "A man stands by the shore." << endl;
            cout << "Suddenly, he turns around, and offers you something." << endl;
            cout << "Will you take it?" << endl;
            cout << " 1. Yes, 2. No" << endl;
            
            cin >> choice;
            if(choice == 1){
                cout << "Then, it is done." << endl;
                player.addInventory(item("Egg",0));
            }
            else{
                cout << "Then the world shall wait for you.";
            }
           }
           else{
            cout << "Your voice echoes aimlessly." << endl;
           }
    }
     void game::processchoice(int c){
        if(c==1){
            handlemove();
        }
        else if(c==2){
            beginDialogue();
        }
        else if(c==3){
            player.printInventory();
        }
        else if(c==4){
            checkList();
        }
        else if(c==5){
            performAction();
        }
        else if(c==6){
            cout << "Goodbye";
        }
        else{
            cout << "bad choice" << endl;
        }
    }
    void game::run(){
        cout << "start game" << endl;
        int choice =-1;
        int time = 50;
        int progress = 0;
        player = farmer(100,loadchar().getName(),loadchar().getLocation());
        
        while(gameovere==false){
            if(player.removeInventory(item("End",0))){
                cout << "And thus the world crumbled about you" << endl;
                cout << "Leaving nothing but a vague sensation" << endl;
                cout << "Of... completion?";
                gameovere=true;
                }
            else if(player.removeInventory(item("Complete",0))){
                cout << "Having fully funded the center,";
                cout << "You win!";
                gameovere = true;
             }
            else{
                if(player.removeInventory(item("Egg",0))){
                player.addInventory(item("Egg",0));
            cout << " " << endl;
        cout << "        [Forest]" << endl;
        cout << "           | " << endl;
        cout << "[Shop] -- [Town] -- [Community Center] -- [Lake]" << endl;
        }
        else{
                cout << " " << endl;
        cout << "        [Forest]" << endl;
        cout << "           | " << endl;
        cout << "[Shop] -- [Town] -- [Community Center] -- [Lake] -------------------- [The Other Side]" << endl;
        }
            cout << "Current Location: " << player.getLocation() << endl;
             cout << "Remaining Energy: " << time << "/50" << endl;
             progress = 0;
             int oil = 0;
             int rope = 0;

             for(int i=0;i<player.inventorysize();i++){
                if(player.getItem(i)=="Glass"||player.getItem(i)=="Egg"||player.getItem(i)=="Conch"){
                    progress++;
                }
                else if(player.getItem(i)=="Oil" && oil == 0){
                    oil++;
                    progress++;
                }
                else if(player.getItem(i)=="Rope" && rope == 0){
                    rope++;
                    progress++;
                }
             }
             cout << "Necessary items: " << progress << "/5" << endl;
            displaymenu();
            cin >> choice;
            if(choice==6){
            ofstream outFile("characters.txt");
            outFile << player.getName() << "," << player.getLocation() << endl;
            outFile.close();
            gameovere=true;
        }
            processchoice(choice);
            if(player.removeInventory(item("Egg",0))){
            player.addInventory(item("Egg",0));
            }
        time += -1;
        if(time<1){
            gameovere = true;
            cout << "You collapse to the ground, and perish";
        }
        }
    }
     
}



