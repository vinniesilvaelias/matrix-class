#ifndef RESULTADO_H
#define RESULTADO_H
#include <QMovie>
#include <QDialog>

namespace Ui {
class Resultado;
}

class Resultado : public QDialog
{
    Q_OBJECT

public:
    explicit Resultado(QWidget *parent = nullptr);
    ~Resultado();
    void set_resultado(bool op, QString msg, bool r);
private:
    Ui::Resultado *ui;
};

#endif // RESULTADO_H
