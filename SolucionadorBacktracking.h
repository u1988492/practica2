#ifndef SOLUCIONADORBACKTRACKING_H
#define SOLUCIONADORBACKTRACKING_H

#include "Solucionador.h"
class Examen;
class Horario;

class SolucionadorBacktracking: public Solucionador
{
    public:

        SolucionadorBacktracking(const vector<Examen>&examenes, const Horario&horario)
        : Solucionador(examenes, horario) {}

        // implementacion de la funcion de solucionar
        bool solucionar() override;

    private:
        // funcion recursiva
        bool backtracking(int indiceExamen);
};

#endif // SOLUCIONADORBACKTRACKING_H
