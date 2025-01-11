#ifndef ALGORITMOVORAZ_H
#define ALGORITMOVORAZ_H

#include "Solucionador.h"
class Horario;
class Examen;

class AlgoritmoVoraz : public Solucionador{
    public:
        // constructor con examenes(candidatos) y solucion(horario)
        AlgoritmoVoraz(const vector<Examen>& examenes, Horario&horario);
        // destructor por defecto
        ~AlgoritmoVoraz() override = default;
        // implementación del metodo de resolver
        bool solucionar() override;

    private:
        // método para ordenar los exámenes en el constructor según la heurística
        void ordenarExamenes();
};

#endif // ALGORITMOVORAZ_H
