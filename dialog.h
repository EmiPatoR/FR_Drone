#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTimer>
#include "ardrone/ardrone.h"

#define COMMAND_NOTHING -1
#define COMMAND_NOTHING_V1 0
#define COMMAND_TAKE_OFF 1
#define COMMAND_LAND 2
#define COMMAND_LIFT 3
#define COMMAND_GO_DOWN 4
#define COMMAND_FORWARD 5
#define COMMAND_BACKWARD 6
#define COMMAND_STRAFE_LEFT 7
#define COMMAND_STRAFE_RIGHT 8
#define COMMAND_ROTATE_LEFT 9
#define COMMAND_ROTATE_RIGHT 10
#define COMMAND_CONFIG_TRIMM 11
#define COMMAND_CONFIG_MAGNETO 12
#define COMMAND_NOTHING_V2 13
#define COMMAND_NOTHING_V3 14
#define COMMAND_NOTHING_V4 15
#define COMMAND_ANIMATION 16

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(ARDrone *ardrone, QWidget *parent = 0);
    ~Dialog();

public slots:
    void send_commands();

private:
    Ui::Dialog *ui;
    ARDrone *drone;
    QTimer *commands;
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    int command;
    int anim;
};

#endif // DIALOG_H
