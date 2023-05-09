/**
 * 僵尸进程的解决方法：wait、waitpid、信号
 * (1) pid_t wait(int *status)
 * 功能：阻塞父进程，等待任何一个子进程结束，回收资源
 * 头文件   #include <sys/types.h>
 *         #include <wait.h>
 * 参数：   status
 * 保存子进程退出时的状态或者exit函数的实参.
 * 返回值：
 * 成功：   返回退出的子进程ID
 * 失败：   返回-1
*/



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <wait.h>
#include <unistd.h>

#define WAIT__  0   // wait阻塞父进程等待任何一个子进程结束，回收资源(wait())
#define WAITPID_ 1  // 阻塞父进程，等待子进程结束，回收资源
int main(int agrc, const char* argv[])
{
    pid_t pid;
    pid = fork();

    if (pid < 0) {
        perror("fork");
        return -1;
    } else if (pid > 0) {
        printf("father wait...\n");

        int status;

        wait(&status);

        printf("%d %d\n", WEXITSTATUS(status), WIFEXITED(status));
        printf("---------------------->\n");
        while(1);
    } else {
        sleep(5);
        exit(0);
    }
    return 0;
}
