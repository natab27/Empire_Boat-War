#ifndef TABLERO_H
#define TABLERO_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>

namespace Ui {
class Tablero;
}

class Tablero : public QWidget
{
    Q_OBJECT

public:
    explicit Tablero(QWidget *parent = 0);
    ~Tablero();

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
    int turno;
    int tablero[10][10];
    enum estadoCelda { Vacio = 0, Barco = 1, Bomba = 2, Averiado = 3};
    QRect rectCelda(int fila, int columna) const;
    int anchoCelda() const { return width() / 10; }
    int altoCelda() const { return height() / 10; }
    void iniciarTablero();
    void colocarBarco();
    bool validarBomba(int x, int y);
    bool validarBarco();
    void dipararEnemigo();

    Ui::Tablero *ui;    
};

#endif // TABLERO_H
