#include<iostream>
using namespace std;
class Sample{
	int x;
	int y;
	public:
	void setx(int n){x=n;}
	void sety(int n){y=n;}
	int gety{return y;}
	int getx{return x;}
};
class Experiment{
	public:
	display(Sample t){t.setx(8);
	cout<<t.x;
	}
};
int main(){
	Sample t;
	Experiment e;
	e.display(t);
}
