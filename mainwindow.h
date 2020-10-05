#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QTextTable>
#include <QTableView>
#include <QTableWidget>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QMovie>
#include "matriz.h"
#include <resultado.h>
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
private:

    /********* LABEL *************/

    QLabel* lbligual;

    /*********** BOTÕES **********/

    /* Operações com 2 matrizes */

    QPushButton* btnAdd;
    QPushButton* btnSub;
    QPushButton* btnMult;
    QPushButton* btnMultEsc;    // multiplicar por escalar
    QPushButton* btnIgual;      // verifica se as matrizes são iguais


    /* Operações com 1 matriz */

    QPushButton* btnTglSup;     // verifica se é triângular superior
    QPushButton* btnTglInf;     // verifica se é triângular inferior
    QPushButton* btnStc;        // verifica se é simetrica
    QPushButton* btnIdent;      // identidade
    QPushButton* btnTransp;     // transposta
    QPushButton* btnPot;        // potenciação
    QPushButton* btnOrtog;      // ortogonal
    QPushButton* btnPerm;       // permutação

    /* Botões para setar a Matriz A */

    QPushButton *btnAddLineA;   // inserir linhas
    QPushButton *btnAddColA;    // inserir colunas
    QPushButton *btnDelLineA;   // deletar linhas
    QPushButton *btnDelColA;    // deletar coluna

    /* Botões para setar a Matriz B */

    QPushButton *btnAddLineB;   // inserir linhas
    QPushButton *btnAddColB;    // inserir colunas
    QPushButton *btnDelLineB;   // deletar linhas
    QPushButton *btnDelColB;    // deletar coluna

    /* Tabelas representam as Matrizes na tela */

    QTableWidget *tabWidgetA;    // matriz A
    QTableWidget *tabWidgetB;    // matriz B
    QTableWidget *tabWidgetC;    // matriz C

    /* Matrizes */

    Matriz *a;                   // primeiro campo
    Matriz *b;                   // segundo campo
    Matriz *c;                   // matriz resultado

private slots:

    // Operações com 2 matrizes

    void add();
    void sub();
    void mult();
    void equal();                // igualdade entre 2 matrizes

    /* Operações com 1 matrizes */

    void multEsc();              // multiplica uma matriz por um n° real
    void trianSup();             // verifica se é uma matriz triangular superior
    void trianInf();             // verifica se é uma matriz triangular inferior
    bool triangComp();// verifica se é uma matriz triangular completa
    void simetrica();            // verifica se é uma matriz é simetrica
    void identidade();           // verifica se é uma matriz identidade
    void transp();               // calcula a matriz transposta
    void pot();                  // calcula a potenciação de uma matriz
    void ortog();                // verifica se é uma matriz ortogonal
    void perm();

    /* Configura a Matriz A */

    void addLineA();             // aciona linhas
    void addColA();              // aciona colunas
    void delLineA();             // deleta linhas
    void delColA();              // deleta colunas

    /* Configura a Matriz B */

    void addLineB();             // aciona linhas
    void addColB();              // aciona colunas
    void delLineB();             // deleta linhas
    void delColB();              // deleta colunas


    void setMatriz(Matriz* m, QTableWidget *tb);
    void setTableValues(Matriz* m, QTableWidget *tb);
    void setTable(QTableWidget *tb, int line, int col);
    void setBackGround();

};

#endif // MAINWINDOW_H
