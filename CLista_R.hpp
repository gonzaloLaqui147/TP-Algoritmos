#pragma once
#include <iostream>
#include "CNodo.hpp"

using namespace std;

template <class T>
class CLista_R {
private:
	Nodo<T>* inicio;
	Nodo<T>* fin;
	int tam;
public:
	CLista_R() {
		inicio = nullptr; fin = nullptr; tam = 0;
	}

	void ingresar(T obj) {
		Nodo<T>* nuevo = new Nodo<T>(obj);
		if (tam == 0) { inicio = fin = nuevo; }
		else {
			fin->s = nuevo;
			fin = nuevo;
		}
		tam++;
	}

	void enviar() {
		Nodo<T>* aux = inicio;
		for (int i = 0; i < tam; i++) {
			cout << "/-----------------------------------------------------/" << endl;
			cout << "El bus numero " << i + 1 << " se dirige a: " << aux->e->getDestino() << endl;
			if (aux->e->getCapacidad() > 0) { cout << "Capacidad restante: " << aux->e->getCapacidad() << endl << endl; }
			else {
				cout << "El bus esta lleno" << endl;
			}
			aux->e->mostrar_Vector();
			aux = aux->s;
		}
	}

	void mostrar() {
		Nodo<T>* aux = inicio;
		for (int i = 0; i < tam; i++) {
			cout << "/-----------------------------------------------------/" << endl;
			cout << "El bus numero " << i + 1 << " se dirige a: " << aux->e->getDestino() << endl;
			cout << "Capacidad: " << aux->e->getCapacidad() << endl;
			aux = aux->s;
		}
	}

	T getNodo(string criterio) {
		Nodo<T>* aux = inicio;
		for (; !is_Empty();) {
			if(aux->e->getDestino() == criterio){
				return aux->e;
			}
			else {
				aux = aux->s;
			}
		}
	}

	int getTamanio() { return this->tam; }
	
	void reiniciar_Capacidad() {
		Nodo<T>* aux = inicio;
		for (int i = 0; i < tam; i++) {
			aux->e->setCapacidad(40);
			aux = aux->s;
		}
	}

	void reiniciar_Vectores() {
		Nodo<T>* aux = inicio;
		for (int i = 0; i < tam; i++) {
			aux->e->vaciar_Vector();
			aux = aux->s;
		}
	}

	bool is_Empty() {
		auto lambda = [](int tam) { return (tam == 0) ? true : false; };
		return lambda(tam);
	}
};
