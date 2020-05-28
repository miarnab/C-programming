#include<iostream>
#include<string>
using namespace std;
class Employee{
	public:
	string name,addr;
	const int id;
	string dob;
	Employee(string nm,string ad,string dt,int d):name(nm),addr(ad),dob(dt),id(d){ }
	void print_attr_dob() const{
		this->dob="12-02-1986";
		cout<<this->dob;
	}
	void print_attr_name(){
		cout<<this->name;
	}
};
static int count=1;
int main(){
	const Employee e1("Ram","Kolkata","12-02-02",count++);
	e1.print_attr_dob();
	e1.print_attr_name();
	return 0;
}
