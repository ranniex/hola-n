#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NTHREADS 50000


void *do_nothing(void*);

int main(int argc, char *argv[]) {
	pthread_t tid;
	int j;

	for (j = 0; j < NTHREADS; j++) {
		pthread_create(&tid, NULL, do_nothing, NULL);
		pthread_join(tid, NULL);
	}
	printf("mensaje desde el main\n");
	return 0;
}

void *do_nothing(void *null) {
	printf("mensaje desde el hilo\n");
	pthread_exit(NULL);
}            
