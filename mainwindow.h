#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTimer>
#include <QImage>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include "ardrone/ardrone.h"
#include "dialog.h"
#include "mldata.h"
//#include "frame.h"
#include "dialogshowdata.h"

#define ALG_NOTHING -1
#define ALG_SVM 0
/* ajouter les autres ici... */

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setSVMParams(double p, double gamma, double degree,double coef0, double C, double nu, int svm_type, int kernel_type ){


        std::cerr << "test : " << svm_params <<  std::endl;
        if(svm_params == NULL){
            svm_params = new CvSVMParams();
        }

        svm_params->svm_type = svm_type;
        svm_params->kernel_type = kernel_type;
        svm_params->C = C;
        svm_params->p = p;
        svm_params->gamma = gamma;
        svm_params->degree = degree;
        svm_params->coef0 = coef0;
        svm_params->nu = nu;

    }
    void setSVMClassifier(CvSVM *val){svm_classifier = val;}
    void setAlgoChoisi(int val){algo_choisi = val;}

public slots:
    void on_actionTest4_triggered();
    void on_actionTest4_hovered();
    void on_btn_takeoff_clicked();
    void on_btn_land_clicked();
    void on_btn_goup_pressed();
    void on_btn_goup_released();
    void on_btn_godown_pressed();
    void on_btn_godown_released();
    void on_btn_rotleft_pressed();
    void on_btn_rotleft_released();
    void on_btn_rotright_pressed();
    void on_btn_rotright_released();
    void on_btn_keyctrl_clicked();
    void on_btn_chgCam_clicked();
    void on_btn_anim_clicked();
    void on_btn_parcourir_clicked();
    void on_btn_drone_connect_clicked();
    void on_btn_drone_disconnect_clicked();
    void on_btn_show_data_clicked();
    void on_btn_load_clicked();
    void on_btn_creer_clicked();
    void test(QString fichier);
    void close_tab(int index);
    void dessiner_sinus();
    void updateGUI();

private:
    Ui::MainWindow *ui;
    QLabel* status;
    cv::VideoCapture capWebcam;

    int camera;

    //Cam
    cv::Mat matOriginal;
    QImage imgOriginal;
    QTimer* tm;

    //Niveau de gris
    cv::Mat matGrey;

    //Detec Visages
    cv::CascadeClassifier face_cascade;

    //Drone
    ARDrone ardrone;

    //Dialog
    Dialog *fen_ctrl;
    DialogShowData* fen_aff;

    //Frames
    //Frame *test_frame;

    //Apprentissage
    MLData *data;

    //Paint
    QPainterPath path;
    //QPainter painter;


    // Algorithme choisi
    int algo_choisi;

    //Classifier
    CvSVM *svm_classifier;
    /* ajouter les autres... */

    //Classifier params
    CvSVMParams *svm_params;
    /* ajouter les autres... */

};

#endif // MAINWINDOW_H
