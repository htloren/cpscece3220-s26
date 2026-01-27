#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

void mysignalhandler(int signum) {
    char *taunting = "Ha ha, I won't die!\n";
    write(STDOUT_FILENO, taunting, strlen(taunting));
}

int main()
{
    struct sigaction action = {.sa_handler = mysignalhandler};
    sigaction(SIGINT, &action, NULL);
    sigaction(SIGTERM, &action, NULL);
    sigaction(SIGSEGV, &action, NULL); //in practice, don't do this
    //sigaction(SIGKILL, &action, NULL); //not optional

    //SIGSEGV
    //SIGUSR1, SIGUSR2

    int *p = NULL;

    *p = 45; //produces SIGSEGV
    
    while (true) {
        printf("Wasting your cycles!!! %d\n", getpid());
        sleep(3);
    }
    
}