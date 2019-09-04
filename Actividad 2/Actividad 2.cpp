#include <iostream>
using namespace std;

float mediana(int arreglo[], int tamano){
	int i=0;
	float a, b;
	if(tamano%2!=0){
		cout << "La mediana del arreglo " << endl;
		for(i=0;i<tamano;i++)
		cout << arreglo[i] << " ";
		i=tamano/2;
		cout << "es " << arreglo[i] << endl;
	}
	
	else{
		cout << "La mediana del arreglo " << endl;
		for(i=0;i<tamano;i++)
		cout << arreglo[i] << " ";
		i=tamano/2;
		a=arreglo[i-1];
		b=arreglo[i];
		cout << "es " << ((a+b)/2) << endl;
	}
}

int main(){
	int num, arr[50], tamano=0, i=0;
	cout << "Ingrese los elementos del arrgelo o una letra para finalizar:" << endl;
	while(cin >> arr[i]){
		i++;
		tamano++;
	}
	cout << endl << tamano << endl << endl;
	
	mediana(arr, tamano);
	
	return 0;
}

