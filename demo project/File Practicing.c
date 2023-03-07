#include<stdio.h>

int main() {
    FILE *fp;

    char filename[] = "Random_File.txt";

    fp = fopen(filename , "w");

    char str[];
    fgetc(str);

    fprintf(fp, str);
    fclose(fp);

    return 0;

}
