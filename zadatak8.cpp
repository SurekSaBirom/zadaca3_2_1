#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <functional>
#include <iterator>
#include <stdlib.h>

using vektor = std::vector<std::string>;

void ispisi (vektor& a, std::ostream& ode){
    for(auto var : a)
        ode << var << ' ';
    std::cout << std::endl;
}

vektor dodaj(vektor& v, std::string a){
    v.push_back(a);
    return v;
}

void kopiraj(const vektor& v1, vektor& v2 ){
    if ( v2.size() <= v1.size() ){
        v2.clear();
        for(auto& var : v1)
            v2.push_back(var);
        exit;
    }
    vektor::const_iterator it1 = v1.begin();
    vektor::iterator it2 = v2.begin();
    while(it1 != v1.end()){
        *it2 = *it1;
        ++it1; ++it2;
    }
}

template <typename t>
void izvrsi( vektor& v1, t lamb ){
    for(auto& var : v1)
        var = lamb(var);
}

void obrisi(vektor& v){ v.clear();}

void obrisiRijec( vektor& v, std::string rijec){
    auto l = [rijec](std::string r){ return rijec == r; };
    vektor::iterator it = v.begin();
    while( it != v.end() )
        (*it == rijec) ? it=v.erase(it) : ++it;
}

vektor sortiraj( vektor& v, std::function<bool(std::string, std::string)> l = [](std::string a, std::string b) {return a < b;} ){
    std::sort(v.begin(), v.end(), l);
    return v;
}

void dodajVektor(const vektor& a, vektor& b){
    std::copy( a.begin(), a.end(), std::back_inserter(b) );
}

void obrisiIsteRijeci( const vektor& a, vektor& b ){
    vektor::const_iterator it1 = a.begin();
    vektor::iterator it2 = b.begin();

    while(it1 != a.end() ){
        while (it2 != b.end() )
            (*it1 == *it2) ? it2 = b.erase(it2) : ++it2;
        ++it1;
        it2 = b.begin();
    }
}

void obrisiRazliciteRijeci( const vektor& a, vektor& b){
    vektor::const_iterator it1 = a.begin();
    vektor::iterator it2 = b.begin();
    bool pojav = false;
    while(it2 != b.end() ){
        while( it1 != a.end() ){
            if ( *it1 == *it2 ) pojav = true;
            ++it1;
        }
        (pojav == false) ? it2 = b.erase(it2) : ++it2;
        pojav = false;
        it1 = a.begin();
    }
}

template <typename t>
void izvrsiNPuta(vektor& v, t l, int a){
    for(int i = 0; i < a; ++i){
        for (auto &&i : v)
        {
            l(i);
        }
    }
}

int main(int argc, const char** argv) {
 
    std::vector<std::string> baza1{"emir", "mirza", "meliha", "jasnim", "dzemo"};
    std::vector<std::string> baza2;
    kopiraj(baza1, baza2);
    dodaj(baza1, "dino");
    dodaj(baza2, "samir");
    obrisiIsteRijeci(baza1, baza2);
    obrisiRazliciteRijeci(baza2, baza1);
    dodaj(baza2, "emina");
    dodaj(baza1, "muharem");
    dodajVektor(baza1, baza2);
    sortiraj(baza2);
    izvrsiNPuta(baza2,[](std::string& rijec){rijec[0]++;},3);
    dodajVektor(baza2, baza2);
    vektor k = dodaj(baza2,"amer");
    k = sortiraj(k);
    ispisi(k, std::cout);


    return 0;
}