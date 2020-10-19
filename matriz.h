#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
using namespace std;
using std::string;

template<class T>
class Matrix
{
    template<T>
    friend ostream &operator<<( ostream &, const Matrix<T> & );
    template<T>
    friend istream &operator>>( istream &, Matrix<T> & );
private:
    T** values;
    int rows;
    int columns;
public:
    Matrix();
    Matrix( const Matrix & );
    Matrix( int, int );
    std::string getMatrix() const;
    void setElement( int, int, T );
    T getElement( int, int ) const;
    int getSize()const { return rows * columns; };
    Matrix operator+( const Matrix& )const;
    Matrix operator-( Matrix& )const;
    Matrix operator*( Matrix& )const;
    const Matrix &operator=( const Matrix& );
    bool operator==(const Matrix &)const;
    bool operator!=(const Matrix &matrix)const { return !(*(this)==matrix); };
    bool upperTriangular();
    bool lowerTriangular();
    bool symmetric();
    bool identity();
    Matrix transposed();
    Matrix potentiation(int );
    Matrix scalarMult(int );
    bool equal(Matrix m);
    bool orthogonal();
    bool permutation();
    ~Matrix();
    int getrows() const;
    void setrows(int );
    int getcolumns() const;
    void setcolumns(int);
};

template<class T>
ostream &operator<<(ostream & output, const Matrix<T> &matrix)
{
    for (int i=0;i<matrix.getrows();i++) {
        for (int j=0;j<matrix.getcolumns();j++) {
            output  << matrix.getElement(i,j) << " ";
        }
        output << endl;
    }
    return output;
}

template<class T>
istream &operator>>(istream &input, Matrix<T> &matrix)
{
    for (int i=0;i<matrix.getrows();i++) {
        for (int j=0;j<matrix.getcolumns();j++) {
            T aux;
            input >> aux;
            matrix.setElement(i,j,aux);
        }
    }
    return input;
}
template<class T>
Matrix<T>::Matrix(): values(nullptr), rows(0), columns(0) { }

template<class T>
Matrix<T>::Matrix(const Matrix &copy):
    rows(copy.rows),
    columns(copy.columns)
{
    try {
        this->values = new T*[copy.rows];
        for (int i=0;i<copy.columns;i++) {
            this->values[i] = new T[copy.columns];
        }
        this->rows = copy.rows;
        this->columns = copy.columns;
    } catch (std::bad_alloc&) {
        throw string("Insufficient Memory");
    }
    for (int i=0;i<this->rows;i++) {
        for (int j=0;j<this->columns;j++) {
            this->values[i][j] = copy.values[i][j];
        }
    }
}
template<class T>
Matrix<T>::Matrix(int rows, int columns):
    values(nullptr),
    rows(0),
    columns(0)
{
    if (rows < 1 || columns < 1) {
        throw string("Rows and columns cannot be null!");
    }
    try {
        this->values = new T*[rows];
        for (int i=0;i<rows;i++) {
            this->values[i] = new T[columns];
        }
    } catch (std::bad_alloc&) {
        throw string("Insufficient Memory!");
    }
    this->rows = rows;
    this->columns = columns;
}

template<class T>
void Matrix<T>::setElement(int rows, int columns, T element) {
    if (rows < 0 || rows > this->rows || columns < 0 || columns > this->columns) {
        throw string("Rows and columns cannot be null and arrays must have the same dimesions!");
    }
    this->values[rows][columns] = element;
}

template<class T>
T Matrix<T>::getElement(int rows, int columns) const {
    if (rows < 0 || rows > this->rows || columns < 0 || columns > this->columns) {
        throw string("Rows and columns cannot be null and arrays must have the same dimesions!");
    }
    return this->values[rows][columns];
}

template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix &matrix) const {
    if (this->rows != matrix.rows || this->columns != matrix.columns) {
        throw string("The arrays must have the same dimensions!");
    }
    Matrix<T> tmp = *(this);
    for (int i=0;i<this->rows;i++) {
        for (int j=0;j<this->columns;j++) {
            tmp.values[i][j] = this->values[i][j] + matrix.values[i][j];
        }
    }
    return tmp;
}

template<class T>
Matrix<T> Matrix<T>::operator-(Matrix &matrix) const {
    if (this->rows != matrix.rows || this->columns != matrix.columns) {
        throw string("The arrays must have the same dimensions!");
    }
    Matrix<T> tmp = Matrix(*(this));
    for (int i=0;i<this->rows;i++) {
        for (int j=0;j<this->columns;j++) {
            tmp.values[i][j] = this->values[i][j] - matrix.values[i][j];
        }
    }
    return tmp;
}

template<class T>
Matrix<T> Matrix<T>::operator*(Matrix &matrix) const {
    if (this->columns != matrix.rows) {
        throw string("The number of columns in the first matrix must equal the number of rows in the second!");
    }
    Matrix<T>tmp(this->rows,matrix.columns);
    for (int i=0;i<this->rows;i++) {
        for (int j=0;j<matrix.columns;j++) {
            tmp.values[i][j] = 0;
            for (int k=0;k<this->columns;k++) {
                tmp.values[i][j] += this->values[i][k] * matrix.values[k][j];
            }
        }
    }
    return tmp;
}

