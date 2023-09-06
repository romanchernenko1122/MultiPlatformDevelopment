#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    allItems = new QTreeWidgetItem(ui->treeWidget);
    allItems->setText(0, "All items");
    allItems->setFlags(allItems->flags() | Qt::ItemIsUserCheckable | Qt::ItemIsSelectable| Qt::ItemIsAutoTristate);
    allItems->setCheckState(0, Qt::Checked);
    allItems->setFlags(allItems->flags() | Qt::ItemIsUserCheckable |Qt::ItemIsSelectable);

    ui->treeWidget->addTopLevelItem(allItems);

    for (int i=0;i<4;i++)
    {
        QTreeWidgetItem *childItem= new QTreeWidgetItem(allItems);
        childItem->setText(0, "Child item #" + QString::number(i));
        childItems.append(childItem);

        childItem->setFlags(childItem->flags() | Qt::ItemIsUserCheckable | Qt::ItemIsSelectable);
        childItem->setCheckState(0, Qt::Checked);
    }

    allItems->addChildren(childItems);
    allItems->setExpanded(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

