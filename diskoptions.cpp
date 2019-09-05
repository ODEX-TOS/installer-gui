#include "diskoptions.h"
#include <QPushButton>

DiskOptions::DiskOptions(QWidget *parent) : QWidget(parent)
{
    box = new QGroupBox;

    layout = new QVBoxLayout;
    edit = new QTextEdit;
    edit->setText(tr("Hello world"));
    layout->addWidget(new QPushButton(tr("Button 1")));
    layout->addWidget(new QPushButton(tr("Button 2")));
    layout->addWidget(edit);
    box->setLayout(layout);
}


