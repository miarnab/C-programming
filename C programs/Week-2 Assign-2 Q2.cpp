#include<iostream>
using namespace std;
	int main(){
    int m = 4;
    const int n = 5;
    const int * p = &n;
    int * const q = &m;
    // ...

    n = 6; // stmt-1
    *p = 7; // stmt-2
    p = &m; // stmt-3
    *q = 8; // stmt-4
    q = &n; // stmt-5
    // ...
 }
