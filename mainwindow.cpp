#include "mainwindow.h"
#include <QTextCodec>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi(this);


    connect(pb_connect, &QAbstractButton::pressed, this, &MainWindow::slotConnect);
    connect(pb_send, &QAbstractButton::pressed, this, &MainWindow::slotSend);


    tcpSocket = new QTcpSocket;
    connect(tcpSocket, &QIODevice::readyRead, this, &MainWindow::slotRead);
//    connect(tcpSocket, &QAbstractSocket::errorOccurred, this, &MainWindow::displayError);
    connect(tcpSocket, &QAbstractSocket::stateChanged, this, &MainWindow::displayState);

    connect(pb_1, &QAbstractButton::pressed, this, &MainWindow::slotAddData);
    connect(pb_2, &QAbstractButton::pressed, this, &MainWindow::slotAddData);
    connect(pb_3, &QAbstractButton::pressed, this, &MainWindow::slotAddData);
    connect(pb_4, &QAbstractButton::pressed, this, &MainWindow::slotAddData);
    connect(pb_5, &QAbstractButton::pressed, this, &MainWindow::slotAddData);
    connect(pb_6, &QAbstractButton::pressed, this, &MainWindow::slotAddData);
    connect(pb_7, &QAbstractButton::pressed, this, &MainWindow::slotAddData);
    connect(pb_8, &QAbstractButton::pressed, this, &MainWindow::slotAddData);
    connect(pb_9, &QAbstractButton::pressed, this, &MainWindow::slotAddData);
}

MainWindow::~MainWindow()
{
    delete tcpSocket;
}

