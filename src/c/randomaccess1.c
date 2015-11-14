#include <stdio.h>
#include <fcntl.h>
//Defining a record
struct record {
	int id;
	char name[75];
};

void main()
{
	int fd, size = sizeof(struct record);
	struct record info;
	fd = open("records-file", O_RDWR | O_CREAT, 0777);
	//put pointer after the size of one record
	lseek(fd, size, SEEK_SET);
	read(fd, &info, size);

	info.id = 99;
	lseek(fd, -size, SEEK_CUR);
	write(fd, &info, size);

	close(fd);
}

	
