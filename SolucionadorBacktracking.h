#ifndef SOLUCIONADORBACKTRACKING_H
#define SOLUCIONADORBACKTRACKING_H

/**
 * @file SolucionadorBacktracking.h
 * @brief Contiene la definición de la clase SolucionadorBacktracking, que implementa una estrategia de resolución
 *        utilizando el método de backtracking para organizar los exámenes.
 */

#include "Solucionador.h"
class Examen;
class Horario;

/**
 * @class SolucionadorBacktracking
 * @brief Implementa una solución basada en backtracking para la programación de los exámenes.
 *
 * Esta clase hereda de `Solucionador` y utiliza el algoritmo de backtracking para organizar
 * los exámenes en el horario. Este enfoque permite explorar diferentes opciones de forma recursiva, retrocediendo
 * cuando una opción no es válida y probando otras alternativas.
 */
class SolucionadorBacktracking: public Solucionador
{
    public:

        /**
         * @brief Constructor de la clase SolucionadorBacktracking.
         *
         * Inicializa el solucionador utilizando el conjunto de exámenes (candidatos) y el horario en el cual
         * se deben organizar los exámenes.
         * @param examenes Lista de exámenes que se deben organizar.
         * @param horario Referencia al horario sobre el cual se trabajará.
         */
        SolucionadorBacktracking(const vector<Examen>&examenes, Horario&horario)
        : Solucionador(examenes, horario) {}

        /**
         * @brief Implementación del método para resolver el problema de programación de exámenes utilizando backtracking.
         *
         * Utiliza el algoritmo de backtracking para organizar los exámenes en el horario, probando diferentes
         * configuraciones de manera recursiva y retrocediendo cuando se llega a un estado no válido.
         *
         * @return true si la solución fue exitosa, false en caso contrario.
         */
        // función para implementar recursividad
        bool solucionar() override;

    private:
        /**
         * @brief Función recursiva para realizar el proceso de backtracking.
         *
         * Esta función realiza el recorrido recursivo de todas las opciones posibles para asignar los exámenes al horario.
         * En caso de encontrar una asignación no válida, retrocede y prueba con otras alternativas.
         *
         * @param indiceExamen Índice del examen que se está procesando en el momento.
         * @return true si se encuentra una solución válida, false en caso contrario.
         */
        // funcion recursiva
        bool backtracking(int indiceExamen);

        /**
         * @brief Función para ordenar los exámenes de acuerdo a un criterio que facilite el cálculo.
         *
         * Este método ordena los exámenes antes de iniciar el proceso de backtracking, con el objetivo de
         * facilitar la asignación de los exámenes de manera eficiente.
         */
        // función para ordenar exámenes para facilitar los cálculos
        void ordenarExamenes();
};

#endif // SOLUCIONADORBACKTRACKING_H
