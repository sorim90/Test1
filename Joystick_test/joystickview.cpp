#include "joystickview.h"
#include "ui_joystickview.h"

#include <dirent.h>
#include <QDebug>

joystickview::joystickview (QString directory, QWidget *parent) : QDialog(parent), ui(new Ui::joystickview), mDirectory(directory) {
    ui->setupUi(this);
    if(!mDirectory.endsWith('/')) mDirectory += '/';
    refreshList();
    refreshTimer = new QTimer();
    refreshTimer->start(1000);
    connect(refreshTimer, SIGNAL(timeout()), this, SLOT(refreshList()));
    connect(ui->pushButton, SIGNAL(clicked), this, SLOT(getJoystick()));
}

joystickview::~joystickview()
{
    delete ui;
}

void joystickview::refreshList() {
    bool reselect = false;
    QModelIndex index;
    if(ui->joystickList->selectedItems().count() > 0) {
        index = ui->joystickList->selectionModel()->selectedIndexes().at(0);
        reselect = true;
    }
    ui->joystickList->clear();
    DIR* dir;
    struct dirent *dirp;
    dir = opendir(mDirectory.toAscii().data());
    while((dirp = readdir(dir)) != NULL) {
        if(QString(dirp->d_name).startsWith("js")) {
            QString path = mDirectory + dirp->d_name;
            JSInfo info = QJoystick::getJoystickInfo(path);
            QListWidgetItem *item = new QListWidgetItem(info.name, ui->joystickList);
            item->setToolTip(path);
            //qDebug() << path;
        }
    }
    if(reselect) {
        ui->joystickList->selectionModel()->select(index, QItemSelectionModel::Select);
    }
}

QJoystick* joystickview::getJoystick() {
/*    if(ui->joystickList->selectedItems().count() < 1)
        return NULL;
    QListWidgetItem *item = ui->joystickList->selectedItems().at(0);*/
    return QJoystick::openJoystick("/dev/input/js0", 1);
}

QJoystick* joystickview::enumerate(QString jsDir, QWidget *parent) {
    joystickview *enumerator = new joystickview(jsDir, parent);
/*    if(enumerator->exec() == QDialog::Accepted) {
        return enumerator->getJoystick();
    }*/
    return enumerator->getJoystick();
}

void joystickview::on_pushButton_2_clicked()
{
    this->close();
}
/*
void joystickview::on_pushButton_clicked()
{
    this->close();
}
*/
