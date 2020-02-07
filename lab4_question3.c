#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/time.h> //gettimeofday
#include <time.h> //time
#include <sys/stat.h>

int main(){

	int myflag;
	char buf[256];
	int status=0;
	char myinput1[256];
	char myinput2[256];
	printf("enter first command\n");
	scanf("%s",myinput1);
	printf("enter second command that you want to replace\n");
	scanf("%s",myinput2);
	struct timeval start,stop;
	srand(time(NULL));
	gettimeofday(&start,NULL);
	sleep(rand()%10);
	pid_t pid;
	pid=fork();
	int inChild=0;
	if(pid==0)
	{
		execl(".",myinput2,myinput1);
		inChild=1;
	}
	if (pid!=0)
	{
		myflag=wait(&status);
		if(myflag>0){
			gettimeofday(&stop,NULL);
			long sec=stop.tv_sec-start.tv_sec;
			float m1=start.tv_usec;
			float m2=stop.tv_usec;
			long elapsed = sec*1000+(m2-m1)/1000;
			printf("%ld\n",elapsed);
			sprintf(buf,"%ld",elapsed);
			int openFile=open("n.txt",O_CREAT | O_TRUNC| O_RDWR,00777);
			write(openFile,buf,strlen(buf));
			
		}
	}

	
	/*while(inChild==0)
	{
		printf("this is parent\n");
		sleep(1);
	}
	while(inChild==1)
	{
		printf("this is Child\n");
		sleep(1);
	}*/



}