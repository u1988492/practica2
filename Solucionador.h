#ifndef SOLUCIONADOR_H
#define SOLUCIONADOR_H

/**
 * @file Solucionador.h
 * @brief Contiene la definición de la clase base Solucionador para encapsular las funcionalidades y datos
 *        compartidos en los diferentes modos de resolución del problema.
 */

#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <iostream>
#include <iomanip>
#include "Examen.h"
#include "Horario.h"

using namespace std;

// clase base para encapsular las funcionalidades y datos compartidos en los diferentes modos de resolucion del problema
/**
 * @class Solucionador
 * @brief Clase base para resolver el problema de la organización de los exámenes.
 *
 * Esta clase encapsula los datos y métodos comunes necesarios para resolver el problema de la programación
 * de los exámenes, los cuales pueden ser implementados de manera diferente en las clases derivadas.
 */
class Solucionador
{
    public:
        /**
         * @brief Constructor de la clase Solucionador.
         *
         * Inicializa el solucionador con la lista de exámenes y el horario en el que se trabajará.
         * @param examenes Lista de exámenes que se desean organizar.
         * @param horario Referencia al horario sobre el cual se trabajará.
         */
        // constructor
        Solucionador(const vector<Examen>& examenes, Horario& horario)
        : examenes(examenes), horario(horario) {}

        /**
         * @brief Destructor de la clase Solucionador.
         *
         * Destructor virtual necesario para clases derivadas.
         */
        virtual ~Solucionador() = default;

        /**
         * @brief Método virtual puro para resolver el problema.
         *
         * Este método se debe implementar en las clases derivadas del solucionador para resolver el problema
         * de manera específica.
         *
         * @return true si la solución fue exitosa, false en caso contrario.
         */
        // metodo virtual que se implementa en las clases derivadas del solucionador
        virtual bool solucionar() = 0;

        /**
         * @brief Obtiene el horario final una vez que el problema ha sido resuelto.
         *
         * @return Una referencia constante al horario resultante después de la solución.
         */
        // funcion para obtener el resultado final
        const Horario& obtHorario() const;

    protected:
        // lista de examenes que organizar
        vector<Examen> examenes; /**< Lista de los exámenes que deben ser organizados. */
        // horario sobre el que se trabaja
        Horario& horario; /**< Referencia al horario sobre el cual se trabaja. */
};

#endif // SOLUCIONADOR_H
