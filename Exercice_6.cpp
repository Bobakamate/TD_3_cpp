#include <iostream>
#include <cstring> // Pour std::memcpy

class vect {
protected:
    int nelem; // nombre d'éléments
    int* adr; // adresse de la zone dynamique contenant les éléments

public:
    vect(int n) : nelem(n), adr(new int[n]) {
        // Initialiser les éléments à zéro
        for (int i = 0; i < n; ++i) {
            adr[i] = 0;
        }
    }

    ~vect() {
        delete[] adr;
    }

    int& operator[](int index) {
        return adr[index];
    }

    int taille() const {
        return nelem;
    }
};

class vectok : public vect {
public:
    vectok(int n) : vect(n) {}

    // Constructeur par recopie
    vectok(const vect& other) : vect(other.nelem) {
        std::memcpy(adr, other.adr, nelem * sizeof(int));
    }

    // Opérateur d'affectation
    vectok& operator=(const vect& other) {
        if (this != &other) { // Éviter l'auto-affectation
            if (nelem != other.nelem) {
                delete[] adr; // Libérer la mémoire existante
                nelem = other.nelem;
                adr = new int[nelem];
            }
            std::memcpy(adr, other.adr, nelem * sizeof(int));
        }
        return *this;
    }
};

int main() {
    vectok v1(5);
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;

    vectok v2 = v1; // Utilisation du constructeur par recopie
    vectok v3(3);
    v3 = v2; // Utilisation de l'opérateur d'affectation

    std::cout << "Taille de v1 : " << v1.taille() << std::endl;
    std::cout << "Contenu de v2 : " << v2[0] << ", " << v2[1] << ", " << v2[2] << std::endl;
    std::cout << "Contenu de v3 : " << v3[0] << ", " << v3[1] << ", " << v3[2] << std::endl;

    return 0;
}
