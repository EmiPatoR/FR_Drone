#include "frame.h"
#include "ui_frame.h"

Frame::Frame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Frame)
{
    ui->setupUi(this);

    ui->type_svm->addItem("C SVC");
    ui->type_svm->addItem("NU SVC");
    ui->type_svm->addItem("ONE-CLASS SVM");
    ui->type_svm->addItem("EPS SVR");
    ui->type_svm->addItem("NU SVR");

    ui->type_noyau->addItem("Linear");
    ui->type_noyau->addItem("Polynomial");
    ui->type_noyau->addItem("Radial basis function RBF");
    ui->type_noyau->addItem("Sigmoid");
    delete ui;
}

Frame::~Frame(){

}
