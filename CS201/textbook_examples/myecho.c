#include "stdio.h"
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[], char *envp[]) {

	int i = 0;
	pid_t forkID = fork();

	if ( forkID > 0 ) {
		while ( argv[i] != NULL ) {
			printf("argv[%d] = %s\n", i, argv[i++]);
		}
	} else {
		while ( envp[i] != NULL ) {
			printf("envp[%d] = %s\n", i, envp[i++]);
		}
		exit(0);
	}
	waitpid(-1, NULL, 0);

	return 0;
}
