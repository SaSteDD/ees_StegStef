/********************************************************************************
** Form generated from reading UI file 'stepdialog.ui'
**
** Created: Tue May 21 17:00:02 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STEPDIALOG_H
#define UI_STEPDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_StepDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QSpinBox *timeBox;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QSlider *QualitySlider;
    QLabel *label_2;
    QComboBox *TypeBox;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *StepDialog)
    {
        if (StepDialog->objectName().isEmpty())
            StepDialog->setObjectName(QString::fromUtf8("StepDialog"));
        StepDialog->resize(240, 138);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/nxt.png"), QSize(), QIcon::Normal, QIcon::Off);
        StepDialog->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(StepDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        timeBox = new QSpinBox(StepDialog);
        timeBox->setObjectName(QString::fromUtf8("timeBox"));
        timeBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        timeBox->setMinimum(3);
        timeBox->setMaximum(20);

        gridLayout->addWidget(timeBox, 3, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 1, 1, 1);

        label_3 = new QLabel(StepDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        QualitySlider = new QSlider(StepDialog);
        QualitySlider->setObjectName(QString::fromUtf8("QualitySlider"));
        QualitySlider->setMinimum(1);
        QualitySlider->setMaximum(4);
        QualitySlider->setPageStep(1);
        QualitySlider->setOrientation(Qt::Horizontal);
        QualitySlider->setInvertedAppearance(false);
        QualitySlider->setTickPosition(QSlider::TicksBelow);
        QualitySlider->setTickInterval(1);

        gridLayout->addWidget(QualitySlider, 2, 2, 1, 1);

        label_2 = new QLabel(StepDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        TypeBox = new QComboBox(StepDialog);
        TypeBox->setObjectName(QString::fromUtf8("TypeBox"));

        gridLayout->addWidget(TypeBox, 1, 2, 1, 1);

        label = new QLabel(StepDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(StepDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(StepDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), StepDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), StepDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(StepDialog);
    } // setupUi

    void retranslateUi(QDialog *StepDialog)
    {
        StepDialog->setWindowTitle(QApplication::translate("StepDialog", "neuer Schritt", 0, QApplication::UnicodeUTF8));
        timeBox->setSuffix(QApplication::translate("StepDialog", "s", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("StepDialog", "Bearbeitungszeit:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("StepDialog", "min. Qualit\303\244t:", 0, QApplication::UnicodeUTF8));
        TypeBox->clear();
        TypeBox->insertItems(0, QStringList()
         << QApplication::translate("StepDialog", "Bohren", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("StepDialog", "Drehen", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("StepDialog", "Fr\303\244sen", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("StepDialog", "Stationsart:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class StepDialog: public Ui_StepDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STEPDIALOG_H
