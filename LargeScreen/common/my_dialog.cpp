#include "my_dialog.h"
MyDialog::MyDialog(QWidget *parent) : QDialog(parent)
{
    //setWindowFlags(Qt::FramelessWindowHint);
    //setWindowFlags(Qt::Widget);
    setWindowState(Qt::WindowNoState);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
}

MyDialog::~MyDialog()
{

}

void MyDialog::loadStyleSheet(const QString &sheetName)
{
    QFile file(sheetName);
    file.open(QFile::ReadOnly);
    if (file.isOpen())
    {
        QString styleSheet = this->styleSheet();
        styleSheet += QLatin1String(file.readAll());
        this->setStyleSheet(styleSheet);
    }
}

void MyDialog::setStyleSheet1(QString style)
{
    QString styleSheet = this->styleSheet();
    styleSheet += style;
    this->setStyleSheet(styleSheet);
}

//void MyDialog::CanMove(bool b)
//{
//    mouse_press2=b;
//}


//void MyDialog::AddToComboBox(QStringList *mlist, myComboBox *mcomboBox, QListWidget  *mlistWidget)
//{
//    if(mlist != NULL && mcomboBox != NULL && mlistWidget != NULL)
//    {
//        mcomboBox->removeAll();
//        for (int i = 0; i < mlist->size(); i++)
//        {
//            QString str = mlist->at(i);
//            AccountItem *account_item = new AccountItem();
//            account_item->setAccountNumber(QPixmap(""), str, QPixmap(""), false);
//            account_item->SetIndex(i);
//            connect(account_item, SIGNAL(showAccount(QString)), mcomboBox, SLOT(showAccount(QString)));
//            connect(account_item, SIGNAL(removeAccount(QString)), mcomboBox, SLOT(removeAccount(QString)));
//            connect(account_item, SIGNAL(GetIndex(int)), mcomboBox, SLOT(GetCurrentIndex(int)));
//            QListWidgetItem* list_item = new QListWidgetItem;
//            list_item->setSizeHint(QSize(0, 30));
//            mlistWidget->addItem(list_item);
//            mlistWidget->setItemWidget(list_item, account_item);
//        }
//    }
//}

//int MyDialog::SetLabelPixmap(QString sPath,QLabel*label,int width,int height)
//{
//    QImage img;
//    img.load(sPath);
//    QPixmap mp;
//    mp=mp.fromImage(img);
//    if(mp.isNull())
//        return -1;

//    QSize picSize;
//    if(width==0&&height==0)picSize=QSize(mp.width(),mp.height());
//    else picSize=QSize(width,height);
//    QPixmap scaledPixmap = mp.scaled(picSize);
//    label->setPixmap(scaledPixmap);
//    return 1;
//}

//int MyDialog::TimeComparison(QString time1,QString time2)//时间比较
//{
//    QDateTime t = QDateTime::fromString(time1,"yyyy-MM-dd hh:mm:ss");
//    QDateTime t2 = QDateTime::fromString(time2,"yyyy-MM-dd hh:mm:ss");
//    qint64 elapsed = t.msecsTo(t2);
//    if(elapsed>0)
//        return 1;
//    else
//        return 0;
//}

//void MyDialog::paintEvent(QPaintEvent *event)
//{
//    QPainter painter(this);
//    painter.setPen(Qt::NoPen);
//    painter.setBrush(Qt::white);

//    painter.drawRect(QRect(0, 0, this->width(), this->height()));

//    QPixmap pixmap_top = QPixmap(qApp->applicationDirPath()+"/Resources/images/top_bg.png");
//    QPixmap pixmap_img = QPixmap(qApp->applicationDirPath()+"/Resources/images/img_bg.png");


//    int height = this->height() - pixmap_top.height() - pixmap_img.height() - 20;

//    if(!pixmap_top.isNull())
//        painter.drawPixmap(QRect(0, height, this->width(),pixmap_top.height()), pixmap_top);
//    height += pixmap_top.height() + 20;


//    if(!pixmap_img.isNull())
//        painter.drawPixmap(QRect(0, height, this->width(), pixmap_img.height()), pixmap_img);
//    //height += pixmap.height();

//    QDialog::paintEvent(event);
//}



//void MyDialog::mousePressEvent(QMouseEvent *event)
//{
//    //只能是鼠标左键移动和改变大小
//    if(event->button() == Qt::LeftButton)
//    {
//        if(mouse_press2)
//            mouse_press = true;
//    }

//    //窗口移动距离
//    move_point = event->globalPos() - pos();
//}

//void MyDialog::mouseReleaseEvent(QMouseEvent *)
//{
//    mouse_press = false;
//}

//void MyDialog::mouseMoveEvent(QMouseEvent *event)
//{
//    //移动窗口
//    if(mouse_press)
//    {
//        if( isShowMax==true)
//        {
//            //            this->showNormal();
//            //            isShowMax=false;
//            mouse_press=false;
//            return;
//        }

//        //qDebug()<<isShowMax;
//        QPoint move_pos = event->globalPos();
//        move(move_pos - move_point);
//    }
//}



//void MyDialog::ShowMax()
//{
//    if(isShowMax== false)
//    {
//        iWidth=this->width();
//        iHeight=this->height();
//        QDesktopWidget* desktopWidget = QApplication::desktop();
//        QRect screenRect = desktopWidget->screenGeometry();
//        int g_nActScreenW = screenRect.width();
//        int g_nActScreenH = screenRect.height();
//        setFixedSize(QSize(g_nActScreenW,g_nActScreenH));
//        isShowMax=true;
//    }
//    else
//    {
//        isShowMax=false;
//        setFixedSize(QSize(iWidth,iHeight));
//    }
//}

//void MyDialog::ShowMin()
//{
//    this->showMinimized();
//}



//bool MyDialog::event(QEvent *event)
//{
//    switch (event->type())
//    {
//    case QEvent::MouseMove:
//        mouseMoveEvent((QMouseEvent*)event);
//        break;
//    case QEvent::MouseButtonPress:

//        mousePressEvent((QMouseEvent*)event);
//        break;
//    case QEvent::MouseButtonRelease:
//        //qDebug()<<"12";
//        emit clicked();
//        mouseReleaseEvent((QMouseEvent*)event);
//        break;
//    case QEvent::MouseButtonDblClick:
//        //qDebug()<<"11";
//        emit DblClick();
//        mouseDoubleClickEvent((QMouseEvent*)event);
//        break;
//    }
//    return QDialog::event(event);// event(e);
//}

//bool MyDialog::eventFilter(QObject *obj, QEvent *e)
//{
//    //qDebug()<<"11";
//    switch (e->type())
//    {
//    case QEvent::MouseMove:
//        mouseMoveEvent((QMouseEvent*)e);
//        //isLeftPressDown = false;
//        break;
//    case QEvent::MouseButtonPress:
//        mousePressEvent((QMouseEvent*)e);
//        break;
//    case QEvent::MouseButtonRelease:
//        mouseReleaseEvent((QMouseEvent*)e);

//        break;
//    case QEvent::MouseButtonDblClick:
//        mouseDoubleClickEvent((QMouseEvent*)e);
//        break;
//    }
//    return QDialog::eventFilter(obj, e);// event(e);
//}


//void MyDialog::keyPressEvent(QKeyEvent *event)
//{
//    if ( event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return){
//    }
//}

//void MyDialog::keyReleaseEvent(QKeyEvent *event)
//{
//    if ( event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return){
//    }
//}
