#ifndef HORARIO_H
#define HORARIO_H

#include <vector>
#include "Examen.h"

// "Solucion

class Horario
{
    public:
        // constructor de horario con dias maximos que ocupar, numero de aulas grandes, y numero de aulas pequeñas
        Horario(int maxDias, int aulasG, int aulasR)
        : maxDias(maxDias), aulasG(aulasG), aulasR(aulasR);
        // funcion para obtener el numero maximo de dias que ocupar
        int obtMaxDias();
        //funcion para obtener el numero de aulas grandes disponibles
        int obtAulasG();
        // funcion para obtener el numero de aulas de capacidad reducida disponibles
        int obtAulasR();
        // funcion para obtener los horarios de examenes
        const vector<vector<vector<Examen>>> obtHorarios() const;

        // funcion para comprobar si se puede agregar un examen al horario
        bool sePuedeAgregar(int dia, int turno, const Examen& examen) const;
        // funcion para agregar un examen al horario
        void agregarExamen(int dia, int turno, const Examen& examen);
        // funcion para quitar un examen del horario
        void quitarExamen(int dia, int turno, const Examen& examen);7
        // funcion para mostrar horario
        void mostrarHorario() const;


    private:
        // horario de examenes organizado por día y turno
        vector<vector<vector<Examen>>> dias;
        // numero maximo de días que ocupar
        int maxDias;
        // cantidad de aulas de gran capacidad
        int aulasG;
        // cantidad de aulas de capacidad reducida
        int aulasR;

};

#endif // HORARIO_H
