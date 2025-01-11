#include "SolucionadorBacktracking.h"
#include "Examen.h"
#include "Horario.h"

using namespace std;


void SolucionadorBacktracking::ordenarExamenes(){
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

bool SolucionadorBacktracking::solucionar(){
    ordenarExamenes();
    return backtracking(0); // comenzar con el primer examen
}

bool SolucionadorBacktracking::backtracking(int indiceExamen){
    // caso base: todos los exámenes están colocados en el horario
    if(indiceExamen >= examenes.size()){
        return true;
    }

    // obtener el candidato actual
    const Examen& examen = examenes[indiceExamen];

    //intentar colocar el examen en cada dia y turno posibles
    for(int dia = 0; horario.obtMaxDias() == -1 || dia < horario.obtMaxDias(); dia++){
        //añadir días dinámicamente si es necesario
        if(horario.obtMaxDias() == -1 && dia >= horario.obtHorarios().size()){
            horario.agregarDia();
        }

        for(int turno = 0; turno < 2; turno++){
            // comprobar si se puede agregar el examen al horario
            if(!horario.sePuedeAgregar(dia, turno, examen)) continue;

            // comprobar restricciones de aulas
                int aulasRUsadas = 0, aulasGUsadas = 0;
                for(const auto& examenColocado : horario.obtHorarios()[dia][turno]){
                    if(examenColocado.esGrupoGrande()) aulasGUsadas++;
                    else aulasRUsadas++;
                }

                if(examen.esGrupoGrande() && aulasGUsadas >= horario.obtAulasG()) continue; // siguiente turno si es examen de gran capacidad no hay aulas grandes disponibles
                if(!examen.esGrupoGrande() && aulasRUsadas >= horario.obtAulasR()) continue; // siguiente turno si es examen de capacidad reducida y no hay aulas pequeñas disponibles

                // colocar el examen y pasar al siguiente
                horario.agregarExamen(dia, turno, examen);
                if(backtracking(indiceExamen+1)){
                    return true; // se ha encontrado una solución
                }

                // backtracking: quitar el examen y probar la siguiente posibilidad
                horario.quitarExamen(dia, turno, examen);
        }
        // dejar de probar días si se ha llegado al máximo establecido
        if(dia >= horario.obtHorarios().size()) break;
    }
    //si no hay posición válida para el examen
    return false;
}
