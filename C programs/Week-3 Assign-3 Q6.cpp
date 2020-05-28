#include<iostream>
using namespace std;
class Test{
	int x_[2];
	int y_;
	public:
	void printf(){cout<<x_[0]<<""<<y_;}
	void setx(int m_){x_[0]=m_;x_[1]=0;}
	void sety(int n_){y_=n_;}
	int calc1(int n_){
		int t;
		t=n_*x_[0]*y_;
		x_[0]=n_*3;
		return t;
	}
	void calc2(int n_){
		int t;
		t=n_*x_[0];
		cout<<t;
	}
};
int main(){//Application Section
	Test t;
	t.setx(5);
}
