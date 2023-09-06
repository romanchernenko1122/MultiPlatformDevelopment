#include "CustomButton.h"
#include <QPainter>
#include <QPainterPath>
#include <QWidget>
#include <QFont>

CustomButton::CustomButton(QObject *parent, QRect pos, QString text)
    : QObject{parent}, position_(pos), text_(text)
{

}

void CustomButton::draw()
{
    auto parentWidget = dynamic_cast<QWidget*>(parent());

    QPainter painter(parentWidget);
    painter.setRenderHint(QPainter::Antialiasing);

    QPainterPath path;
    path.addRoundedRect(position_, 5, 5);

    if (pressed_)
    {
        QPen pen(Qt::black, 3);
        painter.setPen(pen);
        painter.drawPath(path);
    }
    else
    {
        QPen pen(Qt::black, 1);
        painter.setPen(pen);
        painter.drawPath(path);
    }

    if (hovered_)
    {
        painter.fillPath(path, Qt::darkGray);
    }
    else
    {
        painter.fillPath(path, Qt::lightGray);
    }

    QPen pen(Qt::red, 1);
    painter.setPen(pen);
    painter.drawText(position_, Qt::AlignCenter, text_);
}

bool CustomButton::handleLeftClick(QPoint clickPosition)
{
    if (pressed_)
        return false;

    pressed_ = position_.contains(clickPosition);
    if (pressed_)
        emit(buttonPressed());
    return pressed_;
}

bool CustomButton::handleLeftClickEnd(QPoint clickPosition)
{
    if (!pressed_)
        return false;

    pressed_ = false;
    return true;
}

bool CustomButton::handleHover(QPoint mousePosition)
{
    if (!hovered_ && position_.contains(mousePosition))
    {
        hovered_ = true;
        return true;
    }
    else if (hovered_ && !position_.contains(mousePosition))
    {
        hovered_ = false;
        return true;
    }

    return false;
}

QString CustomButton::text()
{
    return text_;
}
