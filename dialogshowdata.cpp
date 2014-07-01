#include "dialogshowdata.h"
#include "ui_dialogshowdata.h"
#include <QTableWidget>
#include <QStringList>
#include <iostream>
#include "mldata.h"

DialogShowData::DialogShowData(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogShowData)
{
    ui->setupUi(this);
}

DialogShowData::DialogShowData(MLData* data, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogShowData)
{
    QStringList str_list;
    QString value;
    ui->setupUi(this);
    if(data != NULL){
        m_data = data;
        int nb_rows = m_data->get_values()->rows;
        int nb_cols = m_data->get_values()->cols;
        ui->table_data->setRowCount(nb_rows);
        ui->table_data->setColumnCount(nb_cols);

        for(int i=0;i<data->get_var_idx()->rows;i++){
            str_list.append("Variable " + QString::number(i+1));
            if(i==m_data->get_var_idx()->rows - 1)
                str_list.append("Classe");
        }

        ui->table_data->setHorizontalHeaderLabels(str_list);

        for(int i=0;i<data->get_values()->rows;i++){
            for(int j=0;j<data->get_values()->cols;j++){
                value.setNum(data->get_values()->at<float>(i,j));
                QTableWidgetItem *newItem = new QTableWidgetItem(value);
                        if(j == m_data->get_responses_idx()){
                            ui->table_data->setItem(i,m_data->get_values()->cols -1,newItem);
                        }
                        else{
                            if(j == m_data->get_values()->cols-1){
                                ui->table_data->setItem(i,m_data->get_responses_idx(),newItem);
                            }
                            else{
                                 ui->table_data->setItem(i,j,newItem);
                            }

                        }
            }
        }
    }
    this->show();
}

DialogShowData::~DialogShowData()
{
    delete ui;
}
