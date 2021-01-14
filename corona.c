#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int goBack(){

}

void newCode(){
    printf("new code added\n");
    return;
}

void printCodes(){
    printf("codes\n");
    return;
}

void newPhone(){
    printf("new phone added\n");
    return;
}

void printPhones(){
    printf("phones\n");
    return;
}

void sendAlarm(){
    printf("alarm sent\n");
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
    else if(menu == 4){
        exit(0);
    }
    else if(menu == 11){
        printf("\t#''''''''''''''''''''#\n");
        printf("\t|   Ny öppningskod   |\n");
        printf("\t#....................#\n\n");
        printf("Mata in öppningskod: \n");
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
        printf("Mata in ny Nära Telefon: \n");
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
        if(input > 0 || input < items){
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
        number = (number*10)+menu;
        size = printMenues(number);
        menu = getInput(size);
    }

    return 0;
}
