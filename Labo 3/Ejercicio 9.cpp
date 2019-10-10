#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

struct datosPersona{
    string nombre;
    string apellido;
    int edad;
    string nacionalidad;
    int genero;
};

typedef struct datosPersona Datos;

Datos solicitarDatos(){
    Datos d;
    bool flag = true;
    int opc;
    cin.ignore();
    
    cout << "Nombres: "; getline(cin, d.nombre);
    cout << "Apellidos: "; getline(cin, d.apellido);
    cout << "Edad: "; cin >> d.edad;
    cout << "Nacionalidad: "; cin >> d.nacionalidad;
    cout << "1. Mujer\n2. Hombre\nGenero: "; cin >> d.genero;
    
    return d;
}

void mostrarDatos(Datos d){
    cout << "Nombre: " << d.apellido << ", " << d.nombre << endl;
    cout << "Edad: " << d.edad << " años" << endl;
    cout << "Nacionalidad: " << d.nacionalidad << endl;
    cout << "Genero: ";
    if(d.genero==1) cout << "Mujer\n"; else cout << " Hombre\n";
    cout << endl;
	
}

vector<Datos> lista;

void agregarDatos(){
    Datos d = solicitarDatos();
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\nIntroducir\n\t1) Al principio\n\t2) Al final"
            << "\n\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: lista.insert(lista.begin(), d);
                continuar = false;
            break;
            case 2: lista.push_back(d);
                continuar = false;
            break;
            default: cout << "Opcion erronea!" << endl;
            break;
        }
    }while(continuar);
}

void mostrarLista(int size) {
    for (int i = 0; i < size; i++){
    	cout << "Persona " << (i+1) << endl;
        mostrarDatos(lista[i]);
    }
}

void eliminarDatos(){
	int opc;
	int size = lista.size();
	if(lista.empty()) cout << "No hay datos que eliminar" << endl;
	else{
		cout << "Escoga a quien eliminar:" << endl << endl;
		mostrarLista(size);
		cout << "Eliminar a: "; cin >> opc;
		swap(lista[opc-1], lista.back());
		lista.pop_back();
		cout << "\nEliminado!" << endl;
	}
}

void actualizarDatos(){
	int opc;
	int size = lista.size();
	cout << "Escoga que a alguien para actualizar sus datos: " << endl << endl;
	mostrarLista(size);
	cout << "Actualizar los datos de: "; cin >> opc; cout << endl;
	swap(lista[opc-1], lista.back());
	lista.pop_back();
	agregarDatos();
	cout << "\nDatos actualizados!" << endl;
}

int main() {
    bool flag = true;
    char opc;
    do{
    	int size = lista.size();
        cout << "\nOpciones:\na) Llenar la lista\nb) Eliminar una persona\nc) Actualizar los datos de una persona\n"
                <<"d) Mostrar todas las personas\ne) Salir" << endl;
        cin >> opc;
        switch(opc){
            case 'a': cout << "\nAgregando...\n" << endl;
                agregarDatos();
                break;
            
            case 'b': cout << "\nEliminando...\n" << endl;
           		eliminarDatos();
            	break;
            
            case 'c': cout << "\nActualizando...\n" << endl;
            	actualizarDatos();
            	break;
            
            case 'd': cout << "\nListando...\n" << endl;
               mostrarLista(size);
               break;
               
            case 'e': cout << "\nHasta la proxima!\n" << endl; flag=false; break;
        }
        
    }while(flag);

    return 0;
}