void MainWindow::slotAddData()
{
    te_send->clear();
    QString str;
    if(pb_1->isDown())
    {
        str="<?xml version=\"1.0\" encoding=\"utf-8\"?>\n"
            "    <CardServiceRequest xmlns=\"http://www.nrf-arts.org/IXRetail/namespace\"\n"
            "                        xmlns:IFSF=\"http://www.ifsf.org/\"\n"
            "                        xmlns:xs=\"http://www.w3.org/2001/XMLSchema\"\n"
            "                        xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"\n"
            "                        xsi:schemaLocation=\".\\CardRequest.xsd\"\n"
            "                        RequestType=\"SafeStatus\"\n"
            "                        ApplicationSender=\"POSeps01\"\n"
            "                        WorkstationID=\"POS\"\n"
            "                        RequestID=\"00016\">\n"
            "        <POSdata LanguageCode=\"en\">\n"
            "            <POSTimeStamp>2012-10-04T14:26:07+02:00</POSTimeStamp>\n"
            "            <OutdoorPosition>1</OutdoorPosition>\n"
            "        </POSdata>\n"
            "    </CardServiceRequest>\n";
    }
    else if(pb_2->isDown())
    {
        str="<?xml version=\"1.0\" encoding=\"utf-8\"?>\n"
            "    <CardServiceRequest xmlns=\"http://www.nrf-arts.org/IXRetail/namespace\"\n"
            "                        xmlns:IFSF=\"http://www.ifsf.org/\"\n"
            "                        xmlns:xs=\"http://www.w3.org/2001/XMLSchema\"\n"
            "                        xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"\n"
            "                        xsi:schemaLocation=\".\\CardRequest.xsd\"\n"
            "                        RequestType=\"SafeStatusEx\"\n"
            "                        ApplicationSender=\"POSeps01\"\n"
            "                        WorkstationID=\"POS\"\n"
            "                        RequestID=\"00016\">\n"
            "        <POSdata LanguageCode=\"en\">\n"
            "            <POSTimeStamp>2012-10-04T14:26:07+02:00</POSTimeStamp>\n"
            "            <OutdoorPosition>1</OutdoorPosition>\n"
            "        </POSdata>\n"
            "    </CardServiceRequest>\n";
    }
    else if(pb_3->isDown())
    {
        str="<?xml version=\"1.0\" encoding=\"utf-8\"?>\n"
            "    <CardServiceRequest xmlns=\"http://www.nrf-arts.org/IXRetail/namespace\"\n"
            "                        xmlns:IFSF=\"http://www.ifsf.org/\"\n"
            "                        xmlns:xs=\"http://www.w3.org/2001/XMLSchema\"\n"
            "                        xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"\n"
            "                        xsi:schemaLocation=\".\\CardRequest.xsd\"\n"
            "                        RequestType=\"SafeEncashment\"\n"
            "                        ApplicationSender=\"POSeps01\"\n"
            "                        WorkstationID=\"POS\"\n"
            "                        RequestID=\"00016\">\n"
            "        <POSdata LanguageCode=\"en\">\n"
            "            <POSTimeStamp>2012-10-04T14:26:07+02:00</POSTimeStamp>\n"
            "            <OutdoorPosition>1</OutdoorPosition>\n"
            "            <TypeIncassation>Current</TypeIncassation>\n"
            "        </POSdata>\n"
            "    </CardServiceRequest>\n";
    }
    else if(pb_4->isDown())
    {
        str="<?xml version=\"1.0\" encoding=\"utf-8\"?>\n"
            "    <CardServiceRequest xmlns=\"http://www.nrf-arts.org/IXRetail/namespace\"\n"
            "                        xmlns:IFSF=\"http://www.ifsf.org/\"\n"
            "                        xmlns:xs=\"http://www.w3.org/2001/XMLSchema\"\n"
            "                        xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"\n"
            "                        xsi:schemaLocation=\".\\CardRequest.xsd\"\n"
            "                        RequestType=\"SafeDepositBegin\"\n"
            "                        ApplicationSender=\"POSeps01\"\n"
            "                        WorkstationID=\"POS\"\n"
            "                        RequestID=\"00016\">\n"
            "        <POSdata LanguageCode=\"en\">\n"
            "            <POSTimeStamp>2012-10-04T14:26:07+02:00</POSTimeStamp>\n"
            "            <OutdoorPosition>1</OutdoorPosition>\n"
            "            <Amount>999999999</Amount>\n"
            "        </POSdata>\n"
            "    </CardServiceRequest>\n";
    }
    else if(pb_5->isDown())
    {
        str="<?xml version=\"1.0\" encoding=\"utf-8\"?>\n"
            "    <CardServiceRequest xmlns=\"http://www.nrf-arts.org/IXRetail/namespace\"\n"
            "                        xmlns:IFSF=\"http://www.ifsf.org/\"\n"
            "                        xmlns:xs=\"http://www.w3.org/2001/XMLSchema\"\n"
            "                        xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"\n"
            "                        xsi:schemaLocation=\".\\CardRequest.xsd\"\n"
            "                        RequestType=\"SafeDepositEnd\"\n"
            "                        ApplicationSender=\"POSeps01\"\n"
            "                        WorkstationID=\"POS\"\n"
            "                        RequestID=\"00016\">\n"
            "        <POSdata LanguageCode=\"en\">\n"
            "            <POSTimeStamp>2012-10-04T14:26:07+02:00</POSTimeStamp>\n"
            "            <OutdoorPosition>1</OutdoorPosition>\n"
            "            <Number>123</Number>\n"
            "            <Info>RRN=78637823568976634</Info>\n"
            "        </POSdata>\n"
            "    </CardServiceRequest>\n";
    }
    else if(pb_6->isDown())
    {
        str="<?xml version=\"1.0\" encoding=\"utf-8\"?>\n"
            "    <CardServiceRequest xmlns=\"http://www.nrf-arts.org/IXRetail/namespace\"\n"
            "                        xmlns:IFSF=\"http://www.ifsf.org/\"\n"
            "                        xmlns:xs=\"http://www.w3.org/2001/XMLSchema\"\n"
            "                        xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"\n"
            "                        xsi:schemaLocation=\".\\CardRequest.xsd\"\n"
            "                        RequestType=\"SafeDepositInfo\"\n"
            "                        ApplicationSender=\"POSeps01\"\n"
            "                        WorkstationID=\"POS\"\n"
            "                        RequestID=\"00016\">\n"
            "        <POSdata LanguageCode=\"en\">\n"
            "            <POSTimeStamp>2012-10-04T14:26:07+02:00</POSTimeStamp>\n"
            "            <OutdoorPosition>1</OutdoorPosition>\n"
            "        </POSdata>\n"
            "    </CardServiceRequest>\n";
    }
    else if(pb_7->isDown())
    {
        str="<?xml version=\"1.0\" encoding=\"utf-8\"?>\n"
            "    <CardServiceRequest xmlns=\"http://www.nrf-arts.org/IXRetail/namespace\"\n"
            "                        xmlns:IFSF=\"http://www.ifsf.org/\"\n"
            "                        xmlns:xs=\"http://www.w3.org/2001/XMLSchema\"\n"
            "                        xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"\n"
            "                        xsi:schemaLocation=\".\\CardRequest.xsd\"\n"
            "                        RequestType=\"SafeDepositSum\"\n"
            "                        ApplicationSender=\"POSeps01\"\n"
            "                        WorkstationID=\"POS\"\n"
            "                        RequestID=\"00016\">\n"
            "        <POSdata LanguageCode=\"en\">\n"
            "            <POSTimeStamp>2012-10-04T14:26:07+02:00</POSTimeStamp>\n"
            "            <OutdoorPosition>1</OutdoorPosition>\n"
            "\n"
            "        </POSdata>\n"
            "    </CardServiceRequest>\n";
    }
    else if(pb_8->isDown())
    {
        str="<?xml version=\"1.0\" encoding=\"utf-8\"?>\n"
            "    <CardServiceRequest xmlns=\"http://www.nrf-arts.org/IXRetail/namespace\"\n"
            "                        xmlns:IFSF=\"http://www.ifsf.org/\"\n"
            "                        xmlns:xs=\"http://www.w3.org/2001/XMLSchema\"\n"
            "                        xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"\n"
            "                        xsi:schemaLocation=\".\\CardRequest.xsd\"\n"
            "                        RequestType=\"SafeTimeSet\"\n"
            "                        ApplicationSender=\"POSeps01\"\n"
            "                        WorkstationID=\"POS\"\n"
            "                        RequestID=\"00016\">\n"
            "        <POSdata LanguageCode=\"en\">\n"
            "            <POSTimeStamp>2012-10-04T14:26:07+02:00</POSTimeStamp>\n"
            "            <OutdoorPosition>1</OutdoorPosition>\n"
            "        </POSdata>\n"
            "    </CardServiceRequest>\n";
    }
    else if(pb_9->isDown())
    {
        str="<?xml version=\"1.0\" encoding=\"utf-8\"?>\n"
            "    <CardServiceRequest xmlns=\"http://www.nrf-arts.org/IXRetail/namespace\"\n"
            "                        xmlns:IFSF=\"http://www.ifsf.org/\"\n"
            "                        xmlns:xs=\"http://www.w3.org/2001/XMLSchema\"\n"
            "                        xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"\n"
            "                        xsi:schemaLocation=\".\\CardRequest.xsd\"\n"
            "                        RequestType=\"SafeTransactionWithOutBank\"\n"
            "                        ApplicationSender=\"POSeps01\"\n"
            "                        WorkstationID=\"POS\"\n"
            "                        RequestID=\"00016\">\n"
            "        <POSdata LanguageCode=\"en\">\n"
            "            <POSTimeStamp>2012-10-04T14:26:07+02:00</POSTimeStamp>\n"
            "            <OutdoorPosition>1</OutdoorPosition>\n"
            "        </POSdata>\n"
            "    </CardServiceRequest>\n";
    }
    te_send->setText(str);
}

