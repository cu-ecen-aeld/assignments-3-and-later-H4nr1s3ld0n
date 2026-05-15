#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <syslog.h>
#include <errno.h>


int main(int argc, char *argv[])
{
int fd;
ssize_t nr;

openlog("writer.c", LOG_PID, LOG_USER);

  
	if (argc < 3){
    syslog(LOG_ERR, "Unexpected error invalid arguments.");
		printf("Usage : %s <path> <string>\n", argv[0]);
    closelog();
		return 1;
	}

fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);

	if (fd == -1)
	{
    syslog(LOG_ERR, "Unexpected error opening : %s : %s", argv[1], strerror(errno));
    closelog();
		return 1;
	}
	

	nr = write (fd, argv[2], strlen(argv[2]));
	if (nr == -1)
	{
	syslog(LOG_ERR, "Unexpected error writing the string : %s : %s", argv[2], strerror(errno));
  closelog();
	return 1;
	}
	
syslog(LOG_DEBUG, "Successfully writing : %s to %s", argv[2], argv[1]);

printf("Successfully wrote %zd to the file\n", nr);

close(fd);
closelog();
return 0;

}
