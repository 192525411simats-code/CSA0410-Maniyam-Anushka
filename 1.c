#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid;

    pid = fork();

    if (pid == 0)
    {
        printf("Child Process\n");
        printf("Child PID = %d\n", getpid());
        printf("Parent PID = %d\n", getppid());
    }
    else if (pid > 0)
    {
        printf("Parent Process\n");
        printf("Parent PID = %d\n", getpid());
        printf("Parent's Parent PID = %d\n", getppid());
    }
    else
    {
        printf("Process creation failed\n");
    }

    return 0;
}