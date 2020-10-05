#include "mainwindow.h"
#include <QCoreApplication>
#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QHeaderView>
#include <QMessageBox>
#include <QFont>
#include <QTableWidget>
#include <QDesktopWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
     a(nullptr),
     b(nullptr),
     c(nullptr)
{
     /************************** TABELA A ***************************/
     setBackGround();
     // Instacia a tabela
     tabWidgetA = new QTableWidget(this);
     // Posiciona na tela
     tabWidgetA->setGeometry(10, 10, 250, 250);
     // Define o tamanho máximo da tabela
     tabWidgetA->setMaximumSize(250, 250);
     // Habilita a grade da tabela
     tabWidgetA->setShowGrid(true);
      // Inicia a contagem das linhas e colunas em 1
     tabWidgetA->setRowCount(1);
     tabWidgetA->setColumnCount(1);
     // Inicialia os valores de uma célula da matriz A
     tabWidgetA->setItem(0, 0, new QTableWidgetItem(" "));
     tabWidgetA->setColumnWidth(0, 50);
     tabWidgetA->setEditTriggers(QAbstractItemView::DoubleClicked);
     tabWidgetA->setSelectionBehavior(QAbstractItemView::SelectRows);
     tabWidgetA->setSelectionMode(QAbstractItemView::SingleSelection);

     /************************** TABELA B *******************************/

     // Instacia a tabela
     tabWidgetB = new QTableWidget(this);
     // Posiciona tabela na tela
     tabWidgetB->setGeometry(450, 10, 250, 250);
     // Define o tamanho máximo
     tabWidgetB->setMaximumSize(250, 250);
     // Habilita a grade da tabela
     tabWidgetB->setShowGrid(true);
     // Inicia a contagem das linhas e colunas em 1
     tabWidgetB->setRowCount(1);
     tabWidgetB->setColumnCount(1);
     // Inicialia os valores de uma célula da matriz B
     tabWidgetB->setItem(0, 0, new QTableWidgetItem(" "));
     tabWidgetB->setColumnWidth(0,50);

     tabWidgetB->setEditTriggers(QAbstractItemView::DoubleClicked);
     tabWidgetB->setSelectionBehavior(QAbstractItemView::SelectRows);
     tabWidgetB->setSelectionMode(QAbstractItemView::SingleSelection);

    /************************** TABELA C *******************************/

     // Instacia a tabela
     tabWidgetC = new QTableWidget(this);
     // Posiciona tabela na tela
     tabWidgetC->setGeometry(850, 10, 250, 250);
     // Define o tamanho máximo
     tabWidgetC->setMaximumSize(250, 250);
     // Habilita a grade da tabela
     tabWidgetC->setShowGrid(true);
     // Inicia a contagem das linhas e colunas em 1
     tabWidgetC->setRowCount(1);
     tabWidgetC->setColumnCount(1);

     // Inicialia os valores de uma célula da matriz A
     tabWidgetC->setItem(0, 0, new QTableWidgetItem(" "));
     tabWidgetC->item(0,0)->setTextAlignment(Qt::AlignCenter);
     tabWidgetC->setColumnWidth(0,50);


     /************************** LABELS ****************************/

     lbligual= new QLabel("=", this);
     QFont f("Hack Regular", 25, QFont::StyleNormal);
     lbligual->setFont(f);
     lbligual->setGeometry(QRect(QPoint(773,100), QSize(50, 50)));


     /************************** BOTÕES *******************************/
         /******************  OPERAÇÕES COM 2 MATRIZES ********************/

         btnAdd = new QPushButton("+", this);
         //  Posiciona botão na tela
         btnAdd->setGeometry(QRect(QPoint(320,80), QSize(75,25)));
         // Cria um evento referente a operação matematica
         connect(btnAdd, SIGNAL(released()), this, SLOT(add()));

         btnSub = new QPushButton("-", this);
         btnSub->setGeometry(QRect(QPoint(320,110), QSize(75,25)));
         connect(btnSub, SIGNAL(released()), this, SLOT(sub()));

         btnMult = new QPushButton("x", this);
         btnMult->setGeometry(QRect(QPoint(320,140), QSize(75,25)));
         connect(btnMult, SIGNAL(released()), this, SLOT(mult()));

         btnMultEsc = new QPushButton("xR", this);
         btnMultEsc->setGeometry(QRect(QPoint(320,170), QSize(75,25)));
         connect(btnMultEsc, SIGNAL(released()), this, SLOT(multEsc()));

         btnIgual = new QPushButton("=", this);
         btnIgual->setGeometry(QRect(QPoint(320,200), QSize(75,25)));
         connect(btnIgual, SIGNAL(released()), this, SLOT(equal()));

         /* ADICIONAR E REMOVER LINHAS E COLUNAS MATRIZ A */

         btnAddLineA = new QPushButton("+lin", this);
         btnAddLineA->setGeometry(QRect(QPoint(10, 270), QSize(122,25))); //
         connect(btnAddLineA, SIGNAL(released()), this, SLOT(addLineA()));

         btnAddColA = new QPushButton("+col", this);
         btnAddColA->setGeometry(QRect(QPoint(138, 270), QSize(122,25)));//
         connect(btnAddColA, SIGNAL(released()), this, SLOT(addColA()));

         btnDelLineA = new QPushButton("-lin", this);
         btnDelLineA->setGeometry(QRect(QPoint(10, 300), QSize(122,25)));//
         connect(btnDelLineA, SIGNAL(released()), this, SLOT(delLineA()));

         btnDelColA = new QPushButton("-col", this);
         btnDelColA->setGeometry(QRect(QPoint(138, 300), QSize(122,25)));//
         connect(btnDelColA, SIGNAL(released()), this, SLOT(delColA()));

         /************** BOTÕES PARA OPERAÇÕES COM 1 MATRIZ (A) ****************/

         btnTglSup = new QPushButton("T.Sup", this);
         btnTglSup->setGeometry(QRect(QPoint(10,330), QSize(122,25))); //
         connect(btnTglSup, SIGNAL(released()), this, SLOT(trianSup()));

         btnTglInf = new QPushButton("T.Inf", this);
         btnTglInf->setGeometry(QRect(QPoint(138,330), QSize(122,25)));//
         connect(btnTglInf, SIGNAL(released()), this, SLOT(trianInf()));

         btnStc = new QPushButton("Simet", this);
         btnStc->setGeometry(QRect(QPoint(10,360), QSize(122,25))); //
         connect(btnStc, SIGNAL(released()), this, SLOT(simetrica()));

         btnIdent = new QPushButton("Ident", this);
         btnIdent->setGeometry(QRect(QPoint(138,360), QSize(122,25))); //
         connect(btnIdent, SIGNAL(released()), this, SLOT(identidade()));

         btnTransp = new QPushButton("Transp", this);
         btnTransp->setGeometry(QRect(QPoint(10,390), QSize(122,25))); //
         connect(btnTransp, SIGNAL(released()), this, SLOT(transp()));

         btnPot = new QPushButton("^", this);
         btnPot->setGeometry(QRect(QPoint(138,390), QSize(122,25))); //
         connect(btnPot, SIGNAL(released()), this, SLOT(pot()));

         btnPerm = new QPushButton("Perm", this);
         btnPerm->setGeometry(QRect(QPoint(10,420), QSize(122,25))); //
         connect(btnPerm, SIGNAL(released()), this, SLOT(perm()));

         btnOrtog = new QPushButton("Ortog", this);
         btnOrtog->setGeometry(QRect(QPoint(138,420), QSize(122,25))); //
         connect(btnOrtog, SIGNAL(released()), this, SLOT(ortog()));

         /************** ADICIONA LINHAS E COLUNAS NA MATRIZ B *****************/

         btnAddLineB = new QPushButton("+lin", this);
         btnAddLineB->setGeometry(QRect(QPoint(450, 270), QSize(122,25))); //
         connect(btnAddLineB, SIGNAL(released()), this, SLOT(addLineB()));

         btnAddColB = new QPushButton("+col", this);
         btnAddColB->setGeometry(QRect(QPoint(578, 270), QSize(122,25))); //
         connect(btnAddColB, SIGNAL(released()), this, SLOT(addColB()));

         btnDelLineB = new QPushButton("-lin", this);
         btnDelLineB->setGeometry(QRect(QPoint(450, 300), QSize(122,25)));
         connect(btnDelLineB, SIGNAL(released()), this, SLOT(delLineB()));

         btnDelColB = new QPushButton("-col", this);
         btnDelColB->setGeometry(QRect(QPoint(578, 300), QSize(122,25)));
         connect(btnDelColB, SIGNAL(released()), this, SLOT(delColB()));
}
void MainWindow::add()
{
    // For the third table
    if((tabWidgetC->columnCount() != tabWidgetA->columnCount()) ||
            (tabWidgetC->rowCount() != tabWidgetA->rowCount()))
    {

        int lineC = tabWidgetA->rowCount();
        int colC = tabWidgetA->columnCount();
        setTable(tabWidgetC,lineC,colC);
    }
    // Set the second table
    if((tabWidgetB->columnCount() != tabWidgetA->columnCount()) ||
            (tabWidgetB->rowCount() != tabWidgetA->rowCount()))
    {
        int lineB = tabWidgetA->rowCount();
        int colB = tabWidgetA->columnCount();
        setTable(tabWidgetB,lineB,colB);
        Resultado r(this);
        QString msg = "As matrizes devem possuir as mesmas dimensões.";
        r.set_resultado(false,msg,false);
        r.exec();
    }
    else {
        try {
            if (b)
                delete b;
            int lineB = tabWidgetB->rowCount();
            int colB = tabWidgetB->columnCount();
            b = new Matriz(lineB,colB);
            setMatriz(b,tabWidgetB);
            if (a)
                delete a;

            int lineA = tabWidgetA->rowCount();
            int colA = tabWidgetA->columnCount();
            a = new Matriz(lineA,colA);
            setMatriz(a,tabWidgetA);

            if (c)
                delete c;

            c = *a+b;
            setTableValues(c,tabWidgetC);
        } catch (string e) {
            cout << e << endl;
        }
    }
}

