#pragma once 
#include <iostream>

using namespace std;

class Asistentes
{
    private:
        string tipo;
        string nombre;
        int edad;
        string ocupacion;
        string institucionEmpresa;
        string tipoEvento;
    
    public:
        Asistentes(string, string , int, string, string,string);
        
            string getTipo();
            string getNombre();
            int getEdad();
            string getOcupacion();
            string getInstitucionEmpresa();
            string getTipoEvento();

            void setTipo(string);
            void setNombre(string);
            void setEdad(int);
            void setOcupacion(string);
            void setInstitucionEmpresa(string);
            void setTipoEvento(string);

};