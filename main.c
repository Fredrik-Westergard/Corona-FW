#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "utilities.h"
#include "codesList.h"
#include "hashMap.h"



//main function
int main(int argc, char const *argv[]){
    bool running = true;        //boolean used to check if the main loop is running
    int number = 0;             //the level it's on
    int id = 0;                 //the user id

    id = checkArgs(argc, argv);
    if(id == -1){
        return 1;
    }
    codes* c = createCodesList();   //creates linked list for codes
    //list* l = createList();         //creates linked list for phones
    //readData(l, id);                //reads phones list from file
    table* t = createTable();
    readToHashMap(t, id);
    
    //check if the server alarmed the user and show alarm to user
    if(getAlarm(id)){
        printf("ALARM: Du har varit i närheten av någon med covid-19,\n");
        printf("vänligen ring coronaupplysningen för instruktioner.\n");
        printf("Tryck på valfrin knapp för att fortsätta...\n\n");
        scanf("%*c");
        clean_stdin();
    }
    int size = printMenus(0, t, c, id);  //how many menu choices there are
    int menu = getInput(size);  //the chosen menu

    //menu loop
    while(running){
        //if the user chose "bakåt" or "avsluta", 
        //they have to be the last choice
        if(size == menu){
            //if the user chose "avsluta"
            if(number == 0){
                break;
            }
            //go back one step
            number = number/10;
        }
        else{
            //go forward one step
            //works like this:
            //(the level * the number of available choices) + the chosen menu = the menus number
            //example: the level = 1, the number of available choices = 10 (only 4 used currently but there is space for more)
            //the chocen menu = 2, becomes (1*10)+2 = 12. open menu 12
            number = (number*10)+menu;
        }
        //prints the menu and gets the number of menu choices
        size = printMenus(number, t, c, id);
        //gets the menu item from user
        menu = getInput(size);
    }
    //writes to file
    //writeData(l,id);
    //destroys the phones list
    //destroyList(l);
    //destroys the codes list
    writeHashMap(t,id);
    destroyHashMap(t);
    destroyCodes(c);
    return 0;
}
