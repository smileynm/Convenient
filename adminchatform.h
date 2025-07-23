#ifndef ADMINCHATFORM_H
#define ADMINCHATFORM_H

#include <QWidget>
#include <QTcpSocket>

namespace Ui {
class AdminChatForm;
}

class AdminChatForm : public QWidget {
    Q_OBJECT

public:
    explicit AdminChatForm(QWidget *parent = nullptr);
    ~AdminChatForm();

private slots:
    void on_toolBox_currentChanged(int index);
    void on_sendButton_clicked();

    // 네트워크 관련 슬롯
    void onConnected();
    void onDisconnected();
    void onReadyRead();

private:
    Ui::AdminChatForm *ui;
    QTcpSocket* socket;  // 네트워크 소켓
};

#endif // ADMINCHATFORM_H
