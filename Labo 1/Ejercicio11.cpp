#include <iostream>
using namespace std;

int main(){
	
	int arr[15], i=0, cont=0, a=0, b, aux;
	cout << "Ingrese los elementos del arreglo o una letra para parar: " << endl;
	while(cin>>arr[i]){
		i++;
		cont++;
		if(i==15)
		break;
	}
	cout << endl;
	int arre[cont-1];
	for(i=0;i<cont;i++){
		arre[i]=arr[i];
	}
	
	for(i=0;i<=cont-1;i++){
		if(arre[i]>a){
			a=arre[i];
		}
	}
			cout << endl << a << endl;
		
	
	return 0;
}

