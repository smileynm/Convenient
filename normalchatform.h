#ifndef NORMALCHATFORM_H
#define NORMALCHATFORM_H

#include <QWidget>
#include <QTcpSocket>

namespace Ui {
class NormalChatForm;
}

class NormalChatForm : public QWidget {
    Q_OBJECT

public:
    explicit NormalChatForm(QWidget *parent = nullptr);
    ~NormalChatForm();

private slots:
    void on_toolBox_currentChanged(int index);
    void on_sendButton_clicked();

    // 네트워크 관련 슬롯
    void onConnected();
    void onDisconnected();
    void onReadyRead();

private:
    Ui::NormalChatForm *ui;
    QTcpSocket* socket;  // 네트워크 소켓
};

#endif // NORMALCHATFORM_H
