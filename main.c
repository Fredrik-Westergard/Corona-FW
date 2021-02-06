#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "utilities.h"
#include "linkedList.h"

//main function
int main(int argc, char const *argv[]){
    bool running = true;
    int number = 0;             //the level it's on
    list* l = createList();
    int size = printMenues(0, l);  //how many menu choices there are
    int menu = getInput(size);  //the chosen menu

    

    //menu loop
    while(running){
        //if the user chose "bakåt" or "avsluta", 
        //they have to be the last choice
        if(size == menu){
            //if the user chose "avsluta"
            if(number == 0){
                exit(0);
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
        size = printMenues(number, l);
        //gets the menu item from user
        menu = getInput(size);
    }
    destroyList(l);
    return 0;
}