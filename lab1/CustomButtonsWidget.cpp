#include "CustomButtonsWidget.h"
#include <QPainter>
#include <QMouseEvent>

CustomButtonsWidget::CustomButtonsWidget(QWidget *parent)
    : QWidget{parent}
{
    setMouseTracking(true);
}

CustomButton* CustomButtonsWidget::addCustomButton(QRect pos, QString text)
{
    CustomButton *button = new CustomButton(this, pos, text);
    buttons_.push_back(button);

    return button;
}

void CustomButtonsWidget::paintEvent(QPaintEvent *paintEvent)
{
    QPainter painter(this);

    for (auto button: buttons_)
    {
        button->draw();
    }
}

void CustomButtonsWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() != Qt::LeftButton)
        return;

    bool updateNeeded = false;
    for (auto button: buttons_)
    {
        updateNeeded |= button->handleLeftClick(event->pos());
    }

    if (updateNeeded)
        this->update();
}

void CustomButtonsWidget::mouseReleaseEvent(QMouseEvent *event)
{
    bool updateNeeded = false;
    for (auto button: buttons_)
    {
        updateNeeded |= button->handleLeftClickEnd(event->pos());
    }

    if (updateNeeded)
        this->update();
}

void CustomButtonsWidget::mouseMoveEvent(QMouseEvent *event)
{
    bool updateNeeded = false;
    for (auto button: buttons_)
    {
        auto st = button->handleHover(event->pos());
        updateNeeded |= st;
    }

    if (updateNeeded)
        this->update();
}
