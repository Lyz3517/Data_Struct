#include <stdio.h>
#include <string.h>

//#define __STDIN__       // 测试stdin stdout stderr
//#define __ADDTO__       // 追加测试
//#define __WRITE__       // 向一个文件写入内容
//#define __TESTHANG__      // 测试行缓冲
//#define __STDERR___       // 测试无缓存
//#define __FULLBUFF__        // 全缓冲
#define __GETLINE__         // 使用fgets计算文件有多少行

int main(void)
{
#ifdef __STDIN__
    FILE *fp = fopen("./1.txt", "r");
    if (NULL == fp) {
        perror("fopen fail!\n");
        return -1;
    }

    char n = fgetc(fp);

    printf("n = %c\n", n);

    printf("len = %d\n", fp->_IO_buf_end - fp->_IO_buf_base);
    printf("fopen success!\n");
    fclose(fp);
    fputc(fgetc(stdin), stdout);
    fputc('\n', stdout);
    return 0;
#endif
#ifdef __ADDTO__
    FILE *fp = fopen("./1.txt", "r+");
    if (fp == NULL) {
        perror("fopen fail!\n");
        return -1;
    }

    printf("%c\n", fgetc(fp));

    int i = 0;

    for (int i = 0; i < 10; i++) {
        fputc('a', fp); 
    }

    printf("fopen success!\n");
    fclose(fp);
    return 0;           // 关闭流指针
#endif

#ifdef __WRITE__
    FILE *fp = fopen("./2.txt", "w");
    if (fp == NULL) {
        perror("fopen fail!\n");
        return -1;
    }

    fputc('x', fp);
    fputc('\n', fp);

    fputc('b', fp);
    fputc('\n', fp);

    fclose(fp);

#endif

/**
 * 缓冲区：行缓冲、无缓冲、全缓冲
 * printf、stdin、stdout是行缓冲，缓冲区大小为1024byte
 * 1.一行满了 或遇到’\n’输出条件
 * 2.fflush可以强制刷新
 * 3.文件关闭的时候 fclose(stdout) exit return
*/

#ifdef __TESTHANG__
    // 行缓冲：只有当遇见'\n'时，才刷新缓存区
    printf("hello world!");     // '\n'
    printf("line size = %d\n", stdout->_IO_buf_end - stdout->_IO_buf_base);

    int i = 0;
    for (i = 0; i <= 1024; i++) {
        fputc('a', stdout);
    }
    printf("%d", i);

    while(1);

#endif

#ifdef __STDERR___
    // 无缓冲：stderr
    fputc('a', stdout);
    fputc('b', stdout);
    fputc('\n', stdout);	
    // fputc('a', stderr);	//：a
	// fputc('b',stderr);	//：b
    while (1);
#endif

#ifdef __FULLBUFF__
    FILE *fp = fopen("./1.txt", "w");
    if (fp == NULL) {
        perror("fopen fail!\n");
        return -1;
    }

    int i = 0;
    for (int i = 0; i < 4097; i++) {    // 当缓存区4096之后满了将数据存储到缓存区去
                // 1.txt内容打印
        fputc('a', fp);
    }
    while (1);
/*
*   运行结果：当全缓存没满时，数据不会打印到缓存区，占满才会放入1.txt中
*/
#endif

#ifdef __GETLINE__
    /*fgets用法，判断文件有多少行*/
    FILE *fp = fopen("./1.txt", "r");
    if (fp == NULL) {
        perror("fopen fail!\n");
        return -1;
    }

    char buf[100];
    int cnt = 0;
    while (1)
    {
        char *p = fgets(buf, sizeof(buf), fp);
        if (p ==  NULL) {
            perror("fgets fail\n");
            break;
        }
        printf("p = %s", p);
        memset(buf, 0, sizeof(buf));
        cnt++;
    }
    printf("cnt = %d\n", cnt);
    fclose(fp);         // 关闭流指针
/*
运行结果：计算文件有多少行
*/
#endif

    return 0;
}