void MainWindow::sub()
{
    if((tabWidgetC->columnCount() != tabWidgetA->columnCount()) ||
            (tabWidgetC->rowCount() != tabWidgetA->rowCount()))
    {

        int lineC = tabWidgetA->rowCount();
        int colC = tabWidgetA->columnCount();
        setTable(tabWidgetC,lineC,colC);
    }
    // Set the second table
    if((tabWidgetB->columnCount() != tabWidgetA->columnCount()) ||
            (tabWidgetB->rowCount() != tabWidgetA->rowCount()))
    {
        int lineB = tabWidgetA->rowCount();
        int colB = tabWidgetA->columnCount();
        setTable(tabWidgetB,lineB,colB);
        Resultado r(this);
        QString msg = "As matrizes devem possuir as mesmas dimensões.";
        r.set_resultado(false,msg,false);
        r.exec();
    }
    else {
        try {
            if (b)
                delete b;
            int lineB = tabWidgetB->rowCount();
            int colB = tabWidgetB->columnCount();
            b = new Matriz(lineB,colB);
            setMatriz(b,tabWidgetB);
            if (a)
                delete a;

            int lineA = tabWidgetA->rowCount();
            int colA = tabWidgetA->columnCount();
            a = new Matriz(lineA,colA);
            setMatriz(a,tabWidgetA);

            if (c)
                delete c;

            c = *a-b;
            setTableValues(c,tabWidgetC);
        } catch (string e) {
            cout << e << endl;
        }
    }
}

