#ifndef PICBUTTON_H
#define PICBUTTON_H

#include <QWidget>
#include <QPoint>
#include <QSize>
#include <QPainter>
#include <QLinearGradient>


class BtnAnimation;
class QPixmap;

class PicButtonData
{
public:
    QString     resPath;
    QPoint      pos;
    QSize       size;
    QPoint      wPos;
    QSize       wSize;
    BtnAnimation* Animation;
    QPixmap*    pixmap;
    QString     text;
    QColor      clrText;
    QLinearGradient Linear;
    int         LinearA;
    QRect       underLine;
};


class PicButton : public QWidget
{
    Q_OBJECT
public:
    explicit PicButton(QWidget *parent = 0);
    void setResPath(const QString& path);
    QString resPath();

    void setText(QString text);

signals:
    void Normal();
    void Hover();

public slots:

protected:
    virtual bool event(QEvent * e);
    virtual void	paintEvent(QPaintEvent * event);

private:
    void DrawText(QPainter& p);
    void DrawUnderLine(QPainter& p);
    void DrawBk(QPainter& p);
    void DrawPic(QPainter& p);
private:
    PicButtonData* d_ptr;
    friend class BtnAnimation;

};

#endif // PICBUTTON_H
