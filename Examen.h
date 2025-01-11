#ifndef EXAMEN_H
#define EXAMEN_H
/**
 * @file Examen.h
 * @brief Contiene la definición de la clase Examen que representa un examen académico.
 *
 * Esta clase almacena información relevante sobre un examen, incluyendo el código de la asignatura,
 * el nombre del grado, el curso, el semestre y si el examen es para un grupo de gran capacidad.
 */
// contiene la información relevante a cada examen
// "Candidatos
#include <iostream>
#include <iomanip>

using namespace std;
/**
 * @class Examen
 * @brief Clase que representa un examen académico.
 *
 * La clase Examen contiene información sobre el examen, como el código de la asignatura, el grado
 * de la carrera, el curso, el semestre y si el grupo tiene gran capacidad.
 */
class Examen
{
    public:
        /**
         * @brief Constructor de la clase Examen.
         *
         * Inicializa los atributos de la clase con los valores proporcionados.
         * @param codigo El código de la asignatura.
         * @param grado El nombre de la carrera.
         * @param curso El curso en el que se encuentra el examen.
         * @param semestre El semestre en el que se cursa el examen.
         * @param granCapacidad Indica si el examen es de un grupo de gran capacidad (true) o no (false).
         */
        // constructor de la clase
        Examen(const string& codigo, const string& grado, int curso, int semestre, bool granCapacidad)
        : codigo(codigo), grado(grado), curso(curso), semestre(semestre), granCapacidad(granCapacidad){}

        /**
         * @brief Sobrecarga del operador de igualdad.
         *
         * Compara dos objetos de tipo Examen basándose en el código de la asignatura.
         * @param e El examen con el que se compara el objeto actual.
         * @return true si los códigos de las asignaturas son iguales, false en caso contrario.
         */
        bool operator==(const Examen& e) const{
            return codigo == e.codigo;
        }
         /**
         * @brief Obtiene el código de la asignatura.
         *
         * @return El código de la asignatura.
         */
        // funcion para obtener el codigo de la asignatura
        string obtCodigo() const;
        /**
         * @brief Obtiene el nombre de la carrera.
         *
         * @return El nombre de la carrera.
         */
        // funcion para obtener el nombre de la carrera
        string obtCarrera() const;
        /**
         * @brief Obtiene el curso en el que se encuentra el examen.
         *
         * @return El curso del examen.
         */
        // funcion para obtener el curso
        int obtCurso() const;
        /**
         * @brief Obtiene el semestre en el que se cursa la asignatura.
         *
         * @return El semestre en el que se cursa la asignatura.
         */
        // funcion para obtener el semestre en el que se cursa la asignatura
        int obtSemestre() const;
        /**
         * @brief Determina si el examen es para un grupo de gran capacidad.
         *
         * @return true si el examen es para un grupo de gran capacidad, false en caso contrario.
         */
        // funcion para saber si el examen es de un grupo de gran o reducida capacidad
        bool esGrupoGrande() const;

    private:
        string codigo;  /**< Código de la asignatura. */
        string grado; /**< Nombre de la carrera. */
        int curso; /**< Curso en el que se encuentra el examen. */
        int semestre; /**< Semestre en el que se cursa la asignatura. */
        bool granCapacidad;  /**< Indica si el grupo es de gran capacidad. */
};

#endif // EXAMEN_H
