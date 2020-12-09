#include "maindialog.h"

MainDialog::MainDialog(QWidget *parent)
    : MyDialog(parent)
{
    m_nHeight = 0;
    m_nWidthRule = 0;
    m_nWidthImg11 = 0;
    m_nHeightImg11 = 0;
    m_nFontSize = 0;

    setFixedSize(1920, 1080);
    my_lg_init();

    char videopath[100] = {0};
    my_lg_getWelcomeConfig(m_monthin, m_monthout, m_monthscrape, m_rulelist, m_title, videopath);
    m_videopath = QString::fromLocal8Bit(videopath);

    m_nFontSize = m_title.size;

    ControlInit();
    translateLanguage();


    connect(m_player, SIGNAL(positionChanged(qint64)), this, SLOT(OnPositionChanged(qint64)));


}

MainDialog::~MainDialog()
{
    m_player->stop();

    my_lg_release();
}

void MainDialog::paintEvent(QPaintEvent *event)
{
    //qDebug() << " 绘画开始。。。";
    setFixedSize(1920, 1080);

    QPainter painter(this);
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::white);

    painter.drawRect(QRect(0, 0, this->width(), this->height()));
    /*-------------------------------------------主背景-------------------------------------*/
    QPixmap pixmap_top = QPixmap(qApp->applicationDirPath()+"/Resources/images/top_bg.png");
    QPixmap pixmap_img = QPixmap(qApp->applicationDirPath()+"/Resources/images/img_bg.png");


    int height = this->height() - pixmap_top.height() - pixmap_img.height() - 20;

    if(!pixmap_top.isNull())
        painter.drawPixmap(QRect(0, height, this->width(),pixmap_top.height()), pixmap_top);

    m_nHeight = this->height() - pixmap_img.height() - 20;

    height += pixmap_top.height() + 20;

    if(!pixmap_img.isNull())
        painter.drawPixmap(QRect(0, height, this->width(), pixmap_img.height()), pixmap_img);

    /*-------------------------------------------规范-------------------------------------*/
    QPixmap pixmap_img1 = QPixmap(qApp->applicationDirPath()+"/Resources/images/img1.png");
    if(!pixmap_img1.isNull())
        painter.drawPixmap(QRect(50, m_nHeight+48, pixmap_img1.width(),pixmap_img1.height()), pixmap_img1);

    m_nWidthRule = 50+pixmap_img1.width();

    /*-------------------------------------------视频-------------------------------------*/
    painter.setBrush(QColor(248, 200, 112));
    int nLeft = m_nWidthRule+42;
    int nTop = m_nHeight+84;
    int nRight = nLeft+800;
    int nBottom = nTop+600;


    painter.drawRect(QRect(nLeft, nTop, 800, 5));
    painter.drawRect(QRect(nLeft, nTop, 5, 600));
    painter.drawRect(QRect(nLeft, nBottom-5, 800, 5));
    painter.drawRect(QRect(nRight-5, nTop, 5, 600));

    /*-------------------------------------------月流水-------------------------------------*/
    QPixmap pixmap_img_11 = QPixmap(qApp->applicationDirPath()+"/Resources/images/img_11.png");
    if(!pixmap_img_11.isNull())
        painter.drawPixmap(QRect(this->width()-60-pixmap_img_11.width(), m_nHeight+68, pixmap_img_11.width(), pixmap_img_11.height()), pixmap_img_11);

    QPixmap pixmap_img_22 = QPixmap(qApp->applicationDirPath()+"/Resources/images/img_22.png");
    if(!pixmap_img_22.isNull())
        painter.drawPixmap(QRect(this->width()-60-pixmap_img_22.width(), m_nHeight+68+26+pixmap_img_11.height(), pixmap_img_22.width(), pixmap_img_22.height()), pixmap_img_22);

    QPixmap pixmap_img_33 = QPixmap(qApp->applicationDirPath()+"/Resources/images/img_33.png");
    if(!pixmap_img_33.isNull())
        painter.drawPixmap(QRect(this->width()-60-pixmap_img_33.width(), m_nHeight+68+26*2+pixmap_img_11.height()+pixmap_img_22.height(), pixmap_img_33.width(), pixmap_img_33.height()), pixmap_img_33);

    m_nWidthImg11 = pixmap_img_11.width();
    m_nHeightImg11 = pixmap_img_11.height();
    m_nWidthMouth = this->width()-60-pixmap_img_11.width();

    //qDebug() << " 绘画结束。。。";

    /*------------艺术字---------------*/

    if( m_nFontSize != 0)
    {
        QString strFont = QString::fromLocal8Bit(m_title.words);

        painter.setRenderHint(QPainter::Antialiasing);
        QFont font;
        font.setFamily("Microsoft YaHei");
        font.setPointSize(m_nFontSize);
        //font.setBold(true);
        font.setLetterSpacing(QFont::AbsoluteSpacing, 20);

        QFontMetrics metrics(font);
        QPainterPath path;
        QPen pen(QColor(233, 158, 26));
        pen.setWidth(2);
        int len = metrics.width(strFont/*QStringLiteral()*/);
        int w = this->width();
        int px = (len - w) / 2;
        if (px < 0) {
            px = -px;
        }
        int py = 120/*(m_nHeight - metrics.height())/2 + metrics.ascent()*/;

        if(py < 0)
        {
            py = -py;
        }
        path.addText(px, py, font, strFont/*QStringLiteral("花莫弦")*/);
        painter.strokePath(path, pen);
        //painter.drawPath(path);
        QLinearGradient l(px, py-metrics.height()*9/10, px, py+metrics.height()/10);
        l.setColorAt(0, QColor(255,200,99)); //255,200,99
        l.setColorAt(1, QColor(220,135,0));

        painter.fillPath(path, QBrush(l)/*QBrush(Qt::blue)*/);
    }

}

