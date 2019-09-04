#include <iostream>
using namespace std;

int mult(int a, int b){
	if(b==1){
		cout << "b = " << b << " como caso base" << endl;
		return a;
	}
	else{
		int num =(b-1);
		int num2 = mult(a, b-1);
		cout << "a=" << num << " b=" << num2 << endl;
		
		return a+num2;
	}
}

int main(){
	int a, b, m;
	cout << "Numeros a multiplicar: " << endl;
	cin >> a >>b;
	m= mult(a, b);
	cout << "Resultado: " << m << endl;
}

