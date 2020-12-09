#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include "sysS.h"
#include "sysM.h"

class MainDialog : public MyDialog
{
    Q_OBJECT

public:
    MainDialog(QWidget *parent = nullptr);
    ~MainDialog();

    void ControlInit();         //控件界面初始化
    void translateLanguage();   //字


public slots:
    void OnPositionChanged(qint64);

protected:
    void paintEvent(QPaintEvent *event);

private:
    MouseFlow                   m_monthin, m_monthout, m_monthscrape;
    RuleList                    m_rulelist;
    Title                       m_title;
    QString                     m_videopath;

    QLabel                      *m_label_title;
    int                         m_nHeight;

    QTextEdit                   *m_tedit_rule1;
    QTextEdit                   *m_tedit_rule2;
    int                         m_nWidthRule;

    QMediaPlaylist              *m_playlist;
    QMediaPlayer                *m_player;
    QVideoWidget                *m_videoWidget;


    int                         m_nWidthImg11;
    int                         m_nHeightImg11;
    int                         m_nWidthMouth;

    int                         m_nFontSize;


};
#endif // MAINDIALOG_H
