#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>

/*
author: Ethan
date: 2013-1-9
*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // ���ع��ʻ��ļ�
    QTranslator translator;
    translator.load("language.qm");
    a.installTranslator(&translator);

    MainWindow w;
    w.show();

    return a.exec();
}
