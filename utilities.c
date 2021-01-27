#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "utilities.h"

//fuction to check whether a date is valid
bool checkDate(struct date d){
    //epoch time variable
    time_t t = time(NULL);
    //time struture for getting day/month/year
    struct tm tm = *localtime(&t);

    //checks if the year is between 1970 and current year
    if(d.year >= 1970 && d.year <= tm.tm_year+1900){
        //checks if it's the current year + month and if the date is under or equal to todays date
        if((d.year == tm.tm_year+1900 && d.month == tm.tm_mon+1) && (d.day > 0 && d.day <= tm.tm_mday)){
            return true;
        }
        //checks if it's a valid month
        if(d.month > 0 && d.month < 13){
            //checks if it's current year, if it's current month and the day is after today or if the month is after current month
            if((d.year == tm.tm_year+1900)&&((d.month == tm.tm_mon+1 && d.day > tm.tm_mday)||(d.month > tm.tm_mon+1))){
                return false;
            }
            //checks if it's february
            if(d.month == 2){
                //checks if it's a leap year
                if(((d.year%4==0) && (d.year%100 != 0)) || (d.year%400 == 0)){
                    //checks if it's between feb 1-29
                    if(d.day > 0 && d.day < 30){
                        return true;
                    }
                }
                //checks if it's between feb 1-28
                else if(d.day > 0 && d.day < 29){
                    return true;
                }         
            }
            //checks if it's a month with 31 days in it
            else if(d.month ==  4 || d.month == 6 || d.month == 9 || d.month == 11){
                //checks if it's between 1-31st
                if(d.day > 0 && d.day < 31){
                    return true;
                }
            }
            //otherwise it checks if it's between 1 and 31
            else if(d.day > 0 && d.day < 32){
                return true;
            }      
        }
    }
    return false;
}
//function to input new opening code
void newCode(){
    unsigned int code;  //unsigned because it can't be negativce
    bool good = false;  
    printf("Mata in Öppningskoden på 8 siffror:\n");
    while(!good){
        scanf("%d", &code);
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

    printf("Ny kod tillagd.\n");
    return;
}
//funtion to print the stored codes
void printCodes(){
    printf("koder.\n");
    return;
}
//function to add a new phone
void newPhone(){
    unsigned int id;    //unsigned because it can't be negative
    bool good = false;
    struct date d;      //date structure

    printf("Mata in identifikationskod på 6 siffror: \n");
    while(!good){
        scanf("%d", &id);
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
    printf("\nid: %6d\ndatum: %04d-%02d-%02d\n\n", id, d.year, d.month, d.day);
    printf("Ny telefon tillagd.\n");
    return;
}

//function to print the stored phones
void printPhones(){
    printf("telefoner.\n");
    return;
}

//function to send an alarm
void sendAlarm(){
    printf("Alarm skickat.\n");
    return;
}


//Prints the menus
int printMenues(int menu){
    //the number of choices in the menu
    int num = 0;
    
    //checks if the menu number corresponds with the choice number
    //tried to make it as dynamic as possible
    if(menu == 0 || menu == 13 || menu == 23 || menu == 32 || 
        menu == 111 || menu == 121 || menu == 211 || menu == 221 || menu == 311){

        printf("\t#'''''''''''''''''''#\n");
        printf("\t|  Coronablinkern!  |\n");
        printf("\t#...................#\n\n");
        printf("1. Mata in öppningskod.\n");
        printf("2. Mata in identifikationskod och datum för en nära telefon.\n");
        printf("3. Ta emot smittalarm.\n");
        printf("4. Avsluta\n\n");
        num = 4;
    }
    else if(menu == 1){
        printf("\t#''''''''''''''''''''''''#\n");
        printf("\t|  Mata In Öppningskod!  |\n");
        printf("\t#........................#\n\n");
        printf("1. Ny öppningskod.\n");
        printf("2. Visa öppningskoder.\n");
        printf("3. Bakåt.\n\n");
        num = 3;
    }
    else if(menu == 2){
        printf("\t#'''''''''''''''''''''''''''''''''''''''''#\n");
        printf("\t|  Mata in identifikationskod och datum   |\n|");   
        printf("\t|          för en nära telefon!           |\n");
        printf("\t#.........................................#\n\n");
        printf("1. Ny nära telefon.\n");
        printf("2. Visa telefoner.\n");
        printf("3. Bakåt.\n\n");
        num = 3;
    }
    else if(menu == 3){
        printf("\t#''''''''''''''''''''''''#\n");
        printf("\t|   Ta emot smittalarm   |\n");
        printf("\t#........................#\n\n");
        printf("1. Nytt smittalarm.\n");
        printf("2. Bakåt.\n\n");
        num = 2;
    }
    else if(menu == 11){
        printf("\t#''''''''''''''''''''#\n");
        printf("\t|   Ny öppningskod   |\n");
        printf("\t#....................#\n\n");
        newCode();
        printf("1. Bakåt.\n\n");
        num = 1;
    }
    else if(menu == 12){
        printf("\t#''''''''''''''''''''''#\n");
        printf("\t|   Visa öppningskod   |\n");
        printf("\t#......................#\n\n");
        printf("Öppningskoder: \n");
        printCodes();
        printf("1. Bakåt.\n\n");
        num = 1;
    }
    else if(menu == 21){
        printf("\t#''''''''''''''''''''#\n");
        printf("\t|   Ny Nära Telefon   |\n");
        printf("\t#.....................#\n\n");
        printf("Mata in ny nära telefon: \n");
        newPhone();
        printf("1. Bakåt.\n\n");
        num = 1;
    }
    else if(menu == 22){
        printf("\t#''''''''''''''''''''#\n");
        printf("\t|   Visa Telefoner   |\n");
        printf("\t#....................#\n\n");
        printf("Telefoner: \n");
        printPhones();
        printf("1. Bakåt.\n\n");
        num = 1;
    }
    else if(menu == 31){
        printf("\t#'''''''''''''''''''''#\n");
        printf("\t|   Nytt Smittalarm   |\n");
        printf("\t#.....................#\n\n");
        printf("Skickar smittalarm.\n");
        sendAlarm();
        printf("1. Bakåt.\n\n");
        num = 1;
    }

    return num;
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