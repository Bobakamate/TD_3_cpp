class erreur
{ public :
int num ;
} ;
class A
{ public :
A(int n)
{ if (n==1) { erreur er ; er.num = 999 ; throw er ; }
}
} ;
/*Quels résultats fournira ce programme utilisant ces deux classes :*/

#include <iostream>
using namespace std ;
main()
{ void f() ;
try
{ f() ;
}
catch (erreur er)
{ cout << "dans main : " << er.num << "\n" ;
}
cout << "suite main\n" ;
} void f()
{ try
{ A a(1) ;
}
catch (erreur er)
{ cout << "dans f : " << er.num << "\n" ;
}


/*
Le programme crée une hiérarchie d'exceptions en utilisant les classes erreur et A. Lorsque la fonction f() est appelée, elle crée un objet de la classe A avec n=1, ce qui déclenche la création de l'objet erreur er avec er.num égal à 999. Ensuite, l'objet er est jeté comme une exception.
Cette exception est attrapée dans le bloc catch de la fonction f(), et le message "dans f : 999" est affiché. Cependant, lorsque la fonction f() se termine, l'exception n'est pas attrapée à un niveau supérieur dans la fonction main() car ce sont des exceptions distinctes.
Le programme affichera donc "dans f : 999" suivi de "suite main". Les deux exceptions sont gérées localement dans leurs blocs catch, sans propagation de l'exception vers un niveau supérieur.

*/