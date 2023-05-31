#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int fd[2];
    int value = 5;
    pid_t pid;

    pipe(fd);

    pid = fork();
    if (pid == 0) { 
        close(fd[0]); 

        value += 15;
        printf("Filho: value = %d\n", value);

        write(fd[1], &value, sizeof(value)); 

        close(fd[1]); 
        return 0;
    }
    else { 
        close(fd[1]); 

        wait(NULL);

        read(fd[0], &value, sizeof(value)); 

        printf("Pai: value = %d\n", value);

        close(fd[0]); 
        return 0;
    }
}
