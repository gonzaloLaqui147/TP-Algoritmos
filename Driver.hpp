#pragma once
#include "CPersona.hpp"
#include "CBus.hpp"
#include "CCola.hpp"
#include "CLista_R.hpp"
#include <sstream>
#include <Windows.h>

using namespace System;

namespace Driver {

	void gotoxy(short x, short y) {
		COORD coord = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}

	void menu()	 {

		gotoxy(45, 13); cout << "1. Registrar Persona    ";
		gotoxy(45, 14); cout << "2. Mostrar Personas Registradas";
		gotoxy(45, 15); cout << "3. Mostrar Buses    ";
		gotoxy(45, 16); cout << "4. Enviar Pasajeros ";
		gotoxy(45, 17); cout << "0. Salir            ";
		gotoxy(45, 18);

	}

	void enviar(CLista_R<CBus*>*& objLista, CCola<CPersona*>* objCola) {
		if (objCola->getTam() == 0) { cout << "No existen personas registradas\n"; }
		else {
			//cout << "/------------------ Piura ------------------/\n";

			
			
		}
	}

	void guardar_Persona(ofstream& arc, CPersona* obj) {

		arc.open("Registrar Personas.txt", ios::app);

		if (arc.is_open()) {
			arc << obj->getNombre() << ", " << obj->getEdad() << ", " << obj->getDNI() << endl;
		}
		else {
			cout << "An error has ocurred" << endl;
			cin.get();
			exit(1);
		}
		arc.close();
	}


	void registrar(CLista_R<CBus*>* objLista, CCola<CPersona*>* objCola, ofstream& arcE) {
		CPersona* objP;
		string a, b, c, nombre, destino; int edad, DNI, prioridad;

		cout << "/------------------------ Registro ---------------------------/";
		cout << "\nSeleccione una opcion(1: Embarazada o Adulto Mayor | 0:Ninguna): "; cin >> prioridad;
		cout << "\nIngrese su primer nombre, apellido paterno y apelldio materno: "; cin >> a >> b >> c;
		cout << "\nIngrese numero de DNI: "; cin >> DNI;
		cout << "\nIngrese la edad: "; cin >> edad;
		cout << "\nCon destino a: "; cin >> destino;

		//Concatenar a,b y c para formar nombre
		nombre = a + " " + b + " " + c;
		
		if(objLista->getNodo(destino)->getCapacidad() == 0){
			cout << "El bus ha excedido su capacidad, intente mas tarde" << endl;
		}
		else {
			objP = new CPersona(nombre, destino, edad, DNI, prioridad);

			//La funcion booleana evita que se guarde a la misma persona más de una vez
			if (objCola->queue(objP)) {
				Driver::guardar_Persona(arcE, objP);
				objLista->getNodo(destino)->agregar_Persona(objP);
			}
		}

	}


	void iniciar(CLista_R<CBus*>*& objLista, CCola<CPersona*>*& objCola, ofstream& arcE, ifstream& arcL) {
		int op;
		do {
			system("cls");
			do {
				menu();
				cin >> op;
			} while (op != 0 && op != 1 && op != 2 && op != 3 && op != 4);
			system("cls");
			switch (op) {
			case 1:
				registrar(objLista, objCola, arcE);
				break;
			case 2:
				objCola->priorizar();
				cout << endl << endl;

				_sleep(10000);
				break;
			case 3:
				objLista->mostrar();
				_sleep(5000);
				break;
			case 4:
				objCola->vaciar_Cola();
				_sleep(3000);
				objCola->mostrar();
			default:
				break;
			}
		} while (op != 0);

	}
}
