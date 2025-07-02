/********************************************************************************
** Form generated from reading UI file 'wrong_id.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WRONG_ID_H
#define UI_WRONG_ID_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_wrong_id
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;

    void setupUi(QDialog *wrong_id)
    {
        if (wrong_id->objectName().isEmpty())
            wrong_id->setObjectName("wrong_id");
        wrong_id->resize(400, 152);
        buttonBox = new QDialogButtonBox(wrong_id);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 100, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        label = new QLabel(wrong_id);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 50, 200, 20));
        QFont font;
        font.setPointSize(10);
        font.setBold(false);
        label->setFont(font);

        retranslateUi(wrong_id);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, wrong_id, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, wrong_id, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(wrong_id);
    } // setupUi

    void retranslateUi(QDialog *wrong_id)
    {
        wrong_id->setWindowTitle(QCoreApplication::translate("wrong_id", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("wrong_id", "\354\236\230\353\252\273\353\220\234 \355\232\214\354\233\220\354\240\225\353\263\264 \354\236\205\353\213\210\353\213\244.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class wrong_id: public Ui_wrong_id {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WRONG_ID_H
