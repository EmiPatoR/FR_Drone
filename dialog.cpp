#include "dialog.h"
#include "ui_dialog.h"
#include "ardrone/ardrone.h"
#include <QKeyEvent>

static double v1 = 0;
static double v2 = 0;
static double v3 = 0;
static double v4 = 0;
static bool v1_active = false;
static bool v2_active = false;
static bool v3_active = false;
static bool v4_active = false;
static int deplacement = 0;

Dialog::Dialog(ARDrone* ardrone, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    this->drone = ardrone;
    ui->setupUi(this);
    this->setModal(true);
    this->show();

    anim = 0;

    ui->btn_d->setEnabled(false);
    ui->btn_q->setEnabled(false);
    ui->btn_s->setEnabled(false);
    ui->btn_z->setEnabled(false);
    ui->btn_alt->setEnabled(false);
    ui->btn_ctrl->setEnabled(false);
    ui->btn_left->setEnabled(false);
    ui->btn_up->setEnabled(false);
    ui->btn_right->setEnabled(false);
    ui->btn_down->setEnabled(false);
    ui->btn_tkoff->setEnabled(false);
    ui->btn_quit->setEnabled(false);

    this->setStyleSheet("QPushButton{color:rgb(0,0,0)}");

    command = COMMAND_NOTHING_V1;

    commands = new QTimer();
    connect(commands,SIGNAL(timeout()),this,SLOT(send_commands()));
    commands->start(30);
}


void Dialog::keyPressEvent(QKeyEvent *event){

    switch(event->key()){
    case Qt::Key_Q:
        command = COMMAND_STRAFE_LEFT;
        deplacement = 1;
        v2_active = true;
        v2 = 1.0;
        ui->btn_q->setStyleSheet("color: rgb(255,0,0)");
        break;

    case Qt::Key_Z:
        command = COMMAND_FORWARD;
        deplacement = 1;
        v1_active = true;
        v1 = 1.0;
        ui->btn_z->setStyleSheet("color: rgb(255,0,0)");
        break;

    case Qt::Key_S:
        command = COMMAND_BACKWARD;
        deplacement = 1;
        v1_active = true;
        v1 = -1.0;
        ui->btn_s->setStyleSheet("color: rgb(255,0,0)");
        break;

    case Qt::Key_D:
        command = COMMAND_STRAFE_RIGHT;
        deplacement = 1;
        v2_active = true;
        v2 = -1.0;
        ui->btn_d->setStyleSheet("color: rgb(255,0,0)");
        break;

    case Qt::Key_Up:
        command = COMMAND_LIFT;
        deplacement = 1;
        v3_active = true;
        v3 = 1.0;
        ui->btn_up->setStyleSheet("color: rgb(255,0,0)");
        break;

    case Qt::Key_Down:
        command = COMMAND_GO_DOWN;
        deplacement = 1;
        v3_active = true;
        v3 = -1.0;
        ui->btn_down->setStyleSheet("color: rgb(255,0,0)");
        break;

    case Qt::Key_Left:
        command = COMMAND_ROTATE_LEFT;
        deplacement = 1;
        v4_active = true;
        v4 = 1.0;
        ui->btn_left->setStyleSheet("color: rgb(255,0,0)");
        break;

    case Qt::Key_Right:
        command = COMMAND_ROTATE_RIGHT;
        v4_active = true;
        deplacement = 1;
        v4 = -1.0;
        ui->btn_right->setStyleSheet("color: rgb(255,0,0)");
        break;

    case Qt::Key_Space:
        if(drone->onGround())
            command = COMMAND_TAKE_OFF;
        else
            command = COMMAND_LAND;
        ui->btn_tkoff->setStyleSheet("color: rgb(255,0,0)");
        break;

    case Qt::Key_Shift:
        if(drone->onGround())
            command = COMMAND_CONFIG_TRIMM;
        ui->btn_ctrl->setStyleSheet("color: rgb(255,0,0)");
        break;

    case Qt::Key_Alt:
        if(!drone->onGround())
            command = COMMAND_CONFIG_MAGNETO;
        ui->btn_alt->setStyleSheet("color: rgb(255,0,0)");
        break;

    case Qt::Key_Escape:
        ui->btn_quit->setStyleSheet("color: rgb(255,0,0)");
        commands->stop();
        this->close();
        break;

    case Qt::Key_Plus:
        if(anim < 19)
            anim++;
        ui->lbl_animation->setText("<font color='red'>" + QString::number(anim) + "</font>");
        ui->btn_plus->setStyleSheet("color: rgb(255,0,0)");
        break;
    case Qt::Key_Minus:
        if(anim > 0)
            anim--;
        ui->lbl_animation->setText("<font color='red'>" + QString::number(anim) + "</font>");
        ui->btn_minus->setStyleSheet("color: rgb(255,0,0)");
        break;

     case Qt::Key_Tab:
        if(!drone->onGround())
            command = COMMAND_ANIMATION;
        ui->btn_tab->setStyleSheet("color: rgb(255,0,0)");
        break;

    }
}

