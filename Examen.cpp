#include "Examen.h"

using namespace std;

string Examen::obtCodigo() const{ return codigo; }
string Examen::obtCarrera() const{ return grado; }
int Examen::obtCurso() const{ return curso; }
bool Examen::esGrupoGrande() const{ return granCapacidad; }
