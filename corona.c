#include <stdio.h>

//Prints the menu
void printMenu(){
    printf("\t#'''''''''''''''''''#\n");
    printf("\t|  Coronablinkern!  |\n");
    printf("\t#...................#\n\n");
    printf("1. Mata in öppningskod\n");
    printf("2. Mata in identifikationskod och datum för en nära telefon\n");
    printf("3. Ta emot smittalarm\n\n");

    return;
}

int main(int argc, char const *argv[])
{
    
    printMenu();

    return 0;
}
