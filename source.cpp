#include <fstream>
#include "Driver.hpp"

using namespace Driver;

void get_Buses(ifstream& arcL, CLista_R<CBus*>* objLista) {
	CBus* objB;
	char c = ',';
	string destino; unsigned int cap;
	const char *val;
	arcL.open("Buses.txt");
	while (getline(arcL, destino)) {

		objB = new CBus(destino);
		objLista->ingresar(objB);

	}
	arcL.close();

}

int main() {
	/*ofstream arc;

	CPersona* objP = new CPersona("Pepe", 40, 123456);

	CBus* objBus = new CBus("Piura");
	CBus* objBus2 = new CBus("Tacna");

	CCola<CPersona*>* objCola = new CCola<CPersona*>();
	CLista_R<CBus*>* Lista_R = new CLista_R<CBus*>();

	objCola->queue(objP);
	guardar_Persona(arc, objP);

	objP = new CPersona("LOLO", 50, 789456);

	objCola->queue(objP);
	guardar_Persona(arc, objP);
	objP = new CPersona("GOWO", 18, 789132);

	objCola->queue(objP);
	guardar_Persona(arc, objP);
	Lista_R->prepararBus(objBus);
	Lista_R->prepararBus(objBus2);

	objCola->mostrar();


	cout << "/-------------------------/" << endl;

	Lista_R->mostrar();
	*/

	CCola<CPersona*>* objCola = new CCola<CPersona*>();
	CLista_R<CBus*>* objLista = new CLista_R<CBus*>();
	ofstream arcE;
	ifstream arcL;

	get_Buses(arcL, objLista);

	Driver::iniciar(objLista, objCola, arcE, arcL);

	system("pause");
	system(EXIT_SUCCESS);
}
