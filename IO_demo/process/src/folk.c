#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
    pid_t result;

    /* 调用frok函数 */
    result = fork();
    /* 通过result的值来判断fork()函数的返回情况，首先进行出错处理 */
    if (result == -1) {
        printf("Fork error!\n");
    }
    else if (result == 0) {     // 返回值为0代表子进程
        printf("The returned value is %d\n\
         In child process!\n My PID is %d\n", result, getpid());
    }
    else {
        printf("The returned value is %d\n\
        In father process!\n My PID is %d\n", result, getpid());
    }
    return result;
}