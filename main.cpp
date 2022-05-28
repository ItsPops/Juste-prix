#include<iostream>
#include <array>
#include "constants.h"
#include "jeu.h"
#include "menu.h"

using namespace std;


int main () {
    bool continuer{true};
    auto indiceCourant{0};
    auto scores = array<int, NOMBRE_SCORES>{0,0,0}; 
    while (continuer) {
        afficherMenu();
        cout << WELCOME_DIALOG << endl;
        //array <int, NOMBRE_SCORES> scores {1,2,3};
        
        auto choix = demanderChoixMenu();
        switch (choix) {
        case ChoixMenu::JOUER:
            
            scores[indiceCourant] = jeu(4598, BORNE_MAX);
            //while (indiceCourant <= 3) {
                //indiceCourant ++;
                //TEST: cout << jeu(4598, BORNE_MAX) << "test" << endl;
                cout << scores[0] << " TEST APRES PARTIE" << endl; //TEST
                indiceCourant = (indiceCourant + 1 ) % NOMBRE_SCORES;
            break;
            // if (indiceCourant == 3) {
            //     indiceCourant = 0;
            //     }
            // } 
            // break;
        case ChoixMenu::AFFICHER_SCORES:
            for(auto i{0}; i < NOMBRE_SCORES; i++) {
                cout << scores[i] << endl;
            }
            break;
        case ChoixMenu::QUITTER:
            cout << "Au revoir !" << endl;
            continuer = false;
            break;
        case ChoixMenu::INCORRECT:
        default:
            cout << "Erreur" << endl;
            return EXIT_FAILURE;
        }
    }
}
