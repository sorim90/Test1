#include "myclass.h"
#include "qjoystick.h"
#include <QDebug>

Myclass *p_instance = 0;

Myclass::Myclass(QObject *parent) : QObject(parent)
{
    QJoystick *joystick = QJoystick::openJoystick("/dev/input/js0", 1);
    if (joystick) {
        qDebug() << "ok";
    } else {
        qDebug() << "bad";
    }
    connect(joystick, SIGNAL(axisChanged(int,short)), this, SLOT(eventAxisFunc()));
    connect(joystick, SIGNAL(buttonChanged(int,bool)), this, SLOT(eventButtonFunc()));
}

Myclass* Myclass::instance()
{
    if (!p_instance)
    {
        p_instance = new Myclass();
        return p_instance;
    }
}

void Myclass::eventAxisFunc()
{

}

void Myclass::eventButtonFunc()
{
    f_flag = true;
    //qDebug() << "button event";
}
