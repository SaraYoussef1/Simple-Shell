static int child_id;

void clear_file(){
    FILE* f;
    f = fopen("terminated processes.log", "w");     //create new file or open clear existing one
    if(f == NULL)
        fprintf(f, "Can't open or create this file...");
}

void child_signal(){
    FILE* f;
    f = fopen("terminated processes.log", "a");
    fprintf(f, "Child process was terminated\n");   ////append this sentence after child termination
    fclose(f);
}

/*void set_id(int id){
    child_id = id;
}

int get_id(){

    return child_id;
}*/