void MainWindow::mult()
{
    if((tabWidgetC->rowCount() != tabWidgetA->rowCount()) ||
      (tabWidgetC->columnCount() != tabWidgetB->columnCount()))
    {
        /*  For the third table  */
        int lineC = tabWidgetA->rowCount();
        int colC = tabWidgetB->columnCount();
        setTable(tabWidgetC,lineC,colC);
        tabWidgetC->setRowCount(tabWidgetA->rowCount());
        tabWidgetC->setColumnCount(tabWidgetB->columnCount());
        tabWidgetC->setColumnWidth(tabWidgetB->columnCount()-1, 50);
    }

    if(tabWidgetA->columnCount() != tabWidgetB->rowCount())
    {

        int lineB = tabWidgetA->columnCount();
        int colB = tabWidgetB->rowCount();
        setTable(tabWidgetB,lineB,colB);
        Resultado r(this);
        QString msg = "O número de colunas da matriz A "
                      "deve ser igual ao número linhas da matriz B.";
        r.set_resultado(false,msg,false);
        r.exec();
//        QMessageBox::information(this,"Info", "O número de colunas da matriz A "
//                                "deve ser igual ao número linhas da matriz B.");
    }
    else
    {
        try {

        /*************************** MATRIZ A *********************************/

                if (a)
                    delete a;

                int lineA = tabWidgetA->rowCount();
                int colA = tabWidgetA->columnCount();
                a = new Matriz(lineA,colA);
                setMatriz(a,tabWidgetA);
                cout << "MATRIZ a\n"  << a->getMatriz() << endl;

        /*************************** MATRIZ B *********************************/

                if (b)
                    delete b;

                int lineB = tabWidgetB->rowCount();
                int colB = tabWidgetB->columnCount();
                b = new Matriz(lineB,colB);
                setMatriz(b,tabWidgetB);
                cout << "MATRIZ B\n"  << b->getMatriz() << endl;

        /*************************** MATRIZ C *********************************/

                if (c)
                    delete c;

                c = *a*b;
                cout << "MATRIZ c\n"  << c->getMatriz() << endl;


        /*************************** TABELA C *********************************/
                int lineC = tabWidgetA->rowCount();
                int colC = tabWidgetB->columnCount();
                setTable(tabWidgetC,lineC,colC);
                setTableValues(c,tabWidgetC);

            } catch (QString e) {
                cout << e.toStdString() << endl;
                QMessageBox::warning(this,"Erro",e);
            }
    }
}

