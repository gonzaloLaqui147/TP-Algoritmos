#pragma once
#include <string>

using namespace std;

class CPersona {
private:
	string nombre, destino;
	int edad, DNI, prioridad;
public:
	CPersona(string _nombre, string _destino, int _edad, int _DNI, int _prioridad) {
		this->nombre = _nombre; this->destino = _destino;
		this->edad = _edad; this->DNI = _DNI;
		this->prioridad = _prioridad;
	}

	string getNombre() { return nombre; }
	string getDestino() { return destino; }
	int getEdad() { return edad; }
	int getDNI() { return DNI; }
	int getPrioridad() { return prioridad; }

	void setNombre(string nombre) { this->nombre = nombre; }
	void setDestino(string destino) { this->destino = destino; }
	void setEdad(int edad) { this->edad = edad; }
	void setDNI(int DNI) { this->DNI = DNI; }
	void setPrioridad(int prioridad) { this->prioridad = prioridad; }
};
