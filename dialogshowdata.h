#ifndef DIALOGSHOWDATA_H
#define DIALOGSHOWDATA_H

#include <QDialog>
#include "mldata.h"

namespace Ui {
class DialogShowData;
}

class DialogShowData : public QDialog
{
    Q_OBJECT

public:
    explicit DialogShowData(QWidget *parent = 0);
    explicit DialogShowData(MLData* data,QWidget *parent = 0);
    ~DialogShowData();

private:
    Ui::DialogShowData *ui;
    MLData* m_data;
};

#endif // DIALOGSHOWDATA_H