void MainWindow::equal()
{
    /*************************** VALIDAÇÃO *********************************/

    if (tabWidgetA->rowCount() != tabWidgetB->rowCount() ||
       tabWidgetA->columnCount() != tabWidgetB->columnCount())
    {
        int lineB = tabWidgetA->rowCount();
        int colB = tabWidgetA->columnCount();
        setTable(tabWidgetA,lineB,colB);
        Resultado r(this);
        QString msg = "As matrizes possuem dimensões diferentes.";
        r.set_resultado(true,msg,false);
        r.exec();
//        QMessageBox::information(this,"Resultado", "As matrizes possuem dimensões diferentes.");
    }
    else
    {
        try {

            /*************************** MATRIZ A *********************************/
            if (a)
                delete a;
            a = new Matriz(tabWidgetA->rowCount(),tabWidgetA->columnCount());
            setMatriz(a,tabWidgetA);
            cout << "MATRIZ A\n"  << a->getMatriz() << endl;

            /*************************** MATRIZ B *********************************/
            if (b)
                delete b;
            b = new Matriz(tabWidgetB->rowCount(),tabWidgetB->columnCount());
            setMatriz(b,tabWidgetB);
            cout << "MATRIZ B\n"  << b->getMatriz() << endl;

            Resultado r(this);
            bool isEqual = a->igual(b);
            QString msg = isEqual ? " As matrizes são iguais.": " As matrizes não são iguais.";
            r.set_resultado(true,msg,isEqual);
            r.exec();
        } catch (QString e) {
            cout << e.toStdString() << endl;
            QMessageBox::warning(this,"Erro",e);
        }
    }

}

void MainWindow::multEsc()
{
    try {
        /*************************** CONFIGURA TABELA C *********************************/
        if (tabWidgetC->rowCount() != tabWidgetA->rowCount() ||
           tabWidgetC->columnCount() != tabWidgetA->columnCount())
        {
            int lineC = tabWidgetA->rowCount();
            int colC = tabWidgetA->columnCount();
            setTable(tabWidgetA,lineC,colC);
        }

        /*************************** CONFIGURA TABELA B *********************************/

        int value = tabWidgetB->item(0,0)->text().toInt();
        if(tabWidgetB->columnCount() != 1 || tabWidgetB->rowCount() != 1)
        {
            int lineB = 1;
            int colB = 1;
            setTable(tabWidgetB,lineB,colB);
            tabWidgetB->item(0,0)->setText(QString::number(value));
        }
        /******************************* MATRIZ A **************************************/
        if (a)
            delete a;
        a = new Matriz(tabWidgetA->rowCount(),tabWidgetA->columnCount());
        setMatriz(a,tabWidgetA);
        cout << "MATRIZ A\n"  << a->getMatriz() << endl;

        /******************************* MATRIZ C **************************************/
        if (c)
            delete c;
        c = a->multipicaEscalar(value);
        setTableValues(c,tabWidgetC);
    } catch (string e) {
        cout << e << endl;
    }
}

