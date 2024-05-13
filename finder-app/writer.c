#include <stdio.h>
#include <syslog.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char *argv[])
{
    char *writefile = argv[1];
    char *writestr = argv[2];
    int fd;

    size_t count;
    ssize_t nr;
     
    openlog("Assignment 2", LOG_PID, LOG_USER);
    syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);


    if(argc != 3)
    {
        printf("Insufficient commands\n");
        syslog(LOG_ERR, "Insufficient commands");
        return 1;
    }

    fd = open(writefile, O_RDWR | O_CREAT);
    if(fd == -1)
    {
        printf("Error opening file\n");
        syslog(LOG_ERR, "Error opening file");
    }

    
    count = strlen(writestr);
    nr = write(fd, writestr, strlen(writestr));

    if(nr == -1)
    {
        printf("Error writing to file\n");
        syslog(LOG_ERR, "Error writing to file");
    }
    else if(count != nr)
    {
        printf("Incomplete write to file.\n");
        syslog(LOG_ERR, "Incomplete write to file.");
        
    }
    close(fd);
    



    return 0;
    

}
