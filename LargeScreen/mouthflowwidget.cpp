#include "mouthflowwidget.h"

MouthFlowWidget::MouthFlowWidget(MouseFlow mouseflow, int width, int height, QString strPath, QString strText, QWidget *parent) : QWidget(parent)
{
    setFixedSize(width, height);
    m_strPath = strPath;
    m_strText = strText;
    m_mouseflow = mouseflow;
    m_nSpeed = 13;

    ControlInit();
    translateLanguage();

}


void MouthFlowWidget::ControlInit()         //控件界面初始化
{
    m_label_title_img = new QLabel;
    QImage img;
    img.load(m_strPath);
    QPixmap mp;
    mp=mp.fromImage(img);
    QSize picSize(23, 23);
    QPixmap scaledPixmap = mp.scaled(picSize);
    m_label_title_img->setPixmap(scaledPixmap);

    m_label_title_text = new QLabel;
    m_label_title_text->setStyleSheet("font-family:Microsoft YaHei;font-size:16px;color:#ffffff;font-weight:bold;");

    QHBoxLayout *layout_title = new QHBoxLayout();
    layout_title->addStretch();
    layout_title->addWidget(m_label_title_img);
    layout_title->addSpacing(3);
    layout_title->addWidget(m_label_title_text);
    layout_title->addStretch();
    layout_title->setContentsMargins(0, 0, 0, 0);

    QWidget *widget_title = new QWidget;
    widget_title->setLayout(layout_title);
    widget_title->setFixedSize(this->width(), 40);


    m_widget_num_few = new QWidget;
    m_widget_scroll = new QWidget;
    QString style_label = "font-family:Microsoft YaHei;font-size:14px;";
    if(m_mouseflow.totalCount <= 6)
    {
        QGridLayout *layout_flow = new QGridLayout();
        for(int i=0; i<6; i++)
        {
            QLabel *label_eName = new QLabel;
            QString str_eName = QString::fromLocal8Bit(m_mouseflow.purchase[i].eName);
            label_eName->setText(str_eName);
            label_eName->setFixedSize(140, 20);
            label_eName->setStyleSheet(style_label);

            QLabel *label_num = new QLabel;
            QString str_num = QString::number(m_mouseflow.purchase[i].num);
            label_num->setText(str_num);
            label_num->setFixedSize(50, 20);
            label_num->setStyleSheet(style_label);

            QLabel *label_date = new QLabel;
            QString str_date = QString::fromLocal8Bit(m_mouseflow.purchase[i].fPurchasedate);
            label_date->setText(str_date);
            label_date->setFixedSize(80, 20);
            label_date->setStyleSheet(style_label);

            if(i >= m_mouseflow.totalCount)
            {
                label_eName->setText("");
                label_num->setText("");
                label_date->setText("");
            }

            layout_flow->addWidget(label_eName, i, 0, 1, 1);
            layout_flow->addWidget(label_num, i, 1, 1, 1);
            layout_flow->addWidget(label_date, i, 2, 1, 1);
        }

        int nHspace = (this->width()-30-29-140-50-80)/2;
        int nVspace = (this->height()-20*6-40-16-13)/5;

        layout_flow->setHorizontalSpacing(nHspace);
        layout_flow->setVerticalSpacing(nVspace);
        layout_flow->setContentsMargins(0, 0, 0, 0);
        m_widget_num_few->setLayout(layout_flow);
    }
    else
    {
        QGridLayout *layout_scroll = new QGridLayout();

        for(int i=0; i<6; i++)
        {
            QLabel *label_eName = new QLabel;
            QString str_eName = QString::fromLocal8Bit(m_mouseflow.purchase[i].eName);
            label_eName->setText("");
            label_eName->setFixedSize(140, 20);
            label_eName->setStyleSheet(style_label);

            QLabel *label_num = new QLabel;
            QString str_num = QString::number(m_mouseflow.purchase[i].num);
            label_num->setText("");
            label_num->setFixedSize(50, 20);
            label_num->setStyleSheet(style_label);

            QLabel *label_date = new QLabel;
            QString str_date = QString::fromLocal8Bit(m_mouseflow.purchase[i].fPurchasedate);
            label_date->setText("");
            label_date->setFixedSize(80, 20);
            label_date->setStyleSheet(style_label);

            layout_scroll->addWidget(label_eName, i, 0, 1, 1);
            layout_scroll->addWidget(label_num, i, 1, 1, 1);
            layout_scroll->addWidget(label_date, i, 2, 1, 1);
        }

        for(int i=0; i<m_mouseflow.totalCount; i++)
        {
            QLabel *label_eName = new QLabel;
            QString str_eName = QString::fromLocal8Bit(m_mouseflow.purchase[i].eName);
            label_eName->setText(str_eName);
            label_eName->setFixedSize(140, 20);
            label_eName->setStyleSheet(style_label);

            QLabel *label_num = new QLabel;
            QString str_num = QString::number(m_mouseflow.purchase[i].num);
            label_num->setText(str_num);
            label_num->setFixedSize(50, 20);
            label_num->setStyleSheet(style_label);

            QLabel *label_date = new QLabel;
            QString str_date = QString::fromLocal8Bit(m_mouseflow.purchase[i].fPurchasedate);
            label_date->setText(str_date);
            label_date->setFixedSize(80, 20);
            label_date->setStyleSheet(style_label);

            layout_scroll->addWidget(label_eName, i+6, 0, 1, 1);
            layout_scroll->addWidget(label_num, i+6, 1, 1, 1);
            layout_scroll->addWidget(label_date, i+6, 2, 1, 1);
        }

        for(int i=m_mouseflow.totalCount+6; i<m_mouseflow.totalCount+12; i++)
        {
            QLabel *label_eName = new QLabel;
            QString str_eName = QString::fromLocal8Bit(m_mouseflow.purchase[i].eName);
            label_eName->setText("");
            label_eName->setFixedSize(140, 20);
            label_eName->setStyleSheet(style_label);

            QLabel *label_num = new QLabel;
            QString str_num = QString::number(m_mouseflow.purchase[i].num);
            label_num->setText("");
            label_num->setFixedSize(50, 20);
            label_num->setStyleSheet(style_label);

            QLabel *label_date = new QLabel;
            QString str_date = QString::fromLocal8Bit(m_mouseflow.purchase[i].fPurchasedate);
            label_date->setText("");
            label_date->setFixedSize(80, 20);
            label_date->setStyleSheet(style_label);

            layout_scroll->addWidget(label_eName, i, 0, 1, 1);
            layout_scroll->addWidget(label_num, i, 1, 1, 1);
            layout_scroll->addWidget(label_date, i, 2, 1, 1);
        }


        layout_scroll->setHorizontalSpacing(44);
        layout_scroll->setVerticalSpacing(10);
        layout_scroll->setContentsMargins(0, 0, 0, 0);
        m_widget_scroll->setLayout(layout_scroll);
    }
    m_widget_num_few->setFixedSize(this->width()-30-29, this->height()-40-16-13);
    m_widget_scroll->setFixedSize(this->width()-30-29, 20*(m_mouseflow.totalCount+12)+10*(m_mouseflow.totalCount+11));

    m_scrollArea = new QScrollArea(this);
    m_scrollArea->setWidgetResizable(true);
    m_scrollArea->setWidget(m_widget_scroll);
    m_scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_scrollArea->setStyleSheet("background: transparent;border:none;");

    QGridLayout *layout_body = new QGridLayout();
    layout_body->addWidget(m_widget_num_few, 0, 0, 1, 1);
    layout_body->addWidget(m_scrollArea, 0, 0, 1, 1);
    layout_body->setContentsMargins(30, 13, 29, 16);


    QWidget *widget_body = new QWidget;
    widget_body->setLayout(layout_body);
    widget_body->setFixedSize(this->width(), this->height()-40);

    QGridLayout *layout = new QGridLayout();
    layout->addWidget(widget_title, 0, 0, 1, 1);
    layout->addWidget(widget_body, 1, 0, 1, 1);
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);

    setLayout(layout);

    if(m_mouseflow.totalCount > 6)
    {
        m_widget_num_few->setVisible(false);
        QTimer *timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
        timer->start(100);
    }
    else
        m_scrollArea->setVisible(false);

}


void MouthFlowWidget::translateLanguage()   //字
{
    m_label_title_text->setText(m_strText);
}

void MouthFlowWidget::onTimeout()
{

    m_scrollArea->verticalScrollBar()->setValue(m_nSpeed);
    m_nSpeed += 1;

    if(m_nSpeed == m_scrollArea->verticalScrollBar()->maximum())
        m_nSpeed = 13;
}














