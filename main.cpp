#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <stdexcept>
#include <set>
#include "Examen.h"
#include "Horario.h"
#include "Solucionador.h"
#include "AlgoritmoVoraz.h"
#include "SolucionadorBacktracking.h"
#include "BacktrackingMejorOpcion.h"
#include "eines.h"

using namespace std;

// FUNCIONES DE INTERACCION CON EL USUARIO

// Función para comprobar que los datos leídos son válidoss
bool validarDatos(const string& grado, const string& codi, int semestre, int curso){
    return !grado.empty() && !codi.empty() && (semestre == 1 || semestre == 2) && curso > 0;
}

// FUNCION PARA LEER LOS DATOS DEL ARCHIVO DE ENTRADA
// Pre:
// Post:
void procesarArchivoEntrada(const string& fichero, vector<Examen>& examenes, Horario& horario){
    ifstream fin(fichero);
    if(!fin.is_open()){
        throw runtime_error("Error: El fichero [" + fichero + "] no se pudo abrir. Repasa el nombre y los permisos.");
    }

    string linea;
    vector<string> campos;
    bool restricciones = false;

    getline(fin, linea); // saltar cabecera
    while(getline(fin, linea)){
        if(linea.empty()) continue;

        if(linea[0] == '*'){
            restricciones = true;
            continue;
        }

        campos = tokens(linea, '\t', true); // comprobar si hay que ponerlo como true o false porque en la anterior practica tuvo que ser true
        /**BORRAR**/
        cout << "leyendo linea " << linea << endl;
        if(!restricciones){
            // leer datos de asignaturas
            if(campos.size()>=7){ // solo procesar lineas que tengan los campos necesarios
                // procesar los campos de interes
                string grado = campos[0];
                string codi = campos[2];
                int semestre = stoi(campos[5]);
                int curso = stoi(campos[6]);
                bool granCapacidad = (campos[3]== "g");

                if(validarDatos(grado, codi, semestre, curso)){
                    // si los datos son válidos, guardar a estructura de datos de examenes que organizar
                    // actualizar contadores de datos
                    Examen e(codi, grado, curso, semestre, granCapacidad);
                    examenes.emplace_back(e);
                }
            }
        }
        else{
            if(campos.size()==2){
                // leer restricciones
                horario.agregarRestriccion(campos[0], campos[1]);
            }
        }
    }
    fin.close();
}

