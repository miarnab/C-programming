#include<iostream>
using namespace std;
class Test{
	int x_;
	int y_;
	void func(){
		x_=y_=1;
		cout<<x_<<" "<<y_;
	}
};
int main(){
	Test t;
	t.func();
}
		
