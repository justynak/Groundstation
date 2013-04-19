/********************************************************************************
** Form generated from reading UI file 'scada.ui'
**
** Created: Sat Apr 20 00:13:47 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCADA_H
#define UI_SCADA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SCADA
{
public:
    QLabel *labelUp;
    QLabel *labelSide;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label_10;
    QLabel *label_9;
    QLabel *label_8;
    QLabel *label;
    QLabel *label_11;
    QLabel *label_7;
    QLabel *label_6;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_3;
    QFormLayout *formLayout;
    QSlider *sliderBatteryU;
    QSlider *sliderBatteryI;
    QSpacerItem *verticalSpacer;
    QSlider *sliderEngine0I;
    QSlider *sliderEngine0w;
    QSpacerItem *verticalSpacer_2;
    QSlider *sliderEngine1I;
    QSlider *sliderEngine1w;
    QSpacerItem *verticalSpacer_3;
    QSlider *sliderEngine2I;
    QSlider *sliderEngine2w;
    QSpacerItem *verticalSpacer_4;
    QSlider *sliderEngine3I;
    QSlider *sliderEngine3w;
    QSpacerItem *verticalSpacer_5;
    QSlider *sliderCylinderI;
    QSlider *sliderCylinderw;
    QSpacerItem *verticalSpacer_6;
    QSlider *sliderTensometer0;
    QSlider *sliderTensometer1;
    QSpacerItem *verticalSpacer_7;
    QSlider *sliderMass;
    QSlider *sliderElectromagnet;
    QSpacerItem *verticalSpacer_8;
    QSlider *sliderCylinderOpen;
    QSlider *horizontalSlider;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *SCADA)
    {
        if (SCADA->objectName().isEmpty())
            SCADA->setObjectName(QString::fromUtf8("SCADA"));
        SCADA->resize(1076, 509);
        labelUp = new QLabel(SCADA);
        labelUp->setObjectName(QString::fromUtf8("labelUp"));
        labelUp->setGeometry(QRect(30, 20, 361, 221));
        labelSide = new QLabel(SCADA);
        labelSide->setObjectName(QString::fromUtf8("labelSide"));
        labelSide->setGeometry(QRect(30, 247, 361, 241));
        horizontalLayoutWidget = new QWidget(SCADA);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(420, 40, 301, 437));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_10 = new QLabel(horizontalLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout->addWidget(label_10);

        label_9 = new QLabel(horizontalLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout->addWidget(label_9);

        label_8 = new QLabel(horizontalLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout->addWidget(label_8);

        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_11 = new QLabel(horizontalLayoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout->addWidget(label_11);

        label_7 = new QLabel(horizontalLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout->addWidget(label_7);

        label_6 = new QLabel(horizontalLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout->addWidget(label_6);

        label_5 = new QLabel(horizontalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);

        label_4 = new QLabel(horizontalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        sliderBatteryU = new QSlider(horizontalLayoutWidget);
        sliderBatteryU->setObjectName(QString::fromUtf8("sliderBatteryU"));
        sliderBatteryU->setMaximum(255);
        sliderBatteryU->setTracking(false);
        sliderBatteryU->setOrientation(Qt::Horizontal);

        formLayout->setWidget(0, QFormLayout::LabelRole, sliderBatteryU);

        sliderBatteryI = new QSlider(horizontalLayoutWidget);
        sliderBatteryI->setObjectName(QString::fromUtf8("sliderBatteryI"));
        sliderBatteryI->setMaximum(255);
        sliderBatteryI->setOrientation(Qt::Horizontal);

        formLayout->setWidget(0, QFormLayout::FieldRole, sliderBatteryI);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(1, QFormLayout::LabelRole, verticalSpacer);

        sliderEngine0I = new QSlider(horizontalLayoutWidget);
        sliderEngine0I->setObjectName(QString::fromUtf8("sliderEngine0I"));
        sliderEngine0I->setMaximum(255);
        sliderEngine0I->setOrientation(Qt::Horizontal);

        formLayout->setWidget(2, QFormLayout::LabelRole, sliderEngine0I);

        sliderEngine0w = new QSlider(horizontalLayoutWidget);
        sliderEngine0w->setObjectName(QString::fromUtf8("sliderEngine0w"));
        sliderEngine0w->setMaximum(255);
        sliderEngine0w->setOrientation(Qt::Horizontal);

        formLayout->setWidget(2, QFormLayout::FieldRole, sliderEngine0w);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(3, QFormLayout::LabelRole, verticalSpacer_2);

        sliderEngine1I = new QSlider(horizontalLayoutWidget);
        sliderEngine1I->setObjectName(QString::fromUtf8("sliderEngine1I"));
        sliderEngine1I->setMaximum(255);
        sliderEngine1I->setOrientation(Qt::Horizontal);

        formLayout->setWidget(4, QFormLayout::LabelRole, sliderEngine1I);

        sliderEngine1w = new QSlider(horizontalLayoutWidget);
        sliderEngine1w->setObjectName(QString::fromUtf8("sliderEngine1w"));
        sliderEngine1w->setMaximum(255);
        sliderEngine1w->setOrientation(Qt::Horizontal);

        formLayout->setWidget(4, QFormLayout::FieldRole, sliderEngine1w);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(5, QFormLayout::LabelRole, verticalSpacer_3);

        sliderEngine2I = new QSlider(horizontalLayoutWidget);
        sliderEngine2I->setObjectName(QString::fromUtf8("sliderEngine2I"));
        sliderEngine2I->setMaximum(255);
        sliderEngine2I->setOrientation(Qt::Horizontal);

        formLayout->setWidget(6, QFormLayout::LabelRole, sliderEngine2I);

        sliderEngine2w = new QSlider(horizontalLayoutWidget);
        sliderEngine2w->setObjectName(QString::fromUtf8("sliderEngine2w"));
        sliderEngine2w->setMaximum(255);
        sliderEngine2w->setOrientation(Qt::Horizontal);

        formLayout->setWidget(6, QFormLayout::FieldRole, sliderEngine2w);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(7, QFormLayout::LabelRole, verticalSpacer_4);

        sliderEngine3I = new QSlider(horizontalLayoutWidget);
        sliderEngine3I->setObjectName(QString::fromUtf8("sliderEngine3I"));
        sliderEngine3I->setMaximum(255);
        sliderEngine3I->setOrientation(Qt::Horizontal);

        formLayout->setWidget(8, QFormLayout::LabelRole, sliderEngine3I);

        sliderEngine3w = new QSlider(horizontalLayoutWidget);
        sliderEngine3w->setObjectName(QString::fromUtf8("sliderEngine3w"));
        sliderEngine3w->setMaximum(255);
        sliderEngine3w->setOrientation(Qt::Horizontal);

        formLayout->setWidget(8, QFormLayout::FieldRole, sliderEngine3w);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(10, QFormLayout::LabelRole, verticalSpacer_5);

        sliderCylinderI = new QSlider(horizontalLayoutWidget);
        sliderCylinderI->setObjectName(QString::fromUtf8("sliderCylinderI"));
        sliderCylinderI->setMaximum(255);
        sliderCylinderI->setOrientation(Qt::Horizontal);

        formLayout->setWidget(11, QFormLayout::LabelRole, sliderCylinderI);

        sliderCylinderw = new QSlider(horizontalLayoutWidget);
        sliderCylinderw->setObjectName(QString::fromUtf8("sliderCylinderw"));
        sliderCylinderw->setMaximum(255);
        sliderCylinderw->setOrientation(Qt::Horizontal);

        formLayout->setWidget(11, QFormLayout::FieldRole, sliderCylinderw);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(12, QFormLayout::LabelRole, verticalSpacer_6);

        sliderTensometer0 = new QSlider(horizontalLayoutWidget);
        sliderTensometer0->setObjectName(QString::fromUtf8("sliderTensometer0"));
        sliderTensometer0->setMaximum(255);
        sliderTensometer0->setOrientation(Qt::Horizontal);

        formLayout->setWidget(13, QFormLayout::LabelRole, sliderTensometer0);

        sliderTensometer1 = new QSlider(horizontalLayoutWidget);
        sliderTensometer1->setObjectName(QString::fromUtf8("sliderTensometer1"));
        sliderTensometer1->setMaximum(255);
        sliderTensometer1->setOrientation(Qt::Horizontal);

        formLayout->setWidget(13, QFormLayout::FieldRole, sliderTensometer1);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(14, QFormLayout::LabelRole, verticalSpacer_7);

        sliderMass = new QSlider(horizontalLayoutWidget);
        sliderMass->setObjectName(QString::fromUtf8("sliderMass"));
        sliderMass->setMaximum(255);
        sliderMass->setOrientation(Qt::Horizontal);

        formLayout->setWidget(15, QFormLayout::LabelRole, sliderMass);

        sliderElectromagnet = new QSlider(horizontalLayoutWidget);
        sliderElectromagnet->setObjectName(QString::fromUtf8("sliderElectromagnet"));
        sliderElectromagnet->setMaximum(1);
        sliderElectromagnet->setOrientation(Qt::Horizontal);

        formLayout->setWidget(16, QFormLayout::LabelRole, sliderElectromagnet);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(17, QFormLayout::LabelRole, verticalSpacer_8);

        sliderCylinderOpen = new QSlider(horizontalLayoutWidget);
        sliderCylinderOpen->setObjectName(QString::fromUtf8("sliderCylinderOpen"));
        sliderCylinderOpen->setMaximum(1);
        sliderCylinderOpen->setOrientation(Qt::Horizontal);

        formLayout->setWidget(18, QFormLayout::LabelRole, sliderCylinderOpen);

        horizontalSlider = new QSlider(horizontalLayoutWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setMaximum(1);
        horizontalSlider->setOrientation(Qt::Horizontal);

        formLayout->setWidget(9, QFormLayout::LabelRole, horizontalSlider);


        horizontalLayout->addLayout(formLayout);

        textBrowser = new QTextBrowser(SCADA);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(750, 40, 291, 441));

        retranslateUi(SCADA);

        QMetaObject::connectSlotsByName(SCADA);
    } // setupUi

    void retranslateUi(QWidget *SCADA)
    {
        SCADA->setWindowTitle(QApplication::translate("SCADA", "Form", 0, QApplication::UnicodeUTF8));
        labelUp->setText(QApplication::translate("SCADA", "UP", 0, QApplication::UnicodeUTF8));
        labelSide->setText(QApplication::translate("SCADA", "SIDE", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SCADA", "Akumulator U/I", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("SCADA", "Silnik 0 I/w", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("SCADA", "Silnik 1 I/w", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("SCADA", "Silnik 2 I/w", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SCADA", "Silnik 3 I/w", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("SCADA", "Arm position", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("SCADA", "B\304\231ben I/w", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("SCADA", "Tensometry 1/2", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("SCADA", "Masa", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("SCADA", "Elektromagnes", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SCADA", "Otwarcie b\304\231bna", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SCADA: public Ui_SCADA {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCADA_H
