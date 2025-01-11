#ifndef BACKTRACKINGMEJOROPCION_H
#define BACKTRACKINGMEJOROPCION_H

#include "SolucionadorBacktracking.h"
class Examen;
class Horario;

class BacktrackingMejorOpcion : public SolucionadorBacktracking
{
    public:
        BacktrackingMejorOpcion(const vector<Examen>& examenes, Horario& horario)
        : SolucionadorBacktracking(examenes, horario), mejorHorario(horario), mejorDesviacion(-1) {}

        bool solucionar() override;

    private:
        Horario mejorHorario;
        double mejorDesviacion;

};

#endif // BACKTRACKINGMEJOROPCION_H
