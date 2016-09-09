#include "herramientas.cpp"

int main(int args, char** argv)
{
herramientas* h = new herramientas();
h->inicializarDatosCedula("datosCedula.txt");
h->inicializarDatosSinCedula("datosSinCedula.txt");
h->rellenarCedulas();
h->construirSalida("datosSalida.txt");
}

