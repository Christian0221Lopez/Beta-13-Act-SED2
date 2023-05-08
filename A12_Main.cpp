/*
Alumno: Lopez Rodriguez Christian Adrian
Codigo: 218022125
Actividad #13
*/
#include <vector> // incluir la librería vector

#include <iostream>
#include "Prototipo.h"
#include "Funciones.cpp"

using namespace std;

int main(int argc, char *argv[])
{
    Lista M;

    std::cout << "Have " << argc << " arguments:" << std::endl;
    for (int i = 0; i < argc; ++i) {
        std::cout << argv[i] << std::endl;
    }

    //string var = argv[1];
    string var = "Lineas de CDMX.txt";
    //M.Recuperar(var);
    M.Menu(var);

    return 0;
}
