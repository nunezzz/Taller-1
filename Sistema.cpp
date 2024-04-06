#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include <set>
#include <map>
#include "Eventos.h"
#include "Asistentes.h"
using namespace std;

vector<Eventos*> listaEventos; // listas dinamicas de los eventos 
vector<Asistentes*> listaAsistentes; // listas dinamicas de los asistentes

vector<string> divideLineas (string str, char separador) // separa los elementos de mi archivo por partes 
{
    vector<string> partes;
    stringstream ss(str);
    string parte;

    while (getline(ss, parte, separador)) {
        partes.push_back(parte);
    }
    return partes;
}

void cargarArchivosEventos()  // Función que realiza lectura de archivo de "eventos.txt"
{
    string linea;
    ifstream archivo("eventos.txt");
    char separador = ',';
   
    while (getline(archivo, linea))
    {
        vector<string> partes = divideLineas(linea, separador);
        string tipo = partes[0];
        string fecha = partes[1];  
        int duracion = stoi(partes[2]); // me convierte una variable de int a string
        string ubicacion = partes[3];

        Eventos* even = new Eventos (tipo,fecha,duracion,ubicacion); //Se instancia un objeto tipo 'Eventos' con los datos ingresados.
        listaEventos.push_back(even); // Se añade el nuevo objeto a la lista de eventos.
    }
    archivo.close();
}
//Función que realiza lectura de archivos de "asistentes.txt"
void cargarArchivosAsistentes()
{
    string linea;
    ifstream archivo("asistentes.txt");
    char separador = ',';

    while(getline(archivo,linea))
    {
        vector<string> partes = divideLineas(linea,separador);
        string tipo = partes[0];
        string nombre = partes[1];
        int edad = stoi(partes[2]); // me convierte variable pasa de int a string
        string ocupacion = partes[3];
        string instiEmpresa = partes[4];
        string tipoEvento = partes[5];

        Asistentes* asis = new Asistentes(tipo, nombre,edad, ocupacion, instiEmpresa,tipoEvento); //Se instancia un objeto tipo 'Asistentes' con los datos ingresados.
        listaAsistentes.push_back(asis); // Se añade el nuevo objeto a la lista de eventos.
    }
    archivo.close();

}
// Función que sobreescribe los datos de eventos ingresados por pantalla en mi txt
void sobreEscribirArchivo()
{
    ofstream archivoEventos ("eventos.txt");
    
    if(!archivoEventos.is_open()) //Comprueba que mi archivo este abierto 
    {
        cout<<"Error al guardar los cambios en Eventos"<<endl;
        return;
    }
    for(Eventos* even : listaEventos) // itero en la lista de eventos
    {
        int duracion = even->getDuracion();
        string dura = to_string(duracion); // paso de int a string el dato 
        string datos = even -> getTipo() + "," + even -> getFecha() + "," + dura + "," + even-> getUbicacion()+ "\n";
        archivoEventos << datos; // agrega los datos ingresado a mi archivo 
    }
    
    archivoEventos.close();
}

// Función para ingresar eventos.
void agregarEvento()
{
    // Detalles del evento a ingresar pedidos por pantalla.
    string tipo;
    cout<<"- Ingrese le tipo de evento: "<<endl;
        cin>>tipo;
    string fecha;
    cout<<"- Ingrese la fecha del Evento (dd-mm-aaaa): "<<endl;
        cin>>fecha;
    int duracion;
    cout<<"- Ingrese la duracion del Evento (minutos): " <<endl;
        cin>>duracion;
    string ubicacion;
    cout<<"- Ingrese la ubicacion del Evento: "<<endl;
        cin.ignore();  // me limpia la entrada antes de llamar al getline()
        getline(cin,ubicacion); // leerme los espacios 
   
    Eventos* evento = new Eventos(tipo,fecha,duracion,ubicacion);// Se crea objeto tipo 'Eventos' con los datos ingresados.
    listaEventos.push_back(evento); // Se añade el nuevo objeto a la lista de eventos.
    sobreEscribirArchivo(); // se llama a la funcion que sobreescribe el archivo 
    
    cout<<"~ El evento se agrego con exito ~"<<endl;
}
// Función que sobreescribe los datos de eventos ingresados por pantalla en mi txt
void sobreEscribirArchivo2()
{
    ofstream archivoEventos ("asistentes.txt");
    
    if(!archivoEventos.is_open()) //comprueba que mi archivo este abierto.
    {
        cout<<"Error al guardar los cambios en Eventos"<<endl;
        return;
    }
    for(Asistentes* asis : listaAsistentes) //itero en la lista asistentes
    {
        int edad = asis->getEdad();
        string edadstr= to_string(edad); // paso el dato de int a string
        string datos = asis-> getTipo() + "," + asis-> getNombre() + "," + edadstr + "," + asis-> getOcupacion() + "," + asis->getInstitucionEmpresa() + "," + asis->getTipoEvento()+"\n";
        archivoEventos << datos; // agrega los datos ingresado a mi archivo 
    }
    archivoEventos.close();
    
}

