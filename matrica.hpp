#include <iostream>
#include <vector>

void ispisiMatricu (const std::vector<std::vector<int>>& n );
std::vector<std::vector<int>> kreirajMatricu();
std::vector<std::vector<int>> kreirajMatricu(int a, int b);
void saberiMatrice( std::vector<std::vector<int>>& a, std::vector<std::vector<int>>& b, std::string& ero);
void pomnoziMatrice(std::vector<std::vector<int>>& a, std::vector<std::vector<int>>& b, std::string& ero);
void pronadjiGlavnuDijagonalu( std::vector<std::vector<int>>& a, char q );
void pronadjiSporednuDijagonalu( std::vector<std::vector<int>>& a, char q)