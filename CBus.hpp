#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "CPersona.hpp"
using namespace std;

class CBus {
private:
	string destino;
	vector<CPersona*> vecP;
	unsigned int capacidad;
public:
	CBus(string destino) : destino(destino) { this->capacidad = 40; }

	string getDestino() { return destino; }
	unsigned int getCapacidad() { return capacidad; }
	void setCapacidad(unsigned int capacidad) { this->capacidad = capacidad; }
	void agregar_Persona(CPersona* objP) {
		if (capacidad <= 0) { cout << "No se pudo agregar a " << objP->getNombre(); }
		else {
			vecP.push_back(objP); capacidad--;
		}
		 
	}
	void mostrar_Vector() {
		if (vecP.size() <= 0) { cout << "No existen personas asignadas a este bus" << endl << endl; }
		else {
			for (int i = 0; i < vecP.size(); i++) {
				cout << "/--------- " << i + 1 << "---------/" << endl;
				cout << vecP.at(i)->getNombre() << endl;
				cout << vecP.at(i)->getDNI() << endl;
				cout << vecP.at(i)->getPrioridad() << endl;
				cout << vecP.at(i)->getEdad() << endl << endl;
			}
		}
	}
};
