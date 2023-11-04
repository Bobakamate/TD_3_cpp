#include <iostream>

template <typename T>
T carre(const T& valeur) {
    return valeur * valeur;
}

int main() {
    int entier = 5;
    float flottant = 3.5;
    double doublePrecision = 2.0;

    // Utilisation de la fonction modèle pour calculer le carré de différentes valeurs
    int carreEntier = carre(entier);
    float carreFlottant = carre(flottant);
    double carreDouble = carre(doublePrecision);

    std::cout << "Carré de " << entier << " : " << carreEntier << std::endl;
    std::cout << "Carré de " << flottant << " : " << carreFlottant << std::endl;
    std::cout << "Carré de " << doublePrecision << " : " << carreDouble << std::endl;

    return 0;
}
