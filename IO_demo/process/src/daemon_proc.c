#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <syslog.h>

int main(void)
{
    pid_t child1, child2;
    int i;

    /* 创建子进程1 */
    child1 = fork();
    if (child1 == 1) {
        
    }
    return 0;
}