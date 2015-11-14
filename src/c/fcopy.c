/*Trivial file copy program using Standard I/O library */

#include <stdio.h>
#define BSIZE 16384

void main()
{
	FILE *fin, *fout; //input and output handlers
	char buf[BSIZE];
	int count;

	fin=fopen("foo","r");
	fout=fopen("bar","w");

	while((count = fread(buf, 1, BSIZE, fin)) > 0)
		fwrite(buf, 1, count, fout);

	fclose(fin);
	fclose(fout);

}

