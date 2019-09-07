#ifndef HANDLER_H
#define HANDLER_H

#include <QObject>
#include <QString>
#include <vector>
#include <QList>

class Handler : public QObject
{
    Q_OBJECT
public:
    explicit Handler(QObject *parent = nullptr);
    Q_INVOKABLE QStringList getDisks();
signals:

public slots:
};

#endif // HANDLER_H
