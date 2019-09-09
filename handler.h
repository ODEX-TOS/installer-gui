#ifndef HANDLER_H
#define HANDLER_H

#include <QObject>
#include <QString>
#include <vector>
#include <QList>


// The handler class takes care of custom data that needs to be displayed in a gui.
// It always returns QString lists that can then Dynamically be shown using models in a view.
class Handler : public QObject
{
    Q_OBJECT
public:
    explicit Handler(QObject *parent = nullptr);
    Q_INVOKABLE QStringList getDisks();
    Q_INVOKABLE QStringList getLocals();
    Q_INVOKABLE QStringList getKeyMaps();
signals:

public slots:
};

#endif // HANDLER_H
