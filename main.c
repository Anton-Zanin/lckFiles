#include <stdio.h>
#include <unistd.h>
#include <strings.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/fcntl.h>
#include <getopt.h>

#ifndef MAX_BUF
#define MAX_BUF 200
#endif

int createFile(const char *filepath, char *pid){

    while(access( filepath, F_OK ) == 0 ){
        continue;
    }
    FILE *fptr;
    fptr = fopen(filepath, "w+");
    fprintf(fptr, "%d", pid);
    fclose(fptr);
    return 0;
}

int processFile(const char *filepath, const int pid)
{
    if (access( filepath, F_OK) != 0){
        perror("File not found");
        exit(EXIT_FAILURE);
    }
    FILE *fptr;
    fptr = fopen(filepath, "r");

    char buff[10];
    fgets(buff, 10, (FILE*)fptr);
    int filePid = atoi(buff);


//    if (filePid - pid == 0){
//        remove(filepath);
//    }
//    else{
//        perror("Pids are different");
//        exit(EXIT_FAILURE);
//    }
}


//
//int createFileDir(char* dir){
//    if (mkdir(dir, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH)) {
//        exit(EXIT_FAILURE);
//    }
//    return 0;
//}

int initialize(char* file){
//    char str[100];
//    scanf("%s", str);
    char cwd[MAX_BUF];
    int *pid = getpid();
    char *filepath = strcat(strcat(getcwd(cwd, MAX_BUF),"/"), strcat(file, ".lck"));
    createFile(filepath, pid);
    processFile(filepath, pid);
}


int main(int argc, char **argv) {

    static struct option long_options[] =
            {
                    {"file", required_argument, NULL, 'f'}
            };

    int ch;
    while ((ch = getopt_long(argc, argv, "f", long_options, NULL)) != -1)
    {
        switch (ch) {
            case 'f':
                initialize(optarg);
                break;
        }
    }
    return 0;

}





