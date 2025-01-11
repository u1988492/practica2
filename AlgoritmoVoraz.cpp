#include "AlgoritmoVoraz.h"
#include "Examen.h"
#include "Horario.h"

using namespace std;

AlgoritmoVoraz::AlgoritmoVoraz(const vector<Examen>&examenes, Horario& horario) : Solucionador(examenes, horario){
    ordenarExamenes();
}

void AlgoritmoVoraz::ordenarExamenes(){
    // ordenar examenes para facilitar el cálculo del horario
    sort(examenes.begin(), examenes.end(), [](const Examen&a, const Examen&b){
        if(a.esGrupoGrande() != b.esGrupoGrande()){
                return a.esGrupoGrande() > b.esGrupoGrande(); // priorizar examenes de aulas grandes
        }
        if(a.obtCarrera() != b.obtCarrera()){
            return a.obtCarrera() < b.obtCarrera(); // ordenar por carrera si ambos son del mismo tipo de aula
        }
        return a.obtCurso() < b.obtCurso(); // ordenar por curso si son del mismo tipo de aula y la misma carrera
     });
}

bool AlgoritmoVoraz::solucionar(){
    // guardar el último día guardado para cada carrera y curso
    map<pair<string, int>, int> ultimoDia;

    // para cada examen de los candidatos, intentar colocar en el horario
    for(const auto& examen : examenes){
        bool asignado = false;
        int mejorDia = -1, mejorTurno = -1, maxDistancia = -1;
        // añadir examenes hasta llegar al maximo de días disponibles; si no hay límite, seguir iterando hasta colocar todos los exámenes
        for(int dia=0; horario.obtMaxDias() == -1 || dia < horario.obtMaxDias(); dia++){
            if(dia >= horario.obtHorarios().size()){
                if(horario.obtMaxDias()==-1){
                    horario.agregarDia(); // añadir días dinámicamente si no hay límite
                }
                else{ break; } // salir del bucle si se ha alcanzado el máximo
            }

            // para cada turno del día
            for(int turno=0; turno < 2; turno++){
                if(!horario.sePuedeAgregar(dia, turno, examen)) continue;

                // comprobar restricciones de aulas
                int aulasRUsadas = 0, aulasGUsadas = 0;
                for(const auto& examenColocado : horario.obtHorarios()[dia][turno]){
                    if(examenColocado.esGrupoGrande()) aulasGUsadas++;
                    else aulasRUsadas++;
                }

                if(examen.esGrupoGrande() && aulasGUsadas >= horario.obtAulasG()) continue; // salir si es examen de gran capacidad no hay aulas grandes disponibles
                if(!examen.esGrupoGrande() && aulasRUsadas >= horario.obtAulasR()) continue; // salir si es examen de capacidad reducida y no hay aulas pequeñas disponibles

                // calcular distancia entre el último examen colocado de la misma carrera y curso que el que se quiere colocar
                auto it = ultimoDia.find({examen.obtCarrera(), examen.obtCurso()});
                int distancia = (it != ultimoDia.end()) ? dia - it->second : dia + 1; // distancia es dia + 1 para el primer examen de la carrera y curso
                // actualizar la mejor posición
                if(distancia > maxDistancia){
                    maxDistancia = distancia;
                    mejorDia = dia;
                    mejorTurno = turno;
                }
            }
        }
        // colocar examen en la mejor posición disponible
        if(mejorDia != -1 && mejorTurno != -1){
            horario.agregarExamen(mejorDia, mejorTurno, examen);
            ultimoDia[{examen.obtCarrera(), examen.obtCurso()}] = mejorDia;
            asignado = true;
        }

        // si no se ha podido colocar un examen, no hay solución
        if(!asignado){
            return false;
        }
    }
    // si se han podido colocar todos los exámenes
    return true;
}
