#include <iostream>
#include <vector>
#include <cmath>

struct tacka{

    tacka(int a, int b)
    : x{a}, y{b} { }; 

    int x;
    int y;

    void ispis(){
        std::cout << '(' << x << ',' << y << ')';
    }
};

double distanca (tacka a, tacka b){
    return sqrt( (b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y) );
}

int main(int argc, const char** argv) {

    int a, b, broj = 0;
    std::vector<tacka> v;
    for(;std::cin >> a >> b;){
        v.push_back( tacka(a, b) );
    }

    int tac1 = 0, tac2 = 0;
    double dist = 0;


    for(int i = 0; i < v.size(); ++i){
        for(int j = i; j < v.size(); ++j){
            if( distanca( v.at(i), v.at(j) ) > dist ){
                tac1 = i;
                tac2 = j;
                dist = distanca( v.at(i), v.at(j) );
            }
        }
    }

    v.at(tac1).ispis();
    v.at(tac2).ispis();
    std::cout << " = " << dist << std::endl;
    
    return 0;
}