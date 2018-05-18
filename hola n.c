#include <pthread.h>
#include <stdio.h>
#define NTHREADS 50


void* hola(void*);

int main(int argc, char *argv[]) {
	pthread_t tid;
	int j;

	for (j = 0; j < NTHREADS; j++) {
		pthread_create(&tid, NULL, hola, NULL);
	}
	return 0;
}

void* hola(void *null) {
	printf("hola n = %u\n", (unsigned int)pthread_self());
	pthread_exit(NULL);
}            