void MainDialog::ControlInit()         //控件界面初始化
{
    //qDebug() << "m_heig " << m_heig;
    /*-------------------------------------------标题-------------------------------------*/
    m_label_title = new QLabel;
    QString style_label_title = "font-family:Microsoft YaHei;font-size:83px;font-weight:bold;color:#dc8700;";
    m_label_title->setStyleSheet(style_label_title);

    QHBoxLayout *layout_title = new QHBoxLayout();
    layout_title->addStretch();
    layout_title->addWidget(m_label_title);
    layout_title->addStretch();
    layout_title->setContentsMargins(0, 0, 0, 0);

    QWidget *widget_title = new QWidget;
    widget_title->setLayout(layout_title);
    widget_title->setFixedSize(1920, 156);

    /*-------------------------------------------规定-------------------------------------*/
    m_tedit_rule1 = new QTextEdit;
    m_tedit_rule1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_tedit_rule1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_tedit_rule1->setStyleSheet("background: transparent;border:none;");
    m_tedit_rule1->setFixedHeight(385);


    m_tedit_rule2 = new QTextEdit;
    m_tedit_rule2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_tedit_rule2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_tedit_rule2->setStyleSheet("background: transparent;border:none;");
    m_tedit_rule2->setFixedHeight(385);

    QVBoxLayout *layout_rule = new QVBoxLayout();
    layout_rule->addSpacing(64);
    layout_rule->addWidget(m_tedit_rule1);
    layout_rule->addSpacing(18);
    layout_rule->addWidget(m_tedit_rule2);
    layout_rule->addStretch();
    layout_rule->setContentsMargins(86, 0, 30, 0);

    QWidget *widget_rule = new QWidget;
    widget_rule->setLayout(layout_rule);
    widget_rule->setFixedSize(550, 924);
    /*-------------------------------------------视频-------------------------------------*/
    m_player = new QMediaPlayer;               // 申请 QMediaPlayer对象
    m_videoWidget = new QVideoWidget;          // 申请 QVideoWidget对象
    m_videoWidget->setFixedSize(800-10, 600-10);
    m_player->setVideoOutput(m_videoWidget);     // 设置mediaplay的显示界面

    m_player->setMedia(QUrl::fromLocalFile(m_videopath));

    m_player->play();


    QVBoxLayout *layout_video = new QVBoxLayout();
    layout_video->addSpacing(89);
    layout_video->addWidget(m_videoWidget);
    layout_video->addStretch();
    layout_video->setContentsMargins(47, 0, 50, 0);

    QWidget *widget_video = new QWidget;
    widget_video->setLayout(layout_video);
    widget_video->setFixedSize(893, 924);

    /*-------------------------------------------列表-------------------------------------*/
    QString strInPath = QString("%1/Resources/images/icon_1.png").arg(qApp->applicationDirPath());
    MouthFlowWidget *mfw_in = new MouthFlowWidget(m_monthin, 417, 239, strInPath, tr("本月入库"));

    QString strOutPath = QString("%1/Resources/images/icon_2.png").arg(qApp->applicationDirPath());
    MouthFlowWidget *mfw_out = new MouthFlowWidget(m_monthout, 417, 239, strOutPath, tr("本月出库"));

    QString strScrapePath = QString("%1/Resources/images/icon_3.png").arg(qApp->applicationDirPath());
    MouthFlowWidget *mfw_scrape = new MouthFlowWidget(m_monthscrape, 417, 239, strScrapePath, tr("本月报废"));



    QVBoxLayout *layout_mouth = new QVBoxLayout();
    layout_mouth->addSpacing(68);
    layout_mouth->addWidget(mfw_in);
    layout_mouth->addSpacing(20);
    layout_mouth->addWidget(mfw_out);
    layout_mouth->addSpacing(20);
    layout_mouth->addWidget(mfw_scrape);
    layout_mouth->addStretch();
    layout_mouth->setContentsMargins(0, 0, 60, 0);

    QWidget *widget_mouth = new QWidget;
    widget_mouth->setLayout(layout_mouth);
    widget_mouth->setFixedSize(477, 924);


    QGridLayout *layout = new QGridLayout();
    layout->addWidget(widget_title, 0, 0, 1, 3);
    layout->addWidget(widget_rule, 1, 0, 1, 1);
    layout->addWidget(widget_video, 1, 1, 1, 1);
    layout->addWidget(widget_mouth, 1, 2, 1, 1);
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);
    setLayout(layout);
}


void MainDialog::translateLanguage()   //字
{

    m_label_title->setText(""/*QString::fromLocal8Bit(m_title.words)*/);

    QString str_rule1 = QString::fromLocal8Bit(m_rulelist.rule[0].text);
    m_tedit_rule1->setText(str_rule1);

    QString str_rule2 = QString::fromLocal8Bit(m_rulelist.rule[1].text);
    m_tedit_rule2->setText(str_rule2);
}

void MainDialog::OnPositionChanged(qint64 position)
{
    {
        m_player->setPosition(0);
        m_player->play();
    }
}