void MainWindow::trianSup()
{
    if (tabWidgetA->rowCount() != tabWidgetA->columnCount())
    {
        int lineA = tabWidgetA->rowCount();
        int colA = lineA;
        setTable(tabWidgetA,lineA,colA);
        Resultado r(this);
        QString msg ="A matriz deve ser quadrada.";
        r.set_resultado(true,msg,false);
        r.exec();
    }
    if (triangComp())
    {
        QString msg = "A matriz  é triangular completa!";
         Resultado r(this);
         r.set_resultado(true,msg,true);
         r.exec();
    }
    else
    {
        if (a)
            delete a;
        a = new Matriz(tabWidgetA->rowCount(),tabWidgetA->columnCount());
        setMatriz(a,tabWidgetA);cout << "MATRIZ a\n"  << a->getMatriz() << endl;
        bool isEqual = a->triangularSuperior();

        QString msg = isEqual ? "A matriz A é triagular superior."
                              : "A matriz A não é triagular superior.";
         Resultado r(this);
         r.set_resultado(true,msg,isEqual);
         r.exec();
    }
}

void MainWindow::trianInf()
{
    if (tabWidgetA->rowCount() != tabWidgetA->columnCount())
    {
        int lineA = tabWidgetA->rowCount();
        int colA = lineA;
        setTable(tabWidgetA,lineA,colA);
        QString msg ="A matriz deve ser quadrada!\nTente novamente.";
        Resultado r(this);
        r.set_resultado(false,msg,false);
        r.exec();
    }
    if (triangComp())
    {
        QString msg = "A matriz  é triangular completa!";
         Resultado r(this);
         r.set_resultado(true,msg,true);
         r.exec();
    }
    else
    {
        if (a)
            delete a;

        a = new Matriz(tabWidgetA->rowCount(),tabWidgetA->columnCount());
        setMatriz(a,tabWidgetA);cout << "MATRIZ a\n"  << a->getMatriz() << endl;
        bool isEqual = a->triangularInferior();
        QString msg = isEqual ? "A matriz A é triagular inferior."
                              : "A matriz A não é triagular inferior.";
         Resultado r(this);
         r.set_resultado(true,msg,isEqual);
         r.exec();
    }

}

