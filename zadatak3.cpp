#include <vector>
#include <iostream>
#include <functional>

using vec = std::vector<int>;

template <typename t>
void transformiraj (vec& v1,const vec& v2, t lamb ){
    if ( v1.size() != v2.size() ) throw std::domain_error("Vektori nisu iste velicine");
    vec::iterator p1 = v1.begin();
    vec::const_iterator p2 = v2.begin();
    while( p1 != v1.end() ){
        *p1 = lamb( *p1, *p2 );
        ++p1;
        ++p2;
    }
}

/*
void transformiraj (vec& v1, vec& v2, std::function<int(int, int)> lamb = [](int a, int b){ return a + b;}){
    if ( v1.size() != v2.size() ) throw std::domain_error(std::string{"Vektori nisu iste velicine"});
    vec::iterator p1 = v1.begin();
    vec::iterator p2 = v2.begin();
    while( p1 != v1.end() ){
        *p1 = lamb( *p1, *p2 );
        ++p1;
        ++p2;
    }
}*/

int main(int argc, const char** argv) {
    
    vec a = {5, 12, 4, 9}, b = {1, 5, 3, 7};

    auto l = [](int x, int y){ return x + y; };

    try{
    transformiraj( a, b, l );
    }catch(const std::domain_error& f){
        std::cout << f.what() << std::endl;
        return 1;
    }

    for(auto var : a)
    {
        std::cout << var << ", ";
    }
    std::cout << "\b\b." << std::endl;

    return 0;
}