#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


/**
 * fork函数特性：
 * 1、子进程创建时，几乎拷贝了父进程全部内容，包括代码段、数据段、堆栈段、文件描述符、虚拟地址空间
 * 2、同一个父进程创建的子进程都是属于同一个进程组pkill -9 -g PGID
 * 3、进程是管理资源的最小单位
*/

#define ALTER_FOEK  0     // 父进程和子进程交替进行
#define PRINT_FORK  0     // 打印父进程与子进程
#define ALTER_FOEKS  0   // 父进程和子进程交替进行打印
#define DOUBLE_FORKS 1      // 会创建多少进程以及进程之间的关系是什么样的。
int main(void)
{
#if ALTER_FOEK == 1
    printf("开始创建进程！\n");

    pid_t pid;      // 进程号
    fork();         // 创建进程
    while(1) {
        printf("abc\n");
        sleep(1);
    }
    return 0;
#endif

#if PRINT_FORK == 1
    printf("开始创建进程!\n");
    pid_t result;
    result = fork();
    if (result == -1) {
        printf("fork process is fair!\n");
        return -1;
    } else if (result == 0) {
        printf("fork process is sucess!\n\
        In child process, value is %d\n My Pid is %d\n", result, getpid());
    } else {
        printf("fork process is sucess!\n\
        In father process, value is %d\n My Pid is %d\n", result, getpid());
    }

#endif

#if ALTER_FOEKS == 1
    printf("开始创建进程!\n");
    pid_t result;
    result = fork();
    if (result == -1) {
        printf("fork is fair!\n");
        return -1;
    } else if (result == 0) {
        while (1) {
            printf("child's process is runing!\n\n");
            sleep(3);
        }
    } else {
        while (1) {
            printf("father's process is runing!\n\n");
            sleep(3);
        }
    }
/* 运行结果：每三秒打印子进程和父进程，父进程和子进程先后顺序随机 */
#endif

#if DOUBLE_FORKS == 1
    printf("开始创建fork!\n");
    pid_t result1;
    result1 = fork();
    if (result1 == -1) {
        printf("fork is error!\n");
        return -1;
    } else if (result1 > 0) {
        printf("pid1 = %d\n", getpid());
    } else {
        printf("pid2 = %d\n", getpid());
    }

    printf("********1*******\n");
    pid_t result2;
    result2 = fork();
    if (result2 == -1) {
        printf("fork is error!\n");
        return -1;
    } else if (result2 > 0) {
        printf("pid3 = %d\n", getpid());
    } else {
        printf("pid4 = %d\n", getpid());
    }
    printf("********2*******\n");
/**
 * 运行结果：创建4个进程，类似二叉树，
 * pid1 = 13038
 * pid3 = 13038
 * pid4 = 13040
 * 
 * pid2 = 13039
 * pid3 = 13039
 * pid4 = 13041
*/
#endif
    return 0;

}