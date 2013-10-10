
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main()
{
#if 0
    FILE *fp = NULL;
    char pBuf[20] = "Hello Linux!";
    int ret = 0;

    //test write
    if(NULL == (fp = fopen("/sys/class/davinci_display/ch0/output","wb"))){
        printf("Failed to open file. %s %d\n",__FUNCTION__,__LINE__);
    }
    fseek(fp,0L,0);
    if(0 == (ret =  fwrite(pBuf,sizeof(pBuf),1,fp))){
        printf("Failed to write file, %s %d\n",__FUNCTION__,__LINE__);
    }
    else
    {
        printf("write success!\n");
	printf("ret = %d\n",ret);
    }

     if(0 == fwrite("Hello world!",13,1,fp)){
          printf("Failed to write file, %s %d\n",__FUNCTION__,__LINE__);
      }
    char c='c';
    fwrite(&c,1,1,fp);
   
    fclose(fp);
    usleep(2000);

    //test read
    if(NULL == (fp = fopen("/sys/class/davinci_display/ch0/output","rb"))){
        printf("Failed to open file.\n");
    }
    //fseek(fp,0L,0);
    rewind(fp);
    char tmp;
    if(feof(fp)){
        printf("file is empty!\n");
    }
    while(!feof(fp)){
        tmp = fgetc(fp);
        putchar(tmp);
	printf("%c ",tmp);		
    } 
    fclose(fp);

    printf("test OK\n");
    return 0;
#else
	int fd;
	char *p = "Hello world";
	int cnt;

	fd = open("/sys/class/davinci_display/ch0/output", O_WRONLY);
	if (fd < 0) {
		printf("Failed to open file\n");
		exit(1);
	}

	if ((cnt = write(fd, p, strlen(p) + 1)) != (strlen(p) + 1)) {
		printf("Failed to write, cnt = %d, %s\n", cnt, strerror(errno));
		close(fd);
		exit(1);
	}
	printf("Write success, cnt = %d\n");

	close(fd);

	fd = open("/sys/class/davinci_display/ch0/output", O_RDONLY);
	if (fd < 0) {
		printf("Failed to open file\n");
		exit(1);
	}
	lseek(fd, 0, SEEK_SET);

	char buf[16] = {0};

	if ((cnt = read(fd, buf, 15)) < 0) {
		printf("Failed to read,cnt = %d\n", cnt);
		close(fd);
		exit(1);
	}
	buf[15] = '\0';

	printf("Read Success, data:%s(count = %d)\n", buf, cnt);

	close(fd);
	exit(0);	
#endif
}

