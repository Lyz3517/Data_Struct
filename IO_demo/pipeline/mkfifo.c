/**
 * 有名管道：
 * 
 * 
 * api接口
 * int mkfifo(const char * filename, mode_t mode);
 * 
 * 头文件
 * #include <sys/types.h>
 * #include <fcntl.h>
 * #include <unistd.h>
 * 
 * 参数：
 * filename： 要操作的管道文件名（包括i路径）
 * mode：     8进制的权限 xxxx
 * 返回值：
 * 成功：返回0
 * 失败：返回-1
 * 
 * 注意：
 * 1、有名管道文件的数据交互在内核之中，本地磁盘文件并没有数据
 * 2、有名管道的读进程结束，写进程写入数据会终止程序运行
 * 3、有名管道的写进程结束，读进程会一直运行，读到0知道数据
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define RELATIONSHIP_PROCESS    1  // 亲缘进程
#define NO_RELATIONSHIP_FIFIO_WRITE 1 // 非亲缘进程写
#define NO_RELATIONSHIP_FIFIO_READ  1 // 非亲缘进程读

int main(int agrc, const char * agrv[])
{
#if RELATIONSHIP_PROCESS == 1
    int ret = mkfifo("f1", 0666);
    if (ret < 0) {
        perror("mkfifo");
        return -1;
    }

    pid_t pid;
    pid = fork();
    if (pid < 0) {
        perror("fork");
        return -1;
    } else if(pid == 0) {       // 子进程
        int fd = open("f1", O_WRONLY);
        write(fd, "hello\n", 6);
        close(fd);
    } else {                    // 父进程
        int fd = open("f1", O_RDONLY);
        char buf[100] = {0};
        read(fd, buf, sizeof(buf));
        printf("buf = %s", buf);
        close(fd);
    }
#elif NO_RELATIONSHIP_FIFIO_WRITE == 1

#elif NO_RELATIONSHIP_FIFIO_READ == 1



#endif
    return 0;
}