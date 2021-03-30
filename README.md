# Simple-Shell

It is a simple Unix shell that allows to run other programs.  
### This shell supports the following:  
**1. A command with no arguments**
• Example: ls, cp, rm ...etc  
• System calls: fork(), execvp(), exit(), wait()  
• Details: shell is blocked until the command completes and, if the return code is abnormal, it prints out a message to that effect.  


**2. A command with arguments**
• Example: ls –l  
• Details: Argument 0 is the name of the command.  
• Concepts: Command-line parameters.  


**3. A command, with or without arguments, executed in the background using &.**
• Example: firefox &  
• Details: shell executes the command and returns immediately, not blocking until the command finishes.  
• Concepts: Background execution, signals, signal handlers, processes and asynchronous execution.  


### To run the shell using Makefile:
```
Open the terminal and go to src in project path 
Write the command " make " to compile project files   
Write the command " ./shell " to run the project  
```

