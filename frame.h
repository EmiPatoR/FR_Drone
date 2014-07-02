#ifndef FRAME_H
#define FRAME_H

#include <QFrame>
#include "mainwindow.h"

// remplacer par des enums à terme
#define CSVC 0
#define NUSVC 1
#define ONECLASSSVM 2
#define EPSSVR 3
#define NUSVR 4

#define LIN 0
#define POLYNOMIAL 1
#define RADIALBASIS 2
#define SIG 3

namespace Ui {
class Frame;
}

class Frame : public QFrame
{
    Q_OBJECT

public:
    Frame(QWidget *parent = 0);
    Frame(MainWindow* pere,QString test);
    ~Frame();

public slots:
  void on_btn_use_algo_clicked();

private:
    Ui::Frame *ui;
    MainWindow* pere;
};

#endif // FRAME_H
