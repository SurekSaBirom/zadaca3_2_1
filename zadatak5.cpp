#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using string = std::string;

struct radnik{
        string ime, prezime, mjstan;
        int godRod;
        double plata;

        explicit radnik(string a, string b, string c, int d, double e) :
        ime{a}, prezime{b}, mjstan{c}, godRod{d}, plata{e} {
            if (plata < 0) throw string{"Unijeli ste negativnu platu!"};
            if (godRod < 0) throw string{"Unijeli ste negativnu godinu rodjenja!"};
            std::cout << "Radnik je unesen u bazu podataka." << std::endl;
            std::cout << string(40, '-') << std::endl;
        };

        void info(){
            std::cout << "Ime:\t\t\t" << ime << std::endl;
            std::cout << "Prezime:\t\t" << prezime << std::endl;
            std::cout << "Mjesto stanovanja:\t" << mjstan << std::endl;
            std::cout << "Godina rodjenja:\t" << godRod << std::endl;
            std::cout << "Plata:\t\t\t" << plata << std::endl;
            std::cout << string(40, '-') << std::endl;
        }
};

radnik unos(){
    string a(40, '-');
    string aa, b, c; 
    int d; 
    double e;
    std::cout << "Unesite ime: \t\t\t"; std::cin >> aa;
    std::cout << a << "\nUnesite prezime: \t\t"; std::cin >> b;
    std::cout << a << "\nUnesite mjesto stanovanja: \t"; std::cin >> c;
    std::cout << a << "\nUnesite godinu rodjenja: \t"; std::cin >> d;
    std::cout << a << "\nUnesite platu: \t\t\t"; std::cin >> e;
    std::cout << a << '\n';

    if(!(std::cin)){
        std::cin.clear();
        throw std::string{"Unos je zavrsen"};
    }

    return radnik(aa, b, c, d, e);
}

void ispis(radnik& a){ a.info(); }

int main(int argc, const char** argv) {
 
    std::vector<radnik> v;

    try{
    while(1)
        v.push_back(unos());
    }catch(const std::string& f){
        std::cout << string(20, '-') << '\n' << f << '\n' << string(20, '-') << std::endl;
    }

    auto l = [](radnik a, radnik b){ 
        if(a.plata != b.plata)
            return a.plata > b.plata;
        if(a.ime != b.ime)
            return a.ime < b.ime;
        return a.godRod < b.godRod;
    };

    std::sort( v.begin(), v.end(), l );

    for (auto& i : v)  ispis(i);

    return 0;
}