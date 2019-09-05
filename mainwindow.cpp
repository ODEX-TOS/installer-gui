#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "diskoptions.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tab = new QTabWidget(parent);
    setCentralWidget(tab);
    setupTabs();
    setWindowTitle(tr("TOS Installer"));
    resize(800,500);
}

void MainWindow::setupTabs(){
    DiskOptions *option = new DiskOptions();

    tab->addTab(option->box,"Install Type");
    tab->addTab(new QWidget(),"Disk select");
    tab->addTab(new QWidget(),"User");
    tab->addTab(new QWidget(),"locals");
    tab->addTab(new QWidget(),"Installing");
    tab->addTab(new QWidget(),"Finished");
}

MainWindow::~MainWindow()
{
    delete ui;
}
