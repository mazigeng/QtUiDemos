#ifndef BTNANIMATION_H
#define BTNANIMATION_H

#include <QObject>
#include <QState>
#include <QStateMachine>
#include <QPropertyAnimation>
#include <QRect>
#include <QColor>

class PicButton;
class QParallelAnimationGroup;

class BtnAnimation : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QRect PicRect READ picRect WRITE setPicRect)
    Q_PROPERTY(QColor TextColor READ colorText WRITE setColorText)
    Q_PROPERTY(int BkAlpha READ bkAlpha WRITE setBkAlpha)
    Q_PROPERTY(QRect UnderLine READ underLine WRITE setUnderLine)

public:
    explicit BtnAnimation(QObject *parent = 0);

    void Init();

    QRect picRect() const;
    void setPicRect(const QRect &picRect);

    QColor colorText() const;
    void setColorText(const QColor &colorText);

    int bkAlpha() const;
    void setBkAlpha(int bkAlpha);

    QRect underLine() const;
    void setUnderLine(const QRect &underLine);

signals:


private:
    void AssignState(const char *property, const QVariant& normal, const QVariant& hover);

    void AddAnimation(const char* property, int duration, const QEasingCurve &easing);

private:
    PicButton* q_ptr;
    QState* _sNormal;
    QState* _sHover;
    QStateMachine* _machine;
    QParallelAnimationGroup* _anGroup;
};

#endif // BTNANIMATION_H
