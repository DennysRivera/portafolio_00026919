#include <iostream>
#include <vector>
using namespace std;

struct PedidoPupusas{
    int revueltas=0;
    int frijolqueso=0;
    int queso=0;
    int harinaRev=0;
    int harinaFrq=0;
    int harinaQu=0;
	//  bool arroz=true;
};
typedef struct PedidoPupusas Pedido;

Pedido solicitarPedido(){
    Pedido p;
    bool flag = true;
    int opc;
    do{
    cout << "\nAgregar de\n\n\t1. Revueltas\n\t2. Frijol con queso\n\t3. Queso\n\t4. Terminar pedido" << endl;
    cout << "\tOpcion: "; cin >> opc; cout << endl;
    switch(opc){
    	case 1:
    		cout << "REVUELTAS\nPedir: "; cin >> p.revueltas;
    		cout << "1. Arroz\n2. Maiz\n"; cin >> p.harinaRev;
   			break;
    	
    	case 2:
    		cout << "FRIJOL CON QUESO\nPedir: "; cin >> p.frijolqueso;
    		cout << "1. Arroz\n2. Maiz\n"; cin >> p.harinaFrq;
    		break;
    	
    	case 3:
   			cout << "QUESO\nPedir: "; cin >> p.queso;
   			cout << "1. Arroz\n2. Maiz\n"; cin >> p.harinaQu;
   			break;
   			
   		case 4: 
   			flag = false;
   			break;
   			
   		default:
   			cout << "Opcion invalida!" << endl;
   			break;
   			
	}
	}while(flag==true);
    return p;
}

void mostrarPedido(Pedido p){
    cout << "Revueltas: " << p.revueltas;
    if(p.harinaRev==1) cout << " de arroz\n"; else if(p.harinaRev==0) cout << " \n"; else cout << " de maiz\n";
    cout << "Frijol con queso: " << p.frijolqueso;
    if(p.harinaFrq==1) cout << " de arroz\n"; else if(p.harinaFrq==0) cout << " \n"; else cout << " de maiz\n";
    cout << "Queso: " << p.queso;
    if(p.harinaQu==1) cout << " de arroz\n"; else if(p.harinaQu==0) cout << " \n"; else cout << " de maiz\n";
    cout << endl;
	
}

vector<Pedido> lista;

void agregarAlPedido(){
    Pedido p = solicitarPedido();
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\t1) Al principio\n\t2) Al final"
            << "\n\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: lista.insert(lista.begin(), p);
                continuar = false;
            break;
            case 2: lista.push_back(p);
                continuar = false;
            break;
            default: cout << "Opcion erronea!" << endl;
            break;
        }
    }while(continuar);
}

void mostrarLista() {
    for (int i = 0; i < lista.size(); i++){
    	cout << "PEDIDO " << (i+1) << endl;
        mostrarPedido(lista[i]);
    }
}

int main(){
    cout << "Inicializando..." << endl;
    
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "Menu: \n\t1) Agregar pedido\n\t2) Ver orden"
            << "\n\t3) Salir\n\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: cout << "\nAgregando..." << endl;
                agregarAlPedido();
            break;
            case 2: cout << "\nListando..." << endl << endl;
                mostrarLista();
            break;
            case 3: if(lista.size()!=0){cout << "\n\tGracias y Buen Provecho!" << endl; continuar = false;}
            else{cout << "\n\tLo esperamos la proxima vez" << endl; continuar = false;}
            break;
            default: cout << "Opcion erronea!" << endl;
            break;
        }
    }while(continuar);

    return 0;
}
