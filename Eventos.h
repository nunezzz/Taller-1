#pragma once
#include <iostream>
using namespace std; 

// en la clase que tiene .h va solamente lo basico y el nombre de los metodos nada mas 

class Eventos
{
    private:
        string tipo;
        string fecha;
        int duracion;
        string ubicacion;
        
        // Asistentes asitente;
       
   
   public:
    Eventos (string, string,int, string);
    
        string getTipo();
        string getFecha();
        int getDuracion();
        string getUbicacion();
        
       
        void setTipo(string);
        void setFecha(string);
        void setDuracion(int);
        void setUbicacion(string);
        
};