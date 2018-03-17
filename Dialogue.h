//
//  QTinker.h
//  Windexing
//
//  Created by Helen Ginn on 11/12/2016.
//  Copyright (c) 2017 Helen Ginn. All rights reserved.
//

#ifndef __Windexing__QUnitCell__
#define __Windexing__QUnitCell__

#include <stdio.h>

#include <QtWidgets/qwidget.h>
#include <QtCore/qglobal.h>
#include <QtWidgets/qapplication.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qmainwindow.h>

class Tinker;

typedef enum
{
    DialogueUndefined,
    DialogueUnitCell,
    DialogueBringAxis,
    DialogueBeamCentre,
    DialogueResolution,
    DialogueDistance,
    DialogueWavelength,
    DialogueRlpSize,
    DialogueDegreeStep,
} DialogueType;

class Dialogue : public QMainWindow
{
    Q_OBJECT
    
public:
    Dialogue(QWidget *parent = 0, std::string windowText = "",
             std::string labelText = "", std::string defaultText = "",
             std::string buttonText = "");
    QPushButton *bDialogue;
    QLineEdit *tDialogue;
    QLabel *lDialogue;

    ~Dialogue();
    
    void setTinker(Tinker *tinker)
    {
        _tinker = tinker;
    }
    
    void setTag(DialogueType type)
    {
        _type = type;
    }

	void cleanup();
private slots:
    void returnClicked();

private:
    Tinker *_tinker;
    DialogueType _type;
};

#endif /* defined(__CaroCode__QTinker__) */
