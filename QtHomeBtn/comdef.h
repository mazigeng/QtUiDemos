#ifndef COMDEF_H
#define COMDEF_H

#endif // COMDEF_H


const QPoint BTN_POS(20,20);                            // 按钮排列左上角起点坐标
const QSize BTN_SIZE(200,200);                          // 按钮固定大小
const int   BTN_COUNT(4);                               // 按钮个数
const QString PIC_PATHS[] = {"://animal.jpg",           // 按钮的图片路径
                          "://plant.jpg",
                          "://object.jpg",
                          "://human.jpg"};

const QString BTN_TEXT[] = {                            // 按钮显示文本
    "Animal",
    "Plant",
    "Substance",
    "Human"
};


const int OFFSET_VALUE(10);                             // 图片放大的位移量
const int DURATION(400);                                // 动画时间
const int DURATION_TEXT(400);                           // 文本颜色动画的时间
const QColor CLR_TEXT_NORMAL(0,154,247);                // normal状态下的文本颜色  海马蓝
const QColor CLR_TEXT_HOVER(250,250,250);               // hover状态下的颜色
const QRect UNDER_LINE_NORMAL(15,50,30,5);              // 下划线位置 normal状态
const QRect UNDER_LINE_HOVER(15,50,80,5);              // 下划线位置 Hover状态


const QString TEXT_FAMILY("楷体");                        // 显示文字的字体
const QRect TEXT_RECT(15,15,180,24);                     // 显示文字的绘图区域
const QRect BK_RECT(0, 0, 200, 200);                    // 背景绘图区域

