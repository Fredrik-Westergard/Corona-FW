#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "utilities.h"
#include "linkedList.h"

//main function
int main(int argc, char const *argv[]){
    bool running = true;        //boolean used to check if the main loop is running
    int number = 0;             //the level it's on
    int id = 0;

    if(argc == 2){
        id = getUser(argv[1]);
        if(id == -1){
            id = 0;
            printf("Ogiltig inmatning av användare!\n");
            exit(0);
        }
        else{
            printf("Välkommen användare %d\n\n", id);
        }
    }
    else{
        printf("Inget användar ID inmatat\n");
        exit(0);
    }

    list* l = createList();     //creates linked list for phones
    readData(l, id);
    if(getAlarm(id)){
        printf("ALARM!\n");
    }
    int size = printMenus(0, l,id);  //how many menu choices there are
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
        size = printMenus(number, l, id);
        //gets the menu item from user
        menu = getInput(size);
    }
    //writes to file
    writeData(l,id);
    //destroys list
    destroyList(l);
    return 0;
}
