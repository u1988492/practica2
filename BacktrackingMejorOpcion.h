#ifndef BACKTRACKINGMEJOROPCION_H
#define BACKTRACKINGMEJOROPCION_H

#include "SolucionadorBacktracking.h"
#include <limits>
class Examen;
class Horario;

using namespace std;

class BacktrackingMejorOpcion : public SolucionadorBacktracking
{
    public:
        // constructor con candidatos, solución vacía, mejor solución como la inicial, y mejor desviación como el peor caso
        BacktrackingMejorOpcion(const vector<Examen>& examenes, Horario& horario)
        : SolucionadorBacktracking(examenes, horario), mejorHorario(horario), mejorDesviacion(-numeric_limits<double>::infinity()) {}

        bool solucionar() override;

    private:
        bool backtrackingMejorOpcion(int indiceExamen);
        double evaluarHorario(const Horario& horario);
        Horario mejorHorario;
        double mejorDesviacion;

};

#endif // BACKTRACKINGMEJOROPCION_H
