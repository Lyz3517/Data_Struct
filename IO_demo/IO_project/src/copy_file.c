#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    FILE *fp1 = fopen("a.txt", "r");
    if (fp1 == NULL) {
        perror("fopen a.txt fail!\n");
        return -1;
    }
    FILE *fp2 = fopen("b.txt", "w");
    if (fp2 == NULL) {
        perror("fopen b.txt fail!\n");
        return -1;
    }
     
    char buf[100];
    while ( fgets(buf, sizeof(buf), fp1) != NULL ) {
        fputs(buf, fp2);
    }

    printf("copy success!\n");

    fclose(fp1);
    fclose(fp2);

    return 0;
}