/* Trivial file copy program using low level I/O */
#include <fcntl.h>
#include <stdlib.h>
#define BSIZE 16384

void main()
{
	int fin,fout; //Input and Output handlers
	char buf[BSIZE]; //Defining an array of the buffer size
	int count;
	//open a read-only file called file2 and test if the process happened
	if((fin = open("file2", O_RDONLY)) < 0)
	{
		//print what error occured if any occured
		//and exit program
		perror("file2");
		exit(1);
	}
	if((fout = open("file3", O_WRONLY | O_CREAT , 0644)) <0 )
	{
		perror("file3");
		exit(2);
	}
	//reads into the buf array from file2 until byte 16384
	//copy the contains of file2 into file3  
	while((count = read(fin, buf, BSIZE)) > 0 ){
		write(fout, buf, count);}

	close(fin);
	close(fout);
}
