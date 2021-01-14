#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

struct date{
    int day;
    int month;
    int year;
};

//fuction to check wether a date is valid
bool checkDate(struct date d){
    //checks if the month is valid
    if(d.month > 0 && d.month < 13){
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
    return false;
}
//function to input new opening code
void newCode(){
    unsigned int code;  //unsigned because it can't be negativce
    bool good = false;
    printf("Mata in Öppningskoden på 8 siffror:\n");
    while(!good){
        scanf("%d%*c", &code);
        fflush(stdin);
        //floor returns the largest value that's less than or equal to the parameter,
        //log10 returns the common log in base 10 of the parameter
        //abs returns the absolute value
        //checks wether code has 8 digits
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
//funtion to print the codes stored
void printCodes(){
    printf("koder.\n");
    return;
}
//function to add a new phone
void newPhone(){
    unsigned int id;
    bool good = false;
    struct date d;

    printf("Mata in identifikationskod på 6 siffror: \n");
    while(!good){
        scanf("%d%*c", &id);
        fflush(stdin);
        if(floor(log10(abs(id)))+1 == 6){
            good = true;
        }
        else{
            printf("Ogiltig inmatning, försök igen: \n\n");
        }
    }
    printf("Mata in datum i YYYY-MM-DD format\n");
    while(good){
        scanf("%d-%d-%d%*c", &d.year, &d.month, &d.day);
        fflush(stdin);
        if(checkDate(d)){
            good = false;
        }
        else{
            printf("Ogiltig inmatning, försök igen: \n\n");
        }
    }
    printf("id: %6d\ndatum: %04d-%02d-%02d\n", id, d.year, d.month, d.day);
    printf("Ny telefon tillagd.\n");
    return;
}

void printPhones(){
    printf("telefoner.\n");
    return;
}

void sendAlarm(){
    printf("Alarm skickat.\n");
    return;
}


//Prints the menues
int printMenues(int menu){
    int num = 0;
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

int getInput(int items){
    int input;

    while(true){
        scanf("%d%*c", &input);
        fflush(stdin);
        if(input > 0 && input < items+1){
            return input;
        }
        else{
            printf("Ogiltig inmatning, försök igen: \n\n");
        }
    }
}

int main(int argc, char const *argv[]){
    bool running = true;
    int number = 0;
    int size = printMenues(0);
    int menu = getInput(size);

    while(running){
        if(size == menu){
            if(number == 0){
                exit(0);
            }
            number = number/10;
        }
        else{
            number = (number*10)+menu;
        }
        printf("%d\n", number);
        size = printMenues(number);
        menu = getInput(size);
    }

    return 0;
}
