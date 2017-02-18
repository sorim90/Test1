#ifndef JOYSTICKVIEW_H
#define JOYSTICKVIEW_H

#include <QDialog>
#include <QTimer>
#include <QListIterator>
#include <QModelIndexList>
#include <QListWidgetItem>

#include "qjoystick.h"

namespace Ui {
class joystickview;
}

class joystickview : public QDialog
{
    Q_OBJECT

    QTimer *refreshTimer;
    QString mDirectory;
    QModelIndexList selectedIndexes;

public:
    explicit joystickview(QString directory, QWidget *parent = 0);
    ~joystickview();
    QJoystick* getJoystick();

    static QJoystick* enumerate(QString jsDir, QWidget *parent = 0);

private:
    Ui::joystickview *ui;

private slots:
    void refreshList();
    void on_pushButton_2_clicked();

};

#endif // JOYSTICKVIEW_H
