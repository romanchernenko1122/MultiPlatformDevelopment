#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "CustomButtonsWidget.h"
#include "CustomButton.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    CustomButtonsWidget *customButtons = new CustomButtonsWidget(this);
    customButtons->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Expanding);
    ui->verticalLayout->insertWidget(0,customButtons);

    for (int i = 0; i < 3; i++)
    {
        auto button = customButtons->addCustomButton(QRect(20, 50+i*100, 200, 40), "Кнопка №" + QString::number(i+1));
        connect(button, &CustomButton::buttonPressed, this, &MainWindow::handleButtonClick);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleButtonClick()
{
    CustomButton *button = dynamic_cast<CustomButton*>(sender());
    if (button)
        ui->labelStatus->setText(button->text() + " натиснута.");
}

