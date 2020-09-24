// Numbers from command line arguments are sent to child process
// from parent process one at a time through pipe.
//
// Child process adds up numbers sent through pipe.
//
// Child process returns sum of numbers to parent process.
//
// Parent process prints sum of numbers.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
	int pipe_path[2];
	pid_t sum_proc;

	pipe(pipe_path);
	
	printf("CS201 - Assignment 3 Premium - Blake Eakin\n");

	if ((sum_proc = fork()) == -1) {
		perror("fork error.");
		exit(1);
	}


	if ( sum_proc == 0 ) {
		// -- running in child process --
		int sum = 0;
		int in_recv = 0;

		close(pipe_path[1]);

		while( read(pipe_path[0], &in_recv, 4) ) {
			sum += in_recv;
		}

		return sum;
		}
	else {
		// -- running in parent process --
		int sum = 0;
		int stat;

		close(pipe_path[0]);
		
		for ( int i = 1; i < argc; ++i ) {
			int in = atoi(argv[i]);

			write(pipe_path[1], &in, 4); 
		}

		close(pipe_path[1]);

		waitpid(sum_proc, &stat, 0);
		sum = (char)WEXITSTATUS(stat);

		printf("sum = %d\n", sum);
		return 0;
		}
}
