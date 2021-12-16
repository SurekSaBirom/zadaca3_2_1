#include "IOrijeci.hpp"
#include "MAXrijec.hpp"
#include "dodavanje.hpp"

void unos( std::vector<std::string>& a){
    std::string k;
    while(std::cin >> k){
        if(!(std::cin)){
            std::cin.clear();
            break;
        }
        a.push_back(k);
    }
}
void ispis( const std::vector<std::string>& a){
    for(auto var : a)
        std::cout << var << std::endl;
}

int maxrijec (const std::vector<std::string>& a){
    int max = a.at(0).size();
    //std::string maxr = a.at(0);
    for(auto var : a)
        if (var.size() > max ) max = var.size();
    return max;
}

std::string dodavanje (std::string a, int c, char b){
    return std::string(c, b) + a;
};
std::string dodavanje (std::string a, int c){
    return std::string(c, ' ') + a;
};