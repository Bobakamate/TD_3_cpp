#include <iostream>
#include <vector>
#include <list>
#include <set>

// Fonction de recherche générique
template <typename InputIt, typename T>
bool rechercheElement(InputIt begin, InputIt end, const T& valeur) {
    for (InputIt it = begin; it != end; ++it) {
        if (*it == valeur) {
            return true;
        }
    }
    return false;
}

int main() {
    // Exemple 1 : Vecteur de chaînes
    std::vector<std::string> vecteurString = {"apple", "banana", "cherry", "date"};
    std::string rechercheString = "banana";
    bool trouveString = rechercheElement(vecteurString.begin(), vecteurString.end(), rechercheString);
    std::cout << "Trouvé dans le vecteur de chaînes : " << trouveString << std::endl;

    // Exemple 2 : Liste d'entiers
    std::list<int> listeEntiers = {1, 2, 3, 4, 5};
    int rechercheEntier = 3;
    bool trouveEntier = rechercheElement(listeEntiers.begin(), listeEntiers.end(), rechercheEntier);
    std::cout << "Trouvé dans la liste d'entiers : " << trouveEntier << std::endl;

    // Exemple 3 : Tableau de flottants
    float tableauFloat[] = {1.1f, 2.2f, 3.3f, 4.4f};
    float rechercheFloat = 3.3f;
    bool trouveFloat = rechercheElement(std::begin(tableauFloat), std::end(tableauFloat), rechercheFloat);
    std::cout << "Trouvé dans le tableau de flottants : " << trouveFloat << std::endl;

    return 0;
}
