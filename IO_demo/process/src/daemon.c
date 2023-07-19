/**
 * （1）守护进程
 * 在linux中与用户交互的界面叫终端，从终端运行起来的程序都依赖于这个终端
 * 在终端关闭时，相应的进程都会被关闭，守护进程可以突破这个限制。
 * 
 * （2）特点：
 * 在后台服务的进程
 * 生存周期很长
 * 守护进程独立于控制终端
 * 比如：init进程pid = 1开机运行 关机才结束
 * 
 * （3）守护进程创建流程：
 * 1、创建子进程、父进程退出（摆脱父进程的控制）
 * fork(void);
 * 2、在子进程中创建新会话（摆脱终端控制，将孤儿进程独立起来）
 * setsid(void);
 * 3、修改工作目录
 * chdir("");
 * 4、修改umask(增加安全性)
 * umask();
 * 5、关闭文件描述(回收资源)
 * close();
 * 
*/

/***
 * 创建一个守护进程
*/

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <strings.h>

// #include <unistd.h>
// #include <sys/types.h>
// #include <sys/stat.h>

// #include <time.h>

// int main(int argc, const char * argv[])
// {
//     pid_t pid;
//     pid = fork();

//     if (pid == 0) {
//         setsid();       // 创建新的会话
//         chdir("./");    // 修改工作目录
//         umask(0);       // 设置文件权限掩码，增加安全性

//         close(0);       // 关闭文件描述符
//         close(1);       // 关闭文件描述符
//         close(2);       // 关闭文件描述符

//         FILE *fp = fopen("./time.txt", "a");
//         while (1) {
//             time_t t;
//             time(&t);

//             fprintf(fp, "%s", ctime(&t));

//             fflush(fp);
//             sleep(2);
//         }
//     } else {        // 父进程退出
//         exit(0);
//     }

// }

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <time.h>

int main(int argc, const char *argv[])
{
	pid_t pid;
	pid = fork();

	if(pid == 0)		//子进程
	{
		setsid();	//创建新的会话

		chdir("./");	//修改工作目录

		umask(0);	//设置文件权限掩码，增加安全性

		close(0);	//关闭文件描述符
		close(1);	//关闭文件描述符
		close(2);	//关闭文件描述符

		FILE *fp = fopen("./time.txt", "a");
		while(1)
		{
			time_t t;
			time(&t);

			fprintf(fp, "%s", ctime(&t));

			fflush(fp);

			sleep(2);
		}
	}
	else			//父进程退出
	{
    	exit(0);
	}
}
