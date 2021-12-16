/*
Napisati funkciju saberi koja moze primiti argumente proizvoljnih tipova. Za numericke tipove ova funkcija vraca rezultat generisan koristenjem + operatora, dok za stringove i niz karaktera vrsi spajanje (konkatenacija). Funkcija moze primati opcioni (treci argument) koji ako je proslijedjen mnozi rezultat sabiranja.
*/

#include <iostream>
#include <string>

template <typename T>
T saberi (T a, T b, int c){
    T sab{};
    for(int i = 0; i < c; ++i)
        sab += a + b;
    return sab;
}

int main(int argc, const char** argv) {
    int a, b;
    std::string g, l;
    std::cout << "Unesi a:";
    std::cin >> a;
    std::cout << "Unesi b:";
    std::cin >> b;
    std::cout << "Unesi g:";
    std::cin >> g;
    std::cout << "unesi l:" << std::endl;
    std::cin >> l;

    std::cout << saberi(a, b, 4);
    std::cout << saberi(g, l, 3);

    return 0;
}