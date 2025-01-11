#include "Horario.h"

using namespace std;

Horario::Horario(int maxDias, int aulasG, int aulasR, int semestre)
    : maxDias(maxDias), aulasG(aulasG), aulasR(aulasR), semestre(semestre){

    if(maxDias>0){
        turnos.resize(maxDias, vector<vector<Examen>>(2)); // reservar días con 2 turnos
    }
}

int Horario::obtMaxDias(){ return maxDias; }

int Horario::obtAulasG(){ return aulasG; }

int Horario::obtAulasR(){ return aulasR; }

int Horario::obtSemestre(){ return semestre; }

const vector<vector<vector<Examen>>>& Horario::obtHorarios() const{ return turnos; }

void Horario::agregarDia(){
    if(maxDias == -1 || turnos.size() < maxDias){
        turnos.emplace_back(vector<vector<Examen>>(2)); // añadir día nuevo con 2 turnos
    }else{
        throw runtime_error("Error: se ha alcanzado el número máximo de días permitidos.");
    }
}

bool Horario::sePuedeAgregar(int dia, int turno, const Examen& e) const{

    if(dia >= turnos.size()) return false;

    const auto& turnoActual = turnos[dia][turno];

    for(const auto&examen : turnoActual){
        // si el turno actual tiene un examen del mismo curso y grado que el que se quiere agregar
        if(examen.obtCarrera() == e.obtCarrera() && examen.obtCurso() == e.obtCurso()){
            return false; // incumple restricción
        }
        for(const auto& restriccion : restricciones){
            // si el examen que se quiere añadir tiene alguna restricción con el examen actual
            if((restriccion.first == examen.obtCodigo() && restriccion.second == e.obtCodigo()) ||
            (restriccion.second == examen.obtCodigo() && restriccion.first == e.obtCodigo())){
                return false;
            }
        }
    }
    return true;
}

void Horario::agregarExamen(int dia, int turno, const Examen& e){
    if(dia >= turnos.size()) agregarDia(); // agregar días dinámicamente si es necesario
    turnos[dia][turno].push_back(e);
}

void Horario::quitarExamen(int dia, int turno, const Examen& e){
    if(dia >= turnos.size()) return;
    auto& turnoActual =  turnos[dia][turno];
    turnoActual.erase(remove(turnoActual.begin(), turnoActual.end(), e), turnoActual.end());
}

void Horario::mostrarHorario() const{
    int nTurnos = 0, nDias = 0;
    for(size_t dia = 0; dia < turnos.size(); ++dia){
        nDias++;
        for(size_t turno=0; turno < turnos[dia].size(); ++turno){
            cout << "Turno " << turno+1 << endl;
            nTurnos++;

            for(const auto& examen : turnos[dia][turno]){
                cout << "* " << examen.obtCodigo() << " (tipo " << (examen.esGrupoGrande() ? "g" : "r") << "), "
                << examen.obtCarrera() << "-" << examen.obtCurso() << " *" << endl;
            }
        }
    }

    double desviacion = calcularDesviacion(); //ESPECIFICAR PRECISION

    cout << "Num. turnos: " << nTurnos << endl;
    cout << "Num. dias: " << nDias << endl;
    cout << "Desviación: " << desviacion << endl;
}

void Horario::agregarRestriccion(const string& codi1, const string& codi2){
    restricciones.emplace_back(codi1, codi2);
}

double Horario::calcularDesviacion() const{
    // guardar examenes por grado y curso
    map<pair<string, int>, vector<int>> turnosPorCarreraCurso;

    // agrupar exámenes por grado y curso
    for(int dia = 0; dia < turnos.size(); dia++){
        for(int turno = 0; turno < turnos[dia].size(); turno++){
            for(const Examen& examen : turnos[dia][turno]){
                turnosPorCarreraCurso[{examen.obtCarrera(), examen.obtCurso()}].push_back(dia * 2 + turno);
            }
        }
    }

    // calcular desviación estándar para cada carrera y curso
    double sumaDesviaciones = 0.0;
    int nCarrerasCursos = 0;

    for(map<pair<string, int>, vector<int>>::const_iterator it = turnosPorCarreraCurso.begin();
        it != turnosPorCarreraCurso.end(); ++it){
        const vector<int>&turnos = it->second;

        if(turnos.size() < 2) continue; // si hay solo un examen, no hay desviación

        // calcular media de la asignatura y curso
        double mediaTurnos = 0.0;
        for(size_t i = 0; i < turnos.size(); i++){
            mediaTurnos += turnos[i];
        }
        mediaTurnos /= turnos.size();

        // calcular suma de variaciones
        double sumaVariaciones = 0.0;
        for(size_t i = 0; i < turnos.size(); i++){
            sumaVariaciones += (turnos[i] - mediaTurnos) * (turnos[i] - mediaTurnos);
        }

        double desviacion = sqrt(sumaVariaciones/turnos.size());
        sumaDesviaciones += desviacion;
        ++nCarrerasCursos;
    }

    // calcular desviación estándar media de todas las carreras y cursos
    return nCarrerasCursos > 0 ? sumaDesviaciones / nCarrerasCursos : 0.0;
}
