#include <iostream>
#include <cmath>
using namespace std;

void sumatoria(int n, int x, int suma){
	int i=n-1;
	if(i==-1){
		cout << endl << "Listo" << endl;
		cout << suma << endl;
	}
	else{
		suma = suma + pow(x, i);
		sumatoria(i, x, suma);
	}
}

int main(){
	
	int n, x, sum=0;
	
	cout << "Ingrese el ultimo valor de n:"; cin >> n;
	cout << "Ingrese un x: "; cin >> x;
	
	sumatoria(n+1, x, sum);
	
	return 0;
}

