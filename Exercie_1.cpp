#include <iostream>

class Complexe {
private:
    double reel;
    double imaginaire;

public:
    Complexe(double r = 0.0, double i = 0.0) : reel(r), imaginaire(i) {}

    // Redéfinition des opérateurs
    Complexe operator+(const Complexe& autre) const {
        return Complexe(reel + autre.reel, imaginaire + autre.imaginaire);
    }

    Complexe operator-(const Complexe& autre) const {
        return Complexe(reel - autre.reel, imaginaire - autre.imaginaire);
    }

    Complexe operator*(const Complexe& autre) const {
        double nouveauReel = (reel * autre.reel) - (imaginaire * autre.imaginaire);
        double nouveauImaginaire = (reel * autre.imaginaire) + (imaginaire * autre.reel);
        return Complexe(nouveauReel, nouveauImaginaire);
    }

    void afficher() {
        std::cout << "Partie réelle : " << reel << ", Partie imaginaire : " << imaginaire << std::endl;
    }
};

int main() {
    double partieReelle1, partieImaginaire1, partieReelle2, partieImaginaire2;

    std::cout << "Entrez la partie reelle du premier nombre complexe : ";
    std::cin >> partieReelle1;
    std::cout << "Entrez la partie imaginaire du premier nombre complexe : ";
    std::cin >> partieImaginaire1;
    
    std::cout << "Entrez la partie reelle du deuxieme nombre complexe : ";
    std::cin >> partieReelle2;
    std::cout << "Entrez la partie imaginaire du deuxieme nombre complexe : ";
    std::cin >> partieImaginaire2;

    Complexe nombre1(partieReelle1, partieImaginaire1);
    Complexe nombre2(partieReelle2, partieImaginaire2);

    Complexe somme = nombre1 + nombre2;
    Complexe difference = nombre1 - nombre2;
    Complexe produit = nombre1 * nombre2;

    std::cout << "Somme : ";
    somme.afficher();

    std::cout << "Difference : ";
    difference.afficher();

    std::cout << "Produit : ";
    produit.afficher();

    return 0;
}
