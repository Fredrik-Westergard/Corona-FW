#include <stdio.h>

int main(int argc, char const *argv[])
{
    int id, code;
    printf("Enter ID: ");
    scanf("%d", &id);
    printf("Enter opening code: ");
    scanf("%d", &code);

    FILE* f = fopen("openingCodes", "ab+");

    fprintf(f,"%d - %d\n", id, code);

    fclose(f);

    return 0;
}
