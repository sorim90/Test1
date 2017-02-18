#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

#include "myclass.h"
#include <QTime>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTime t;
    t.start();
    qDebug() << "******* start *********";
    //Myclass::instance()->f_flag = false;
    int elapsed_t = 0;

    while( elapsed_t < 5000 ) {

        elapsed_t = t.elapsed();
        QApplication::processEvents(QEventLoop::WaitForMoreEvents, 10);
        if (elapsed_t > 500) {

            if (Myclass::instance()->f_flag) {
                qDebug() << "flag is true";

                Myclass::instance()->f_flag = false;
                //break;
            }
        } else {
            Myclass::instance()->f_flag = false;
        }
    }

 //   MainWindow w;
 //   w.show();

    return a.exec();
}
