#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>

#include "funciones.h"



/*
* Operadores de criterio.
*/
struct {
    bool operator()(estudiante& a, estudiante& b) { return a.prom_gen > b.prom_gen; };
}maximos;

struct {
    bool operator()(estudiante& a, estudiante& b) { return a.prom_art_edf > b.prom_art_edf; };
}artistico;

struct {
    bool operator()(estudiante& a, estudiante& b) { return a.prom_len_his > b.prom_len_his; };
}humanismo;

struct {
    bool operator()(estudiante& a, estudiante& b) { return a.prom_tec_mat_sci > b.prom_tec_mat_sci; };
}tecnicos;

/* 
*@param lectura El stream de texto desde la memoria de la función main.
*@return notas El vector de todas las notas del archivo.
*/
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

            ++columna;
        }

        /*
        * Cálculo del promedio.
        */
        temp.prom_gen = double((temp.prom_len+temp.prom_ing+temp.prom_mat+temp.prom_sci+temp.prom_his+temp.prom_tec+temp.prom_art+temp.prom_edf)/8.0);
        temp.prom_art_edf = double((temp.prom_art+temp.prom_edf)/2.0);
        temp.prom_len_his = double((temp.prom_len+temp.prom_his)/2.0);
        temp.prom_tec_mat_sci = double((temp.prom_tec+temp.prom_mat+temp.prom_sci)/3.0);

        notas.push_back(temp);
    }
    
    return notas;
}

/* 
* @param notas Vector con las notas relativas de los aún no seleccionados.
* @param Criterio El criterio a elegirse desde main.
* @param n Cantidad de estudiantes a seleccionar.
* @return seleccionados El vector de los selccionados.
*/
std::vector<estudiante> sort(std::vector<estudiante> notas, std::string criterio, int n)
{
    std::vector<estudiante> seleccionados;

    if (criterio == "maximos")
    {
        std::sort(notas.begin(), notas.end(), maximos);

        for(int i = 0; i < n; ++i)
        {
            estudiante aux = notas.front();
            notas.erase(notas.begin());
            aux.aptitud = new char[criterio.length()+1];
            std::strcpy(aux.aptitud, criterio.c_str());
            seleccionados.push_back(aux);
        }
    }

    if (criterio == "artistico")
    {
        std::sort(notas.begin(), notas.end(), artistico);

        for(int i = 0; i < n; ++i)
        {
            estudiante aux = notas.front();
            notas.erase(notas.begin());
            aux.aptitud = new char[criterio.length()+1];
            std::strcpy(aux.aptitud, criterio.c_str());
            seleccionados.push_back(aux);
        }
    }

    if (criterio == "humanismo")
    {
        std::sort(notas.begin(), notas.end(), humanismo);

        for(int i = 0; i < n; ++i)
        {
            estudiante aux = notas.front();
            notas.erase(notas.begin());
            aux.aptitud = new char[criterio.length()+1];
            std::strcpy(aux.aptitud, criterio.c_str());
            seleccionados.push_back(aux);
        }
    }

    if (criterio == "tecnicos")
    {
        std::sort(notas.begin(), notas.end(), tecnicos);

        for(int i = 0; i < n; ++i)
        {
            estudiante aux = notas.front();
            notas.erase(notas.begin());
            aux.aptitud = new char[criterio.length()+1];
            std::strcpy(aux.aptitud, criterio.c_str());
            seleccionados.push_back(aux);
        }
    }
    
    return seleccionados;
}

/*
@param seleccionados Vector con los seleccionados a escribirse.
@return Ninguno.
*/
void escribir(std::vector<estudiante> seleccionados)
{
    std::ofstream salida;

    std::string aptitud = seleccionados.begin() -> aptitud;
    
    salida.open("./"+std::string(aptitud)+".csv");
    
    salida << "id;nombre;promedio" << std::endl;

    if (aptitud == "maximos")
    {
        for(std::vector<estudiante>::iterator it = seleccionados.begin(); it !=  seleccionados.end(); ++it )
            salida << std::to_string(it -> id_numerico)+';'+std::string(it -> id_generico)+';'+std::to_string(it -> prom_gen) << std::endl;
    }

    if (aptitud == "artistico")
    {
        for(std::vector<estudiante>::iterator it = seleccionados.begin(); it !=  seleccionados.end(); ++it )
            salida << std::to_string(it -> id_numerico)+';'+std::string(it -> id_generico)+';'+std::to_string(it -> prom_art_edf) << std::endl;
    }

    if (aptitud == "humanismo")
    {
        for(std::vector<estudiante>::iterator it = seleccionados.begin(); it !=  seleccionados.end(); ++it )
            salida << std::to_string(it -> id_numerico)+';'+std::string(it -> id_generico)+';'+std::to_string(it -> prom_len_his) << std::endl;
    }

    if (aptitud == "tecnicos")
    {
        for(std::vector<estudiante>::iterator it = seleccionados.begin(); it !=  seleccionados.end(); ++it )
            salida << std::to_string(it -> id_numerico)+";"+std::string(it -> id_generico)+';'+std::to_string(it -> prom_tec_mat_sci) << std::endl;
    }
    
}

/*
*@param Ninguno.
*@return Ninguno.
*/
void integrantes()
{
    std::cout << "----------------------\n  ===Integrantes===\n    -Edgar Matus\n    -Alex Bidart\n    -Nicolas Jimenez\n----------------------" << std::endl;
}