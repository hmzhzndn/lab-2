#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void child(){
	char str[50];
	printf("Enter your name: ");
	scanf("%s", str);
	printf("Your name is: %s", str);
	printf("\n");
	}
void parent(){
	printf("Job is done\n");
	}
int main(void){
	for(int i=0;i<4;i++){

	pid_t pid = fork();

	if(pid==0){
		child();
		exit(0);
		}
	wait(NULL);
	}
	parent();
	return EXIT_SUCCESS;
}
