#include <iostream>
#include <stdexcept> // Pour les exceptions

using namespace std;

class Test {
public:
    static int tableau[];

public:
    static int division(int indice, int diviseur) {
        if (diviseur == 0) {
            throw std::invalid_argument("Division par zéro !");
        }
        if (indice < 0 || indice >= 10) {
            throw std::out_of_range("Indice hors limites !");
        }
        return tableau[indice] / diviseur;
    }
};

int Test::tableau[] = {17, 12, 15, 38, 29, 157, 89, -22, 0, 5};

int main() {
    int x, y;

    cout << "Entrez l'indice de l'entier à diviser : " << endl;
    cin >> x;

    cout << "Entrez le diviseur : " << endl;
    cin >> y;

    try {
        cout << "Le résultat de la division est : " << endl;
        cout << Test::division(x, y) << endl;
    } catch (const std::invalid_argument& e) {
        cerr << "Erreur : " << e.what() << endl;
    } catch (const std::out_of_range& e) {
        cerr << "Erreur : " << e.what() << endl;
    } catch (const std::exception& e) {
        cerr << "Erreur inattendue : " << e.what() << endl;
    }

    return 0;
}
