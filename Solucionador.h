#ifndef SOLUCIONADOR_H
#define SOLUCIONADOR_H

#include <vector>
#include "Examen.h"
#include "Horario.h"


// clase base para encapsular las funcionalidades y datos compartidos en los diferentes modos de resolucion del problema

class Solucionador
{
    public:
        // constructor
        Solucionador(const vector<Examen>& examenes, const Horario& horario)
        : examenes(examenes), horario(horario) {}

        // metodo virtual que se implementa en las clases derivadas del solucionador
        virtual bool solucionar() = 0;

        // funcion para obtener el resultado final
        const Horario& obtHorario() const;

    protected:
        // horario sobre el que se trabaja
        Horario horario;
        // lista de examenes que organizar
        vector<Examen> examenes;

};

#endif // SOLUCIONADOR_H
