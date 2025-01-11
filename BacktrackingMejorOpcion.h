#ifndef BACKTRACKINGMEJOROPCION_H
#define BACKTRACKINGMEJOROPCION_H

/**
 * @file BacktrackingMejorOpcion.h
 * @brief Contiene la definición de la clase BacktrackingMejorOpcion, que implementa una estrategia de resolución
 *        utilizando backtracking con la evaluación de la mejor opción basada en la desviación estándar del horario.
 */

#include "SolucionadorBacktracking.h"
#include <limits>
class Examen;
class Horario;

using namespace std;

/**
 * @class BacktrackingMejorOpcion
 * @brief Extiende la solución de backtracking para seleccionar la mejor opción según la desviación estándar del horario.
 *
 * Esta clase hereda de `SolucionadorBacktracking` y mejora el algoritmo de backtracking al evaluar cada posible
 * solución utilizando la desviación estándar del horario. El algoritmo selecciona la mejor opción en cada paso,
 * basándose en la minimización de la desviación.
 */
class BacktrackingMejorOpcion : public SolucionadorBacktracking
{
    public:
        /**
         * @brief Constructor de la clase BacktrackingMejorOpcion.
         *
         * Inicializa el solucionador con el conjunto de exámenes, el horario y establece la mejor solución
         * y la mejor desviación inicial.
         * @param examenes Lista de exámenes que se deben organizar.
         * @param horario Referencia al horario sobre el cual se trabajará.
         */
        // constructor con candidatos, solución vacía, mejor solución como la inicial, y mejor desviación como el peor caso
        BacktrackingMejorOpcion(const vector<Examen>& examenes, Horario& horario)
        : SolucionadorBacktracking(examenes, horario), mejorHorario(horario), mejorDesviacion(-numeric_limits<double>::infinity()) {}

        /**
         * @brief Implementación del método para resolver el problema de programación de exámenes utilizando
         *        backtracking y seleccionando la mejor opción según la desviación estándar del horario.
         *
         * Este método recursivo organiza los exámenes en el horario, seleccionando la mejor opción en cada paso
         * al evaluar la desviación estándar de la configuración actual.
         *
         * @return true si la solución fue exitosa, false en caso contrario.
         */
        bool solucionar() override;

    private:
        /**
         * @brief Función recursiva para realizar el proceso de backtracking, buscando la mejor opción.
         *
         * Esta función realiza el recorrido recursivo de todas las opciones posibles para asignar los exámenes
         * al horario. En cada paso, evalúa la calidad del horario utilizando la desviación estándar y selecciona
         * la mejor opción en función de ese valor.
         *
         * @param indiceExamen Índice del examen que se está procesando en el momento.
         * @return true si se encuentra una solución válida, false en caso contrario.
         */
        bool backtrackingMejorOpcion(int indiceExamen);

        /**
         * @brief Evalúa la calidad del horario utilizando la desviación estándar.
         *
         * Esta función calcula la desviación estándar del horario y la utiliza para evaluar qué tan equilibrado
         * está el horario, lo que influirá en la elección de la mejor opción en el proceso de backtracking.
         *
         * @param horario El horario que se va a evaluar.
         * @return El valor de la desviación estándar del horario.
         */
        double evaluarHorario(const Horario& horario);

        /**
         * @brief Mejor horario encontrado durante el proceso de resolución.
         *
         * Almacena el mejor horario obtenido, basado en la evaluación de la desviación estándar.
         */
        Horario mejorHorario;

        /**
         * @brief La mejor desviación estándar obtenida durante el proceso de resolución.
         *
         * Esta variable almacena el valor más bajo de desviación estándar encontrado, que representa
         * el horario más equilibrado.
         */
        double mejorDesviacion;

};

#endif // BACKTRACKINGMEJOROPCION_H
