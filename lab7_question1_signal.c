
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
// "handler1" is handler function for action1
int c=0;
void handler1(int signo){
switch(signo){
case SIGINT:
printf("Interrupt Signal received \n");
c++;
break;
}
}
int main()
{
while(1){
//initializing sigaction structure
struct sigaction action1;
action1.sa_handler = handler1;
action1.sa_flags = 0;
sigaction(SIGINT,(struct sigaction *) &action1,NULL);
//runnign forever, while process is sensitive to SIGINT
if(c==5){
	break;
}
}
return 0;
}