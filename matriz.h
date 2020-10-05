#ifndef MATRIZ_H
#define MATRIZ_H
#include <string>
#include <iostream>
using namespace std;
using std::string;

class Matriz
{
private:
    int ** mat;
    int line;
    int col;
public:
    Matriz();
    Matriz(int l, int c);
    std::string getMatriz() const;
    void setElemento(int l,int c, int elemento);
    int getElemento(int l,int c) const;
    Matriz* operator+(Matriz* m);
    Matriz* operator-(Matriz* m);
    Matriz* operator*(Matriz* m);
    Matriz&  operator=(const Matriz &m);
    bool triangularSuperior();
    bool triangularInferior();
    bool simetrica();
    bool identidade();
    Matriz* transposta();
    void potenciacao(int pot);
    Matriz* multipicaEscalar(int k);
    bool igual(Matriz* m);
    bool ortogonal();
    bool permutacao();
    int getLine() const;
    void setLine(int value);
    int getCol() const;
    void setCol(int value);
    ~Matriz();
};

#endif // MATRIZ_H
