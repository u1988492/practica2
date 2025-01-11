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
        int dia = 0;

        while(horario.obtMaxDias() == -1 || dia < horario.obtMaxDias()){
            // añadir nuevo día si es necesario y no hay restricciones
            if(dia >= horario.obtHorarios().size()){
                if(horario.obtMaxDias() == -1){
                    horario.agregarDia();
                }
                else{
                    break;
                }
            }

            // comprobar ambos turnos del día
            for(int turno=0; turno < 2; ++turno){
                if(!horario.sePuedeAgregar(dia, turno, examen)) continue; // siguiente turno si no se cumplen restricciones

                // comprobar restricciones de aulas
                int aulasRUsadas = 0, aulasGUsadas = 0;
                for(const auto& examenColocado : horario.obtHorarios()[dia][turno]){
                    if(examenColocado.esGrupoGrande()) aulasGUsadas++;
                    else aulasRUsadas++;
                }

                if(examen.esGrupoGrande() && aulasGUsadas >= horario.obtAulasG()) continue; // siguiente turno si es examen de gran capacidad no hay aulas grandes disponibles
                if(!examen.esGrupoGrande() && aulasRUsadas >= horario.obtAulasR()) continue; // siguiente turno si es examen de capacidad reducida y no hay aulas pequeñas disponibles

                // si se puede, colocar el examen en el horario
                horario.agregarExamen(dia, turno, examen);
                ultimoDia[{examen.obtCarrera(), examen.obtCurso()}] = dia;
                asignado = true;
                break; // dejar de probar turnos
            }
            if(asignado) break; // dejar de probar días si se ha colocado el examen
            ++dia;
        }

        // si no se ha podido colocar un examen, no hay solución
        if(!asignado){
            return false;
        }
    }
    // si se han podido colocar todos los exámenes
    return true;
}
