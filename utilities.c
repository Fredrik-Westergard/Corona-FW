#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include "utilities.h"
#include "date.h"
#include <errno.h>
#include <limits.h>
#include <string.h>
#include "codesList.h"
#include "hashMap.h"

//function to input new opening code
void newCode(table* t, codes* c){
    unsigned int code;  //unsigned because it can't be negativce
    bool good = false;  
    printf("Enter opening code of 8 digits:\n");
    while(!good){
        scanf("%u", &code);
        clean_stdin();
        //floor returns the largest value that's less than or equal to the parameter,
        //log10 returns the common log in base 10 of the parameter
        //abs returns the absolute value
        //checks wether code has 8 digits
        //would be easier if these were strings instead
        if(floor(log10(abs(code)))+1 == 8){
            good = true;
        }
        else{
            printf("Invalid input, try again: \n\n");
        }
    }
    printf("Opening code: %8d\n", code);
    printf("New code added.\n\n");
    printf("Close proximity phones for the last 21 days:\n");
    addToCodes(c, code);
    //removeTooOld(l);
    printPhones(t);
    removeOld(t);
    


    return;
}
//funtion to print the stored codes
void printCodes(codes* c){
    printCodesList(c);
    return;
}

//function to add a new phone
void newPhone(table* t){
    unsigned int id;    //unsigned because it can't be negative
    bool good = false;
    date d;      //date structure

    printf("Enter identfication code of 6 digits: \n");
    while(!good){
        scanf("%u", &id);
        clean_stdin();
        //floor returns the largest value that's less than or equal to the parameter,
        //log10 returns the common log in base 10 of the parameter
        //abs returns the absolute value
        //checks wether code has 6 digits
        if(floor(log10(abs(id)))+1 == 6){
            good = true;
        }
        else{
            printf("Invalid input, try again: \n\n");
        }
    }
    printf("Enter date with YYYY-MM-DD format\n");
    while(good){
        scanf("%d-%d-%d", &d.year, &d.month, &d.day);
        clean_stdin();
        //checks if the date is valid
        if(checkDate(d)){
            good = false;
        }
        else{
            printf("Invalid input, try again: \n\n");
        }
    }
    //addToList(l, id, d);
    addItem(t, d, id);
    printf("\nID: %6d\nDate: ", id);
    printDateISO(d);
    printf("\n\n");
    printf("New phone added.\n");
    return;
}
//prints the phones
void printPhones(table* t){
    printf("ID\tDate\n");
    //printList(l);
    printItems(t);
    printf("\n");
    return;
}
//function to send alarm recursively
void sendAlarmRec(item* it){
    if(it == NULL){
        return;
    }
    int id = it->data;
    char loc[18] = "coronaAlarm";
    char str[7];
    sprintf(str,"%d",id);
    strcat(loc, str);
    FILE* f = fopen(loc,"wb+");

    if(f != NULL){
        date d = getTodaysDate();
        fprintf(f, "%d-%d-%d", d.year,d.month,d.day);
        fclose(f);
    }
    sendAlarmRec(it->next);
}
//function to send alarm
void sendAlarm(table* t, codes* c, int id){
    codes* toCompare = createCodesList();
    bool temp = false;
    if(readCodes(toCompare, id)){
        if(toCompare->length != 0){
            if(compareCodes(c, toCompare)){
                //removeTooOld(l);
                removeOld(t);
                for(int i = 0; i < SIZE; i++){
                    sendAlarmRec(t->items[i]);
                }
                temp = true;
                printf("Alarm sent!\n");
            }
        }
    }

    if(!temp){
        printf("Alarm failed, please input a valid opening code!\n");
    }

    destroyCodes(toCompare);
}
//Prints the menus
int printMenus(int menu, table* t, codes* c, int id){  
    //checks if the menu number corresponds with the choice number
    //tried to make it as dynamic as possible
    if(menu == 0 || menu == 13 || menu == 23 || menu == 33 || 
        menu == 111 || menu == 121 || menu == 211 || menu == 221 || menu == 311){

        printf("\t#'''''''''''''''''''#\n");
        printf("\t|  Corona Blinker!  |\n");
        printf("\t#...................#\n\n");
        printf("1. Enter opening code.\n");
        printf("2. Enter identification code and date for a phone.\n");
        printf("3. Send or receive an alarm.\n");
        printf("4. Exit\n\n");
        return 4;
    }
    else if(menu == 1){
        printf("\t#''''''''''''''''''''''''#\n");
        printf("\t|   Enter Opening Code!  |\n");
        printf("\t#........................#\n\n");
        printf("1. New opening code.\n");
        printf("2. Show opening codes.\n");
        printf("3. Back.\n\n");
        return 3;
    }
    else if(menu == 2){
        printf("\t#'''''''''''''''''''''''''''''''''''''''#\n");
        printf("\t|   Enter identification code and date  |\n");   
        printf("\t|              for a phone!             |\n");
        printf("\t#.......................................#\n\n");
        printf("1. New close phone\n");
        printf("2. Show phones.\n");
        printf("3. Back.\n\n");
        return 3;
    }
    else if(menu == 3){
        printf("\t#'''''''''''''''''''''''''''''''''''''#\n");
        printf("\t|      Send or receive new alarm      |\n");
        printf("\t#.....................................#\n\n");
        printf("1. New alarm.\n");
        printf("2. Search for alarm.\n");
        printf("3. Back.\n\n");
        return 3;
    }
    else if(menu == 11){
        printf("\t#''''''''''''''''''''''#\n");
        printf("\t|   New opening code   |\n");
        printf("\t#......................#\n\n");
        newCode(t,c);
        printf("1. Back.\n\n");
        return 1;
    }
    else if(menu == 12){
        printf("\t#''''''''''''''''''''''''#\n");
        printf("\t|   Show opening codes   |\n");
        printf("\t#........................#\n\n");
        printf("Opening codes: \n");
        printCodes(c);
        printf("1. Back.\n\n");
        return 1;
    }
    else if(menu == 21){
        printf("\t#'''''''''''''''''''''#\n");
        printf("\t|   New close phone   |\n");
        printf("\t#.....................#\n\n");
        printf("Enter new phone: \n");
        newPhone(t);
        printf("1. Back.\n\n");
        return 1;
    }
    else if(menu == 22){
        printf("\t#'''''''''''''''''''''#\n");
        printf("\t|     Show phones     |\n");
        printf("\t#.....................#\n\n");
        printf("Phones: \n");
        printPhones(t);
        printf("1. Back.\n\n");
        return 1;
    }
    else if(menu == 31){
        printf("\t#'''''''''''''''''''''#\n");
        printf("\t|      New alarm      |\n");
        printf("\t#.....................#\n\n");
        sendAlarm(t,c,id);
        printf("1. Bakåt.\n\n");
        return 1;
    }
    else if(menu == 32){
        printf("\t#''''''''''''''''''''''#\n");
        printf("\t|   Search for alarm   |\n");
        printf("\t#......................#\n\n");
        if(getAlarm(id)){
        printf("ALARM: you have been in close proximity to someone with covid-19,\n");
        printf("please contact the corona information number at +358 457 00 0000.\n");
        }
        printf("1. Back.\n\n");
        return 1;
    }
    return 0;
}
//function taken from stackoverflow, fflush did not work on linux for some reason.
//this does what fflush is supposed to do.
void clean_stdin(void){
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}
//gets and checks if the menu input is valid
int getInput(int items){
    while(true){
        int input;

        if(scanf("%d", &input) == 1){
            if(input > 0 && input < items+1){
                return input;
            }
            else{
                printf("Invalid input, try again: \n\n");
            }
        }
        else{
            printf("Invalid input, try again: \n\n");
        }
        clean_stdin();

    }
}
//function to get the user id from command line arguments
//function modified from stackoverflow
int getUser(const char* argv){
    char *c; //character pointer used by strtol
    
    errno = 0; //used for errorchecking, sometimes gives errors in vsCode?
    long conv = strtol(argv, &c, 10); //converts string to long

    // Check for errors: e.g., the string does not represent an integer
    // or the integer is larger than int
    if (errno != 0 || *c != '\0' || conv > INT_MAX || floor(log10(abs(conv)))+1 != 6 || conv < 0) {
        return -1;
    } else {
        int id = conv; //convert long to int   
        return id;
    }
}

