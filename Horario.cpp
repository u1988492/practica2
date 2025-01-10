#include "Horario.h"

using namespace std;

int Horario::obtMaxDias(){ return maxDias; }

int Horario::obtAulasG(){ return aulasG; }

int Horario::obtAulasR(){ return aulasR; }

const vector<vector<vector<Examen>>>& Horario::obtHorarios() const{ return turnos; }

bool Horario::sePuedeAgregar(int dia, int turno, const Examen& e) const{
    return false;
}

void Horario::agregarExamen(int dia, int turno, const Examen& e){
    cout << "agregar examen" << endl;
}

void Horario::quitarExamen(int dia, int turno, const Examen& e){
    cout << "quitar examen" << endl;
}

void Horario::mostrarHorario() const{
    cout << "mostrar horario" << endl;
}

void Horario::agregarRestriccion(const string& codi1, const string& codi2){
    cout << "agregar restriccion" << endl;
}
