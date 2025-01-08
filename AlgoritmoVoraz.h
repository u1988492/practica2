#ifndef ALGORITMOVORAZ_H
#define ALGORITMOVORAZ_H

#include "Solucionador.h"
class Horario;
class Examen;

class AlgoritmoVoraz : public Solucionador{
    public:
        AlgoritmoVoraz(const vector<Examen>& examenes, const Horario&horario)
        : Solucionador(examenes, horario){}

        // implementación del metodo de resolver
        bool solucionar() override;
};

#endif // ALGORITMOVORAZ_H
