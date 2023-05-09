/**
 * 创建一个文件
*/

#include <stdio.h>
int main(void)
{
    FILE *fp = fopen("./1.txt", "w");
    if (fp == NULL) {
        perror("fopen fair!\n");
        return -1;
    }
    printf("fopen success!\n");

    fclose(fp);         // 关闭流指针
    return 0;
}