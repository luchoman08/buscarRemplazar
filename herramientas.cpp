#include <stdio.h>
#include "herramientas.hpp"

void herramientas::inicializarDatosCedula(string nombreArchivo){
  string tmpCodigo = "";
  string tmpCedula = "";
  datosCedula.open (nombreArchivo.c_str(), std::fstream::in);
  int i = 0;
   while(!datosCedula.eof()) {
	  if(i % 2 == 0){
		datosCedula>>tmpCodigo;  		 
	  }
	  if(i % 2 == 1){
		datosCedula>>tmpCedula;  
		estructuraCedulas.push_back(make_pair(tmpCodigo, tmpCedula)); 
	  }
	  ++i;

   }
	datosCedula.close();
}
void herramientas::inicializarDatosSinCedula(string nombreArchivo){
  string tmpCodigo = "";
  string tmpCedula = "";
  datosSinCedula.open (nombreArchivo.c_str(), std::fstream::in);
   while(!datosSinCedula.eof()) {
        
		datosSinCedula>>tmpCodigo;
		
		estructuraSinCedulas.push_back(make_pair(tmpCodigo, tmpCedula)); 
	  }
	  datosSinCedula.close();

}
 auto func = [] (pair<string, string> par1, pair<string, string> par2){
	
	return atoi( par1.first.c_str() ) < atoi( par2.first.c_str() );

	
};

bool herramientas::concordanciaCodigo(pair<string, string> estructura, string codigo){
	if(estructura.first == codigo)
	return true;
	else
	return false;
}
void herramientas::ordenarDatosCedula(){
	std::sort(estructuraCedulas.begin(), estructuraCedulas.end(), func);
}

void herramientas::construirSalida(string nombreArchivo){
	fstream salida; 
	salida.open(nombreArchivo.c_str(), std::fstream::out);
	for(vector<pair<string,string> >::iterator i = estructuraSinCedulas.begin(); i != estructuraSinCedulas.end(); i++){
		salida << i->first<<"	" << i->second << endl;
		
		cout << i->first<<" " << i->second << endl;
	}
	salida.close();
}

void herramientas::rellenarCedulas(){
    
    for(vector<pair<string,string> >::iterator i = estructuraSinCedulas.begin(); i != estructuraSinCedulas.end(); i++){
    const string codigo = i->first;
    vector<pair<string,string> >::iterator it = std::find_if (estructuraCedulas.begin(), estructuraCedulas.end(), 
    
    [codigo](const pair<string,string> & m) -> bool { return m.first == codigo ; }
    
    );
    if(*it != estructuraSinCedulas.back())
    i->second = it->second;
    }
   
    
}
