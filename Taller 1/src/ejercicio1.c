#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>  
#include <pthread.h> 


u_int8_t Arr1[10];
u_int8_t Arr2[10];


void *arreglo1(void *Arr){  
  int i = 0; 
  u_int8_t num = 0;
  for(i=0; i<10; i++){
    num = rand()%256;
    Arr1[i] = num;
    sleep(0.001);
  }
  return NULL; 
} 

void *arreglo2(void *Arr){ 
  int i = 0; 
  u_int8_t num = 0;
  for(i=0; i<10; i++){
    num = rand()%256;
    Arr2[i] = num;
    sleep(0.0005);
  }
  return NULL; 
} 

void *hilo3(void *Arr){ 
  sleep(0.5);
  int i = 0; 
  for(i=0; i<10; i++){
    
    u_int8_t out = Arr1[i] & Arr2[i];
    printf("EL ASCII del numero %d es: %c\n", out, out);
    sleep(0.001);
  }
  return NULL; 
} 
   
int main(){ 
  pthread_t thread_1, thread_2, thread_3; 
  pthread_create(&thread_1, NULL, arreglo1, NULL); 
  pthread_create(&thread_2, NULL, arreglo2, NULL);
  pthread_create(&thread_3, NULL, hilo3, NULL); 
  pthread_join(thread_1, NULL); 
  pthread_join(thread_2, NULL); 
  pthread_join(thread_3, NULL); 

  exit(0); 
}