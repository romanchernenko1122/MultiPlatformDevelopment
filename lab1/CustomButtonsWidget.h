#ifndef CUSTOMBUTTONSWIDGET_H
#define CUSTOMBUTTONSWIDGET_H

#include <QWidget>
#include <vector>
#include "CustomButton.h"

class CustomButtonsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CustomButtonsWidget(QWidget *parent = nullptr);
    CustomButton* addCustomButton(QRect pos, QString text);

signals:

protected:
    virtual void paintEvent(QPaintEvent *paintEvent);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);

private:
    std::vector<CustomButton*> buttons_;


};

#endif // CUSTOMBUTTONSWIDGET_H
