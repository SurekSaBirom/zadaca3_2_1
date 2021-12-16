#include <iostream>
#include <vector>
#include <algorithm>
#include "IOrijeci.hpp"
#include "MAXrijec.hpp"
#include "dodavanje.hpp"

int main(int argc, const char** argv) {

    std::vector<std::string> s1 = { "adfa", "gadgdagda", "dsf", "adfaffadfafa", "adf", "ds" };

    //unos(s1);

    auto kriterij = [] ( std::string a, std::string b ) -> bool {return a.size() < b.size();};
    std::sort(s1.begin(), s1.end(), kriterij);

    int maxr = maxrijec(s1);

    for(auto& var : s1)
        var = dodavanje(var, maxr - var.size());
    ispis(s1);

    return 0;
}