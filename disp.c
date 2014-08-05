#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#define PERMS 0666 
char buffer[2048];

main(int argc,char *argv[]){
    int fdold,fdnew;
    if(argc != 2){
        printf("need 1 aruments in the program\n");
        exit(1);
        }
	fdold = open(argv[1],O_RDONLY);
        int ret = read(fdold,buffer,sizeof(buffer));
        if(ret != 0){
	int w = write(1,buffer,ret);
         printf("***File displayed sucessfully***\n");
        }
        else{
           printf("Error;unable to display the file:\n");
           exit(0);
        }
	close(fdold);
}
