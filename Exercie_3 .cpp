#include <iostream>
#include <list>
#include <string>
#include <algorithm>

// Structure representant une personne
struct Personne {
    std::string nom;
    std::string prenom;
    int age;

    
    bool operator<(const Personne& autre) const {
        if (nom != autre.nom) {
            return nom < autre.nom;
        }
        return prenom < autre.prenom;
    }
};

int main() {
    std::list<Personne> listePersonnes;

    // Saisie des personnes
    while (true) {
        Personne personne;
        std::cout << "Entrez le nom de la personne (ou 'fin' pour terminer) : ";
        std::cin >> personne.nom;

        if (personne.nom == "fin") {
            break;
        }

        std::cout << "Entrez le prenom de la personne : ";
        std::cin >> personne.prenom;

        std::cout << "Entrez l'age de la personne : ";
        std::cin >> personne.age;

        listePersonnes.push_back(personne);
    }

    // Tri de la liste selon l'ordre alphabetique du nom et du prenom
    listePersonnes.sort();

    // Affichage de la liste triée
    std::cout << "Liste triee : " << std::endl;
    for (const Personne& personne : listePersonnes) {
        std::cout << "Nom : " << personne.nom << ", Prenom : " << personne.prenom << ", age : " << personne.age << std::endl;
    }

    return 0;
}