void MainWindow::slotConnect()
{
    tcpSocket->connectToHost(le_ip->text(), quint16(le_port->text().toInt()));
}
void MainWindow::slotSend()
{
    //slotConnect();
    QByteArray buf;
    QString str= te_send->toPlainText().toUtf8();
    for(int i=0; i<str.length(); i++)
    {
        /*
        if((str.at(i)=='\n')||(str.at(i)=='\t'))
        {
            continue;
        }
        else
        {
            buf.append(str.at(i).toLatin1());
        }
        */
        buf.append(str.at(i).toLatin1());
    }
    uint32_t len=static_cast<uint32_t>(buf.length());
    static uint8_t const STX = '\x02';
    static uint8_t const ETX = '\x03';
    //static uint8_t const NAK = '\x15';
    int buffer_size  = buf.length() + 7;
    uint32_t  lrc =  0;
    char *buffer = new char[buffer_size];
    int sz=0;
    buffer[sz++] = STX;
    QString s = QString("%1").arg(buf.length()).rightJustified(4, '0');
    char bytes[4];
    bytes[0] = static_cast<char>(len%256);
    len=len/256;
    bytes[1] = static_cast<char>(len%256);
    len=len/256;
    bytes[2] = static_cast<char>(len%256);
    len=len/256;
    bytes[3] = static_cast<char>(len%256);

    //qDebug()<<"len"<<buf.length()<<"bytes"<< QString("%1").arg(static_cast<uint>(bytes[0]), 0, 16)<< QString("%1").arg(static_cast<uint>(bytes[1]), 0, 16)<< QString("%1").arg(static_cast<uint>(bytes[2]), 0, 16)<< QString("%1").arg(static_cast<uint>(bytes[3]), 0, 16);

    for(int k=0;k<4;k++){
        buffer[sz]= bytes[3-k];
        lrc ^=  static_cast<uint32_t>(buffer[sz]);
        sz++;
    }
    for (int k = 0; k < buf.length(); k++){
        buffer[sz]=static_cast<char>(buf.at(k));
        lrc ^= static_cast<uint32_t>(buffer[sz]);
        sz++;
    }
    buffer[sz++]=ETX;
    lrc ^= ETX;
    buffer[sz++]=static_cast<char>(lrc);
    tcpSocket->write(buffer,buffer_size);
    te_res->append("Отправлено:");
    te_res->append(QString::fromStdString(QByteArray(buffer,buffer_size-2).toStdString()).right(buffer_size-7));
    qDebug()<<QString("%1").arg(buffer, 0, 16);
}



