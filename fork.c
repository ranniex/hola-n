#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#define NFORKS 50000

void do_nothing() {
	int i;
	printf("mensaje desde el hijo\n");
	i= 0;
}

int main(int argc, char *argv[]) {
	int pid, j, status;

	for (j=0; j<NFORKS; j++) {

		/*** error handling ***/
		if ((pid = fork()) < 0 ) {
			printf ("fork failed with error code= %d\n", pid);
			exit(0);
		}

		/*** this is the child of the fork ***/
		else if (pid ==0) {
			do_nothing();
			exit(0);
		}

		/*** this is the parent of the fork ***/
		else {
			waitpid(pid, &status, 0);
		}
	}
}  