bool MainWindow::triangComp()
{
    bool valid = true;
    for (int i=0;i<tabWidgetA->rowCount()&&valid;i++)
        for (int j=0;j<tabWidgetA->columnCount();j++)
            if (tabWidgetA->item(i,j)->text() != "0")
                return false;
    return true;
}
void MainWindow::simetrica()
{
    if (tabWidgetA->rowCount() != tabWidgetA->columnCount())
    {
        int lineA = tabWidgetA->rowCount();
        int colA = lineA;
        setTable(tabWidgetA,lineA,colA);
        QString msg ="A matriz de ser quadrada!\nTente novamente.";
        Resultado r(this);
        r.set_resultado(false,msg,false);
        r.exec();
    }
    else
    {
        if (a)
            delete a;
        a = new Matriz(tabWidgetA->rowCount(),tabWidgetA->columnCount());
        setMatriz(a,tabWidgetA);cout << "MATRIZ a\n"  << a->getMatriz() << endl;

        QString msg = a->simetrica() ? "A matriz A é simetrica."
                                     : "A matriz A não é simetrica.";
        bool isEqual = a->simetrica();

        Resultado r(this);
        r.set_resultado(true,msg,isEqual);
        r.exec();
    }
}
void MainWindow::identidade()
{
    if (tabWidgetA->rowCount() != tabWidgetA->columnCount())
    {
        int lineA = tabWidgetA->rowCount();
        int colA = lineA;
        setTable(tabWidgetA,lineA,colA);
        QString msg ="A matriz de ser quadrada!\nTente novamente.";
        Resultado r(this);
        r.set_resultado(false,msg,false);
        r.exec();
    }

    else
    {
        if (a)
            delete a;
        a = new Matriz(tabWidgetA->rowCount(),tabWidgetA->columnCount());
        setMatriz(a,tabWidgetA);
        bool isEqual = a->identidade();
        QString msg = isEqual ? "A matriz é identidade."
                              : "A matriz não é identidade.";

        Resultado r(this);
        r.set_resultado(true,msg,isEqual);
        r.exec();
        cout << "MATRIZ a\n"  << a->getMatriz() << endl;
    }
}
void MainWindow::transp()
{
    if (a)
        delete a;
    a = new Matriz(tabWidgetA->rowCount(),tabWidgetA->columnCount());
    setMatriz(a,tabWidgetA);cout << "MATRIZ a\n"  << a->getMatriz() << endl;

    if (c)
        delete c;
    c = a->transposta();
      int lineC = tabWidgetA->rowCount();
      int colC = tabWidgetA->columnCount();
      setTable(tabWidgetC,lineC,colC);
      setTableValues(c,tabWidgetC);

}
void MainWindow::pot()
{

    int power  = tabWidgetB->item(0,0)->text().toInt();
    if (tabWidgetA->rowCount() != tabWidgetA->columnCount() || power < 1)
    {
        int lineA = tabWidgetA->rowCount();
        int colA = tabWidgetA->rowCount();
        setTable(tabWidgetA,lineA,colA);
        QString msg = "A matriz deve ser quadrada e a potencia maior que 0.";
        Resultado r(this);
        r.set_resultado(false,msg,false);
        r.exec();
    }
    else
    {
        /*************************** CONFIGURA TABELA C *********************************/
        if((tabWidgetC->columnCount() != tabWidgetA->columnCount()) ||
                (tabWidgetC->rowCount() != tabWidgetA->rowCount()))
        {

            int lineC = tabWidgetA->rowCount();
            int colC = tabWidgetA->columnCount();
            setTable(tabWidgetC,lineC,colC);
        }

        /*************************** CONFIGURA TABELA B *********************************/
        if(tabWidgetB->columnCount() != 1 || tabWidgetB->rowCount() != 1)
        {
            //  Salva o valor da célula(0,0)
            int lineB = 1;
            int colB = 1;
            setTable(tabWidgetB,lineB,colB);
            tabWidgetB->item(0,0)->setText(QString::number(power));
        }
        /******************************* MATRIZ A **************************************/
        if (a)
            delete a;
        // adicionar as variaveis linhas e colunas
        a = new Matriz(tabWidgetA->rowCount(),tabWidgetA->columnCount());
        setMatriz(a,tabWidgetA);cout << "MATRIZ a\n"  << a->getMatriz() << endl;
        a->potenciacao(power);
        cout << "Matriz A:\n" << a->getMatriz() << endl;
        setTableValues(a,tabWidgetC);
    }
}
void MainWindow::ortog()
{
    if (a)
        delete a;
    a = new Matriz(tabWidgetA->rowCount(),tabWidgetA->columnCount());
    setMatriz(a,tabWidgetA);cout << "MATRIZ a\n"  << a->getMatriz() << endl;
    bool isEqual = a->identidade();
    QString result = isEqual ? "A matriz A é ortogonal"
                             : "A matriz A não é ortogonal";
    Resultado r(this);
    r.set_resultado(true,result,isEqual);
    r.exec();
}

void MainWindow::perm()
{
    if (tabWidgetA->rowCount() != tabWidgetA->columnCount()) // não é matriz quadrada
    {
        int lineA = tabWidgetA->rowCount();
        int colA = tabWidgetA->rowCount();
        setTable(tabWidgetA,lineA,colA);
        QString msg = "A matriz deve ser quadrada!";
        Resultado r(this);
        r.set_resultado(false,msg,false);
        r.exec();
    }
    else
    {
        if (tabWidgetA->rowCount() == 1)
        {
            QString msg = "A matriz deve ter mais de 1 linha e coluna\n para ser é permutação!";
            Resultado r(this);
            r.set_resultado(true,msg,false);
            r.exec();
        }
        else
        {
            if (a)
                delete a;
            int lineA = tabWidgetA->rowCount();
            int colA = tabWidgetA->columnCount();
            a = new Matriz(lineA,colA);
            setMatriz(a,tabWidgetA);
            bool isEqual =  a->permutacao();
            QString msg = isEqual ? "A matriz é permutação."
                                  : "A matriz não é permutação.";
            Resultado r(this);
            r.set_resultado(true,msg,isEqual);
            r.exec();
        }

    }
}

