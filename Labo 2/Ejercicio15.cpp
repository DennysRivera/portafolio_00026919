#include <iostream>
#include <stdlib.h> 
#include <stdio.h> 
#include <time.h>

using namespace std;

void merge(int *arr, int iz, int k, int de) 
{ 
	int i=0, j=0, t=iz; 
	int n1 = k - iz + 1; 
	int n2 = de - k; 

	int men[n1], may[n2]; 

	for (i = 0; i < n1; i++) 
		men[i] = arr[iz + i]; 
	for (j = 0; j < n2; j++) 
		may[j] = arr[k + 1+ j]; 

	i = 0;
	j = 0;
	
	while (i < n1 && j < n2){ 
		if (men[i] <= may[j]){ 
			arr[t] = men[i]; 
			i++; 
		} 
		else{ 
			arr[t] = may[j]; 
			j++; 
		} 
		t++; 
	} 

	while (i < n1){ 
		arr[t] = men[i]; 
		i++; 
		t++; 
	} 

	while (j < n2){ 
		arr[t] = may[j]; 
		j++; 
		t++; 
	} 
} 

int mergeSort(int *arr, int izq, int der){ 
	if (izq < der){ 
		int k = izq+(der-izq)/2; 
		mergeSort(arr, izq, k); 
		mergeSort(arr, k+1, der);

		merge(arr, izq, k, der); 
	}
}

int main(){ 
	srand(time(NULL));
	int tam=0;
	cout << "Ingrese el tamano del arreglo: "; cin >> tam;
	int arr[tam];
	cout << "\nEl arreglo es:" << endl;
	
	for(int i=0;i<tam;i++){
		arr[i]=rand()%30;
		cout << arr[i] << " ";
	}

	mergeSort(arr, 0, tam); 
	cout << "\n\nEl arreglo ordenado es:" << endl;
	
	for(int i=0;i<tam;i++){
		cout << arr[i] << " ";
	}
	
	return 0; 
} 

