#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include <QObject>
#include <QRect>

class CustomButton : public QObject
{
    Q_OBJECT
public:
    explicit CustomButton(QObject *parent, QRect pos, QString text);

    void draw();
    bool handleLeftClick(QPoint clickPosition);
    bool handleLeftClickEnd(QPoint clickPosition);
    bool handleHover(QPoint mousePosition);

    QString text();

signals:
    void buttonPressed();

private:
    QRect position_;
    QString text_;

    bool hovered_ = false;
    bool pressed_ = false;
};

#endif // CUSTOMBUTTON_H
