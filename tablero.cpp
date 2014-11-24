#include <QtGui>
#include <QPainter>
#include "tablero.h"
#include "ui_tablero.h"

Tablero::Tablero(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tablero)
{
    ui->setupUi(this);
}

void Tablero::iniciarTablero()
{
    for (int fila = 0; fila < 10; ++fila) {
        for (int columna = 0; columna < 10; ++columna) {
            tablero[fila][columna] = Vacio;
        }
    }
    turno = 1;
}

QRect Tablero::rectCelda(int fila, int columna) const
{
    const int margenH = width() / 25;
    const int margenV = height() / 25;
    return QRect(columna * anchoCelda() + margenH,
                 fila * altoCelda() + margenV,
                 anchoCelda() - 2 * margenH,
                 altoCelda() - 2 * margenV);
}

void Tablero::mousePressEvent(QMouseEvent *event)
{
    if (turno == 3) {
        iniciarTablero();
        update();
    } else {
        for (int fila = 0; fila < 10; ++fila) {
            for (int columna = 0; columna < 10; ++columna) {
                QRect r = rectCelda(fila, columna);
                if (r.contains(event->pos())) {
                    if (tablero[fila][columna] == Vacio) {
                        if (turno == 1) {
                            tablero[fila][columna] = Barco;
                            turno = 2;
                        }
                        else {
                            tablero[fila][columna] = Bomba;
                            turno = 1;
                        }
                        update();
                    }
                    break;
                }
            }
        }
    }
}

void Tablero::paintEvent(QPaintEvent */*event*/)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QPen(Qt::black, 1.0));
    /* Lineas Verticales */
    painter.drawLine(0, 0, 0, 250);
    painter.drawLine(25, 0,25, 250);
    painter.drawLine(25*2, 0,25*2, 250);
    painter.drawLine(25*3, 0,25*3, 250);
    painter.drawLine(25*4, 0,25*4, 250);
    painter.drawLine(25*5, 0,25*5, 250);
    painter.drawLine(25*6, 0,25*6, 250);
    painter.drawLine(25*7, 0,25*7, 250);
    painter.drawLine(25*8, 0,25*8, 250);
    painter.drawLine(25*9, 0,25*9, 250);
    painter.drawLine(25*10, 0, 25*10, 250);
    /* Lineas Horizontales */
    painter.drawLine(0, 0, 250, 0);
    painter.drawLine(0, 25, 250, 25);
    painter.drawLine(0, 25*2, 250, 25*2);
    painter.drawLine(0, 25*3, 250, 25*3);
    painter.drawLine(0, 25*4, 250, 25*4);
    painter.drawLine(0, 25*5, 250, 25*5);
    painter.drawLine(0, 25*6, 250, 25*6);
    painter.drawLine(0, 25*7, 250, 25*7);
    painter.drawLine(0, 25*8, 250, 25*8);
    painter.drawLine(0, 25*9, 250, 25*9);
    painter.drawLine(0, 25*10, 250, 25*10);

    /* Eventos del mouse */
    painter.setPen(QPen(Qt::blue, 4.0));
    for (int fila = 0; fila < 10; ++fila) {
        for (int columna = 0; columna < 10; ++columna) {
            QRect r = rectCelda(fila, columna);
            if (tablero[fila][columna] == Barco) {
                painter.drawRect(r);
            } else if (tablero[fila][columna] == Bomba) {
                painter.drawEllipse(r);
            }
        }
    }
    /*
    painter.setPen(QPen(Qt::darkGreen, 3.0));
    for (int fila = 0; fila < 3; ++fila) {
        if (threeInARow(fila, 0, fila, 2)) {
            int y = rectCelda(fila, 0).center().y();
            painter.drawLine(0, y, width(), y);
            turnNumber = 9;
        }
    }
    for (int columna = 0; columna < 3; ++columna) {
        if (threeInARow(0, columna, 2, columna)) {
            int x = rectCelda(0, columna).center().x();
            painter.drawLine(x, 0, x, height());
            turnNumber = 9;
        }
    }
    if (threeInARow(0, 0, 2, 2)) {
        painter.drawLine(0, 0, width(), height());
        turnNumber = 9;
    }
    if (threeInARow(0, 2, 2, 0)) {
        painter.drawLine(0, height(), width(), 0);
        turnNumber = 9;
    }
    */
}

Tablero::~Tablero()
{
    delete ui;
}
