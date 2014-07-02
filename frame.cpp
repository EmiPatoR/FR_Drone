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

}

Frame::Frame(MainWindow* pere,QString test) :
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

    this->pere = pere;

}

void Frame::on_btn_use_algo_clicked(){
    /*
    // Set parameters for SVM
    //CvSVMParams *params = new CvSVMParams();
    double p,gamma,degree,coef0,C,nu;
    int svm_type = 0,kernel_type = 0;
    //params->class_weights = lexical_cast<double>(ui->txt_weights->text().toStdString());
    p = lexical_cast<double>(ui->txt_p->text().toStdString());
    gamma = lexical_cast<double>(ui->txt_gamma->text().toStdString());
    degree = lexical_cast<double>(ui->txt_degree->text().toStdString());
    coef0 = lexical_cast<double>(ui->txt_coef0->text().toStdString());
    C = lexical_cast<double>(ui->txt_cvalue->text().toStdString());
    nu = lexical_cast<double>(ui->txt_nu->text().toStdString());

    // Set type for SVM
    switch (ui->type_svm->currentIndex()) {
    case CSVC:
        std::cerr << "[DEBUG] coucou" << std::endl;
        svm_type = CvSVM::C_SVC;
        break;
    case NUSVC:
        svm_type = CvSVM::NU_SVC;
        break;
    case ONECLASSSVM:
        svm_type = CvSVM::ONE_CLASS;
        break;
    case EPSSVR:
        svm_type = CvSVM::EPS_SVR;
        break;
    case NUSVR:
        svm_type = CvSVM::NU_SVR;
        break;
    default:
        std::cerr << "test" << std::endl;
        break;
    }

    // Set noyau for SVM
    switch (ui->type_noyau->currentIndex()) {
    case LIN:
        kernel_type = CvSVM::LINEAR;
        break;
    case POLYNOMIAL:
        kernel_type = CvSVM::POLY;
        break;
    case RADIALBASIS:
        kernel_type = CvSVM::RBF;
        break;
    case SIG:
        kernel_type = CvSVM::SIGMOID;
        break;
    default:
        break;
    }

    // Set Parameters
    ((MainWindow*)this->parent())->setSVMParams(p,gamma,degree,coef0,C,nu,svm_type,kernel_type);

    // Set Classifier
    //((MainWindow*)this->parent())->setSVMClassifier(new CvSVM());

    // Set algo choisi
    ((MainWindow*)this->parent())->setAlgoChoisi(ALG_SVM);
    */
    this->pere->on_btn_keyctrl_clicked();
}

Frame::~Frame(){

}
