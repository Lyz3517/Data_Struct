/**
 * 僵尸进程的解决方法：wait、waitpid、信号
 * (1) pid_t wait(int *status)
 * 功能：阻塞父进程，等待任何一个子进程结束，回收资源
 * 头文件   #include <sys/types.h>
 *         #include <wait.h>
 * 参数：   status
 * 可以使用固定的宏函数实现(WIFEXITED, WEXITSTATUS)
 * WEXITSTATUS(status)获取子进程的返回值
 * WIFEXITED(status)判断子进程是否正常结束
 * 保存子进程退出时的状态或者exit函数的实参.
 * 返回值：
 * 成功：   返回退出的子进程ID
 * 失败：   返回-1
*/

/**
 * 僵尸进程/孤儿进程
 * 子进程先于父进程退出--父进程未回收资源--子进程会变成僵尸进程
 * 危害：占用进程号、内存空间、pcb进程控制块等
 * 解决:wait/waitpid/信号
 * 注意：任何进程结束都会变成僵尸进程，只是时间有长有短
 * 
 * 父进程先于子进程退出--子进程变为孤儿进程--被init进程接管(收养)
 * init进程：系统启动后运行的第一个用户进程，pid=1，会定期扫描系统，收养孤儿进程
 * 注意：孤儿进程一般没有什么危害
*/


/**
 * pid_t waitpid(pid_t pid, int *status, int option)
 * 功能: 阻塞父进程，等待子进程结束，回收资源
 * 头文件:      #include <sys/types.h>      #include <wait.h>
 * 参数:
 * pid: -1 等价于wait,回收任何一个退出的子进程资源
 *      >0 为子进程PID，表示指定要回收的子进程
 * 
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <wait.h>
#include <unistd.h>

#define WAIT_  0   // wait阻塞父进程等待任何一个子进程结束，回收资源(wait())
#define WAITPID_ 1  // 阻塞父进程，等待子进程结束，回收资源

int main(int agrc, const char* argv[])
{
#if WAIT_ == 1
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
#endif 

#if WAITPID_ == 1
    pid_t pid;
    pid = fork();
    if (pid < 0) {
        perror("fork");
        return -1;
    } else if (pid > 0) {       // 父进程
        printf("fahter wait....\n");

        // wait(NULL);      //阻塞
        waitpid(-1, NULL, WNOHANG);     // WNOHANG非阻塞
                                        // -1 所有子进程
        printf("----------------\n");
        while(1);
    } else {                    // 子进程
        sleep(5);
        exit(0);
    }
#endif
    return 0;
}