// Función para registrar asistentes.
void registroAsistente()
{
    // Información del asistente a registrar pedidos por pantalla.
    string nombre;
    cout<<"- Ingrese su nombre: "<<endl;
        cin.ignore();
        getline(cin,nombre);
    int edad;
    cout<<"- Ingrese su edad: "<<endl;
        cin>>edad;
    string ocupacion;
    cout<<"- Ingrese su ocupación: "<<endl;
        cin.ignore();
        getline(cin,ocupacion);
    string tipo;
    cout<<"- Ingrese tipo de asistente: "<<endl;
        cin>>tipo;
    string instiEmpresa;
    cout<<"- Ingrese institucion/empresa que pertenezca: "<<endl;
        cin.ignore();
        getline(cin,instiEmpresa);
    string tipoEvento;
    cout<<"- Ingrese tipo de evento al que asiste: " <<endl;
        cin>> tipoEvento;

    Asistentes* asistente = new Asistentes(tipo,nombre,edad,ocupacion,instiEmpresa,tipoEvento); // Se crea objeto tipo 'Asistentes' con los datos ingresados.
    listaAsistentes.push_back(asistente); // Se añade el nuevo objeto a la lista de asistentes.
    sobreEscribirArchivo2(); // se llama a la funcion que sobreescribe el archivo 
}

// Función para ver información de los asistentes ingresados.
void consultarListaAsistentes()
{
    cout<<""<<endl;
    cout <<"-----------------------------------------------------------------------------------------------"<<endl;
    cout<<"Lista de Asistentes"<<endl;
    cout<<"-----------------------------------------------------------------------------------------------"<<endl;
    for(Asistentes* ptrAsis : listaAsistentes) // Se itera en la lista de asistentes.
    {
        // Se muestra por pantalla la información de cada uno.
        cout<< "Nombre: " << ptrAsis -> getNombre() <<" |edad: "<< ptrAsis -> getEdad() << " |Ocupacion: "<< ptrAsis -> getOcupacion()<<" |Tipo: "<< ptrAsis-> getTipo()<<" |Institución/Empresa: "<< ptrAsis->getInstitucionEmpresa()<<endl;
    }
    
}
// Función para ver información de los eventos programados.
void listaEventosProgramados()
{

    cout<<"---- Lista de Eventos Programados ----" <<endl;
    for(Eventos* even : listaEventos) // Se itera en la lista de eventos.
    {
    // Se muestra por pantalla la información de cada uno.
     cout<<"Tipo: "<< even->getTipo()<<"|Fecha: "<< even->getFecha()<<" |Duración: "<< even->getDuracion()<< "|Ubicación: "<< even->getUbicacion()<<endl;
    
    }
}

// Funnción para ver los asistentes registrados por evento.
void listaAsistentesRegistrados()
{             
   /*
   el set no guarda dos veces el mismo elemento
   se debe de añadir la libreria <set>
   */             
    set<string> eventosMostrados; // lista para almacenar los eventos solo uno vez y que estos no se repitan 

    cout<<"---- Lista de Asistentes registrados por Evento ----" <<endl;
    for(Eventos* even : listaEventos) // Se itera en la lista de eventos.
    {
        if(eventosMostrados.find(even->getTipo()) == eventosMostrados.end()) // Verifica si el tipo de evento ya se ha mostrado previamente.
        {
            eventosMostrados.insert(even->getTipo()); // Si el evento no se ha mostrado previamente, se agrega su tipo a la lista de eventosMostrados.
            
            cout<<"------------------------------------------------------"<<endl;
            cout<<"Evento:"<< even -> getTipo()<<endl;
            cout<<"------------------------------------------------------"<<endl;
            cout<<"** Asistentes **"<<endl;
            
            for(Asistentes* asis : listaAsistentes)
            {
                if(asis -> getTipoEvento() == even -> getTipo()) // Verifica si el tipo de evento al que asistió el asistente coincide con el tipo de evento actual.
                {
                    cout<<"Nombre: "<<asis -> getNombre()<<"| Edad: "<< asis->getEdad()<<"| Ocupación: "<<asis->getOcupacion()<<"| Institucion/Empresa: "<< asis->getInstitucionEmpresa()<<endl;
                }
             }
        }
    }
}

