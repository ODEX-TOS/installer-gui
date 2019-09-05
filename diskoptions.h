#ifndef DISKOPTIONS_H
#define DISKOPTIONS_H

#include <QWidget>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QGroupBox>

class DiskOptions : public QWidget
{
    Q_OBJECT
public:
    explicit DiskOptions(QWidget *parent = nullptr);
    QTextEdit *edit;
    QVBoxLayout *layout;
    QGroupBox *box;
signals:

public slots:
};

#endif // DISKOPTIONS_H
