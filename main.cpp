#include <iostream>
#include <fstream>
#include <vector>

#include "dependencias/funciones.h"


/*
*@param argc Cantidad de argumentos.
*@argv Matriz de argumentos.
*@return Código de salida.
*/
int main(int argc, char** argv)
{
    std::string ruta = argv[1];

    std::ifstream lectura;
    
    lectura.open(ruta, std::ios_base::in);

    if (lectura && std::string(ruta.substr(ruta.length()-15, 15)) == "estudiantes.csv")
    {
        /* 
        * Se obtiene el vector.
        */
        std::vector<estudiante> notas = obtenerNotas(lectura);

        /*
        * Se escriben los vectores de los seleccionados según el criterio del segundo parámetro.
        */
        escribir(sort(notas, "maximos", 100));

        escribir(sort(notas, "artistico", 100));

        escribir(sort(notas, "humanismo", 100));

        escribir(sort(notas, "tecnicos", 100));

        lectura.close();

    } else {
        
        std::cout << "El archivo solicitado 'estudiantes.csv' no existe o no se encuentra en el directorio ingresado." << std::endl;

        integrantes();

        return EXIT_FAILURE;
    }
    
    integrantes();

    return EXIT_SUCCESS;
}