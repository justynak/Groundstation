#ifndef SCIAGA_H
#define SCIAGA_H

#include <QWidget>

namespace Ui {
class Sciaga;
}

class Sciaga : public QWidget
{
    Q_OBJECT
    
public:
    explicit Sciaga(QWidget *parent = 0);
    ~Sciaga();
    
private:
    Ui::Sciaga *ui;
};

#endif // SCIAGA_H
