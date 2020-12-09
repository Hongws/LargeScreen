#ifndef MOUTHFLOWWIDGET_H
#define MOUTHFLOWWIDGET_H

#include "sysS.h"
#include "sysM.h"

class MouthFlowWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MouthFlowWidget(MouseFlow mouseflow, int width = 0, int height = 0, QString strPath = "", QString strText = "", QWidget *parent = nullptr);


    void ControlInit();         //控件界面初始化
    void translateLanguage();   //字


signals:

public slots:
    void onTimeout();


private:
    QLabel              *m_label_title_img;
    QLabel              *m_label_title_text;

    QScrollArea         *m_scrollArea;              //设置滚动区
    QWidget             *m_widget_scroll;
    QWidget             *m_widget_num_few;


    QString             m_strPath;
    QString             m_strText;
    MouseFlow           m_mouseflow;

    int                 m_nSpeed;



};

#endif // MOUTHFLOWWIDGET_H