void MainWindow::slotRead()
{
    QByteArray buf = tcpSocket->readAll();
    if(buf.length()==1)
    {
        if(buf.at(0)=='\x15')
        {
            te_res->append("NAK");
            return;
        }
    }
    te_res->append("Принято:");
    te_res->append(QString::fromStdString(buf.left(buf.length()-2).right(buf.length()-7).toStdString()));
}
void MainWindow::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError)
    {
        case QAbstractSocket::RemoteHostClosedError:
            break;
        case QAbstractSocket::HostNotFoundError:
            te_res->append(tr("The host was not found. Please check the "
                                        "host name and port settings."));
            break;
        case QAbstractSocket::ConnectionRefusedError:
            te_res->append(tr("The connection was refused by the peer. "
                                        "Make sure the fortune server is running, "
                                        "and check that the host name and port "
                                        "settings are correct."));
            break;
        default:
            te_res->append(tr("The following error occurred: %1.")
                                     .arg(tcpSocket->errorString()));
        }
}
void MainWindow::displayState(QAbstractSocket::SocketState socketState)
{
    l_status->clear();
    switch (socketState)
    {
    case QAbstractSocket::UnconnectedState:
        l_status->setText("The socket is not connected.");
        break;
    case QAbstractSocket::HostLookupState:
        l_status->setText("The socket is performing a host name lookup.");
        break;
    case QAbstractSocket::ConnectingState:
        l_status->setText("The socket has started establishing a connection.");
        break;
    case QAbstractSocket::ConnectedState:
        l_status->setText("A connection is established.");
        break;
    case QAbstractSocket::BoundState:
        l_status->setText("The socket is bound to an address and port.");
        break;
    case QAbstractSocket::ClosingState:
        l_status->setText("The socket is about to close (data may still be waiting to be written).");
        break;
    case QAbstractSocket::ListeningState:
        l_status->setText("For internal use only.");
        break;
    }
}
