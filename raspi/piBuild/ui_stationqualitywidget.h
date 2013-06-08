/********************************************************************************
** Form generated from reading UI file 'stationqualitywidget.ui'
**
** Created: Tue May 21 17:00:01 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATIONQUALITYWIDGET_H
#define UI_STATIONQUALITYWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_stationSetup
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QSpinBox *spinBox;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QSlider *horizontalSlider;
    QLabel *label_2;
    QComboBox *comboBox;
    QLabel *label;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *stationSetup)
    {
        if (stationSetup->objectName().isEmpty())
            stationSetup->setObjectName(QString::fromUtf8("stationSetup"));
        stationSetup->resize(240, 151);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/nxt.png"), QSize(), QIcon::Normal, QIcon::Off);
        stationSetup->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(stationSetup);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(stationSetup);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox->setMinimum(3);
        spinBox->setMaximum(20);

        gridLayout->addWidget(spinBox, 3, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        horizontalSlider = new QSlider(groupBox);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setMinimum(1);
        horizontalSlider->setMaximum(4);
        horizontalSlider->setPageStep(1);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setInvertedAppearance(false);
        horizontalSlider->setTickPosition(QSlider::TicksBelow);
        horizontalSlider->setTickInterval(1);

        gridLayout->addWidget(horizontalSlider, 2, 2, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 1, 2, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        verticalLayout->addWidget(groupBox);


        retranslateUi(stationSetup);

        QMetaObject::connectSlotsByName(stationSetup);
    } // setupUi

    void retranslateUi(QWidget *stationSetup)
    {
        stationSetup->setWindowTitle(QApplication::translate("stationSetup", "Station", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("stationSetup", "GroupBox", 0, QApplication::UnicodeUTF8));
        spinBox->setSuffix(QApplication::translate("stationSetup", "s", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("stationSetup", "Bearbeitungszeit:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("stationSetup", "Qualit\303\244t:", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("stationSetup", "Bohren", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("stationSetup", "Drehen", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("stationSetup", "Fr\303\244sen", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("stationSetup", "Stationsart:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class stationSetup: public Ui_stationSetup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATIONQUALITYWIDGET_H
