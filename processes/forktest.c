

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int global_var = 5;

int main()
{
    printf("before\n");
    pid_t p = fork();
    if (p == 0) {
        global_var = 7;
        printf("I'm a child!\n");
    } else {
        //kill(p, SIGKILL);
        wait(NULL);
        //waitpid(p, NULL, 0);
        printf("I'm a parent!\n");
    }
    printf("after %d, %d\n", p, global_var);
}