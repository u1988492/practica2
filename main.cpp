#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "Examen.h"
#include "Horario.h"

using namespace std;

// FUNCIONES DE INTERACCION CON EL USUARIO

void procesarArgumentos(int argc, char* argv[], string& algoritmo, int& aulasR, int& aulasG, int& maxDias, int&semestre, string& fichero){
    algoritmo = "backtracking"; // backtracking por defecto
    aulasR = 1;
    aulasG = 1;
    maxDias = -1; // sin limite de dias
    semestre = 1;

    for(int i=1; i<argc; i++){
        string arg = argv[i];
        if(arg == "-h" || arg == "--help"){
            cout << "Opciones: " << endl;
            //mostrar como usar las opciones de entrada
            exit(0);
        }
        else if(arg == "-v"){
            algoritmo = "voraz";
        }
        else if(arg == "-m"){
            algoritmo = "mejorOpcion";
        }
        else if(arg =="-cr" && i+1<argc){
            aulasR = stoi(argv[i+1]); //leer numero de aulas de capacidad reducida
        }
        else if(arg =="-gc" && i+1<argc){
            aulasG = stoi(argv[i+1]); // leer numero de aulas de gran capacidad
        }
        else if(arg == "-s" && i+1<argc){
            semestre = stoi(argv[i+1]); // leer semestre
        }
        else if(arg == "-d" && i+1<argc){
            maxDias = stoi(argc[i+1]); // ler maximo de dias que se pueden ocupar
        }
        else if(fichero.empty()){
            fichero = arg; // se asume que si no hay ninguna opcion en la entrada, la entrada es el archivo de lectura
        }
        else{
            cerr << "Opcion desconocida: " << arg << endl;
            exit(1);
        }
    }

    if(fichero.empty()){
        throw invalid_argument("Debes introducir el nombre del archivo de entrada.");
    }
}

void procesarArchivoEntrada(const string& fichero, vector<Examen>& examenes, Horario& horario){
    ifstream fin(fichero);
    if(!fin.is_open()){
        throw runtime_error("No se pudo abrir el archivo: " + fichero);
    }

    string linea;
    bool restricciones = false;

    while(getline(fin, linea)){
        if(linea.empty() || linea[0] == '#') continue; //saltar comentarios o lineas vacias

        if(linea[0] == '*'){
            restricciones = true;
            continue;
        }

        if(!restricciones){
            //leer datos de examen
            istringstream stream(linea);
            string carrera, codigo, tipo;
            int curso;
            stream >> carrera >> codigo >> curso >> tipo;
            bool grupoGrande = (tipo == "g");
            examenes.emplace_back(codigo, carrera, curso, grupoGrande);
        }
    }
}


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
