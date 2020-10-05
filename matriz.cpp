#include "matriz.h"
Matriz::Matriz()
    :mat(nullptr),
    line(0),
    col(0) { }

Matriz::Matriz(int l, int c):
    mat(nullptr),
    line(0),
    col(0)
{
    if (l < 1 || c < 1) throw string("Nao pertimido!");

    try {
        line = l;
        col = c;
        mat = new int* [line];
        for (int i=0;i<line;i++) mat[i] = new int[col];

    } catch (std::bad_alloc&) {
        throw string("Memoria Insulficiente!");
    }
}

int Matriz::getLine() const
{
    return line;
}

void Matriz::setLine(int value)
{
    line = value;
}

int Matriz::getCol() const
{
    return col;
}

void Matriz::setCol(int value)
{
    col = value;
}

string Matriz::getMatriz() const
{
    if (!col || !line)
        return "0";
    string str = "";
    for (int i=0;i<line;i++) {
        for (int j=0;j<col;j++) {
            str += to_string(getElemento(i,j));
            str += "  ";
        }
        str += '\n';
    }
    return str;
}

void Matriz::setElemento(int l, int c, int elemento)
{
    if (l < 0 || l >= line || c < 0 || c >= col)
        throw string("Passa do tamanho da matriz!");
    mat[l][c] = elemento;
}

int Matriz::getElemento(int l, int c) const
{
    if (l < 0 || l >= line || c < 0 || c >= col)
        throw string("Valores nao permitidos!");
    return mat[l][c];
}

Matriz* Matriz::operator+(Matriz *m)
{
    if (line != m->line || col != m->col)
        throw string("Erro ao adicionar");
    Matriz *C = new Matriz(line,col);
    for(int i=0;i<C->line;i++)
        for(int j=0;j<C->col;j++)
            C->setElemento(i, j, mat[i][j] + m->mat[i][j]);
    return C;
}

Matriz* Matriz::operator-(Matriz* m)
{
    if (line != m->line || col != m->col) throw string("Erro subtrair");
        Matriz* C = new Matriz(line,col);
        for(int i=0;i<line;i++)
            for(int j=0;j<col;j++) {
                int x = mat[i][j] - m->mat[i][j];
                C->setElemento(i,j,x);
            }
        return C;
}

Matriz* Matriz::operator*(Matriz* m)
{
    if (col != m->line) throw string("Erro ao multiplicar!");
    Matriz* C = new Matriz(line, m->col);
    for (int i=0;i<line;i++)
        for (int j=0;j<m->col;j++) {
            C->mat[i][j] = 0;
            for (int k=0;k<col;k++)
                C->mat[i][j] += mat[i][k] * m->mat[k][j];
        }
    cout << "operator*\n"  << C->getMatriz() << endl;
    return C;
}

bool Matriz::triangularSuperior()
{
    if (line != col) return false; // tem que ser matriz quadrada

    for (int i=1;i<line;i++) {
        int j = 0;
        while (i > j && j < col) {
            if (mat[i][j] != 0)
                return false;
            j++;
        }
    }
    return true;
}

bool Matriz::triangularInferior()
{
    if (line != col) return false;// tem que ser matriz quadrada

    for (int i=0;i<line-1;i++) {
        int j = i+1;
        while (i < j && j < col) {
            if (mat[i][j] != 0)
                return false;
            j++;
        }
    }
    return true;
}

bool Matriz::simetrica()
{
    for (int i=0;i<line;i++)
        for (int j=0;j<col;j++)
            if (mat[i][j] != mat[j][i])
                return false;
    return true;
}

bool Matriz::identidade()
{
    if (line != col)
        return false;
    for (int i=0;i<line;i++)
        for (int j=0;j<col;j++)
            if ( (i!=j && mat[i][j] != 0) || (i == j && mat[i][j] != 1) )
                return false;
    return true;
}

Matriz* Matriz::transposta()
{
    Matriz* m = new Matriz(col,line);
    for (int i=0;i<m->line;i++)
        for (int j=0;j<m->col;j++)
           m->setElemento(i,j,mat[j][i]);
    return m;
}

void Matriz::potenciacao(int pot)
{
    if (pot < 0 || col != line)
        throw string("Impossivel calcular");
        Matriz* m = this;
        for (int i=1;i<pot;i++)
            m = *this * m;
        for (int i = 0; i < line; i++)
            for (int j = 0; j < col; j++)
                setElemento(i,j, m->mat[i][j]);
        cout << "Potencia:\n"<<m->getMatriz();
        m = nullptr;
}

Matriz* Matriz::multipicaEscalar(int k)
{
    Matriz* m = new Matriz(line,col);
    for (int i = 0; i < line; i++)
        for (int j = 0; j < col; j++)
            m->setElemento(i, j, k*mat[i][j]);
    return m;
}

bool Matriz::igual(Matriz *m)
{
    if (line != m->getLine() || col != m->getCol())
        return false;
    for (int i=0;i<line;i++)
        for (int j=0;j<col;j++)
            if (mat[i][j] != m->mat[i][j])
                return false;
    return true;
}

bool Matriz::ortogonal()
{
    Matriz* transposta = this->transposta();
    Matriz* produto  = *transposta * this;
    return produto->identidade();
}

bool Matriz::permutacao()
{
    cout << getMatriz() << endl;
    if (line < 1 || col < 1 )
        throw string("Nao permitido!");
    if (line != col)
        return false;

  for (int i = 0; i < getLine(); i++) // busca pelas linhas
  {
        int countZero = 0;
        int countOne = 0;
        for (int j = 0; j < getLine(); j++)
        {
            if (mat[i][j] == 0)
               countZero++;
            else
            {
                if (mat[i][j] == 1)
                    countOne++;
                else
                    return false;
            }
        }
        if (countZero != line-1 || countOne != 1)
            return false;
  }

  for (int j = 0; j < getCol(); j++) // busca pelas colunas
  {
       int  countZero = 0;
       int  countOne = 0;
       for (int i = 0; i < getLine(); i++)
       {
            if (mat[i][j] == 0)
                countZero++;
            else
            {
                if (mat[i][j] == 1)
                    countOne++;
                else
                    return false;
            }
      }
      if (countZero != col - 1 || countOne != 1)
          return false;
  }
  return true;
}

Matriz::~Matriz()
{
    if (mat)
        for (int i=0;i<line;i++) delete mat[i];
    delete [] mat;
}
