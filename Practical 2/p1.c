#include <pthread.h>
#include <stdio.h>

// Function 1
void* thread1_func(void* arg) {
    long sum = 0;
    for (long i = 0; i < 1000000000; i++) {
        sum += 1;
    }
    printf("Thread 1 complete\n");
    return NULL;
}

// Function 2
void* thread2_func(void* arg) {
    long sum = 0;
    for (long i = 0; i < 5000000; i++) {
        sum += 1;
    }
    printf("Thread 2 complete\n");
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // Create thread 1
    pthread_create(&thread1, NULL, thread1_func, NULL);

    // Create thread 2
    pthread_create(&thread2, NULL, thread2_func, NULL);

    // Wait for both threads to complete
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
