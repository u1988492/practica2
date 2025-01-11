#ifndef HORARIO_H
#define HORARIO_H
/**
 * @file Horario.h
 * @brief Contiene la definición de la clase Horario que organiza y gestiona la programación de los exámenes.
 *
 * Esta clase permite gestionar el horario de los exámenes, incluyendo la asignación de días y turnos,
 * las restricciones entre exámenes y el cálculo de la desviación estándar para evaluar la distribución
 * del horario.
 */

#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <string>
#include <iomanip>
#include <map>
#include "Examen.h"

using namespace std;

// "Solucion"
/**
 * @class Horario
 * @brief Clase que representa el horario de los exámenes en un semestre.
 *
 * La clase Horario permite organizar y gestionar los exámenes en un horario específico, respetando
 * el número máximo de días y el número de aulas disponibles. También gestiona las restricciones entre
 * los exámenes y permite calcular la desviación estándar del horario.
 */
class Horario
{
    public:
        /**
         * @brief Constructor de la clase Horario.
         *
         * Inicializa los atributos del horario con los valores proporcionados.
         * @param maxDias El número máximo de días que se puede ocupar para los exámenes.
         * @param aulasG El número de aulas de gran capacidad disponibles.
         * @param aulasR El número de aulas de capacidad reducida disponibles.
         * @param semestre El semestre para el cual se está creando el horario.
         */
        // constructor de horario con dias maximos que ocupar, numero de aulas grandes, y numero de aulas pequeñas
        Horario(int maxDias, int aulasG, int aulasR, int semestre);
         /**
         * @brief Obtiene el número máximo de días que se pueden ocupar para los exámenes.
         *
         * @return El número máximo de días que se pueden ocupar para los exámenes.
         */
        // funcion para obtener el numero maximo de dias que ocupar
        int obtMaxDias();
        /**
         * @brief Obtiene el número de aulas grandes disponibles para los exámenes.
         *
         * @return El número de aulas grandes disponibles.
         */
        //funcion para obtener el numero de aulas grandes disponibles
        int obtAulasG();
        /**
         * @brief Obtiene el número de aulas de capacidad reducida disponibles para los exámenes.
         *
         * @return El número de aulas de capacidad reducida disponibles.
         */
        // funcion para obtener el numero de aulas de capacidad reducida disponibles
        int obtAulasR();
        /**
         * @brief Obtiene el semestre para el cual se está organizando el horario de exámenes.
         *
         * @return El semestre para el cual se está creando el horario.
         */
        // función para obtener el semestre para el cual se quiere calcular el horario
        int obtSemestre();
        /**
         * @brief Obtiene los horarios de los exámenes organizados por día y turno.
         *
         * @return Una referencia constante a la estructura de horarios (días -> turnos -> exámenes).
         */
        // funcion para obtener los horarios de examenes
        const vector<vector<vector<Examen>>>& obtHorarios() const;

        /**
         * @brief Comprueba si se puede agregar un examen al horario respetando las restricciones de horarios.
         *
         * @param dia El día en el que se quiere agregar el examen.
         * @param turno El turno en el que se quiere agregar el examen.
         * @param examen El examen que se quiere agregar.
         * @return true si se puede agregar el examen, false en caso contrario.
         */
        // funcion para comprobar si se puede agregar un examen al horario respetando las restricciones de horarios
        bool sePuedeAgregar(int dia, int turno, const Examen& examen) const;

        /**
         * @brief Agrega un nuevo día al horario.
         *
         * Esta función permite agregar dinámicamente un nuevo día al horario de los exámenes.
         */
        // añadir dias al horario dinámicamente
        void agregarDia();

        /**
         * @brief Agrega un examen al horario en un día y turno específicos.
         *
         * @param dia El día en el que se quiere agregar el examen.
         * @param turno El turno en el que se quiere agregar el examen.
         * @param examen El examen que se quiere agregar.
         */
        // funcion para agregar un examen al horario
        void agregarExamen(int dia, int turno, const Examen& examen);

        /**
         * @brief Quita un examen del horario en un día y turno específicos.
         *
         * @param dia El día en el que se quiere quitar el examen.
         * @param turno El turno en el que se quiere quitar el examen.
         * @param examen El examen que se quiere quitar.
         */
        // funcion para quitar un examen del horario
        void quitarExamen(int dia, int turno, const Examen& examen);

        /**
         * @brief Muestra el horario de los exámenes de forma legible.
         *
         * Esta función muestra el horario completo de los exámenes organizados por día y turno.
         */
        // funcion para mostrar horario
        void mostrarHorario() const;

        /**
         * @brief Calcula la desviación estándar del horario de los exámenes.
         *
         * La desviación estándar se calcula para evaluar cuán distribuido están los exámenes en los días y turnos.
         * @return El valor de la desviación estándar del horario.
         */
        // calcular la desviación estándar del horario
        double calcularDesviacion() const;

        /**
         * @brief Agrega una restricción entre dos exámenes para que no se programen en el mismo día y turno.
         *
         * @param codi1 El código del primer examen.
         * @param codi2 El código del segundo examen.
         */
        // función para agregar restricciones entre examenes
        void agregarRestriccion(const string& codi1, const string& codi2);


    private:
        // horario de examenes organizado por día y turno; dias -> turnos -> examenes
        vector<vector<vector<Examen>>> turnos; /**< Horarios de los exámenes organizados por días y turnos. */
        //restricciones
        vector<pair<string, string>> restricciones; /**< Restricciones entre los exámenes. */
        // numero maximo de días que ocupar
        int maxDias; /**< Número máximo de días que se pueden utilizar para los exámenes. */
        // cantidad de aulas de gran capacidad
        int aulasG; /**< Número de aulas grandes disponibles. */
        // cantidad de aulas de capacidad reducida
        int aulasR; /**< Número de aulas de capacidad reducida disponibles. */
        // semestre para el cual se quieren organizar los exámenes
        int semestre; /**< Semestre para el cual se organiza el horario. */

};

#endif // HORARIO_H
