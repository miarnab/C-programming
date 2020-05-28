#include <stdio.h>

	int sum(int a, int b, int c) {

	    return a + b + c / 2;

	}

	void main() {

	    int (*function_pointer)(int, int, int);

	    function_pointer = sum;

	    printf("%d", function_pointer(2, 3, 4));
	    return ;

	}
