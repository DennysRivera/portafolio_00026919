#include <iostream>
using namespace std;

int lista(int x, int y){
	int n=x+1;
	if(n==y){
		cout << "Listo" << endl;
	}
	else if(x>y){
		cout << "Error" << endl;
		return -1;
	}
	
	else{
		cout << n << endl;
		lista(n, y);
	}
}

int main(){
	
	int a=0, b=0;
	cout << "Ingrese desde donde contar: "; cin >> a;
	cout << "Ingrese hasta donde contar: "; cin >> b;
	cout <<  "Los naturales entre esos dos numeros son: " << endl;
	
	lista(a, b);
	
	return 0;
}