void Dialog::send_commands(){
    switch(command){
    /*
    case COMMAND_STRAFE_LEFT:
        v2 = 1.0;
        // drone->move3D(0.0,1.0,0.0,0.0);
        break;

    case COMMAND_FORWARD:
        v1 = 1.0;
        // drone->move3D(1.0,0.0,0.0,0.0);
        break;

    case COMMAND_BACKWARD:
        v1 = -1.0;
        // drone->move3D(-1.0,0.0,0.0,0.0);
        break;

    case COMMAND_STRAFE_RIGHT:
        v2 = -1.0;
        // drone->move3D(0.0,-1.0,0.0,0.0);
        break;

    case COMMAND_LIFT:
        v3 = 1.0;
        //drone->move3D(0.0,0.0,1.0,0.0);
        break;

    case COMMAND_GO_DOWN:
        v3 = -1.0;
        // drone->move3D(0.0,0.0,-1.0,0.0);
        break;

    case COMMAND_ROTATE_LEFT:
        v4 = 1.0;
        // drone->move3D(0.0,0.0,0.0,1.0);
        break;

    case COMMAND_ROTATE_RIGHT:
        v4 = -1.0;
        // drone->move3D(0.0,0.0,0.0,-1.0);
        break;
    */

    case COMMAND_ANIMATION:
        if(!drone->onGround())
            drone->setAnimation(anim);
        break;

    case COMMAND_TAKE_OFF:
        if(drone->onGround())
            drone->takeoff();
        break;

    case COMMAND_LAND:
        if(!drone->onGround())
            drone->landing();
        break;

    case COMMAND_CONFIG_TRIMM:
        if(drone->onGround())
            drone->setFlatTrim();
        break;

    case COMMAND_CONFIG_MAGNETO:
        if(!drone->onGround())
            drone->setCalibration();
        break;
        /*
    case COMMAND_NOTHING:
        if(!drone->onGround()){
            v1 = 0.0;
            v2 = 0.0;
            v3 = 0.0;
            v4 = 0.0;
        }
        break;

    case COMMAND_NOTHING_V1:
        if(!drone->onGround())
            v1 = 0.0;
        break;

    case COMMAND_NOTHING_V2:
        if(!drone->onGround())
            v2 = 0.0;
        break;

    case COMMAND_NOTHING_V3:
        if(!drone->onGround())
            v3 = 0.0;
        break;

    case COMMAND_NOTHING_V4:
        if(!drone->onGround())
            v4 = 0.0;
        break;

    }
*/
    default:
        drone->move3D(v1,v2,v3,v4);
        break;

    }



}

void Dialog::keyReleaseEvent(QKeyEvent *event){
    switch(event->key()){

    case Qt::Key_Z:
        command = COMMAND_NOTHING_V1;
        v1_active = false;
        v1 = 0.0;
        ui->btn_z->setStyleSheet("color: rgb(0,0,0)");
        break;

    case Qt::Key_S:
        command = COMMAND_NOTHING_V1;
        v1_active = false;
        v1 = 0.0;
        ui->btn_s->setStyleSheet("color: rgb(0,0,0)");
        break;

    case Qt::Key_Q:
        command = COMMAND_NOTHING_V2;
        v2_active = false;
        v2 = 0.0;
        ui->btn_q->setStyleSheet("color: rgb(0,0,0)");
        break;

    case Qt::Key_D:
        command = COMMAND_NOTHING_V2;
        v2_active = false;
        v2 = 0.0;
        ui->btn_d->setStyleSheet("color: rgb(0,0,0)");
        break;

    case Qt::Key_Up:
        command = COMMAND_NOTHING_V3;
        v3_active = false;
        v3 = 0.0;
        ui->btn_up->setStyleSheet("color: rgb(0,0,0)");
        break;

    case Qt::Key_Down:
        command = COMMAND_NOTHING_V3;
        v3_active = false;
        v3 = 0.0;
        ui->btn_down->setStyleSheet("color: rgb(0,0,0)");
        break;

    case Qt::Key_Left:
        command = COMMAND_NOTHING_V4;
        v4_active = false;
        v4 = 0.0;
        ui->btn_left->setStyleSheet("color: rgb(0,0,0)");
        break;

    case Qt::Key_Right:
        command = COMMAND_NOTHING_V4;
        v4_active = false;
        v4 = 0.0;
        ui->btn_right->setStyleSheet("color: rgb(0,0,0)");
        break;

    case Qt::Key_Plus:
        ui->btn_plus->setStyleSheet("color: rgb(0,0,0)");
        break;

    case Qt::Key_Minus:
        ui->btn_minus->setStyleSheet("color: rgb(0,0,0)");
        break;

    default:
        command = COMMAND_NOTHING;
        v1_active = false;
        v2_active = false;
        v3_active = false;
        v4_active = false;
        v1 = 0.0;
        v2 = 0.0;
        v3 = 0.0;
        v4 = 0.0;
        ui->btn_ctrl->setStyleSheet("color: rgb(0,0,0)");
        ui->btn_tkoff->setStyleSheet("color: rgb(0,0,0)");
        ui->btn_quit->setStyleSheet("color: rgb(0,0,0)");
        ui->btn_alt->setStyleSheet("color: rgb(0,0,0)");
        ui->btn_tab->setStyleSheet("color: rgb(0,0,0)");
        break;
    }



    if(!v1_active && !v2_active && !v3_active && !v4_active)
        deplacement = 0;
}

Dialog::~Dialog()
{
    delete ui;
}
