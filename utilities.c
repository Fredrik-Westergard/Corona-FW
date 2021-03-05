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
    printf("Mata in Öppningskoden på 8 siffror:\n");
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
            printf("Ogiltig inmatning, försök igen: \n\n");
        }
    }
    printf("öppningskod: %8d\n", code);
    printf("Ny kod tillagd.\n\n");
    printf("Nära telefoner de senaste 21 dagarna:\n");
    addToCodes(c, code);
    //removeTooOld(l);
    printPhones(t);
    removeOld(t);
    


    return;
}
//funtion to print the stored codes
void printCodes(codes* c){
    printf("koder:\n");
    printCodesList(c);
    return;
}

//function to add a new phone
void newPhone(table* t){
    unsigned int id;    //unsigned because it can't be negative
    bool good = false;
    date d;      //date structure

    printf("Mata in identifikationskod på 6 siffror: \n");
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
            printf("Ogiltig inmatning, försök igen: \n\n");
        }
    }
    printf("Mata in datum i YYYY-MM-DD format\n");
    while(good){
        scanf("%d-%d-%d", &d.year, &d.month, &d.day);
        clean_stdin();
        //checks if the date is valid
        if(checkDate(d)){
            good = false;
        }
        else{
            printf("Ogiltig inmatning, försök igen: \n\n");
        }
    }
    //addToList(l, id, d);
    addItem(t, d, id);
    printf("\nid: %6d\ndatum: ", id);
    printDateISO(d);
    printf("\n\n");
    printf("Ny telefon tillagd.\n");
    return;
}
//prints the phones
void printPhones(table* t){
    printf("ID\tDatum\n");
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
                printf("Alarm skickat!\n");
            }
        }
    }

    if(!temp){
        printf("Alarm misslyckades, vänligen mata in giltig öppningskod!\n");
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
        printf("\t|  Coronablinkern!  |\n");
        printf("\t#...................#\n\n");
        printf("1. Mata in öppningskod.\n");
        printf("2. Mata in identifikationskod och datum för en nära telefon.\n");
        printf("3. Skicka eller ta emot smittalarm.\n");
        printf("4. Avsluta\n\n");
        return 4;
    }
    else if(menu == 1){
        printf("\t#''''''''''''''''''''''''#\n");
        printf("\t|  Mata In Öppningskod!  |\n");
        printf("\t#........................#\n\n");
        printf("1. Ny öppningskod.\n");
        printf("2. Visa öppningskoder.\n");
        printf("3. Bakåt.\n\n");
        return 3;
    }
    else if(menu == 2){
        printf("\t#'''''''''''''''''''''''''''''''''''''''''#\n");
        printf("\t|  Mata in identifikationskod och datum   |\n");   
        printf("\t|          för en nära telefon!           |\n");
        printf("\t#.........................................#\n\n");
        printf("1. Ny nära telefon.\n");
        printf("2. Visa telefoner.\n");
        printf("3. Bakåt.\n\n");
        return 3;
    }
    else if(menu == 3){
        printf("\t#'''''''''''''''''''''''''''''''''''''#\n");
        printf("\t|   Ta skicka eller emot smittalarm   |\n");
        printf("\t#.....................................#\n\n");
        printf("1. Nytt smittalarm.\n");
        printf("2. Sök efter smittlarm.\n");
        printf("3. Bakåt.\n\n");
        return 3;
    }
    else if(menu == 11){
        printf("\t#''''''''''''''''''''#\n");
        printf("\t|   Ny öppningskod   |\n");
        printf("\t#....................#\n\n");
        newCode(t,c);
        printf("1. Bakåt.\n\n");
        return 1;
    }
    else if(menu == 12){
        printf("\t#''''''''''''''''''''''#\n");
        printf("\t|   Visa öppningskod   |\n");
        printf("\t#......................#\n\n");
        printf("Öppningskoder: \n");
        printCodes(c);
        printf("1. Bakåt.\n\n");
        return 1;
    }
    else if(menu == 21){
        printf("\t#''''''''''''''''''''#\n");
        printf("\t|   Ny Nära Telefon   |\n");
        printf("\t#.....................#\n\n");
        printf("Mata in ny nära telefon: \n");
        newPhone(t);
        printf("1. Bakåt.\n\n");
        return 1;
    }
    else if(menu == 22){
        printf("\t#''''''''''''''''''''#\n");
        printf("\t|   Visa Telefoner   |\n");
        printf("\t#....................#\n\n");
        printf("Telefoner: \n");
        printPhones(t);
        printf("1. Bakåt.\n\n");
        return 1;
    }
    else if(menu == 31){
        printf("\t#'''''''''''''''''''''#\n");
        printf("\t|   Nytt Smittalarm   |\n");
        printf("\t#.....................#\n\n");
        sendAlarm(t,c,id);
        printf("1. Bakåt.\n\n");
        return 1;
    }
    else if(menu == 32){
        printf("\t#''''''''''''''''''''''''''''#\n");
        printf("\t|   Söker efter Smittalarm   |\n");
        printf("\t#............................#\n\n");
        if(getAlarm(id)){
        printf("ALARM: Du har varit i närheten av någon med covid-19,\n");
        printf("vänligen ring coronaupplysningen för instruktioner.\n");
        }
        printf("1. Bakåt.\n\n");
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
                printf("Ogiltig inmatning, försök igen: \n\n");
            }
        }
        else{
            printf("Ogiltig inmatning, försök igen: \n\n");
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
            id = 0;
            printf("Ogiltig inmatning av användare!\n");
            printf("Mata in användar ID på sex siffror som kommandoprompt parameter.\n");
            exit(0);
        }
        else{
            if(argc == 2){
                printf("Välkommen användare %d\n\n", id);
                return id;
            }
            else if(argc == 3){
                if(strcmp(argv[2], "debug") == 0){
                    #define DEBUG
                    printf("Välkommen användare %d\n\n", id);
                    printf("debug on\n\n");
                    return id;
                }
                else if(strcmp(argv[2], "help") == 0){
                    printf("hjälp text\n");
                    exit(0);
                }
                else if(strcmp(argv[2], "check") == 0){
                    table* t = createTable();
                    readToHashMap(t, id);
                    if(getAlarm(id)){
                        printf("ALARM: Du har varit i närheten av någon med covid-19,\n");
                        printf("vänligen ring coronaupplysningen för instruktioner.\n");
                    }
                    else{
                        printf("inget alarm!\n");
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
        printf("Inget användar ID inmatat\n");
        printf("Mata in användar ID på sex siffror som kommandoprompt parameter.\n");
        exit(0);
    }
    exit(0);
}