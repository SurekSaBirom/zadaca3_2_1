#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <map>

typedef std::vector<std::vector<int>> matr;

void ispisiMatricu (const matr& n ){
  
  std::string okraj(8*n.at(0).size(), '-');
  std::cout << okraj << '\n';
  for(int i = 0; i < n.size(); ++i){
    for( int j = 0; j < n.at(0).size(); ++j){
      std::cout << n.at(i).at(j) << '\t';
    }
    std::cout << "\b " << std::endl;
  }
  std::cout << okraj << "\n\n";
}

matr kreirajMatricu(){
  std::random_device dev;
  std::mt19937 gesus(dev());
  std::uniform_int_distribution<std::mt19937::result_type> rn(0,100);

  matr v;
  
  int m, n;
  std::cout << "\nBroj redova: ";
  std::cin >> m;
  std::cout << "\nBroj kolona: ";
  std::cin >> n;
  std::cout << std::endl;

  for(int i = 0; i < m; ++i){
    std::vector<int> temp;
    for(int j = 0; j < n; ++j){
      temp.push_back( rn(gesus) );
    }
    v.push_back(temp);
  }

  ispisiMatricu(v);

  return v;
}

matr kreirajMatricu(int a, int b){
  matr v;
  for(int i = 0; i < a; ++i){
    std::vector<int> temp;
    for(int j = 0; j < b; ++j){
      temp.push_back( 0 );
    }
    v.push_back(temp);
  }
  //std::cout << "\n\n\nN U L T A    M A T R I C A :\n";
  //ispisiMatricu(v);
  return v;
}

void saberiMatrice( matr& a, matr& b, std::string& ero){
  if( a.size() != b.size() && a.at(0).size() != b.at(0).size() )
    throw std::logic_error(ero = "Nemoguce je sabrati matrice razlicitog tipa!");
  else{
    matr sum;
    for(int i = 0; i < a.size(); ++i){
    std::vector<int> temp;
    for(int j = 0; j < a.at(0).size(); ++j){
      temp.push_back( a.at(i).at(j) + b.at(i).at(j) );
    }
    sum.push_back(temp);
  }

  std::cout << "\nSuma matrica: \n";
  ispisiMatricu(sum);
  }
}

void pomnoziMatrice(matr& a, matr& b, std::string& ero){
  if( a.size() != b.at(0).size())
    throw std::logic_error(ero = "Nemoguce je pomnoziti matrice ako broj redova prve nije jednak broju kolona druge!");
  else{
    matr proi = kreirajMatricu( a.size(), b.at(0).size() );
    for(int i = 0; i < a.size(); ++i){
      for(int j = 0; j < b.at(0).size(); ++j){
        for(int k = 0; k < a.at(0).size(); ++k){
          proi.at(i).at(j) += a.at(i).at(k) * b.at(k).at(j);
        }
      }
    }
    ispisiMatricu(proi);
  }
}

void pronadjiGlavnuDijagonalu( matr& a, char q ){
  int j = 0, rep = a.size();

  if(a.size()>a.at(0).size())
    rep=a.at(0).size();

  std::cout << "Main diagonal (" << q << ')' << std::endl;
  do{
    std::cout << a[j][j]<< ',';
    ++j;
  } while (j < rep);
  std::cout << "\b \n";
}

void pronadjiSporednuDijagonalu( matr& a, char q){
  int row = 0, col = a.at(0).size()-1;
  std::cout << "Secondary diagonal (" << q << ')' << std::endl;
  do
  {
    std::cout << a[row][col] << ',';
    ++row;
    --col;
  } while (row < a.size() && col != -1);
  std::cout << "\b \n";

}

int main(int argc, const char** argv) {
  
  std::map<char, matr> matrice;
  std::string err = "";
  char y;
  
  std::cout << "Unesite dimenzije matrice A\n";
  matrice['A'] = kreirajMatricu();
  std::cout << "Unesite dimanzije matrice B\n";
  matrice['B'] = kreirajMatricu();

  std::cout << "Unesi operaciju (+ ili *): ";
  for(;!(std::cin >> y) || (y != '+' && y != '*');){
    std::cout << "Nevalidan unos" << std::endl;
    std::cin.clear();
    std::cin.ignore(1000, '\n');
  }
  try{
  (y=='+') ? saberiMatrice(matrice['A'], matrice['B'], err) : pomnoziMatrice(matrice['A'], matrice['B'], err);
  }catch(std::logic_error){std::cout << err << std::endl;};

  pronadjiGlavnuDijagonalu(matrice['A'], 'A');
  pronadjiGlavnuDijagonalu(matrice['B'], 'B');
  pronadjiSporednuDijagonalu(matrice['A'], 'A');
  pronadjiSporednuDijagonalu(matrice['B'], 'B');

  return 0;
}