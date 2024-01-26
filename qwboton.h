#ifndef QWBOTON_H
#define QWBOTON_H

#include <QWidget>

namespace Ui {
class QWBoton;
}

class QWBoton : public QWidget
{
    Q_OBJECT

public:
    explicit QWBoton(QWidget *parent = nullptr);
    ~QWBoton();

private:
    Ui::QWBoton *ui;
};

#endif // QWBOTON_H
