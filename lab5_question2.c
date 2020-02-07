#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

#define MAXCHILD 5
#define MAXIMUM 100


int main(){
    pid_t child [MAXCHILD];
    int child_process=0;
    int fd [2];
    char path[20];
    int pipe;
    int i;
    int goal_val=MAXCHILD-1;
    int max=MAXCHILD;
    int status=0;
    
    sprintf(path,"1.pipe");
    mkfifo(path,0777);
    
    char buffer[256];
		bzero(buffer,256);


    for (i=0;i<MAXCHILD;i++){
        child[i]=fork();

         if(child[i]==0){
           child_process=1;
           break;
   }
}

	
	if (child_process==1)
	{
	
		printf("child %d starts\n", i);
		pipe=open(path,O_RDWR);
	
		  while (1){
		      
		      read(pipe,buffer,255);
		      goal_val=atoi(buffer);
		      
		      printf("child %d  pipe pipevalue is: %d\n",i, goal_val );
		      
		      if (goal_val==-1)
		      {
		      	int zero=-1;
		      	sprintf(buffer,"%d", zero);
		      	write(pipe,buffer,strlen(buffer));
		      	printf("child %d reach the point\n", i);
		      	exit(0);
		      }
		      
		      else
		      {
		      	if (goal_val==i)
		      	{
		      		goal_val--;
		      		sprintf(buffer,"%d", goal_val);
		      		write(pipe,buffer,strlen(buffer));
		      	}
		      	
		      	else
		      	{
		      		sprintf(buffer,"%d", goal_val);
		      		write(pipe,buffer,strlen(buffer));
		      	}
		      
		      }

		      
		       sleep(1);
		  }
	}

		if (child_process==0)
		{
		
		pipe=open(path,O_WRONLY);
		char buff[256];
		sprintf(buff,"%d", max-1);
		write(pipe,buff,strlen(buff));
	
		  while(1){
 
		  for (int i=0; i<MAXCHILD; i++)
		  {
		  	int childd=wait(&status);
		  	
		  	if (childd==-1)
		  	{
		  		printf("finished\n");
		  		exit(0);
		  	}
		  }    
		     sleep(1);
	}
return 0;
}
}
