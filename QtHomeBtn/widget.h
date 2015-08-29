#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QList>

class PicButton;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    void InitRes();

private:
    Ui::Widget *ui;

    QList<PicButton*>    _buttons;

};

#endif // WIDGET_H
