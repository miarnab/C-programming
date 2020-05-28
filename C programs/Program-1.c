#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	union Data{
		int i;
		unsigned char c;
	}data;
	data.c='C';
	data.i=89;
	printf("%c",data.c);
	return 0;
}
