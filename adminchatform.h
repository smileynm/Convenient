#ifndef ADMINCHATFORM_H
#define ADMINCHATFORM_H

#include <QWidget>
#include <qstandarditemmodel.h>     //*김민성* 목록 추가 기능
#include "chatserver.h"

namespace Ui {
class AdminChatForm;
}

class AdminChatForm : public QWidget
{
    Q_OBJECT

public:
    explicit AdminChatForm(QWidget *parent = nullptr);
    ~AdminChatForm();

private slots:
    void on_toolBox_currentChanged(int index);
    void on_joinButton_clicked();
    void on_sendButton_clicked();
    void updateChatView(const QString &message);

private:
    Ui::AdminChatForm *ui;
    QStandardItemModel *attendanceModel;    //*김민성* 접속시 사용자 목록 추가 기능
    ChatServer *m_chatServer;
};
#endif // ADMINCHATFORM_H
