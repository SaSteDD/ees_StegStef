/********************************************************************************
** Form generated from reading UI file 'btwahl.ui'
**
** Created: Tue May 21 17:00:01 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BTWAHL_H
#define UI_BTWAHL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_btDeviceDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *btSearchButton;
    QSpacerItem *horizontalSpacer;
    QProgressBar *progressBar;
    QSpacerItem *verticalSpacer;
    QComboBox *btDeviceSelector;
    QSpacerItem *verticalSpacer_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *btDeviceDialog)
    {
        if (btDeviceDialog->objectName().isEmpty())
            btDeviceDialog->setObjectName(QString::fromUtf8("btDeviceDialog"));
        btDeviceDialog->resize(320, 123);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/nxt.png"), QSize(), QIcon::Normal, QIcon::Off);
        btDeviceDialog->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(btDeviceDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btSearchButton = new QPushButton(btDeviceDialog);
        btSearchButton->setObjectName(QString::fromUtf8("btSearchButton"));
        btSearchButton->setEnabled(true);

        horizontalLayout->addWidget(btSearchButton);

        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        progressBar = new QProgressBar(btDeviceDialog);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setEnabled(false);
        progressBar->setMinimum(0);
        progressBar->setMaximum(1);
        progressBar->setValue(0);
        progressBar->setTextVisible(false);

        horizontalLayout->addWidget(progressBar);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        btDeviceSelector = new QComboBox(btDeviceDialog);
        btDeviceSelector->setObjectName(QString::fromUtf8("btDeviceSelector"));
        btDeviceSelector->setEnabled(false);

        verticalLayout->addWidget(btDeviceSelector);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        buttonBox = new QDialogButtonBox(btDeviceDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setEnabled(true);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(btDeviceDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), btDeviceDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), btDeviceDialog, SLOT(reject()));
        QObject::connect(btSearchButton, SIGNAL(clicked()), btDeviceDialog, SLOT(discoverBtDevices()));

        QMetaObject::connectSlotsByName(btDeviceDialog);
    } // setupUi

    void retranslateUi(QDialog *btDeviceDialog)
    {
        btDeviceDialog->setWindowTitle(QApplication::translate("btDeviceDialog", "Bluetooth Auswahl", 0, QApplication::UnicodeUTF8));
        btSearchButton->setText(QApplication::translate("btDeviceDialog", "Suchen...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class btDeviceDialog: public Ui_btDeviceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BTWAHL_H
