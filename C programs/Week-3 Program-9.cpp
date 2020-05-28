#include<iostream>
#include<string>
using namespace std;
class Sample{
	string name;
	public:
	Sample(string s):name(s){
		cout<<name<<"Created"<<" ";
	}
	Sample(){
		cout<<name<<"Destroyed"<<" ";
	}
};
int main(){
	Sample *s1=new Sample("s1");
	Sample *s2=new Sample("s2");
	return 0;
}
