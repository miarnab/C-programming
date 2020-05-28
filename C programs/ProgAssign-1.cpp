    #include<iostream>
	using namespace std; 
 	int Ref_func( int param) {
  	
	 return (++param);  
}
int main() {
    int x, y, z;
    cin >> x ; 
    cin >> z ;
    y = Ref_func(x);
    cout << x  << " "<< y << endl;

    z=Ref_func(x);
    cout << x  << " "<< y;
}
	 
	 
	 
	 
 
