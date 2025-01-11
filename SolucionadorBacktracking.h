#ifndef SOLUCIONADORBACKTRACKING_H
#define SOLUCIONADORBACKTRACKING_H

#include "Solucionador.h"
class Examen;
class Horario;

class SolucionadorBacktracking: public Solucionador
{
    public:

        SolucionadorBacktracking(const vector<Examen>&examenes, Horario&horario)
        : Solucionador(examenes, horario) {}

        // función para implementar recursividad
        bool solucionar() override;

    private:
        // funcion recursiva
        bool backtracking(int indiceExamen);
        // función para ordenar exámenes para facilitar los cálculos
        void ordenarExamenes();
};

#endif // SOLUCIONADORBACKTRACKING_H
