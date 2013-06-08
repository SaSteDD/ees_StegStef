/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun May 26 19:47:13 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "loggerwidget.h"
#include "trackview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *stationSetupGroupBox;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *station1GroupBox;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout_2;
    QSlider *station1Quality;
    QLabel *label_5;
    QComboBox *station1Type;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_5;
    QGroupBox *station2GroupBox;
    QVBoxLayout *verticalLayout_5;
    QGridLayout *gridLayout_3;
    QSlider *station2Quality;
    QLabel *label_8;
    QComboBox *station2Type;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_6;
    QGroupBox *station3GroupBox;
    QVBoxLayout *verticalLayout_6;
    QGridLayout *gridLayout_4;
    QSpacerItem *horizontalSpacer_7;
    QSlider *station3Quality;
    QLabel *label_11;
    QComboBox *station3Type;
    QLabel *label_12;
    QGroupBox *station4GroupBox;
    QVBoxLayout *verticalLayout_7;
    QGridLayout *gridLayout_5;
    QSpacerItem *horizontalSpacer_8;
    QSlider *station4Quality;
    QLabel *label_14;
    QComboBox *station4Type;
    QLabel *label_15;
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *setupGroupBox;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *btDeviceLabel;
    QPushButton *setupBtDeviceButton;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *taskSetupButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *nxtStopButton;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *startStopButton;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *protocolLogGroupBox;
    QVBoxLayout *verticalLayout_2;
    LoggerWidget *log;
    QGroupBox *trackViewGroupBox;
    QHBoxLayout *horizontalLayout_4;
    TrackView *trackView;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(829, 719);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/nxt.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(MainWindow);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        stationSetupGroupBox = new QGroupBox(MainWindow);
        stationSetupGroupBox->setObjectName(QString::fromUtf8("stationSetupGroupBox"));
        horizontalLayout_2 = new QHBoxLayout(stationSetupGroupBox);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        station1GroupBox = new QGroupBox(stationSetupGroupBox);
        station1GroupBox->setObjectName(QString::fromUtf8("station1GroupBox"));
        verticalLayout_4 = new QVBoxLayout(station1GroupBox);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        station1Quality = new QSlider(station1GroupBox);
        station1Quality->setObjectName(QString::fromUtf8("station1Quality"));
        station1Quality->setMinimum(1);
        station1Quality->setMaximum(4);
        station1Quality->setPageStep(1);
        station1Quality->setOrientation(Qt::Horizontal);
        station1Quality->setInvertedAppearance(false);
        station1Quality->setTickPosition(QSlider::TicksBelow);
        station1Quality->setTickInterval(1);

        gridLayout_2->addWidget(station1Quality, 2, 2, 1, 1);

        label_5 = new QLabel(station1GroupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 2, 0, 1, 1);

        station1Type = new QComboBox(station1GroupBox);
        station1Type->setObjectName(QString::fromUtf8("station1Type"));

        gridLayout_2->addWidget(station1Type, 1, 2, 1, 1);

        label_6 = new QLabel(station1GroupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 1, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 2, 1, 1, 1);


        verticalLayout_4->addLayout(gridLayout_2);


        horizontalLayout_2->addWidget(station1GroupBox);

        station2GroupBox = new QGroupBox(stationSetupGroupBox);
        station2GroupBox->setObjectName(QString::fromUtf8("station2GroupBox"));
        verticalLayout_5 = new QVBoxLayout(station2GroupBox);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        station2Quality = new QSlider(station2GroupBox);
        station2Quality->setObjectName(QString::fromUtf8("station2Quality"));
        station2Quality->setMinimum(1);
        station2Quality->setMaximum(4);
        station2Quality->setPageStep(1);
        station2Quality->setOrientation(Qt::Horizontal);
        station2Quality->setInvertedAppearance(false);
        station2Quality->setTickPosition(QSlider::TicksBelow);
        station2Quality->setTickInterval(1);

        gridLayout_3->addWidget(station2Quality, 2, 2, 1, 1);

        label_8 = new QLabel(station2GroupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_3->addWidget(label_8, 2, 0, 1, 1);

        station2Type = new QComboBox(station2GroupBox);
        station2Type->setObjectName(QString::fromUtf8("station2Type"));

        gridLayout_3->addWidget(station2Type, 1, 2, 1, 1);

        label_9 = new QLabel(station2GroupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_3->addWidget(label_9, 1, 0, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_6, 2, 1, 1, 1);


        verticalLayout_5->addLayout(gridLayout_3);


        horizontalLayout_2->addWidget(station2GroupBox);

        station3GroupBox = new QGroupBox(stationSetupGroupBox);
        station3GroupBox->setObjectName(QString::fromUtf8("station3GroupBox"));
        verticalLayout_6 = new QVBoxLayout(station3GroupBox);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_7, 2, 1, 1, 1);

        station3Quality = new QSlider(station3GroupBox);
        station3Quality->setObjectName(QString::fromUtf8("station3Quality"));
        station3Quality->setMinimum(1);
        station3Quality->setMaximum(4);
        station3Quality->setPageStep(1);
        station3Quality->setOrientation(Qt::Horizontal);
        station3Quality->setInvertedAppearance(false);
        station3Quality->setTickPosition(QSlider::TicksBelow);
        station3Quality->setTickInterval(1);

        gridLayout_4->addWidget(station3Quality, 2, 2, 1, 1);

        label_11 = new QLabel(station3GroupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_4->addWidget(label_11, 2, 0, 1, 1);

        station3Type = new QComboBox(station3GroupBox);
        station3Type->setObjectName(QString::fromUtf8("station3Type"));

        gridLayout_4->addWidget(station3Type, 1, 2, 1, 1);

        label_12 = new QLabel(station3GroupBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_4->addWidget(label_12, 1, 0, 1, 1);


        verticalLayout_6->addLayout(gridLayout_4);


        horizontalLayout_2->addWidget(station3GroupBox);

        station4GroupBox = new QGroupBox(stationSetupGroupBox);
        station4GroupBox->setObjectName(QString::fromUtf8("station4GroupBox"));
        verticalLayout_7 = new QVBoxLayout(station4GroupBox);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_8, 2, 1, 1, 1);

        station4Quality = new QSlider(station4GroupBox);
        station4Quality->setObjectName(QString::fromUtf8("station4Quality"));
        station4Quality->setMinimum(1);
        station4Quality->setMaximum(4);
        station4Quality->setPageStep(1);
        station4Quality->setOrientation(Qt::Horizontal);
        station4Quality->setInvertedAppearance(false);
        station4Quality->setTickPosition(QSlider::TicksBelow);
        station4Quality->setTickInterval(1);

        gridLayout_5->addWidget(station4Quality, 2, 2, 1, 1);

        label_14 = new QLabel(station4GroupBox);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_5->addWidget(label_14, 2, 0, 1, 1);

        station4Type = new QComboBox(station4GroupBox);
        station4Type->setObjectName(QString::fromUtf8("station4Type"));

        gridLayout_5->addWidget(station4Type, 1, 2, 1, 1);

        label_15 = new QLabel(station4GroupBox);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_5->addWidget(label_15, 1, 0, 1, 1);


        verticalLayout_7->addLayout(gridLayout_5);


        horizontalLayout_2->addWidget(station4GroupBox);


        verticalLayout->addWidget(stationSetupGroupBox);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        setupGroupBox = new QGroupBox(MainWindow);
        setupGroupBox->setObjectName(QString::fromUtf8("setupGroupBox"));
        setupGroupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        verticalLayout_3 = new QVBoxLayout(setupGroupBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        btDeviceLabel = new QLabel(setupGroupBox);
        btDeviceLabel->setObjectName(QString::fromUtf8("btDeviceLabel"));
        btDeviceLabel->setMinimumSize(QSize(200, 0));

        horizontalLayout_6->addWidget(btDeviceLabel);

        setupBtDeviceButton = new QPushButton(setupGroupBox);
        setupBtDeviceButton->setObjectName(QString::fromUtf8("setupBtDeviceButton"));
        setupBtDeviceButton->setMinimumSize(QSize(60, 32));

        horizontalLayout_6->addWidget(setupBtDeviceButton);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_9);

        taskSetupButton = new QPushButton(setupGroupBox);
        taskSetupButton->setObjectName(QString::fromUtf8("taskSetupButton"));
        taskSetupButton->setMinimumSize(QSize(48, 32));

        horizontalLayout_6->addWidget(taskSetupButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        nxtStopButton = new QPushButton(setupGroupBox);
        nxtStopButton->setObjectName(QString::fromUtf8("nxtStopButton"));
        nxtStopButton->setEnabled(false);
        nxtStopButton->setMinimumSize(QSize(100, 32));
        nxtStopButton->setMaximumSize(QSize(100, 16777215));
        nxtStopButton->setIcon(icon);

        horizontalLayout_6->addWidget(nxtStopButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_10);

        startStopButton = new QPushButton(setupGroupBox);
        startStopButton->setObjectName(QString::fromUtf8("startStopButton"));
        startStopButton->setMinimumSize(QSize(100, 32));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/media-playback-start.svg"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/icons/media-playback-stop.svg"), QSize(), QIcon::Normal, QIcon::On);
        icon1.addFile(QString::fromUtf8(":/icons/media-playback-start.svg"), QSize(), QIcon::Disabled, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/icons/media-playback-stop.svg"), QSize(), QIcon::Disabled, QIcon::On);
        icon1.addFile(QString::fromUtf8(":/icons/media-playback-start.svg"), QSize(), QIcon::Active, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/icons/media-playback-stop.svg"), QSize(), QIcon::Active, QIcon::On);
        icon1.addFile(QString::fromUtf8(":/icons/media-playback-start.svg"), QSize(), QIcon::Selected, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/icons/media-playback-stop.svg"), QSize(), QIcon::Selected, QIcon::On);
        startStopButton->setIcon(icon1);
        startStopButton->setIconSize(QSize(16, 16));
        startStopButton->setCheckable(false);
        startStopButton->setChecked(false);

        horizontalLayout_6->addWidget(startStopButton);


        verticalLayout_3->addLayout(horizontalLayout_6);


        horizontalLayout_5->addWidget(setupGroupBox);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        protocolLogGroupBox = new QGroupBox(MainWindow);
        protocolLogGroupBox->setObjectName(QString::fromUtf8("protocolLogGroupBox"));
        verticalLayout_2 = new QVBoxLayout(protocolLogGroupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        log = new LoggerWidget(protocolLogGroupBox);
        log->setObjectName(QString::fromUtf8("log"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(2);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(log->sizePolicy().hasHeightForWidth());
        log->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(log);


        horizontalLayout_3->addWidget(protocolLogGroupBox);

        trackViewGroupBox = new QGroupBox(MainWindow);
        trackViewGroupBox->setObjectName(QString::fromUtf8("trackViewGroupBox"));
        trackViewGroupBox->setEnabled(true);
        horizontalLayout_4 = new QHBoxLayout(trackViewGroupBox);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        trackView = new TrackView(trackViewGroupBox);
        trackView->setObjectName(QString::fromUtf8("trackView"));
        trackView->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(trackView->sizePolicy().hasHeightForWidth());
        trackView->setSizePolicy(sizePolicy1);
        trackView->setPixmap(QPixmap(QString::fromUtf8(":/streckenPics/fahrplan_nxt.svg")));

        horizontalLayout_4->addWidget(trackView);


        horizontalLayout_3->addWidget(trackViewGroupBox);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(MainWindow);
        QObject::connect(taskSetupButton, SIGNAL(clicked()), MainWindow, SLOT(runTaskSetup()));
        QObject::connect(setupBtDeviceButton, SIGNAL(clicked()), MainWindow, SLOT(runBtSetup()));
        QObject::connect(startStopButton, SIGNAL(clicked()), MainWindow, SLOT(runBtCom()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "NXT-Steuerung", 0, QApplication::UnicodeUTF8));
        stationSetupGroupBox->setTitle(QApplication::translate("MainWindow", "Stationseigenschaften", 0, QApplication::UnicodeUTF8));
        station1GroupBox->setTitle(QApplication::translate("MainWindow", "Station 1", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Qualit\303\244t:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Stationsart:", 0, QApplication::UnicodeUTF8));
        station2GroupBox->setTitle(QApplication::translate("MainWindow", "Station 2", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "Qualit\303\244t:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "Stationsart:", 0, QApplication::UnicodeUTF8));
        station3GroupBox->setTitle(QApplication::translate("MainWindow", "Station 3", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "Qualit\303\244t:", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "Stationsart:", 0, QApplication::UnicodeUTF8));
        station4GroupBox->setTitle(QApplication::translate("MainWindow", "Station 4", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "Qualit\303\244t:", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MainWindow", "Stationsart:", 0, QApplication::UnicodeUTF8));
        setupGroupBox->setTitle(QApplication::translate("MainWindow", "Einstellungen", 0, QApplication::UnicodeUTF8));
        btDeviceLabel->setText(QApplication::translate("MainWindow", "(kein Bt-Ger\303\244t ausgew\303\244hlt)", 0, QApplication::UnicodeUTF8));
        setupBtDeviceButton->setText(QApplication::translate("MainWindow", "Ger\303\244t \303\244ndern", 0, QApplication::UnicodeUTF8));
        taskSetupButton->setText(QApplication::translate("MainWindow", "Auftrag \303\244ndern", 0, QApplication::UnicodeUTF8));
        nxtStopButton->setText(QApplication::translate("MainWindow", "NXT Stopp", 0, QApplication::UnicodeUTF8));
        startStopButton->setText(QApplication::translate("MainWindow", "Start", 0, QApplication::UnicodeUTF8));
        startStopButton->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        protocolLogGroupBox->setTitle(QApplication::translate("MainWindow", "Protokoll-Log", 0, QApplication::UnicodeUTF8));
        trackViewGroupBox->setTitle(QApplication::translate("MainWindow", "Stations\303\274bersicht", 0, QApplication::UnicodeUTF8));
        trackView->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
