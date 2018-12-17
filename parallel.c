#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

char* arguments[] = {"", NULL};
char* args[] = {"ls","df","ps","pwd"};
int main(int argc, char const *argv[]){
    int i = 0;
    while(i < 4){
        pid_t pid = fork();
        if(pid == 0){
            printf("%s:\n",args[i]);
            arguments[0] = args[i];
            execvp(arguments[0], arguments);
        }
        else{
            waitpid(-1,0,0);
        }
        i++;
        printf("\n");
    }
    return 0;
}