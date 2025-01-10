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
        Examen(const string& codigo, const string& grado, int curso, int semestre, bool granCapacidad)
        : codigo(codigo), grado(grado), curso(curso), semestre(semestre), granCapacidad(granCapacidad){}

        bool operator==(const Examen& e) const{
            return codigo == e.codigo;
        }
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
        string grado;
        int curso;
        int semestre;
        bool granCapacidad;
};

#endif // EXAMEN_H
