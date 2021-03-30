#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "command.h"
#include "log_file.h"
#define COMMAND_LIMIT 100


void terminate(char inst[]){  //exit shell
    if(!strcmp(inst,"exit"))
        exit(0);
}

void handler(int signo){      //write to log file
    child_signal();
}

void valid_command(int statue){
    if(statue < 0){                                      //execvp return <0
        printf("this command is not found!\n");         //unknown command
    }
    exit(0);
}

void creating_child(struct Data ready_command){

    char* str_pt[ready_command.words_number+1];

    //prepare pointer array to be sent to execvp
    for(int i=0; i<ready_command.words_number; i++)
        str_pt[i] = &ready_command.splitted[i][0];
    str_pt[ready_command.words_number] = NULL;

    //get signal when process terminate
    signal(SIGCHLD, handler);

    int statue;
    pid_t pid = fork();
    if(pid == 0){
        //set_id(getpid());
        statue = execvp(str_pt[0], str_pt);
        valid_command(statue);
        }
    else if (ready_command.background == 0 )
        wait();
/*
    //child process
    if(pid == 0){

        //background process
        if(ready_command.background == 1){

            //create another child
            pid_t pid2 = fork();

            //grand child process
            if(pid2 == 0){
                statue = execvp(str_pt[0], str_pt);
                valid_command(statue);
                }
            else
                //child waiting for grandchild
                wait();
        }
        else{
            statue = execvp(str_pt[0], str_pt);
            valid_command(statue);
            }
        }
    //parent waiting fro non-background child
    else if (ready_command.background == 0)
        wait();
*/

}

int main()
{
    clear_file();                   //create new or clear existed log file
    struct Data ready_command;
    char str[COMMAND_LIMIT];

    while(1){
        printf("ShellOoO :~$  ");
        fgets(str, COMMAND_LIMIT, stdin);           //gets user's command
        ready_command = split(str);
        if(ready_command.words_number>0){           //there is an input
            terminate(ready_command.splitted[0]);    //check for exit call
            creating_child(ready_command);
        }
    }

    return 0;
}

