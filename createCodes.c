#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

//function taken from stackoverflow, fflush did not work on linux for some reason.
//this does what fflush is supposed to do.
void clean_stdin(void){
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

int main(int argc, char const *argv[])
{
    int id;
    unsigned int code;
    bool good = false;

    while(!good){
        printf("Enter ID: ");
        scanf("%d", &id);
        if(floor(log10(abs(id)))+1 == 6){
            good = true;
        }
        else{
            clean_stdin();
            printf("ERROR: wrong ID. Try again:\n");
        }
    }
    while(good){
        printf("Enter opening code: ");
        scanf("%u", &code);
        if(floor(log10(abs(code)))+1 == 8){
            good = false;
        }
        else{
            clean_stdin();
            printf("ERROR: wrong opening code. Try again:\n");
        }
    }
    

    FILE* f = fopen("openingCodes", "ab+");

    fprintf(f,"%d - %d\n", id, code);

    fclose(f);

    return 0;
}
