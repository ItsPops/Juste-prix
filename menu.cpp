#include <iostream>
#include "menu.h"

using namespace std;


ChoixMenu demanderChoixMenu() {
        char saisieChoix;
        cin >> saisieChoix;
        if (saisieChoix == static_cast<char>(ChoixMenu::JOUER) || saisieChoix == static_cast<char>(ChoixMenu::QUITTER)
        || saisieChoix == static_cast<char>(ChoixMenu::AFFICHER_SCORES)) {
            return static_cast<ChoixMenu>(saisieChoix);
        } else {
            return ChoixMenu::INCORRECT; 
    }
}

void afficherMenu() {
    cout << static_cast<char>(ChoixMenu::JOUER) << " : jouer" << endl;
    cout << static_cast<char>(ChoixMenu::AFFICHER_SCORES) << " : afficher les scores" << endl;
    cout << static_cast<char>(ChoixMenu::QUITTER) << " : quitter" << endl;
}