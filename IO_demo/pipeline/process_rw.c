/**
 * 进程间的通信
 * 概念
 * 1、传统进程间通信方式
 * 无名管道、有名管道、信号
 * 
 * 2、（System V5）IPC对象通信方式
 * 共享内存、消息队列、信号灯集
 * 
 * 3、BSD套接字通信
 * 网络编程socketn通信
 * 
 * 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/types.h>

#include <unistd.h>

#define PROCESS_RW 0          // 一个进程的读写
#define PROCESS_BETWEEN_FS  1 // 一个管道读，一个管道写


int main()
{
#if PROCESS_RW == 1
    int fd[2];      // 无名管道

    int ret = pipe(fd);
    if (ret == -1) {
        perror("pipe");
        return -1;
    }
    // fd[1]写端
    write(fd[1], "hello", 5);

    char buf[100] = {0};

    // fd[0] 读端
    read(fd[0], buf, sizeof(buf));

    printf("buf = %s\n", buf);

    close(fd[0]);
    close(fd[1]);
#endif

#if PROCESS_BETWEEN_FS == 1
    // pipe
    int fd[2];

    int ret = pipe(fd);
    if (ret < 0) {
        perror("pipe\n");
        return -1;
    }

    // fork()
    pid_t pid;
    pid = fork();

    if (pid == -1) {
        perror("pid\n");
        return -1;
    } else if (pid == 0) {      // 子进程
        close(fd[0]);
        write(fd[1], "world!\n", 6);
        close(fd[1]);

    } else {                    // 父进程
        close(fd[1]);
        char buf[100] = {0};
        read(fd[0], buf, sizeof(buf));
        printf("buf = %s\n", buf);
        close(fd[0]);
    }

#endif
    return 0;
}