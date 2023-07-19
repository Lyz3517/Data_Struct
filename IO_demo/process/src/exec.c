/**
 * exec函数族
 * (1)概念
 * 函数族提供了一种在进程中启动另一个程序执行的方法
 * 它可以根据指定的文件名或目录名找到可执行文件，并用它来取代原调用进程的数据段、代码段和堆栈段
 * 在执行之后，原调用进程的内容除了进程号外，其他的全部被新的程序的内容替代了。
 * 另外这里的可执行文件是二进制文件，也可以是Linux下任何可执行脚本文件。
 * 
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>

int main(int argc, const char* argv[])
{
    int ret = execl("/bin/ls", "ls", "-l", NULL);
    if (ret == -1) {
        perror("execl!\n");
        return -1;
    }
    printf("------->\n");
    
    return 0;
}