#include <iostream>
#include <array>
#include <random>
#include "constants.h"
#include "jeu.h"
#include "menu.h"

using namespace std;

int main () {
    bool continuer{true};
    auto indiceCourant{0};
    auto scores = array <int, NOMBRE_SCORES>{0,0,0};
    auto generateurAleatoire = std::random_device{};  
    auto generateur = mt19937{generateurAleatoire()};
    auto distribution = std::uniform_int_distribution{BORNE_MIN, BORNE_MAX};
    
    while (continuer) {
        afficherMenu();
        cout << WELCOME_DIALOG << endl;
        auto choix = demanderChoixMenu();
        switch (choix) {
        case ChoixMenu::JOUER:
            scores[indiceCourant] = jeu(distribution(generateur), BORNE_MAX);
            indiceCourant = (indiceCourant + 1 ) % NOMBRE_SCORES;
            break;
        case ChoixMenu::AFFICHER_SCORES:
            for(auto i{0}; i < NOMBRE_SCORES; i++) {
                if (scores[i] == 1) {
                    cout << "Partie " << i+1 << ": " << scores[i] << " tentative" << endl;
                }
                else if (scores[i] == 0) {
                    cout << "Partie " << i+1 << ": " << "-" << endl;
                }
                else {
                    cout << "Partie " << i+1 << ": " << scores[i] << " tentatives" << endl;  
                }
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
