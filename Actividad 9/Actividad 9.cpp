#include <iostream>
#include <stack>
using namespace std;

int main(){
	float a=0,b=0,c=0,i=0;
	stack<float> unaPila;
	
	unaPila.push(1.2);
	unaPila.push(3.4);
	unaPila.push(5.6);

	while(i<unaPila.size()){
		if(unaPila.empty())
			return -1;
		
		a = unaPila.top();
		unaPila.pop();
	
		if(unaPila.empty())
			return -1;
		else{
			b=unaPila.top();
			cout << "2do: " << b << endl;
			break;
		}
	i++;
	}
	
	while(i<unaPila.size()){
		if(unaPila.empty())
			return -1;
		
		unaPila.pop();
	
		if(unaPila.empty())
			return -1;
		else{
			//unaPila.pop();
			c=unaPila.top();
			cout << "Ultimo con pila vacia: " << c << endl;
			unaPila.pop();
			break;
		}
	i++;
	}
	
	unaPila.push(c);
	unaPila.push(b);
	unaPila.push(a);
	
	cout << "Ultimo con pila intacta: " << c << endl;

	return 0;
}
