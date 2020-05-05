#pragma once
#include "CNodo.hpp"
#include <iostream>
#include <functional>

template <class T>
class CCola {
private:
	Nodo<T>* inicio;
	Nodo<T>* fin;
	int tam;
public:
	CCola() {
		inicio = nullptr; fin = nullptr;
		tam = 0;
	}

	bool queue(T e) {
		Nodo<T>* nuevo = new Nodo<T>(e);

		if (tam == 0) { inicio = fin = nuevo; tam++; return true; }
		else {
			Nodo<T>* aux = inicio;
			for (int i = 0; i < tam; i++) {
				if (verif(aux, nuevo)) {
					cout << "Ya se encuentra registrada esta persona\n";
					cin.get();
					return false;
				}
				aux = aux->s;
			}
			fin->s = nuevo;
			nuevo->a = fin;
			fin = nuevo;
			tam++;
			return true;
		}

	}

	

	void enqueue() {
		Nodo<T>* aux = inicio;
		cout << aux->e->getNombre() << " / " << aux->e->getEdad() << " / " << aux->e->getDNI() << endl;
		inicio = aux->s;
		tam--;
		delete aux;
	}

	void priorizar() {
		if (tam == 0) { cout << "No existen personas registradas en el sistema\n"; cin.get(); }
		else {
			if (tam == 1) { cout << "Solo existe una persona en la cola\n"; cin.get(); }
			else {
				Nodo<T>* aux = inicio;
				Nodo<T>* aux2 = aux;
				string nombre, destino; int edad, DNI, prioridad;
				bool parada = true;

				nombre = aux->e->getNombre(); destino = aux->e->getDestino(); edad = aux->e->getEdad(); DNI = aux->e->getDNI(); prioridad = aux->e->getPrioridad();


				if (inicio->e->getPrioridad() == 0) {
					for (; !is_Empty() && parada == true;) {
						if (aux2->e->getPrioridad() == 1) {
							inicio->e->setNombre(aux2->e->getNombre());
							inicio->e->setDestino(aux2->e->getDestino());
							inicio->e->setEdad(aux2->e->getEdad());
							inicio->e->setDNI(aux2->e->getDNI());
							inicio->e->setPrioridad(aux2->e->getPrioridad());

							aux2->e->setNombre(nombre);
							aux2->e->setDestino(destino);
							aux2->e->setEdad(edad);
							aux2->e->setDNI(DNI);
							aux2->e->setPrioridad(prioridad);
							parada = false;
						}
						else {
							aux2 = aux2->s;
						}
					}
					aux2->a->s = aux2->s;
					aux2->s = inicio->s;
					inicio->s->a = aux2;
					inicio->s = aux2;
					aux2->a = inicio;
				}


				for (int i = 0; i < tam - 1; i++) {
					if (aux->s->e->getPrioridad() == 0) {
						aux2 = aux->s;
						aux->s = aux2->s;
						fin->s = aux2;
						fin = aux2;
					}
					else {
						aux = aux->s;
					}
				}

			}
			mostrar();
		}
		
	}

	T getNodo() {
		Nodo<T>* aux = inicio;
		return aux->e;
	}

	bool is_Empty() {
		if (tam == 0) { return true; }
		else {
			return false;
		}
	}
	void mostrar() {
		Nodo<T>* aux = inicio;
		if (tam == 0) { cout << "No existen personas registradas en el sistema"; }
		else {
			for (int i = 0; i < tam; i++) {
				cout << i + 1 << ".-" << aux->e->getNombre() << ", " << aux->e->getEdad() << ", " << aux->e->getDNI() << ", " << aux->e->getPrioridad() << endl;
				aux = aux->s;
			}
		}
		cout << endl;
	}

	void vaciar_Cola() {

		for (; !is_Empty();) {
			Nodo<T>* aux = inicio;
			inicio = inicio->s;
			delete aux;
			tam--;
		}
	}

	int getTam() { return tam; }

	T getFin() {
		return fin->e;
	}

	bool verif(Nodo<T>* nodo, Nodo<T>* nuevo) {

		auto lambda = [](int a, int b) { if (a != b) { return false; } else { return true; }};

		return lambda(nodo->e->getDNI(), nuevo->e->getDNI());
	}

};