/* Configura a Matriz A */

void MainWindow::addLineA()
{
    int line = tabWidgetA->rowCount() + 1;
    tabWidgetA->setRowCount(line);

    // Cria novas células
    for(int i = 0; i < tabWidgetA->columnCount(); i++)
        tabWidgetA->setItem((line-1), i, new QTableWidgetItem(" "));
}
void MainWindow::addColA()
{
    int col = tabWidgetA->columnCount() + 1;
    tabWidgetA->setColumnCount(col);
    // Cria novas célula
    for(int i = 0; i < tabWidgetA->rowCount(); i++)
        tabWidgetA->setItem(i, (col-1), new QTableWidgetItem(" "));
    tabWidgetA->setColumnWidth((col-1), 50);
}

void MainWindow::delLineA()
{
    int line = tabWidgetA->rowCount()-1;
    tabWidgetA->removeRow(line);
}

void MainWindow::delColA()
{
    tabWidgetA->removeColumn(tabWidgetA->columnCount()-1);
}

void MainWindow::addLineB()
{
    int line = tabWidgetB->rowCount() + 1;
    tabWidgetB->setRowCount(line);

    // Cria novas células
    for(int i = 0; i < tabWidgetB->columnCount(); i++)
        tabWidgetB->setItem((line-1), i, new QTableWidgetItem(" "));
}
void MainWindow::addColB()
{
    int col = tabWidgetB->columnCount() + 1;
    tabWidgetB->setColumnCount(col);
    // Cria novas célula
    for(int i = 0; i < tabWidgetB->rowCount(); i++)
        tabWidgetB->setItem(i, (col-1), new QTableWidgetItem(" "));
    tabWidgetB->setColumnWidth((col-1), 50);
}
void MainWindow::delLineB()
{
    int line = tabWidgetB->rowCount()-1;
    tabWidgetB->removeRow(line);
}
void MainWindow::delColB()
{
    tabWidgetB->removeColumn(tabWidgetB->columnCount()-1);
}

void MainWindow::setMatriz(Matriz *m, QTableWidget* tb)
{
        int line = tb->rowCount();
        int col = tb->columnCount();
        for (int i=0;i <line;i++)
        {
            for (int j=0;j<col;j++)
            {
                 int value = tb->item(i,j)->text().toInt();
                 m->setElemento(i,j,value);
            }
        }
        cout << "Matriz setOperator\n" << m->getMatriz() << endl;
}
void MainWindow::setTableValues(Matriz *m, QTableWidget *tb)
{
    if (m->getLine() == tb->rowCount() && m->getCol() == tb->columnCount())
    {
        for(int rows = 0; rows < tb->rowCount(); rows++)
        {
            for(int cols = 0; cols < tb->columnCount(); cols++)
            {
                QString value = QString::number(m->getElemento(rows,cols));
                tb->item(rows, cols)->setText(value);
            }
        }
    }
}

void MainWindow::setTable(QTableWidget *tb, int line, int col)
{
    tb->setRowCount(line);
    tb->setColumnCount(col);
    tb->setColumnWidth(tb->columnCount()-1, 50);
    for(int i = 0; i < tb->rowCount(); i++)
    {
        for(int j = 0; j < tb->columnCount(); j++)
        {
            tb->setItem(i, j, new QTableWidgetItem(" "));
            tb->setColumnWidth(j, 50);
        }
    }
}
void MainWindow::setBackGround()
{
    QString img = "/home/vinicius/Documents/Vinicius/PUC/TECNICAS_DE_PROGRAMACAO_II/matrizInterfaceFinal/images/bcgnd5.jpg";
    QPixmap bkgnd(img);
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}
