#include <iostream>

using namespace std;

void mostrarCola(int n, int *cola){//////La cola se tiene un comportamiento algo extraño al imprimirse////
	int i=0;
	for(i=0;i<n;i++)
		cout << cola[i] << " ";
		cout << endl << endl;
}

int main(){
	int cola[10], n=0, frente=0, max=10, i=0, opc=0, num=0;

	cout << "COLA CIRCULAR PARA 10 ELEMENTOS\n"; 
	cout << "La cola aumentara de 1 en 1 al insertar un nuevo elemento\n" << endl;
	do{
		int ubicacion=(frente+n)%max;
		cout << "1. Insertar elemento\n2. Eliminar elemento\n3. Terminar" << endl;
	
		cin >> opc;
		cout << endl;
		switch(opc){
			case 1:
				if(n==max)
					cout << "La cola esta llena!" << endl;
				else{
					num=num+1;
					cola[ubicacion]=num;
					n++;
					
					cout << "Frente: " << frente << " | n: " << n << " | Maximo: " << max << " | Elemento " << num << " en ubicacion: " << ubicacion << endl;
					cout << "Cola actual: ";
					mostrarCola(n, cola);
				}
				break;
			
			case 2:
				if(n==0)
					cout << "La cola esta vacia!" << endl;
				else{
					int aux=cola[frente];
					cout << "Sale elemento " << aux << endl;
					frente=(frente+1)%max;
					n--;
					cout << "Frente: " << frente << " | n: " << n << " | Maximo: " << max << " | Elemento " << num << " en ubicacion: " << ubicacion << endl;
					cout << "Cola actual: ";
					mostrarCola(n, cola);
				}
				break;
				
			case 3:
				return 0;
					
			default:
				cout << "Opcion invalida!" << endl;
		}
	}
	while(opc!=3);
	
	return 0;
}

