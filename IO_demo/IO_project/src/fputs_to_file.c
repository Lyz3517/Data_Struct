#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
    FILE *fp = fopen("./1.txt", "w+");
    if (fp == NULL) {
        perror("fopen");
        return -1;
    }
    char buf[50];

    while (fgets(buf, sizeof(buf), stdin) != NULL) {
        if (strcmp(buf, "quit\n") == 0) break;
        fputs(buf, fp);
    }
    printf("success!\n");
    fclose(fp);
    return 0;
}