#include "BacktrackingMejorOpcion.h"
#include "Examen.h"
#include "Horario.h"

using namespace std;

bool BacktrackingMejorOpcion::solucionar(){
    // ordenar candidatos para facilitar cálculos
    return backtrackingMejorOpcion(0); // comenzar por el primer examen
}

bool BacktrackingMejorOpcion::backtrackingMejorOpcion(int indiceExamen){
    // cuando todos los examenes estén posicionados, evaluar la solución
    if(indiceExamen == examenes.size()){
        double puntuacionActual = evaluarHorario(horario);
        if(puntuacionActual < mejorDesviacion){
            mejorDesviacion = puntuacionActual;
            mejorHorario = horario;
        }
        // seguir buscando opciones mejores
        return true;
    }

    // intentar colocar el examen actual en cada posición posible
    const Examen& examen = examenes[indiceExamen];
    bool solEncontrada = false;

    for(int dia = 0; horario.obtMaxDias() == -1 || dia < horario.obtMaxDias(); dia++){
        // añadir día nuevo dinámicamente si es necesario y posible
        if(horario.obtMaxDias() == -1 && dia >= horario.obtMaxDias()){
            horario.agregarDia();
        }
        else{break;} // alcanzado maximo de días

        for(int turno = 0; turno < 2; turno++){
            // comprobar restricciones de asignaturas
            if(!horario.sePuedeAgregar(dia, turno, examen)) continue;

            // comprobar restricciones de aulas
            int aulasRUsadas = 0, aulasGUsadas = 0;
            for(const auto& examenColocado : horario.obtHorarios()[dia][turno]){
                if(examenColocado.esGrupoGrande()) aulasGUsadas++;
                else aulasRUsadas++;
            }

            if(examen.esGrupoGrande() && aulasGUsadas >= horario.obtAulasG()) continue; // siguiente turno si es examen de gran capacidad no hay aulas grandes disponibles
            if(!examen.esGrupoGrande() && aulasRUsadas >= horario.obtAulasR()) continue; // siguiente turno si es examen de capacidad reducida y no hay aulas pequeñas disponibles

            // colocar el examen
            horario.agregarExamen(dia, turno, examen);

            // intentar colocar el siguiente examen
            bool resultado = backtrackingMejorOpcion(indiceExamen+1);
            solEncontrada = solEncontrada ||resultado;

            // quitar el examen para probar la siguiente posibilidad
            horario.quitarExamen(dia, turno, examen);
        }
        // dejar de probar días si se ha llegado al máximo establecido
        //if(horario.obtMaxDias() != -1 && dia >= horario.obtHorarios().size()) break;
    }
    return solEncontrada;
}

double BacktrackingMejorOpcion::evaluarHorario(const Horario& horario){
    return horario.calcularDesviacion();
}
