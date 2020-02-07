#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MAXCHILD 3

void makechild(){
	int inchild=0;
	pid_t pid;
	pid=fork();
	srand(getpid());
 	int endoffor=0;
	int r = rand()%10+1;
	endoffor=sleep(r);
	for(int i=0;i<=endoffor;i++);
	printf("Message from child %d : waited for %d seconds\n",getpid(), r);

}

int main(){
pid_t child [MAXCHILD];
int inChild=0;
int status=0;
for (int i=0;i<MAXCHILD;i++){
	child[i]=fork();
	printf("this is Child[%d]\n",i);
 	if(child[i]==0){
	inChild=1;
	break;
	}
}
while (inChild==1){
 	srand(getpid());
 	int endoffor=0;
	int r = rand()%10+1;
	endoffor=sleep(r);
	for(int i=0;i<=endoffor;i++);
	printf("message from child %d : waited for %d seconds\n",getpid(), r);
	inChild=-1;
	}
while(inChild==0){
		sleep(5);
		int child_d;
		for(int j=0;j<MAXCHILD;j++){
			child_d= waitpid(child[j],&status,WNOHANG);
    		if(child_d>0){
    			printf("child[%d] is dead now \n",child[j]);
				makechild();
				inChild=1;
    		}

		}	
	}
return 0;
}