template<class T>
const Matrix<T> &Matrix<T>::operator=(const Matrix &matrix) {
    if (this->rows != matrix.rows || this->columns != matrix.columns) {
        delete [] this->values;
        try {
            this->values = new T*[matrix.rows];
            for (int i=0;i<matrix.columns;i++) {
                this->values[i] = new T[matrix.columns];
            }
            this->rows = matrix.rows;
            this->columns = matrix.columns;
        } catch (std::bad_alloc&) {
            throw string("Insufficient Memory");
        }
    }
    for (int i=0;i<this->rows;i++) {
        for (int j=0;j<this->columns;j++) {
            this->values[i][j] = matrix.values[i][j];
        }
    }
    return *(this);
}

template<class T>
bool Matrix<T>::operator==(const Matrix &matrix) const
{
    if (this->rows!= matrix.rows || this->columns!= matrix.columns) {
        return false;
    }
    for (int i=0;i<this->rows;i++) {
        for (int j=0;j<this->columns;j++) {
            if (this->values[i][j] != matrix.values[i][j]) {
                return false;
            }
        }
    }
    return true;
}

template<class T>
bool Matrix<T>::upperTriangular() {
    if (this->rows != this->columns) {
        return false;
    }
    for (int i=0;i<this->rows;i++) {
        int j = 0;
        while (i > j && j < this->columns) {
            if (this->values[i][j] != 0) {
                return false;
            }
            j++;
        }
    }
    return true;
}

template<class T>
bool Matrix<T>::lowerTriangular() {
    if (this->rows != this->columns) {
        return false;
    }
    for (int i=0;i<this->rows-1;i++)
    {
        int j = i+1;
        while (i < j && j < this->columns)
        {
            if (this->values[i][j] != 0)
                return false;
            j++;
        }
    }
    return true;
}

template<class T>
bool Matrix<T>::symmetric() {
    if (this->rows != this->columns) {
        return false;
    }
    for (int i=0;i<this->rows;i++) {
        for (int j=0;j<this->columns;j++) {
            if (this->values[i][j] != this->values[j][i]) {
                return false;
            }
        }
    }
    return true;
}

template<class T>
bool Matrix<T>::identity() {
    if (this->rows != this->columns) {
        return false;
    }
    for (int i=0;i<this->rows;i++) {
        for (int j=0;j<this->columns;j++) {
            if ((i !=j && this->values[i][j] != 0) || (i==j && this->values[i][j] != 1)) {
                return false;
            }
        }
    }
    return true;
}

template<class T>
Matrix<T> Matrix<T>::transposed() {
    Matrix<T>tmp(this->columns,this->rows);
    for (int i=0;i<tmp.rows;i++) {
        for (int j=0;j<tmp.columns;j++) {
            tmp.values[i][j] =this->values[j][i];
        }
    }
    return tmp;
}

template<class T>
Matrix<T> Matrix<T>::potentiation(int power) {
    if (power < 0 || this->rows != this->columns) {
        throw string("The power must have greater than 0 and number of rows and columns must have the same!");
    }

    if (power > 1) {
        Matrix<T>tmp = *(this);
        for (int i=0;i<this->rows;i++) {
            for (int j=0;j<this->columns;j++) {

            }
        }
    }
}

template<class T>
Matrix<T> Matrix<T>::scalarMult(int scalar) {
    Matrix<T> matrix(this->rows,this->columns);
    for (int i=0;i<matrix.rows;i++) {
        for (int j=0;j<matrix.columns;j++) {
            matrix.values[i][j] = scalar * this->values[i][j];
        }
    }
    return matrix;
}
template<class T>
bool Matrix<T>::orthogonal() {
    Matrix<T> transposed = this->transposed();
    Matrix<T> product = *(this) * transposed;
    return product.identity();
}

template<class T>
bool Matrix<T>::permutation() {
    if (this->rows < 1 || this->columns < 1 ) {
        throw string("The rows and columns cannot be null!");
    }
   if (this->rows != this->columns) {
        return false;
   }
   for (int i = 0; i < this->rows; i++)
   {
       int countZero = 0;
       int countOne = 0;
       for (int j = 0; j < columns; j++)
       {
           if (values[i][j] == 0)
              countZero++;
           else
           {
               if (values[i][j] == 1) {
                   countOne++;
               }
               else {
                   return false;
               }
           }
       }
       if (countZero != rows-1 || countOne != 1) {
           return false;
       }
   }
   for (int j = 0; j < this->rows; j++) // busca pelas colunas
   {
      int  countZero = 0;
      int  countOne = 0;
      for (int i = 0; i < this->columns; i++)
      {
           if (values[i][j] == 0) {
               countZero++;
           }
           else
           {
               if (values[i][j] == 1) {
                   countOne++;
               }
               else {
                   return false;
               }
           }
     }
     if (countZero != this->columns - 1 || countOne != 1) {
         return false;
     }
   }
   return true;
}


template<class T>
Matrix<T>::~Matrix() {
    if (this->values) {
        for (int i=0;i<this->rows;i++) {
            delete this->values[i];
        }
    }
    delete [] this->values;
}

template<class T>
int Matrix<T>::getrows() const {
    return this->rows;
}

template<class T>
void Matrix<T>::setrows(int rows) {
    if (!rows) {
        throw string("Rows cannot be null!");
    }
    this->rows = rows;
}

template<class T>
int Matrix<T>::getcolumns() const {
    return this->columns;
}

template<class T>
void Matrix<T>::setcolumns(int columns) {
    if (!columns) {
        throw string("Columns cannot be null!");
    }
    this->columns = columns;
}

#endif // Matrix_H
