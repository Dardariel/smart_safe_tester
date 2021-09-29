#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include <QTcpSocket>


class MainWindow : public QMainWindow, public Ui::MainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();




public slots:
    void slotConnect();
    void slotSend();
    void slotRead();
    void displayError(QAbstractSocket::SocketError socketError);
    void displayState(QAbstractSocket::SocketState socketState);

    void slotAddData();


private:
    QTcpSocket *tcpSocket = nullptr;
};
#endif // MAINWINDOW_H