// Función para calcular la asistencia total por evento.
void asistenciaTotal()
{
    // Este mapa se utilizará para almacenar el recuento total de asistentes para cada tipo de evento.
    map<string,int> asistencia;
    cout<< "--- Asistencia Total por Evento ---"<<endl;

    for(Asistentes* asis : listaAsistentes)
    {
        // Incrementa el contador de asistencia para el tipo de evento al que pertenece el asistente actual.
        asistencia[asis->getTipoEvento()]++; 
    }
    for(auto const& ma : asistencia)
    {
        // Imprime el nombre del evento y la cantidad total de asistentes para ese evento.
        cout<<"Evento: "<< ma.first <<", asistencia: "<< ma.second <<endl;
    }
}
void eventoConMayorYMenorAsistencia()
{
    // Este mapa se utilizará para almacenar el recuento de asistentes por evento para encontrar el evento con la mayor asistencia.
    map<string,int> mayorAsistencia;
     // Este mapa se utilizará para almacenar el recuento de asistentes por evento para encontrar el evento con la menor asistencia.
    map<string,int> menorAsistencia;
    int mayor = mayorAsistencia.begin()->second;
    int menor = menorAsistencia.begin()->second;
    string nomMenor;
    string nomMayor;
   
   cout<<" "<<endl;
   cout<<"--- Evento con más asistencia ---"<< endl;
    for(Asistentes* asis : listaAsistentes)
    {
        mayorAsistencia[asis->getTipoEvento()]++;
    }
    for(auto const& ma : mayorAsistencia) // Itera sobre el mapa mayorAsistencia para encontrar el evento con la mayor cantidad de asistentes.
    {
        if(ma.second > mayor)
        {
            mayor = ma.second; //guarda en la variable la mayor asistencia 
            nomMayor = ma.first; // guarda en la variable el nombre de la mayor asistencia 
        }
    }
    cout<<"El evento: "<< nomMayor<<" es el con mayor asistencia, asisten: "<<mayor<<endl;
    
    cout<<""<<endl;
    cout<<"--- Evento con menor asistencia ---"<< endl;
    for(Asistentes* asis : listaAsistentes)
    {
        menorAsistencia[asis->getTipoEvento()]++;
    }
    for(auto const& ma : menorAsistencia) // Itera sobre el mapa menorAsistencia para encontrar el evento con la menor cantidad de asistentes.
    {
        if(ma.second < menor)
        {
            menor = ma.second; // guarda en la variable la menor asistencia 
            nomMenor = ma.first; // guarda en la variable el nombre de la menor asistencia
        }
    }
     cout<<"El evento: "<< nomMenor <<" es el con menor asistencia, asisten: "<< menor <<endl;

}

// Función para ver estadísticas calculadas.
void estadisticasAsistenciasEventos()
{
    asistenciaTotal(); 
    int totalAsistentes = listaAsistentes.size();
    cout<<" "<<endl;
    cout<<"---- Número Total de Asistentes ----"<<endl;
    cout<<totalAsistentes<<endl;
    eventoConMayorYMenorAsistencia();
}

// Función para ver información especifica de los eventos 
void informacionEventos()
{
    string eventoIngresado;  // se pide por pantalla el evento por el cual desea preguntar
    cout<<""<<endl;
    cout<<"Ingrese el Evento: "<< endl;
    cin>>eventoIngresado;

    cout<<"Evento: "<< eventoIngresado<<endl;
    cout<<"------------------------------------------------------"<<endl;
    cout<<"-- Eventos Relacionados --"<<endl;
    for(Eventos* even : listaEventos) 
    {
        if(eventoIngresado == even ->getTipo()) // La respuesta ingresada se compara con los eventos ya existentes
        {
            // Se imprimen los eventos relacionados 
            cout<<"Tipo: "<< even->getTipo()<<"|Fecha: "<< even->getFecha()<<" |Duración: "<< even->getDuracion()<< "|Ubicación: "<< even->getUbicacion()<<endl;
        }
        else
        {
            cout<<"No existe ningún evento de ese tipo, lo sentimos :("<<endl;
        }
        
    }
}
// Función que me retorna la edad promedio de los asistentes 
double edadPromedio()
{
    int sumadorEdades;
    for(Asistentes* asis : listaAsistentes)
    {
        sumadorEdades += asis->getEdad(); // Se suman todas las edades existentes y se guardan en una variable
    }
    double edadPro = static_cast<double>(sumadorEdades/listaAsistentes.size());
    return edadPro;
}

