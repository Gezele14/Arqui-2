#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>  
#include <pthread.h> 

int count = 0;
int threadNum = 0;

pthread_mutex_t lock;

void *contador(void *arg){ 
  threadNum++;
  pthread_mutex_lock(&lock);
  printf("Entrando al hilo %d\n", threadNum);
  int i = 0;
  for(i=0; i<100; i++){
    count++;
    printf("Contando por: %d\n",count);
  }

  printf("Saliendo del hilo %d\n", threadNum);
  pthread_mutex_unlock(&lock);

}

int main(){ 
  int i = 0;
  pthread_t thread; 
  for(i=0;i<2; i++){
    pthread_create(&thread, NULL, contador, NULL);
    pthread_join(thread, NULL); 
  }

  exit(0); 
}