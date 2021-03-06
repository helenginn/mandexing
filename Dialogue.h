// Mandexing: a manual indexing program for crystallographic data.
// Copyright (C) 2017-2018 Helen Ginn
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.
// 
// Please email: vagabond @ hginn.co.uk for more details.

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
