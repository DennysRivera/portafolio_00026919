#include <iostream>
using namespace std;

int	inicio = 0;
int	fin = 7;

int busqueda(int x, int low, int high){
	int arr[]={1,3,4,5,17,18,31,33}, mid;
	if(low>high)
		return (-1);
	mid = (low+high)/2;
	if(x== arr[mid])
		return (mid);
	if(x< arr[mid])
		busqueda(x, low, (mid-1));
	else
		busqueda(x, (mid+1), high);
}

int main(){
	int x, i, arr[8]={1,3,4,5,17,18,31,33};
	cout << "Ingrese un entero: ";
	cin >> x;

	i=busqueda(x, inicio, fin);
	if(i==-1)
		cout << "El número no está en el arreglo" << endl;
	else
		cout << x  << " está en la casilla " << i << endl;
	
	
}