// Función para ver cual es la ocupación más común en los asistentes 
void ocupacionComun()
{
    // Este mapa se utilizará para almacenar el recuento de asistentes para encontrar la ocupación que con más gente.
    map<string,int> ocupacionComun;
    int mayor = ocupacionComun.begin()->second; 
    string nomMayor;

    for(Asistentes* asis : listaAsistentes)
    {
        // Incrementa el contador de ocupación.
        ocupacionComun[asis->getOcupacion()]++;
    }
    for(auto const& ma : ocupacionComun)
    {
        if(ma.second > mayor )
        {
            mayor = ma.second; // guarda en la variable la ocupación con mayor número de asistentes.
            nomMayor = ma.first; // guarda en la variable el nombre de ocupación con mayor número de asistentes.
        }
    }
    cout<<"----------------------------------------------------------------------"<<endl;
    cout<<"La Ocupacion más común es: "<< nomMayor <<endl;
    cout<<"----------------------------------------------------------------------"<<endl;
}

// Función para ver la intitución/empresa más común en los asistentes 
void instiEmpreComun()
{
   // Este mapa se utilizará para almacenar el recuento de asistentes para encontrar la institucion/empresa más común.
    map<string,int> instiEmpreComun;
    int mayor = instiEmpreComun.begin()->second;
    string nomMayor;

    for(Asistentes* asis : listaAsistentes)
    {
        // incrementa el contador de intitución/empresa
        instiEmpreComun[asis->getInstitucionEmpresa()]++;
    }
    for(auto const& ma : instiEmpreComun)
    {
        if(ma.second > mayor )
        {
            mayor = ma.second; // guarda en la variable la intitución/empresa con mayor cantidad de asistentes
            nomMayor = ma.first;// guarda en la variable el nombre de la intitución/empresa con la mayor cantidad de asistentes.
        }
    }
    
    cout<<"La Intitución/Empresa más común es: "<< nomMayor <<endl;
    cout<<"----------------------------------------------------------------------"<<endl;
}

// Función para ver detalles especificos de los asistentes
void detallesAsistentes()
{
    cout<<"----------------------------------------------------------------------"<<endl;
    double edad = edadPromedio();
    cout<<"La Edad Promedio de los asistentes es de : "<< edad <<" años"<<endl;
    ocupacionComun();
    instiEmpreComun();
}

// Función que me genera informes 
void generarInformes()
{
    int opcion;
    cout<<" "<<endl;
    cout<<"Eliga una opción: "<<endl;
    cout<<"1) Lista eventos programados"<<endl;
    cout<<"2) Lista de asistentes registrados por evento"<<endl;
    cout<<"3) Estadisticas asistencia a eventos"<< endl;
    cout<<"4) Detalles sobre asistentes"<<endl;
    cout<<"5) Informacion sobre eventos especificos"<<endl;
    cin>>opcion;

    while(opcion != 6)
    {
        switch(opcion)
        {
            case 1:
            listaEventosProgramados();
            break;
            case 2:
            listaAsistentesRegistrados();
            break;
            case 3:
            estadisticasAsistenciasEventos();
            break;
            case 4:
            detallesAsistentes();
            break;
            case 5:
            informacionEventos();
            break;
        }
    
    cout<<" "<<endl;
    cout<<"Eliga una opción: "<<endl;
    cout<<"1) Lista eventos programados"<<endl;
    cout<<"2) Lista de asistentes registrados por evento"<<endl;
    cout<<"3) Estadisticas asistencia a eventos"<< endl;
    cout<<"4) Detalles sobre asistentes"<<endl;
    cout<<"5) Informacion sobre eventos especificos"<<endl;
    cout<<"6) Salir"<<endl;
    cin>>opcion;
    }
}

int main()
{
    
    cargarArchivosEventos(); 
    cargarArchivosAsistentes();
    int opcion;
    cout<<"1) Agregar Evento nuevo" <<endl;
    cout<<"2) Registrar Asistentes" <<endl;
    cout<<"3) Consulta de lista Asistentes" <<endl;
    cout<<"4) Generar informes" <<endl;
    cin>> opcion;
    while (opcion != 5)
    {
        switch(opcion)
        {
        case 1:
            agregarEvento();
        break;
        case 2:
            registroAsistente();
        break;
        case 3:
            consultarListaAsistentes();
        break;
        case 4:
            generarInformes();
        break;
        };
        cout<<"  "<<endl;
        cout<<"1) Agregar Evento nuevo" <<endl;
        cout<<"2) Registrar Asistentes" <<endl;
        cout<<"3) Consulta de lista Asistentes" <<endl;
        cout<<"4) Generar informes" <<endl;
        cout<<"5) Salir"<<endl;
        cin>> opcion;
    }
    cout<<"bye bye :)"<<endl;
  
    return 0;
}