#include <iostream>
#include <cmath>
using namespace std;

int sumPi(int n, int k, double sum){
	k=k+1;
	
	if(k==n){
		cout << "Valor aproximado de pi: ";
		cout << sum << endl;
	}
	else{
		sum=sum + (4*(pow(-1, k))/((2*k)+1));
		sumPi(n, k, sum);
		return sum;
	}
}

int main(){
	int n=0, k=-1;
	double sum=0;
	cout << "SUMATORIA DE PI\n\n";
	cout << "Ingrese un n: "; cin >> n;
	
	sumPi(n, k, sum);
	
	return 0;
}

