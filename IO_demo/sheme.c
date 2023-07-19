/**
 * ftok(const char *pathname, int project_id);
 * 头文件： #include <sys/types.h>  #include <sys/ipc.h>
 * 
 * void *memcopy(void *destin, void *source, unsigned n);
 * 头文件   #include<string.h>
 * 参数：   destin: 目标地址
 *         source: 源地址
 *         n:       数据长度
 * 
*/



#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 2048

#define SHEME_ONE   0   // 创建一个共享内存地址
#define SHEME_FROK 0   // 
#define SHEME_ALL   1   // 父子进程

int main(const int argc, const char * argv[])
{
#if SHEME_ONE == 1
    int shmd;
    shmd = shmget(IPC_PRIVATE, 125, 0777);
    if (shmd < 0 ){
        perror("shmget is fair!\n");
        return 0;
    } else {
        printf("shmget is success!\n");
    }
    system("ipcs -m");
#endif


#if SHEME_FROK == 1
    int shaid;
    int key;
    key = ftok("./a.c", 'a');
    if (key < 0 ){
        printf("creat key failure!\n");
        return -1;
    }
    printf("create key is successful key = %d\n", key);
    shaid = shmget(key, 128, IPC_CREAT|0777);
    if (shaid < 0) {
        printf("create share memory failure!\n");
        return -1;

    } else {
        printf("craete is successful!\n");
    }
    system("ipcs -m");
#endif


#if SHEME_ALL == 1
    pid_t pid;
    int shmid;
    char *shm_addr;
    char flag[] = "WROTE";
    char *buf;

    /* 创建共享内存 */
    if ((shmid = shmget(IPC_PRIVATE, BUFFER_SIZE, 0666)) < 0) {
        perror("shmget");
        return -1;
    }
#endif
    return 0;
}