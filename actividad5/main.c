#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *thread_func(void *arg)
{
    printf("Hilo creado\n");
    return NULL;
}

void thread_create()
{
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, thread_func, NULL);
    pthread_join(thread_id, NULL);
}

int main()
{
    pid_t pid;

    pid = fork();
    if (pid == 0)
    {
        printf("Proceso hijo creado\n");
        fork();
        printf("Proceso hijo creado\n");
        thread_create();
    }
    fork();
    printf("Proceso hijo creado\n");

    return 0;
}