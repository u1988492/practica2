#ifndef HORARIO_H
#define HORARIO_H

#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include "Examen.h"

using namespace std;

// "Solucion"

class Horario
{
    public:
        // constructor de horario con dias maximos que ocupar, numero de aulas grandes, y numero de aulas pequeñas
        Horario(int maxDias, int aulasG, int aulasR);
        // funcion para obtener el numero maximo de dias que ocupar
        int obtMaxDias();
        //funcion para obtener el numero de aulas grandes disponibles
        int obtAulasG();
        // funcion para obtener el numero de aulas de capacidad reducida disponibles
        int obtAulasR();
        // funcion para obtener los horarios de examenes
        const vector<vector<vector<Examen>>>& obtHorarios() const;

        // funcion para comprobar si se puede agregar un examen al horario respetando las restricciones de horarios
        bool sePuedeAgregar(int dia, int turno, const Examen& examen) const;
        // añadir dias al horario dinámicamente
        void agregarDia();
        // funcion para agregar un examen al horario
        void agregarExamen(int dia, int turno, const Examen& examen);
        // funcion para quitar un examen del horario
        void quitarExamen(int dia, int turno, const Examen& examen);
        // funcion para mostrar horario
        void mostrarHorario() const;
        // calcular la desviación estándar del horario
        double calcularDesviacion() const;
        // función para agregar restricciones entre examenes
        void agregarRestriccion(const string& codi1, const string& codi2);


    private:
        // horario de examenes organizado por día y turno; dias -> turnos -> examenes
        vector<vector<vector<Examen>>> turnos;
        //restricciones
        vector<pair<string, string>> restricciones;
        // numero maximo de días que ocupar
        int maxDias;
        // cantidad de aulas de gran capacidad
        int aulasG;
        // cantidad de aulas de capacidad reducida
        int aulasR;

};

#endif // HORARIO_H