//function to get the user id from command line arguments
//function modified from stackoverflow
unsigned int getCode(const char* argv){
    char *c; //character pointer used by strtol
    
    errno = 0; //used for errorchecking, sometimes gives errors in vsCode?
    long conv = strtol(argv, &c, 10); //converts string to long

    // Check for errors: e.g., the string does not represent an integer
    // or the integer is larger than int
    if (errno != 0 || *c != '\0' || conv > INT_MAX || floor(log10(abs(conv)))+1 != 8 || conv < 0) {
        return -1;
    } else {
        unsigned int code = conv; //convert long to int   
        return code;
    }
}

//function to get alarm from server
bool getAlarm(int id){
    char loc[18] = "coronaAlarm";
    char str[7];
    sprintf(str,"%d",id);
    strcat(loc, str);
    FILE* f = fopen(loc,"r");

    if(f != NULL){
        date d, b;
        fscanf(f, "%d-%d-%d", &d.year,&d.month,&d.day);
        b = getDateNumBefore(getTodaysDate(),21);
        if(compareDates(d, b) > 0){
            return true;
        }
        fclose(f);
    }
    return false;
}

int checkArgs(int argc, const char* argv[]){
    int id = 0;
    if(argc >= 2){
        id = getUser(argv[1]);
        if(id == -1){
            if(strcmp(argv[1], "help") == 0){
                printf("usage:\n");
                printf("corona help\t\t\t\t\tdisplay this help text\n");
                printf("corona ~userID~\t\t\t\t\tdefault usage, replace ~userID~ with your six digit user ID\n");
                printf("corona ~userID~ debug\t\t\t\tenter debug mode\n");
                printf("corona ~userID~ check\t\t\t\tchecks for alarms\n");
                printf("corona ~userID~ sick ~opening code~\t\tsends alarm, replace ~opening~ code with your opening code\n");
                printf("corona ~userID~ add ~userID2~ ~date~\t\tadds phone to phone list, replace ~userID2~ with the second user ID and ~date~ with a valid date\n");
            }
            else{
                id = 0;
                printf("Invalid input of user ID!\n");
                printf("Please input a valid user ID of six digits.\n");
            }
            exit(0);
        }
        else{
            if(argc == 2){
                printf("Welcome user %d\n\n", id);
                return id;
            }
            else if(argc == 3){
                if(strcmp(argv[2], "debug") == 0){
                    #define DEBUG
                    printf("Welcome user %d\n\n", id);
                    printf("debug on\n\n");
                    return id;
                }
                else if(strcmp(argv[2], "check") == 0){
                    table* t = createTable();
                    readToHashMap(t, id);
                    if(getAlarm(id)){
                        printf("ALARM: you have been in close proximity to someone with covid-19,\n");
                        printf("please contact the corona information number at +358 457 00 0000.\n");
                    }
                    else{
                        printf("No alarm!\n");
                    }
                    destroyHashMap(t);
                    exit(0);
                }
            }
            else if(argc == 4){
                if(strcmp(argv[2], "sick") == 0){
                    unsigned int code = getCode(argv[3]);
                    if(code != -1){
                        table* t = createTable();
                        codes* c = createCodesList();
                        readToHashMap(t, id);
                        addToCodes(c, code);
                        sendAlarm(t,c,id);
                        destroyCodes(c);
                        destroyHashMap(t);
                    }
                }
                exit(0);
            }
            else if(argc == 5){
                if(strcmp(argv[2], "add") == 0){
                    date d;
                    parseDate(&d, argv[3]);
                    int user = getUser(argv[4]);
                    if(user != -1){
                        table* t = createTable();
                        readToHashMap(t, id);
                        addItem(t, d, user);
                        printPhones(t);
                        writeHashMap(t, id);
                        destroyHashMap(t);
                    }
                    
                }
                exit(0);
            }
            else{
                exit(0);
            }          
        }
    }
    else{
        printf("No user ID\n");
        printf("Pleas input a valid user ID as a command line argument.\n");
        exit(0);
    }
    exit(0);
}