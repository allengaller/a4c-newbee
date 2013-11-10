#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int f;
	const char *f_path = "test";
	mode_t f_attrib;
	struct stat *buf = malloc(sizeof(stat));
	f_attrib = S_IRUSR | S_IRGRP | S_IWGRP | S_IROTH;
	f = creat(f_path, f_attrib);
	if(f == -1){
		puts("File create failed.\n");
		return 1;
		}
	else
		puts("File create sucess.\n");
	fstat(f,buf);
	if(buf->st_mode & S_IRUSR)
		puts("The owner can read.\n");
	if(buf->st_mode & S_IRGRP)
		puts("The group can read.\n");
	close(f);
	chmod(f_path, 0771);
	stat(f_path, buf);
	if(buf->st_mode & S_IWUSR)
		puts("The owner can write.\n");
	if(buf->st_mode & S_IWGRP)
		puts("The group can write.\n");
	free(buf);
	return 0;
}
