#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char * argv[])
{
    struct stat info;               // 结构体用来获取指定路径的文件或文件夹的信息
    bzero(&info, sizeof(info));

    if (argc != 2) {        // 判断输入参数是否正确
        perror("输入格式错误!用法:<文件>\n");
        exit(0);
    }

    FILE *src = fopen(argv[1], "w");        // 标准IO获取指定文件的文件指针
    if (src == NULL) {                      // 获取失败，返回NULL
        perror("打开文件失败!\n");
        exit(0);
    }
    while (1) {
        fwrite("a", 1, 1, src);
        stat(argv[1], &info);
        if (info.st_size > 0) break;
    }
    printf("缓冲区大小： %ld\n",info.st_size);	
	fclose(src);						//关闭指定的文件并释放其资源
    return 0;
}