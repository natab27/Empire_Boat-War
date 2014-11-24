#ifndef BARCO_H
#define BARCO_H

#include <QWidget>

namespace Ui {
class Barco;
}

class Barco : public QWidget
{
    Q_OBJECT

public:
    explicit Barco(QWidget *parent = 0);
    ~Barco();

private:
    int tamBarco;
    int vidasBarco;
    enum orientacionBarco {BarcoH = 1, BarcoV = 2};
    enum tipoBarco {AircraftCarrier = 1, BattlesShip = 2, Fragate = 3, Submarine = 4, MinesWeeper = 5};
    QList < QPair<int, int> > coordenadasBarco;
    void crearBarco(int tamanioBarco);

    Ui::Barco *ui;
};

#endif // BARCO_H
