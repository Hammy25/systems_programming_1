#include<fcntl.h>
#include<errno.h>
#include<stdio.h>
#include<stdlib.h>

void main()
{
	//declare the file desriptor
	int fd;
	//open a file named foo in the current directory
	//make it write only and create if doesn't exist
	//give it file permisions 644(rw-r-r)
	fd = open("foo", O_WRONLY | O_CREAT, 0644);
	//check if file descriptor is  less than 0
	if (fd<0)
	{
		//Print the error number
		printf("Error number %d \n", errno);
		//Print what the error is
		perror("foo");
		//exit the program
		exit(1);
	}
	write(fd, "Hello World", 11);
	close(fd);
}
