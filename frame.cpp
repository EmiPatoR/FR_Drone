#include "frame.h"
#include "ui_frame.h"
#include "mainwindow.h"
#include <boost/lexical_cast.hpp>

using boost::lexical_cast;
using boost::bad_lexical_cast;

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

void Frame::on_btn_use_algo_clicked(){

    // Set parameters for SVM
    CvSVMParams *params = new CvSVMParams();

    //params->class_weights = lexical_cast<double>(ui->txt_weights->text().toStdString());
    params->p = lexical_cast<double>(ui->txt_p->text().toStdString());
    params->gamma = lexical_cast<double>(ui->txt_gamma->text().toStdString());
    params->degree = lexical_cast<double>(ui->txt_degree->text().toStdString());
    params->coef0 = lexical_cast<double>(ui->txt_coef0->text().toStdString());
    params->C = lexical_cast<double>(ui->txt_cvalue->text().toStdString());
    params->nu = lexical_cast<double>(ui->txt_nu->text().toStdString());

    // Set type for SVM
    switch (ui->type_svm->currentIndex()) {
    case CSVC:
        params->svm_type = CvSVM::C_SVC;
        break;
    case NUSVC:
        params->svm_type = CvSVM::NU_SVC;
        break;
    case ONECLASSSVM:
        params->svm_type = CvSVM::ONE_CLASS;
        break;
    case EPSSVR:
        params->svm_type = CvSVM::EPS_SVR;
        break;
    case NUSVR:
        params->svm_type = CvSVM::NU_SVR;
        break;
    default:
        break;
    }

    // Set noyau for SVM
    switch (ui->type_noyau->currentIndex()) {
    case LIN:
        params->kernel_type = CvSVM::LINEAR;
        break;
    case POLYNOMIAL:
        params->kernel_type = CvSVM::POLY;
        break;
    case RADIALBASIS:
        params->kernel_type = CvSVM::RBF;
        break;
    case SIG:
        params->kernel_type = CvSVM::SIGMOID;
        break;
    default:
        break;
    }

    ((MainWindow*)this->parent())->setSVMParams(params);
}

Frame::~Frame(){

}
