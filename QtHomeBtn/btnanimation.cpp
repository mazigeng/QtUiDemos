#include "btnanimation.h"
#include "picbutton.h"

#include <QAbstractTransition>
#include <QParallelAnimationGroup>

#include "comdef.h"

#define QD q_ptr->d_ptr



BtnAnimation::BtnAnimation(QObject *parent) :
    QObject(parent),
    q_ptr((PicButton*)parent),
    _anGroup(NULL)

{
}

void BtnAnimation::Init()
{
    _machine = new QStateMachine(q_ptr);
    _sNormal = new QState(_machine);
    _sHover = new QState(_machine);


    AddAnimation("PicRect", DURATION, QEasingCurve::Linear);
    AddAnimation("TextColor", DURATION, QEasingCurve::Linear);
    AddAnimation("BkAlpha", DURATION, QEasingCurve::Linear);
    AddAnimation("UnderLine", DURATION, QEasingCurve::OutBack);

    AssignState("PicRect", QRect(QD->wPos,QD->wSize), QRect(QD->wPos + QPoint(OFFSET_VALUE,OFFSET_VALUE),QD->wSize - QSize(OFFSET_VALUE,OFFSET_VALUE) * 2));
    AssignState("TextColor", CLR_TEXT_NORMAL, CLR_TEXT_HOVER);
    AssignState("BkAlpha", 0, 255);
    AssignState("UnderLine", UNDER_LINE_NORMAL, UNDER_LINE_HOVER);

    QAbstractTransition* t = (QAbstractTransition*)_sNormal->addTransition(q_ptr,SIGNAL(Hover()),_sHover);
    t->addAnimation(_anGroup);
    t = (QAbstractTransition*)_sHover->addTransition(q_ptr,SIGNAL(Normal()),_sNormal);
    t->addAnimation(_anGroup);


    _machine->setInitialState(_sNormal);
    _machine->start();
}

QRect BtnAnimation::picRect() const
{
    return QRect(QD->wPos,QD->wSize);
}

void BtnAnimation::setPicRect(const QRect &picRect)
{
    QD->wPos = picRect.topLeft();
    QD->wSize = picRect.size();
    q_ptr->update();
}
QColor BtnAnimation::colorText() const
{
    return QD->clrText;
}

void BtnAnimation::setColorText(const QColor &colorText)
{
    QD->clrText = colorText;
    q_ptr->update();
}
int BtnAnimation::bkAlpha() const
{
    return QD->LinearA;
}

void BtnAnimation::setBkAlpha(int bkAlpha)
{
    QD->LinearA = bkAlpha;
    q_ptr->update();
}
QRect BtnAnimation::underLine() const
{
    return QD->underLine;
}

void BtnAnimation::setUnderLine(const QRect &underLine)
{
    QD->underLine = underLine;
    q_ptr->update();
}

void BtnAnimation::AssignState(const char* property, const QVariant &normal, const QVariant &hover)
{
    _sNormal->assignProperty(this,property,normal);
    _sHover->assignProperty(this,property,hover);
}

void BtnAnimation::AddAnimation(const char *property, int duration, const QEasingCurve &easing)
{
    if (!_anGroup)
        _anGroup = new QParallelAnimationGroup(this);

    QPropertyAnimation* pAni = new QPropertyAnimation(this, property, this);
    pAni->setDuration(duration);
    pAni->setEasingCurve(easing);
    _anGroup->addAnimation(pAni);
    pAni = NULL;
}






