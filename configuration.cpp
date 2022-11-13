﻿#include "configuration.h"
#include "ui_configuration.h"
#include <mainwindow.h>
//#include <QSizeF>

Configuration::Configuration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Configuration)
{
    ui->setupUi(this);
    FUI = (MainWindow*)parent;//((MainWindow*)FUI)->octonetwork.SendGCode(_GCode_Setting);

    //各个窗体名字
    QStringList strList;
    strList.append("Wifi");
//    strList.append("GConde");
    strList.append("RPI Terminal");
    strList.append("Gcode Terminal");
//    strList.append("OctoPrint Webside");

    foreach(QString item,strList)
    {
        QStandardItem *menulist = new QStandardItem(static_cast<QString>(item));
        menulist->setForeground(QColor(255,255,255));
        menulist->setTextAlignment(Qt::AlignCenter);
        if(item == "Wifi")
        {
            menulist->setIcon(QIcon(":/assets/Wifi.svg"));
        }
        else if(item == "RPI Terminal")
        {
            menulist->setIcon(QIcon(":/assets/terminal.svg"));
        }
        else if(item == "Gcode Terminal")
        {
            menulist->setIcon(QIcon(":/assets/yuanchengkongzhi.svg"));
        }
//        else if(item == "OctoPrint Webside")
//        {
//            menulist->setIcon(QIcon(":/assets/webside.svg"));
//            menulist->setBackground(QBrush(Qt::blue));
//        }

        ItemModel->appendRow(menulist);
    }
    ui->Frm_ListView->setModel(ItemModel);
    ui->Frm_ListView->setIconSize(QSize((int)(SizePercent.width()*72),(int)(SizePercent.height()*72)));

    QFont font;
    font.setPointSize((int)(ui->Frm_ListView->font().pointSize()*(SizePercent.width() < SizePercent.height() ? SizePercent.width():SizePercent.height())));
    ui->Frm_ListView->setFont(font);

    this->resize((int)(SizePercent.width()*800),(int)(SizePercent.height()*480));
    this->setMaximumSize((int)(SizePercent.width()*800),(int)(SizePercent.height()*480));
    this->setFixedSize((int)(SizePercent.width()*800),(int)(SizePercent.height()*480));
}

Configuration::~Configuration()
{
    delete ui;
}

void Configuration::on_Btn_Back_clicked()
{
    this->close();
}

void Configuration::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);
}

void Configuration::on_Frm_ListView_clicked(const QModelIndex &index)
{
    //ui->Btn_Help->setText(index.data().toString());
    if(index.data().toString() == "Wifi")
        ((MainWindow*)FUI)->wlanconfig->show();
    if(index.data().toString() == "RPI Terminal")
        ((MainWindow*)FUI)->terminaldialog->show();
    if(index.data().toString() == "Gcode Terminal")//GCode 控制台
        ((MainWindow*)FUI)->gcodedialog->show();
//    if(index.data().toString() == "OctoPrint Webside")
//        ((MainWindow*)FUI)->webdialog->show();
}

void Configuration::on_Btn_Help_clicked()
{
    ((MainWindow*)FUI)->wlanconfig->GetNetworkInfo();
}
