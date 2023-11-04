#include <iostream>
#include <list>

// Fonction pour afficher une liste
void afficherListe(const std::list<int>& liste) {
    for (const int& element : liste) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

// Tri à bulles
void triABulles(std::list<int>& liste) {
    for (auto it1 = liste.begin(); it1 != liste.end(); ++it1) {
        for (auto it2 = std::next(it1); it2 != liste.end(); ++it2) {
            if (*it1 > *it2) {
                std::swap(*it1, *it2);
            }
        }
    }
}

// Tri par sélection
void triParSelection(std::list<int>& liste) {
    for (auto it1 = liste.begin(); it1 != std::prev(liste.end()); ++it1) {
        auto min = it1;
        for (auto it2 = std::next(it1); it2 != liste.end(); ++it2) {
            if (*it2 < *min) {
                min = it2;
            }
        }
        if (min != it1) {
            std::swap(*it1, *min);
        }
    }
}

// Tri par insertion
void triParInsertion(std::list<int>& liste) {
    for (auto it1 = std::next(liste.begin()); it1 != liste.end(); ++it1) {
        int element = *it1;
        auto it2 = it1;
        while (it2 != liste.begin() && *(std::prev(it2)) > element) {
            *it2 = *(std::prev(it2));
            --it2;
        }
        *it2 = element;
    }
}

int main() {
    std::list<int> liste;

    int n;
    std::cout << "Entrez des entiers (0 pour arrêter) : ";
    while (true) {
        std::cin >> n;
        if (n == 0) {
            break;
        }
        liste.push_back(n);
    }

    std::cout << "Liste non triée : ";
    afficherListe(liste);

    std::list<int> listeTrieeBulles = liste;
    triABulles(listeTrieeBulles);
    std::cout << "Tri à bulles : ";
    afficherListe(listeTrieeBulles);

    std::list<int> listeTrieeSelection = liste;
    triParSelection(listeTrieeSelection);
    std::cout << "Tri par sélection : ";
    afficherListe(listeTrieeSelection);

    std::list<int> listeTrieeInsertion = liste;
    triParInsertion(listeTrieeInsertion);
    std::cout << "Tri par insertion : ";
    afficherListe(listeTrieeInsertion);

    return 0;
}
