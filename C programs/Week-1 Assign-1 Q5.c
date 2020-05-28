#include<stdio.h>

	#include <string.h>

	int main() {

	    union Data {

	        int i;

	        unsigned char c;

	    } data;

	    data.c ='C';

	    data.i = 89;

	    printf( "%c\n", data.c);

	    return 0;

	}
