#include <iostream>
#include <vector>
#include <string>

typedef std::string str;

void svicarski_noz(){
    std::cout << "11:04:10" << std::endl; // ne znam ispisat vrijeme
}

void svicarski_noz(int a){
    a*=a;
    if(a%2!=0)
        --a;
    std::cout << a << std::endl;
}

void svicarski_noz(const std::vector<int>& a){
    for(auto var : a)
    {
        std::cout << var << ' ';
    }
    std::cout << std::endl;
}

str svicarski_noz(str a){
    for(int i = 0; i<a.size()/2; ++i)
        std::swap( a.at(i), a.at(a.size()-1-i) );
    a += '\n';
    return a;
}

void svicarski_noz(str a, str b){
    str k = a + " " + b + '\n';
    std::cout << k;
}

void svicarski_noz(double a){
    std::cout << a << ", " << a+a << ", " << a+a+a << std::endl;
}



int main(int argc, const char** argv) {
    
    std::vector<int> niz{1,2,3};
    svicarski_noz(2);
    svicarski_noz(3);
    svicarski_noz(4);
    svicarski_noz("pozdrav","svima");
    svicarski_noz(3.14);
    svicarski_noz(niz);
    svicarski_noz();
    std::cout << svicarski_noz("pozdrav");
    std::cout << svicarski_noz(svicarski_noz("pozdrav"));


    return 0;
}