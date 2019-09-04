#include <iostream>
using namespace std;

struct paises{ 			////Estructura para información de países
	string nombre;
	string capital;
	int nhabitantes;
	float promedad;
};

typedef struct paises mip;
struct continent{
	string nomb;
	mip pais1[6];
//	mip pais2;
//	mip pais3;
//	mip pais4;
//	mip pais5;
};

void totalhab(struct continent cont[6]){
	int total1=0, total2=0, total3=0, total4=0, total5=0, tmundial=0;
	float prom1=0, prom2=0, prom3=0, prom4=0, prom5=0, edadmundi=0;
	string capitalmayor;
	
	for(int i=1;i<=5;i++){
		total1 = total1 + (cont[1].pais1[i].nhabitantes);
		total2 = total2 + (cont[2].pais1[i].nhabitantes);
		total3 = total3 + (cont[3].pais1[i].nhabitantes);
		total4 = total4 + (cont[4].pais1[i].nhabitantes);
		total5 = total5 + (cont[5].pais1[i].nhabitantes);
		
	}
	
	for(int i=1;i<=5;i++){
		prom1 = prom1 + (cont[1].pais1[i].promedad);
		prom2 = prom2 + (cont[2].pais1[i].promedad);
		prom3 = prom3 + (cont[3].pais1[i].promedad);
		prom4 = prom4 + (cont[4].pais1[i].promedad);
		prom5 = prom5 + (cont[5].pais1[i].promedad);
	}
	
	edadmundi = ((prom1+prom2+prom3+prom4+prom5)/25);
	
	int mayorpoblacion=0;
	for(int j=1;j<=5;j++){
		for(int i=1;i<=5;i++){
			if(cont[j].pais1[i].nhabitantes > cont[j+1].pais1[i+1].nhabitantes)
			mayorpoblacion=cont[j].pais1[i].nhabitantes;
			capitalmayor=cont[j].pais1[i].capital;
		}
	}
	
	cout << endl;
	cout << "Poblacion total de " << cont[1].nomb << ": " << total1 << " habitantes" << endl;
	cout << "Poblacion total de " << cont[2].nomb << ": " << total2 << " habitantes" << endl;
	cout << "Poblacion total de " << cont[3].nomb << ": " << total3 << " habitantes" << endl;
	cout << "Poblacion total de " << cont[4].nomb << ": " << total4 << " habitantes" << endl;
	cout << "Poblacion total de " << cont[5].nomb << ": " << total5 << " habitantes" << endl;
	cout << endl << "Capital con mayor poblacion: " << capitalmayor << " con " << mayorpoblacion << " habitantes" << endl;
	cout << endl << "Promedio de la edad mundial: " << edadmundi << " años" << endl;
}



int main(){
	
	struct continent micont[6];
	int i=1, j=1;

for(j=1;j<=5;j++){
	cout << "Continente " << j << ": "; cin >> micont[j].nomb;
	for(i=1;i<=5;i++){
		cout << "Pais " << i << ": "; cin >> micont[j].pais1[i].nombre;
		cout << "Capital: "; cin >> micont[j].pais1[i].capital;
		cout << "Numero de habitantes: "; cin >> micont[j].pais1[i].nhabitantes;
		cout << "Promedio de edad: "; cin >> micont[j].pais1[i].promedad;
		
	}
	
}

totalhab(micont);

	return 0;
}

