/********************************************************************************
** Form generated from reading UI file 'taskdialog.ui'
**
** Created: Wed May 22 21:06:44 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKDIALOG_H
#define UI_TASKDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include "taskdialogtablewidget.h"

QT_BEGIN_NAMESPACE

class Ui_TaskDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QSpinBox *taskNum;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QGroupBox *taskStepGroupBox;
    QHBoxLayout *horizontalLayout_2;
    TaskDialogTableWidget *taskTable;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_2;
    QPushButton *stepUpButton;
    QPushButton *stepAddButton;
    QPushButton *stepDeleteButton;
    QPushButton *stepDownButton;
    QSpacerItem *verticalSpacer_3;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *TaskDialog)
    {
        if (TaskDialog->objectName().isEmpty())
            TaskDialog->setObjectName(QString::fromUtf8("TaskDialog"));
        TaskDialog->resize(431, 284);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/nxt.png"), QSize(), QIcon::Normal, QIcon::Off);
        TaskDialog->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(TaskDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(TaskDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        taskNum = new QSpinBox(TaskDialog);
        taskNum->setObjectName(QString::fromUtf8("taskNum"));
        taskNum->setMinimum(1);
        taskNum->setValue(30);

        horizontalLayout->addWidget(taskNum);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        taskStepGroupBox = new QGroupBox(TaskDialog);
        taskStepGroupBox->setObjectName(QString::fromUtf8("taskStepGroupBox"));
        taskStepGroupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        horizontalLayout_2 = new QHBoxLayout(taskStepGroupBox);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        taskTable = new TaskDialogTableWidget(taskStepGroupBox);
        if (taskTable->columnCount() < 3)
            taskTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        taskTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        taskTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        taskTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        taskTable->setObjectName(QString::fromUtf8("taskTable"));
        taskTable->horizontalHeader()->setDefaultSectionSize(90);
        taskTable->horizontalHeader()->setMinimumSectionSize(60);

        horizontalLayout_2->addWidget(taskTable);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        stepUpButton = new QPushButton(taskStepGroupBox);
        stepUpButton->setObjectName(QString::fromUtf8("stepUpButton"));
        stepUpButton->setMinimumSize(QSize(32, 32));
        stepUpButton->setBaseSize(QSize(40, 40));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/go-up.svg"), QSize(), QIcon::Normal, QIcon::Off);
        stepUpButton->setIcon(icon1);

        verticalLayout_3->addWidget(stepUpButton);

        stepAddButton = new QPushButton(taskStepGroupBox);
        stepAddButton->setObjectName(QString::fromUtf8("stepAddButton"));
        stepAddButton->setMinimumSize(QSize(32, 32));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/list-add.svg"), QSize(), QIcon::Normal, QIcon::Off);
        stepAddButton->setIcon(icon2);

        verticalLayout_3->addWidget(stepAddButton);

        stepDeleteButton = new QPushButton(taskStepGroupBox);
        stepDeleteButton->setObjectName(QString::fromUtf8("stepDeleteButton"));
        stepDeleteButton->setMinimumSize(QSize(32, 32));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/list-remove.svg"), QSize(), QIcon::Normal, QIcon::Off);
        stepDeleteButton->setIcon(icon3);

        verticalLayout_3->addWidget(stepDeleteButton);

        stepDownButton = new QPushButton(taskStepGroupBox);
        stepDownButton->setObjectName(QString::fromUtf8("stepDownButton"));
        stepDownButton->setMinimumSize(QSize(32, 32));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/go-down.svg"), QSize(), QIcon::Normal, QIcon::Off);
        stepDownButton->setIcon(icon4);

        verticalLayout_3->addWidget(stepDownButton);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);


        horizontalLayout_2->addLayout(verticalLayout_3);


        verticalLayout->addWidget(taskStepGroupBox);

        buttonBox = new QDialogButtonBox(TaskDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(TaskDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), TaskDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), TaskDialog, SLOT(reject()));
        QObject::connect(stepUpButton, SIGNAL(clicked()), taskTable, SLOT(moveCurrentRowUp()));
        QObject::connect(stepAddButton, SIGNAL(clicked()), taskTable, SLOT(addRow()));
        QObject::connect(stepDeleteButton, SIGNAL(clicked()), taskTable, SLOT(removeRow()));
        QObject::connect(stepDownButton, SIGNAL(clicked()), taskTable, SLOT(moveCurrentRowDown()));

        QMetaObject::connectSlotsByName(TaskDialog);
    } // setupUi

    void retranslateUi(QDialog *TaskDialog)
    {
        TaskDialog->setWindowTitle(QApplication::translate("TaskDialog", "Auftrag festlegen", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("TaskDialog", "Auftragsnummer:", 0, QApplication::UnicodeUTF8));
        taskStepGroupBox->setTitle(QApplication::translate("TaskDialog", "Schritte:", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = taskTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("TaskDialog", "Typ", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = taskTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("TaskDialog", "min. Qualit\303\244t", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = taskTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("TaskDialog", "Zeit", 0, QApplication::UnicodeUTF8));
        stepUpButton->setText(QString());
        stepAddButton->setText(QString());
        stepDeleteButton->setText(QString());
        stepDownButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TaskDialog: public Ui_TaskDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKDIALOG_H
