#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>

#include "coordwidget.h"
#include "coordsyswidget.h"
#include "datamodel.h"
#include "dbconn.h"

//namespace Ui {
//class MainWindow;
//}
#define WIDTH 800
#define HEIGHT 600

class QLabel;
class QMenu;
class QAction;
class QScrollArea;
class QDialogButtonBox;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

public slots:
    void accept();
//    void reject();

private slots:
    void about();
    void drawCoordSys();

private:
//    Helper helper;
    void createMenus();
    void createActions();
    void createButtonBox();

    QWidget *centralWidget;
    QScrollArea *coordInputArea;
    QScrollArea *coordSysArea;
//    GLWidget *glWidget;
    CoordWidget *coordWidget;
    CoordSysWidget *coordSysWidget;
    DataModel *dataModel;

    QMenu *dataMenu;
    QMenu *modelMenu;
    QMenu *seismicSourceMenu;
    QMenu *helpMenu;
    QAction *fileFormatAct;
    QAction *mergeAct;
    QAction *signalAnalysisAct;
    QAction *exitAct;
    QAction *drawCoordSysAct;
    QAction *travelTimeCalcAct;
    QAction *aboutAct;

    QDialogButtonBox *buttonBox;
};

#endif // MAINWINDOW_H
