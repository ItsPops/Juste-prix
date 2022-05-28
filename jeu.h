#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

#include <array>
#include "constants.h"

void demanderProposition(int& proposition); 
int jeu(int leJustePrix, int max = BORNE_MAX); // int max = BORNE_MAX permet de rendre facultatif le fait de spécifier le deuxième argument. A défaut, BORNE_MAX sera utilisé. Les paramètres facultatifs sont à placer en fin d'arguments. 

#endif 