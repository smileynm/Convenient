#ifndef ADMINCHATFORM_H
#define ADMINCHATFORM_H

#include <QWidget>
#include <qstandarditemmodel.h>     //*김민성* 목록 추가 기능

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


private:
    Ui::AdminChatForm *ui;
    QStandardItemModel *attendanceModel;    //*김민성* 목록 추가 기능
};
#endif // ADMINCHATFORM_H
