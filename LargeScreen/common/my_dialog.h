#ifndef MYDIALOG_H
#define MYDIALOG_H

#include "sysS.h"
//#include <qmath.h>
//#include "my_combobox.h"

class MyDialog : public QDialog
{
    Q_OBJECT
public:
    explicit MyDialog(QWidget *parent = 0);
    ~MyDialog();
    void loadStyleSheet(const QString &sheetName);
    void setStyleSheet1(QString style);
    void CanMove(bool);
};

#endif // MYDIALOG_H
