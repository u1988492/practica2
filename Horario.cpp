#include "Horario.h"

using namespace std;

Horario::Horario(int maxDias, int aulasG, int aulasR): maxDias(maxDias), aulasG(aulasG), aulasR(aulasR){

    if(maxDias>0){
        turnos.resize(maxDias, vector<vector<Examen>>(2)); // reservar días con 2 turnos
    }
}

int Horario::obtMaxDias(){ return maxDias; }

int Horario::obtAulasG(){ return aulasG; }

int Horario::obtAulasR(){ return aulasR; }

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
    cout << "agregar examen" << endl;
    if(dia >= turnos.size()) agregarDia(); // agregar días dinámicamente si es necesario
    turnos[dia][turno].push_back(e);
}

void Horario::quitarExamen(int dia, int turno, const Examen& e){
    cout << "quitar examen" << endl;
    if(dia >= turnos.size()) return;
    auto& turnoActual =  turnos[dia][turno];
    turnoActual.erase(remove(turnoActual.begin(), turnoActual.end(), e), turnoActual.end());
}

void Horario::mostrarHorario() const{
    for(size_t dia = 0; dia < turnos.size(); ++dia){
        cout << " Dia " << dia + 1 << endl;
        for(size_t turno=0; turno < turnos[dia].size(); ++turno){
            cout << "Turno " << (turno == 0 ? "Mañana" : "Tarde") << endl;
            for(const auto& examen : turnos[dia][turno]){
                cout << "   " << examen.obtCodigo() << " (" << (examen.esGrupoGrande() ? "g" : "r") << "), "
                << examen.obtCarrera() << " - " << examen.obtCarrera() << "º curso" << endl;
            }
        }
    }
}

void Horario::agregarRestriccion(const string& codi1, const string& codi2){
    cout << "agregar restriccion" << endl;
    restricciones.emplace_back(codi1, codi2);
}

double Horario::calcularDesviacion() const{
    vector<int> examenesPorDia;

    for(const auto&dia : turnos){ // dia: <vector<vector<vector<Examen>>>
        int cont = 0;
        for(const auto&turno : dia){ // turno: <vector<vector<Examen>>
            cont += turno.size(); //  total de turnos en cada dia
        }
        examenesPorDia.push_back(cont);
    }

    double media = 0.0;
    for(int cont : examenesPorDia){
        media += cont;
    }
    media /= examenesPorDia.size();

    double variacion = 0.0;
    for(int cont : examenesPorDia){
        variacion += (cont-media) * (cont-media);
    }

    variacion /= examenesPorDia.size();

    return sqrt(variacion);
}
