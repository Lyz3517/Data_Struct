#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

/**
 * 相关考点概念：
 * 僵尸进程：子进程先于父进程结束，父进程没有回收子进程资源
 * 孤儿进程：父进程先于子进程结束，子进程被系统init.d托管
*/

#define EXIT_FUN   0    // 结束进程，并且刷新缓冲区
#define _EXIT_FUN  1    // 结束进程，不会刷新缓冲区

void eixt_fun()
{
    printf("cccc");
#if EXIT_FUN == 1
    exit(0);        // 结束进程 c库函数 刷新缓冲区
#elif _EXIT_FUN == 1
    _exit(0);       // 结束进程 系统调用 不会刷新缓冲区
#endif
}


int main(int argc, const char * argv[])
{
#if EXIT_FUN == 1
    printf("aaaa\n");

    eixt_fun();

    printf("bbbb\n");
/**
 * 运行结果：aaaa
 *         cccc
*/
#endif

#if _EXIT_FUN == 1
    printf("aaaa\n");

    eixt_fun();

    printf("bbbb\n");
/**
 * 运行结果：aaaa
*/
#endif
    return 0;
}