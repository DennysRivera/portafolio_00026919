#include <iostream>
#include <vector>
using namespace std;

vector<int> lista;

struct nodo{
    int info;
    struct nodo *izq;
    struct nodo *der;
};
typedef struct nodo Nodo;
typedef struct nodo *Arbol;

Arbol crearArbol(int x){
    Arbol p = new Nodo;
    p->info = x;
    p->izq = NULL;
    p->der = NULL;
    return p;
}

//------ Agregar nodos a un arbol ------
void asignarIzq(Arbol a, int unDato){
    if(a == NULL)
        cout << "Error: arbol vacio" << endl;
    else if(a->izq != NULL)
        cout << "Error: subarbol IZQ ya existe" << endl;
    else
        a->izq = crearArbol(unDato);
}

void asignarDer(Arbol a, int unDato){
    if(a == NULL)
        cout << "Error: arbol vacio" << endl;
    else if(a->der != NULL)
        cout << "Error: subarbol DER ya existe" << endl;
    else
        a->der = crearArbol(unDato);
}

void agregarNodo(Arbol a, int numero){
    Arbol p = a;
    
    while(true){
        if(numero == p->info){
            return;
        }
        else if(numero < p->info){
            if(p->izq == NULL)
                break;
            else
                p = p->izq;
        }
        else{
            if(p->der == NULL)
                break;
            else
                p = p->der;
        }
    }
    
    if(numero < p->info)
        asignarIzq(p, numero);
    else
        asignarDer(p, numero);
}

void preorden(Arbol a){
    if(a != NULL){
        cout << " " << a->info;
        preorden(a->izq);
        preorden(a->der);
    }
}
void inorden(Arbol a){
    if(a != NULL){
        inorden(a->izq);
        cout << " " << a->info;
        inorden(a->der);
    }
}
void postorden(Arbol a){
    if(a != NULL){
        postorden(a->izq);
        postorden(a->der);
        cout << " " << a->info;
    }
}

void recorrerArbol(Arbol a){
    cout << "Recorrido PRE orden:"; preorden(a); cout << endl;
    cout << "Recorrido IN orden:"; inorden(a); cout << endl;
    cout << "Recorrido POST orden:"; postorden(a); cout << endl;
}

void agregarListaArbol(Arbol a){
	for(int i=1; i<lista.size(); i++){
		agregarNodo(a, lista[i]);
	}
}

void agregarNum(){
    int num = 0;
    cout << "Ingrese un numero: "; cin >> num;
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\t1) Al principio\n\t2) Al final"
            << "\n\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: lista.insert(lista.begin(), num);
                continuar = false;
            break;
            case 2: lista.push_back(num);
                continuar = false;
            break;
            default: cout << "Opcion erronea!" << endl;
            break;
        }
    }while(continuar);
}

void mostrarLista() {
    for (int i = 0; i < lista.size(); i++)
        cout << lista[i] << " ";
    cout << endl << endl;
}

int main(){
	Arbol arbol;
	bool arbolCreado = false;
    cout << "Inicializando..." << endl;
    
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "Menu: \n\t1) Insertar un numero a la lista\n\t2) Ver numeros insertados en la lista"
            << "\n\t3) Crear arbol binario\n\t4) Insertar la lista en el arbol binario\n\t5) Recorrer arbol binario\n\t6) Salir\n\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: cout << "\nAgregando..." << endl;
                agregarNum();
            break;
            case 2: cout << "\nListando..." << endl << endl;
                mostrarLista();
            break;
            case 3:
				cout << "\nCreando arbol..." << endl;
				arbol = crearArbol(lista[0]);
				cout << "\nArbol creado!" << endl << endl;
				break;
            case 4: agregarListaArbol(arbol); cout << "\nAgregando numeros al arbol..." << endl << endl;
				break;
            case 5: cout << "\nRecorriendo..." << endl << endl; recorrerArbol(arbol); cout << endl; break;
            case 6: continuar = false;
            break;
            default: cout << "Opcion erronea!" << endl;
            break;
        }
    }while(continuar);

    return 0;
}
