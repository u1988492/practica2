#ifndef EXAMEN_H
#define EXAMEN_H

// contiene la información relevante a cada examen
// "Candidatos
#include <iostream>
#include <iomanip>

using namespace std;

class Examen
{
    public:
        // constructor de la clase
        Examen(const string& codigo, const string& carrera, int curso, int semestre, bool grupoGrande)
        : codigo(codigo), carrera(carrera), curso(curso), semestre(semestre), grupoGrande(grupoGrande){}
        // funcion para obtener el codigo de la asignatura
        string obtCodigo() const;
        // funcion para obtener el nombre de la carrera
        string obtCarrera() const;
        // funcion para obtener el curso
        int obtCurso() const;
        // funcion para obtener el semestre en el que se cursa la asignatura
        int obtSemestre() const;
        // funcion para saber si el examen es de un grupo de gran o reducida capacidad
        bool esGrupoGrande() const;

    private:
        string codigo;
        string carrera;
        int curso;
        int semestre;
        bool grupoGrande;
};

#endif // EXAMEN_H
