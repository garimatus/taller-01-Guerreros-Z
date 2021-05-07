#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <sstream>
#include <algorithm>

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
            {
                item=item.substr(1,item.length()-2);
                temp.id_numerico = atoi(item.c_str());
            }
            if (columna == 1)
            {
                item=item.substr(1,item.length()-2);
                temp.id_generico = new char[item.length()+1];
                std::strcpy(temp.id_generico, item.c_str());
            }
            if (columna == 2)
            {
                item=item.substr(1,item.length()-2);
                temp.prom_len = atof(item.c_str());
            }
            if (columna == 3)
            {
                item=item.substr(1,item.length()-2);
                temp.prom_ing = atof(item.c_str());
            }
            if (columna == 4)
            {
                item=item.substr(1,item.length()-2);
                temp.prom_mat = atof(item.c_str());
            }
            if (columna == 5)
            {
                item=item.substr(1,item.length()-2);
                temp.prom_sci = atof(item.c_str());
            }
            if (columna == 6)
            {
                item=item.substr(1,item.length()-2);
                temp.prom_his = atof(item.c_str());
            }
            if (columna == 7)
            {
                item=item.substr(1,item.length()-2);
                temp.prom_tec = atof(item.c_str());
            }
            if (columna == 8)
            { 
                item=item.substr(1,item.length()-2);
                temp.prom_art = atof(item.c_str());
            }
            if (columna == 9)
            {
                item=item.substr(1,item.length()-2);
                temp.prom_edf = atof(item.c_str());
            }

            temp.prom_gen = double((temp.prom_len+temp.prom_ing+temp.prom_mat+temp.prom_sci+temp.prom_his+temp.prom_tec+temp.prom_art+temp.prom_edf)/8.0);
            temp.prom_art_edf = double((temp.prom_art+temp.prom_edf)/2.0);
            temp.prom_len_his = double((temp.prom_len+temp.prom_his)/2.0);
            temp.prom_tec_mat_sci = double((temp.prom_tec+temp.prom_mat+temp.prom_sci)/3);

            ++columna;
        }

        notas.push_back(temp);
    }
    
    return notas;
}