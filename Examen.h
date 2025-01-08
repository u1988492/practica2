#ifndef EXAMEN_H
#define EXAMEN_H

// contiene la información relevante a cada examen

class Examen
{
    public:
        // constructor de la clase
        Examen(const string& codigo, const string& carrera, int curso, bool gran_capacidad)
        : codigo(codigo), carrera(carrera), curso(curso), gran_capacidad(gran_capacidad){}
        // funcion para obtener el codigo de la asignatura
        string obtCodigo() const;
        // funcion para obtener el nombre de la carrera
        string obtCarrera() const;
        // funcion para obtener el curso
        int obtCurso() const;
        // funcion para saber si el examen es de un grupo de gran o reducida capacidad
        bool esGrupoGrande() const;

    private:
        string codigo;
        string carrera;
        int curso;
        bool grupoGrande;
};

#endif // EXAMEN_H
