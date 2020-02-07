#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>

#define MAX_CHILD 5

int main(){
	int fd[MAX_CHILD][2];
	int v=100,i,which;
	int total=0;
	int Chile_process=0;
	char buffer[256];
	int mypipe[MAX_CHILD];
	pid_t pid[MAX_CHILD];
	char parent_buffer[256];

	for(i=0;i<MAX_CHILD;i++){

		mypipe[i]=pipe(fd[i]);
		pid[i]=fork();
		
		//which=i;

		if(pid[i]==0){
			Chile_process=1;
			break;
		}

	}

	while(Chile_process==1)
	{
		close(fd[i][0]);
		srand(time(NULL)+getpid());
        int myrandnum= rand()%10+1;
		printf("in child and i is %d and myrandnum is %d\n",i,myrandnum);

		sprintf(buffer,"%d", myrandnum);
		printf("%s\n",buffer);
        write(fd[i][1],buffer,255);
        printf("pass write\n");
        sleep(myrandnum);
	}

	while(Chile_process==0){
		//close(fd[i][1]);
		for(int k=0;k<MAX_CHILD;k++){
			close(fd[i][1]);
			if(read(fd[k][0],buffer,255)>0)
            {
              total+=atoi(buffer);
              printf("the total is %d \n", total);

    			sleep(1);
            }

        }

        if (total>30)
            {
              	printf("now total is %d\n", total);
              		 kill(0, SIGKILL);
                printf("process is killed\n");
                //sleep(1);
              	}
               
            }
	
	

    return 0;
}

