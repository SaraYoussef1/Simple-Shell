#include <string.h>
#define MAX 10

struct Data {
    char splitted[MAX][MAX];
    int words_number;
    int background;
};


struct Data split(char str[]){
    struct Data ready_command;
    ready_command.background = 0;

    //n: number of words in this command, j: index for word characters
    int n = 0 , j = 0;

    // remove /n coming from pressing Enter
    str[strlen(str)-1] = '\0';

    for(int i=0;i<=(strlen(str));i++)
    {
        // if space or NULL found, this word is done
        if(i > 0 && (str[i]==' '|| str[i]=='\0') && str[i-1] != ' ' )
        {
            // end this word
            ready_command.splitted[n][j]='\0';

            // initialize new word word
            n++;
            j=0;
        }
        else if(str[i] == '&' && str[i+1] == '\0')
            ready_command.background = 1;

        //ignore extra spaces
        else if (str[i] != ' ' && str[i] != '\0')
        {
            //add new character to the current word
            ready_command.splitted[n][j] = str[i];
            j++;
        }
    }
    ready_command.words_number = n;
    return ready_command;
}


