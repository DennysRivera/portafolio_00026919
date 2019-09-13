#include <iostream>
using namespace std;

struct Tpila{
	float elements[100];
	int top;
};
typedef struct Tpila Pila;

void initialize(Pila *s){
	s->top = -1;
}

bool empty(Pila *s){
	return s->top < 0;
}

void push(Pila *s, float e){
	if(s->top < 99){
		(s->top)++;
		s->elements[s->top] = e;
	}
}

void pop(Pila *s, float *e){
	if(s->top >= 0){
		*e = s->elements[s->top];
		(s->top)--;
	}
}

////////////////FUNCIÓN SEEK///////////////////
void seek(Pila *s, float *e){
	if(s->top >= 0){
		*e = s->elements[s->top];
	}
}
/////////////////////////////////////////////


float obtener2do(Pila *s){
	if(empty(s))
		return -1;
	float a = 0, b = 0;
	pop(s, &a);
	if(empty(s))
		return -1;
	pop(s, &b);
	push(s, b);
	push(s, a);
	return b;
}


///////////FUNCIÓN PARA ELEMENTO DEL FONDO Y VACIAR PILA/////////////////////
float obtenultimo(Pila *s){
	if(empty(s))
		return -1;
	float a = 0, b = 0, c = 0;
	pop(s, &a);
	if(empty(s))
		return -1;
	pop(s, &b);
	if(empty(s))
		return -1;
	pop(s, &c);
	return c;
}
/////////////FUNCIÓN PARA ELEMTENTO DEL FONDO SIN VACIAR PILA/////////////
float ultimoseek(Pila *s){
	if(empty(s))
		return -1;
	float a = 0, b = 0, c = 0;
	pop(s, &a);
	if(empty(s))
		return -1;
	pop(s, &b);
	if(empty(s))
		return -1;
	seek(s, &c);
	push(s, b);
	push(s, a);
	return c;
}

////////////////////////////////////////////////////////////////////////////

int main()
{
	Pila unaPila;
	initialize(&unaPila);
	
	push(&unaPila, 1.2);
	push(&unaPila, 3.4);
	push(&unaPila, 5.6);
	
	float segundo = obtener2do(&unaPila);
	cout << "2do: " << segundo << endl;
	
	float ultimo1 = ultimoseek(&unaPila);
	cout << "Ultimo con pila intacta: " << ultimo1 << endl;
	
	float ultimo = obtenultimo(&unaPila);
	cout << "Ultimo con pila vacia: " << ultimo << endl;
}
