#ifndef HERRAMIENTAS_HPP
#define HERRAMIENTAS_HPP
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class herramientas {
	
	private:
	fstream datosCedula;
	fstream datosSinCedula;
	vector<pair<string, string> > estructuraCedulas; //pair <codigo, cedula>
	vector<pair<string, string> > estructuraSinCedulas; // pair <codigo, empty> en principio no habra cedulas, luego si lo habra despues de ejecutar el rellenar cedula
	
	public :
	 
	
	 void inicializarDatosCedula(string nombreArchivo);
	 void inicializarDatosSinCedula(string nombreArchivo);
	 void rellenarCedulas();
	 bool concordanciaCodigo(pair<string, string> estructura, string codigo); //dice si dado un codigo el par a buscar es igual
	 void ordenarDatosCedula();
	 void construirSalida(string nombreArchivo); //se encarga de guardar el codigo y la cedula en un archivo de salida 	la salida estar en estructuraSinCedula despues de ejecutar rellenar cedula
};


#endif