// Función para procesar los argumentos de entrada de la linea de comando
void procesarArgumentos(int argn, char** argv, string& algoritmo, int& aulasR, int&aulasG, int& maxDias, int& semestre, string& fichero){

    if(argn>0){
        //procurar no acceder a valores indefinidos
        for(int i=1; i<argn; i++){
            string arg = argv[i];
            // mostrar menú de opciones
            if(arg == "-h" || arg == "--help"){
                cout << "Uso: " << argv[0] << " [-h] | [-v] [-m] [-cr <int>] [-gc <int>] [-s <int> [-d <int>] fichero" << endl;
                const int width = 15;
                cout << "Opciones disponibles: " << endl;
                cout << left << setw(width) << "-h, --help"  << "muestra este mensaje de ayuda y sale del programa" << endl;
                cout << left << setw(width) << "-v" << "búsqueda rápida con un algoritmo voraz" << endl;
                cout << left << setw(width) << "-m" << "busca la solución que minimiza el número de turnos y maximiza la dispersión" << endl;
                cout << left << setw(width) << "-cr <int>" << "asigna <int> como el número de aulas de capacidad reducida disponibles para los exámenes" << endl;
                cout << left << setw(width) << "-gc <int>" << "asigna <int> como el número de aulas de gran capacidad disponibles para los exámenes" << endl;
                cout << left << setw(width) << "-s <int>" << "indica que la asignación se tiene que hacer para el semestre <int>< (1 o 2)" << endl;
                cout << left << setw(width) << "-d <int>" << "indica el límite máximo de días que se pueden utilizar" << endl;
                cout << left << setw(width) << "fichero" << "archivo de texto con todas las asignaturas a las que se quiere asignar un turno de examen, y las posibles restricciones entre parejas de asignaturas" << endl;
                exit(0); // salir del programa
            }
            else if(arg == "-v"){
                algoritmo = "voraz";
                cout << "Usando algoritmo voraz" << endl;
            }
            else if(arg == "-m"){
                algoritmo = "mejorOpcion";
                cout << "Usando algoritmo mejor opcion" << endl;
            }
            else if(arg =="-cr" && i+1<argn){
                cout << "procesando -cr: " << argv[i+1] << endl;
                string par = string(argv[++i]);
                if (!all_of(par.begin(), par.end(), ::isdigit)) {
                    throw invalid_argument("Error: El valor de -cr debe ser un entero válido.");
                }
                aulasR = stoi(par); //leer numero de aulas de capacidad reducida
            }
            else if(arg =="-gc" && i+1<argn){
                cout << "procesando -gc: " << argv[i+1] << endl;
                string par = string(argv[++i]);
                if (!all_of(par.begin(), par.end(), ::isdigit)) {
                    throw invalid_argument("Error: El valor de -gc debe ser un entero válido.");
                }
                aulasG = stoi(par); // leer numero de aulas de gran capacidad
            }
            else if(arg == "-s" && i+1<argn){
                string par = string(argv[++i]);
                if (!all_of(par.begin(), par.end(), ::isdigit)) {
                    throw invalid_argument("Error: El valor de -cr debe ser un entero válido.");
                }

                semestre = stoi(par); // leer semestre

                if(semestre!=1 && semestre!=2){
                    throw invalid_argument("Error: el valor asociado a la opción '-s' es incorrecto.");
                }
            }
            else if(arg == "-d" && i+1<argn){
                cout << "procesando -d: " << argv[i+1] << endl;
                string par = string(argv[++i]);
                if (!all_of(par.begin(), par.end(), ::isdigit)) {
                    throw invalid_argument("Error: El valor de -d debe ser un entero válido.");
                }
                maxDias = stoi(par); // ler maximo de dias que se pueden ocupar
            }
            else if(fichero.empty()){
                fichero = arg; // se asume que si no hay ninguna opcion en la entrada, la entrada es el archivo de lectura
            }
            else{
                throw invalid_argument("Error: Opción desconocida: " + arg);
            }
        }
        if(fichero.empty()){
            throw invalid_argument("Error:  falta el nombre del fichero");
        }
    }
}




int main(int argn, char ** argv){
    try{
        string algoritmo = "backtracking"; // backtracking básico por defecto; cualquier solución válida
        int aulasR = 1;
        int aulasG = 1;
        int maxDias = -1; // maxDias indefinidos
        int semestre = 1;
        string fichero;

        vector<Examen> examenes; // candidatos

        procesarArgumentos(argn, argv, algoritmo, aulasR, aulasG, maxDias, semestre, fichero);

        Horario horario(maxDias, aulasG, aulasR); // añadir restricciones a horario

        procesarArchivoEntrada(fichero, examenes, horario); // guardar info de examenes y restricciones del archivo de entrada

        // guardar carreras diferentes de los examenes leidos para obtener el total
        set<string> carreras;
        for(const auto&examen: examenes){
            carreras.insert(examen.obtCarrera());
        }

        cout << examenes.size() << " asignaturas leídas de " << carreras.size() << " grados diferentes." << endl;
        cout << "algoritmo seleccionado: " << algoritmo << endl; // QUITAR ESTA LINEA

        // organizar el horario con el algoritmo seleccionado
        Solucionador* solucionador = nullptr;
        if(algoritmo=="voraz"){
            solucionador = new AlgoritmoVoraz(examenes, horario);
        }
        else if(algoritmo=="backtracking"){
            solucionador = new SolucionadorBacktracking(examenes, horario);
        }
        else if(algoritmo=="mejorOpcion"){
            solucionador = new BacktrackingMejorOpcion(examenes, horario);
        }
        else{
            throw invalid_argument("Error: algoritmo desconocido.");
        }

        // si hay solución
        if(solucionador->solucionar()){
            cout << "Horario calculado con éxito:" << endl;
            horario.mostrarHorario();
        }
        // si no hay solución
        else{ cout << "No se pudo calcular un horario válido" << endl; }

        delete solucionador; // limpiar memoria


    } catch(const invalid_argument& e){
        cerr << e.what() << endl;
        return 1;
    } catch(const runtime_error& e){
        cerr << e.what() << endl;
        return 1;
    }

    return 0;
}
