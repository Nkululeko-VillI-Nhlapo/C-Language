#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

#define Init 64.0;



float iterator = Init;
pthread_mutex_t mute;

void* incr(void *arg){
  pthread_mutex_lock(&mute);

  iterator += 1;

  pthread_mutex_unlock(&mute);
  printf("Incremented value: %.2f\n", iterator);

  return NULL;
}

void* decr(void *arg){
  pthread_mutex_lock(&mute);

  iterator -= 1;
  printf("Decremented value: %.2f\n" , iterator);

  pthread_mutex_unlock(&mute);

  return NULL;
}

void* doubl(void *arg){
  pthread_mutex_lock(&mute);

  iterator = iterator * 2;
  printf("Doubled value: %.2f\n", iterator);

  pthread_mutex_unlock(&mute);

  return NULL;
}

void* halve(void *arg){
  pthread_mutex_lock(&mute);

  iterator = iterator/2;
  printf("Halved value: %.2f\n", iterator);

  pthread_mutex_unlock(&mute);

  return NULL;
}


int main(void){
  pthread_t tid[4];
  pthread_mutex_init(&mute, NULL);
  
  printf("Original value: %.2f\n", iterator);
  pthread_create(&(tid[0]), NULL, incr, NULL);
  pthread_create(&(tid[1]), NULL, decr, NULL);
  pthread_create(&(tid[2]), NULL, doubl, NULL);
  pthread_create(&(tid[3]), NULL, halve, NULL);
 

  for (int i = 0; i < 4; i++) {
      pthread_join(tid[i], NULL);
  }
  pthread_mutex_destroy(&mute);
  
  return 0;
}