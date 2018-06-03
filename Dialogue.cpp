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

#include "Dialogue.h"
#include <QtCore/qdebug.h>
#include <string>
#include "Tinker.h"

#define DEFAULT_WIDTH 300
#define DEFAULT_HEIGHT 140
#define BUTTON_WIDTH 100

Dialogue::Dialogue(QWidget *parent, std::string windowText,
                   std::string labelText, std::string defaultText,
                   std::string buttonText) : QMainWindow(parent)
{
	this->resize(DEFAULT_WIDTH, DEFAULT_HEIGHT);
	_tinker = NULL;

	this->setWindowTitle(windowText.c_str());

	lDialogue = new QLabel(this);
	lDialogue->setText(labelText.c_str());
	lDialogue->setGeometry(50, 20, 200, 30);
	lDialogue->show();

	tDialogue = new QLineEdit(this);
	tDialogue->setPlaceholderText(defaultText.c_str());
	tDialogue->setGeometry(50, 60, 200, 30);

	bDialogue = new QPushButton(buttonText.c_str(), this);
	bDialogue->setGeometry(75, 100, 150, 30);
	bDialogue->show();

	connect(bDialogue, SIGNAL(clicked()), this, SLOT(returnClicked()));
	connect(tDialogue, SIGNAL(editingFinished()),
	        this, SLOT(returnClicked()));
}

void Dialogue::returnClicked()
{
    QString qText = tDialogue->text();
    std::string text = qText.toStdString();
    
    if (_tinker)
    {
        _tinker->receiveDialogue(_type, text);
    }
}

void Dialogue::cleanup()
{
	tDialogue->disconnect();	
	tDialogue->deleteLater();
}

Dialogue::~Dialogue()
{
	delete lDialogue;
	delete bDialogue;
	
}
