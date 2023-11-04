#include <iostream>

template <class T>
class point {
    T x, y;

public:
    point(T abs, T ord) : x(abs), y(ord) {}

    // Surcharge de l'opérateur << pour l'affichage
    friend std::ostream& operator<<(std::ostream& out, const point<T>& p) {
        out << "Coordonnees : " << p.x << " " << p.y;
        return out;
    }
};

int main() {
    point<char> p(60, 65);
    std::cout << p << std::endl;

    return 0;
}
