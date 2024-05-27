#include <stdio.h>
#include <syslog.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char *argv[])
{
    char *writefile = argv[1];
    char *writestr = argv[2];

    openlog("Assignment 2", LOG_PID, LOG_USER);
    syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);


    if(argc != 3)
    {
        printf("Insufficient commands\n");
        syslog(LOG_ERR, "Insufficient commands");
	closelog();
        return 1;
    }
	
    
    FILE *file = fopen(writefile, "w");
    if(file == NULL)
    {
        printf("Error opening file\n");
        syslog(LOG_ERR, "Error opening file");
	return 1;
    }

    fprintf(file, "%s", writestr);
    syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);

    fclose(file);    
    closelog();
        
    
    return 0;
    

}
