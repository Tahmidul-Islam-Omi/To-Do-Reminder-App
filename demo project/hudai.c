#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename[] = "Never_give_up_11.txt";
    FILE* fp;

    fp = fopen(filename, "w");
    fprintf(fp, "Hello&6:30\n");
    fprintf(fp, "Hi&4:45\n");
    fprintf(fp, "Coding&2:30\n");

    fclose(fp);

    fp = fopen(filename, "r");

    char temp[200];

    while(fgets(temp, 200, fp) != NULL) {

        char *token;
        token = strtok(temp, "&");

        printf("%s", token);

        printf("   ");

        token = strtok(NULL , "&");

        printf("%s",token);

    }

    fclose(fp);
    return 0;
}
