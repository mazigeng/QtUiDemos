#include "widget.h"
#include "ui_widget.h"

#include <QPaintEvent>
#include <QPainter>

#include "picbutton.h"

#include "comdef.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    InitRes();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::InitRes()
{
    for (int n=0; n<BTN_COUNT; ++n)
    {
        PicButton* pBtn = new PicButton(this);

        pBtn->setResPath(PIC_PATHS[n]);
        pBtn->setText(BTN_TEXT[n]);

        QPoint pos(BTN_POS + QPoint(n % 2 * BTN_SIZE.width() , n / 2 * BTN_SIZE.height()));
        pBtn->setGeometry(QRect(pos,BTN_SIZE));
        pBtn->show();

        _buttons.append(pBtn);
    }
}


