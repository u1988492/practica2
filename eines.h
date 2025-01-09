//
// Created by jordir on 25/9/21.
//

#ifndef LECTURA_EINES_H
#define LECTURA_EINES_H

#include <string>
#include <vector>
using namespace std;

// pre: --
// post: excepcions: si cometes és cert, el primer caràcter és " i no hi ha unes segones " que tanquin, es genera una excepció
// retorna: cadena entre posicio primer i següent separador o final de linia
//          si cometes és cert, quan el token comença per " busca la " que ho tanca i les elimina del token
string token(const string &s, char separador, bool cometes, long &primer, long &ultim);

// pre: --
// post: --
// retorna: vector<string> amb tots els components d'una línia CSV bàsica (només tractant separadors)
//          un component està format per tots els caràcters entre dos separador excepte el primer i l'últim
//              el primer component està format per tots els caràcters abans del primer separador
//              l'últim component està format per tots els caràcters de després de l'últim separador
vector<string> tokens(const string &s, char separador = ',', bool cometes = false);


#endif //LECTURA_EINES_H
