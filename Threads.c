#include <pthread.h>
#include <stdio.h>

void *threadSafe(void *args) {
  int *threadId = (int *)args;
  printf("Hello from Thread: %d\n", *threadId);
}

int main() {
  
  int i, j;
  int NUM_THREADS = 10;
  pthread_t threads[NUM_THREADS];

  for(i = 0; i < NUM_THREADS; i++) {
    pthread_create(&threads[i], NULL, threadSafe, (void *)&i);
  }

  for(int j = 0; j < NUM_THREADS; j++) {
    pthread_join(threads[j], NULL);
  }

  pthread_exit(NULL);

  return 0;
}