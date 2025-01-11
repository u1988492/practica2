#ifndef ALGORITMOVORAZ_H
#define ALGORITMOVORAZ_H
/**
 * @file AlgoritmoVoraz.h
 * @brief Contiene la definición de la clase AlgoritmoVoraz, que implementa una estrategia de solución
 *        utilizando un algoritmo voraz para organizar los exámenes.
 */

#include "Solucionador.h"
class Horario;
class Examen;

/**
 * @class AlgoritmoVoraz
 * @brief Implementa un algoritmo voraz para resolver la programación de los exámenes.
 *
 * Esta clase hereda de `Solucionador` y utiliza una estrategia de algoritmo voraz para organizar los exámenes
 * en el horario. El algoritmo prioriza los exámenes de acuerdo con una heurística y los organiza de forma
 * eficiente sin la necesidad de explorar exhaustivamente todas las posibilidades.
 */
class AlgoritmoVoraz : public Solucionador{
    public:
        /**
         * @brief Constructor de la clase AlgoritmoVoraz.
         *
         * Inicializa el solucionador utilizando el conjunto de exámenes (candidatos) y el horario donde se deben
         * organizar los exámenes.
         * @param examenes Lista de exámenes que se deben organizar.
         * @param horario Referencia al horario sobre el cual se trabajará.
         */
        // constructor con examenes(candidatos) y solucion(horario)
        AlgoritmoVoraz(const vector<Examen>& examenes, Horario&horario): Solucionador(examenes, horario){}

        /**
         * @brief Destructor de la clase AlgoritmoVoraz.
         *
         * Destructor por defecto.
         */
        // destructor por defecto
        ~AlgoritmoVoraz() override = default;

        /**
         * @brief Implementación del método para resolver el problema de programación de exámenes.
         *
         * Utiliza la estrategia de algoritmo voraz para organizar los exámenes en el horario disponible,
         * priorizando según la heurística definida.
         *
         * @return true si la solución fue exitosa, false en caso contrario.
         */
        // implementación del metodo de resolver
        bool solucionar() override;

    private:
        /**
         * @brief Método para ordenar los exámenes según una heurística en el constructor.
         *
         * Este método ordena los exámenes de acuerdo con criterios definidos, con el objetivo de mejorar
         * la eficiencia del proceso de programación utilizando el algoritmo voraz.
         */
        // método para ordenar los exámenes en el constructor según la heurística
        void ordenarExamenes();
};

#endif // ALGORITMOVORAZ_H
