#include <iostream>
#include "Asistentes.h"
using namespace std;

Asistentes :: Asistentes (string tipo, string nombre, int edad, string ocupacion, string institucionEmpresa, string tipoEvento)
{
    this -> tipo = tipo;
    this -> nombre = nombre;
    this -> edad = edad;
    this -> ocupacion = ocupacion;
    this -> institucionEmpresa = institucionEmpresa;
    this -> tipoEvento = tipoEvento;
}

string Asistentes :: getTipo(){return this-> tipo;}
void Asistentes :: setTipo(string tipo){this -> tipo = tipo;}
string Asistentes :: getNombre(){return this -> nombre;}
void Asistentes :: setNombre(string nombre){this -> nombre = nombre;}
int Asistentes :: getEdad(){return edad;}
void Asistentes :: setEdad(int edad){this -> edad = edad;}
string Asistentes :: getOcupacion(){return this-> ocupacion;}
void Asistentes :: setOcupacion(string ocupacion){this -> ocupacion = ocupacion;}
string Asistentes :: getInstitucionEmpresa(){return this -> institucionEmpresa;}
void Asistentes :: setInstitucionEmpresa(string institucionEmpresa){this -> institucionEmpresa = institucionEmpresa;}
string Asistentes :: getTipoEvento(){return this-> tipoEvento;}
void Asistentes :: setTipoEvento(string tipoEvento){this-> tipoEvento = tipoEvento;}

