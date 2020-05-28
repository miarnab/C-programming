#include<iostream>
using namespace std;
int main()
{
	int a=20,b;
	b=Ref_const(a);
}
int Ref_const(int &x)
{
	return (x+1);
}
