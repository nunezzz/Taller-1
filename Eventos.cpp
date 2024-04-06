#include <iostream>
#include "Eventos.h"
using namespace std;

Eventos::Eventos(string tipo, string fecha, int duracion, string ubicacion)
{
    this -> tipo = tipo;
    this -> fecha = fecha;
    this -> duracion = duracion;
    this -> ubicacion = ubicacion;
    
}

string Eventos :: getTipo(){return this-> tipo;}
void Eventos :: setTipo(string tipo){this->tipo = tipo;}
string Eventos :: getFecha(){return this-> fecha;}
void Eventos :: setFecha(string fecha){this -> fecha= fecha;}
int Eventos :: getDuracion(){return this-> duracion;}
void Eventos :: setDuracion(int duracion){this-> duracion = duracion;}
string Eventos :: getUbicacion(){return this-> ubicacion;}
void Eventos :: setUbicacion(string ubicacion){this-> ubicacion = ubicacion;}








