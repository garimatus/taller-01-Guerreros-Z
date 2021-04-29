#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#include "funciones.h"




std::vector<estudiante> obtenerNotas(std::istream& lectura)
{
    std::string linea;
    std::vector<estudiante> notas;

    while (std::getline(lectura, linea, '\n'))
    {
        estudiante temp;
        std::stringstream ss(linea);
        std::string item;
        int columna = 0;

        while (std::getline(ss, item, ';'))
        {
            if (columna == 0)
                temp.id_numerico = atoi(item.c_str());
            
            if (columna == 1)
                temp.id_generico = item.c_str();
            
            if (columna == 2)
                temp.prom_len = atof(item.c_str());
            
            if (columna == 3)
                temp.prom_ing = atof(item.c_str());
            
            if (columna == 4)
                temp.prom_mat = atof(item.c_str());
            
            if (columna == 5)
                temp.prom_sci = atof(item.c_str());
            
            if (columna == 6)
                temp.prom_his = atof(item.c_str());
            
            if (columna == 7)
                temp.prom_tec = atof(item.c_str());
            
            if (columna == 8)
                temp.prom_art = atof(item.c_str());
            
            if (columna == 9)
                temp.prom_edf = atof(item.c_str());
            
            ++columna;
        }

        notas.push_back(temp);
    }
    
    return notas;
}