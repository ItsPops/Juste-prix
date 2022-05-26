#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

enum class ChoixMenu {
    JOUER = 'j',
    AFFICHER_SCORES = 's',
    QUITTER = 'q',
    INCORRECT
};
void afficherMenu();
ChoixMenu demanderChoixMenu();



#endif 