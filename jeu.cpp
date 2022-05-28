#include <iostream>
#include <chrono>
#include "jeu.h"
#include "constants.h"


using namespace std;

void demanderProposition(int& proposition) {
    cin >> proposition;
}

int jeu(int leJustePrix, int max) {
auto proposition{0};
auto nombreTentative{0};

using Duree = std::chrono::duration<double>; 
auto debutPartie = std::chrono::system_clock::now();

do {
    cout << INPUT_DIALOG << endl;
    demanderProposition(proposition);
    if(proposition >= BORNE_MIN && proposition < max) {
        nombreTentative++;
        if(proposition == leJustePrix) {
            cout << "Bravo ! Vous avez trouvé en " << nombreTentative << " tentatives." << endl;
        } else if (proposition > leJustePrix) {
            cout << "C'est moins !" << endl;
        } else {
            cout << "C'est plus !" << endl;
        }
        
    }
    
} while(proposition != leJustePrix && proposition >= BORNE_MIN);
auto finPartie = std::chrono::system_clock::now();
auto duree = std::chrono::duration_cast<Duree>(finPartie - debutPartie);
if (proposition == leJustePrix) {
    cout << "Partie terminée en " << duree.count() << " secondes." << endl;
} else {
    cout << "Partie abandonnée..." << endl;
    }
return nombreTentative;
}
