#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/time.h>

long* shared_variable;
double total_duration = 0.0;

// Function 1
void* thread1_func(void* arg) {
    struct timeval start, end;
    gettimeofday(&start, NULL);
    
    printf("Thread1: %ld\n", *shared_variable);
    
    long sum = 0;
    for (long i = 0; i < 1000000000; i++) {
        sum += 1;
    }

    gettimeofday(&end, NULL);
    double duration = (double)(end.tv_sec - start.tv_sec) + (double)(end.tv_usec - start.tv_usec) / 1000000;
    printf("Thread1 took %lf seconds to execute\n", duration);
    total_duration += duration;
    
    return NULL;
}

// Function 2
void* thread2_func(void* arg) {
    struct timeval start, end;
    gettimeofday(&start, NULL);
    
    printf("Thread2: %ld\n", *shared_variable);
    
    long sum = 0;
    for (long i = 0; i < 5000000; i++) {
        sum += 1;
    }

    gettimeofday(&end, NULL);
    double duration = (double)(end.tv_sec - start.tv_sec) + (double)(end.tv_usec - start.tv_usec) / 1000000;
    printf("Thread2 took %lf seconds to execute\n", duration);
    total_duration += duration;
    
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    int shmid;
    
    // Allocate shared memory
    shmid = shmget(IPC_PRIVATE, sizeof(long), IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }
    
    // Attach shared memory
    shared_variable = (long*)shmat(shmid, NULL, 0);
    if ((long)shared_variable == -1) {
        perror("shmat");
        exit(1);
    }
    
    *shared_variable = 1; // Set shared variable
    
    // Create thread 1
    pthread_create(&thread1, NULL, thread1_func, NULL);

    // Sleep for a short duration to ensure threads print in order
    usleep(100000);

    // Update shared variable for thread 2
    *shared_variable = 2;

    // Create thread 2
    pthread_create(&thread2, NULL, thread2_func, NULL);

    // Wait for both threads to complete
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Print total duration and average time taken
    printf("Total duration for thread1 and thread2: %lf seconds\n", total_duration);
    printf("Average time taken was %lf\n", total_duration / 2.0);

    // Detach and deallocate shared memory
    shmdt(shared_variable);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
