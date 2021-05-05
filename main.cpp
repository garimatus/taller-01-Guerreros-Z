#include <iostream>
#include <fstream>
#include <vector>

#include "dependencias/funciones.h"

int n=0;

int main(int argc, char** argv)
{

    std::string ruta = argv[1];

    std::ifstream lectura;
    lectura.open(ruta, std::ios_base::in);

    if (lectura && std::string(ruta.substr(ruta.length()-15, 15)) == "estudiantes.csv")
    {
        std::vector<estudiante> notas = obtenerNotas(lectura);
        
        for (std::vector<estudiante>::iterator it = notas.begin(); it != notas.end(); it++, n++)
    {

        std::cout<<notas.at(n).prom_len<<std::endl;

    }
    
        lectura.close();

    } else {
        
        std::cout << "El archivo solicitado 'estudiantes.csv' no existe o no se encuentra en el directorio ingresado." << std::endl;

        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}