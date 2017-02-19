#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>

class Myclass : public QObject
{
    Q_OBJECT
public:
    explicit Myclass(QObject *parent = 0);

    static Myclass* instance();
    bool f_flag;
signals:

public slots:
    void eventAxisFunc();
    void eventButtonFunc();
};

#endif // MYCLASS_H
