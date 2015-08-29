#include "picbutton.h"
#include "btnanimation.h"

#include <QEvent>
#include <QPaintEvent>

#include "comdef.h"



PicButton::PicButton(QWidget *parent) :
    QWidget(parent),
    d_ptr(new PicButtonData())
{
    d_ptr->Animation = new BtnAnimation(this);
    d_ptr->Linear.setStart(0.0,0.0);
}

void PicButton::setResPath(const QString &path)
{
    d_ptr->resPath = path;
    d_ptr->pixmap = new QPixmap(path);
    d_ptr->wSize = d_ptr->pixmap->size();

    d_ptr->Animation->Init();
}

QString PicButton::resPath()
{
    return d_ptr->resPath;
}

void PicButton::setText(QString text)
{
    d_ptr->text = text;
}

bool PicButton::event(QEvent *e)
{
    switch(e->type())
    {
    case QEvent::Enter:
        emit Hover();
        break;
    case QEvent::Leave:
        emit Normal();
        break;
    }

    return QWidget::event(e);
}

void PicButton::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    DrawPic(painter);
    DrawBk(painter);
    DrawText(painter);
    DrawUnderLine(painter);
}

void PicButton::DrawText(QPainter &p)
{
    p.save();

    QFont ft(TEXT_FAMILY);
    ft.setPixelSize(TEXT_RECT.height());
    ft.setBold(true);
    p.setPen(d_ptr->clrText);
    p.setFont(ft);
    p.drawText(TEXT_RECT,Qt::AlignJustify,d_ptr->text);

    p.restore();

}

void PicButton::DrawUnderLine(QPainter &p)
{
    p.save();
    p.fillRect(d_ptr->underLine,QBrush(d_ptr->clrText));
    p.restore();
}

void PicButton::DrawBk(QPainter &p)
{
    p.save();
    d_ptr->Linear.setFinalStop(BK_RECT.width(),BK_RECT.height());
    QColor start = CLR_TEXT_NORMAL;
    start.setAlpha(d_ptr->LinearA);
    QColor end = CLR_TEXT_NORMAL;
    end.setAlpha(0);
    d_ptr->Linear.setColorAt(0.0,start);
    d_ptr->Linear.setColorAt(1.0,end);
    p.setBrush(QBrush(d_ptr->Linear));
    p.fillRect(rect(),QBrush(d_ptr->Linear));
    p.restore();
}

void PicButton::DrawPic(QPainter &p)
{
    p.save();
    QPixmap pic(d_ptr->resPath);
    p.drawPixmap(QRect(QPoint(0,0),size()),pic,QRect(d_ptr->wPos,d_ptr->wSize));
    p.restore();
}

