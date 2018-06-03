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

#include "PredictionView.h"
#include <iostream>
#include <Qt3DInput/qmouseevent.h>
#include "Tinker.h"
#include <vector>
#include <algorithm>

#include "FileReader.h"

#include <QtWidgets/qmessagebox.h>
#include <QtWidgets/qwidget.h>
#include <QtWidgets/qapplication.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qlabel.h>
#include <QtGui/qpixmap.h>
#include <QtWidgets/qfiledialog.h>
#include <QtWidgets/qgraphicsview.h>

#define MOUSE_SENSITIVITY 1000

PredictionView::PredictionView(QWidget *parent) : QGraphicsView(parent)
{
    _lastX = -1;
    _lastY = -1;
    _crystal = 0;
    _tinker = 0;
    _keyPresses = 0;
    _keyPressSwitch = 5;
    _fixAxisStage = 0;
    _refineStage = 0;
	_identifyHklStage = 0;
    _radPerKeyPress = 1. / 500.;
}

void PredictionView::keyPressEvent(QKeyEvent *event)
{
    double diffX = 0;
    double diffY = 0;

    if (event->key() == Qt::Key_A)
    {
        diffX -= _radPerKeyPress;
    }
    else if (event->key() == Qt::Key_D)
    {
        diffX += _radPerKeyPress;
    }
    else if (event->key() == Qt::Key_S)
    {
        diffY += _radPerKeyPress;
    }
    else if (event->key() == Qt::Key_W)
    {
        diffY -= _radPerKeyPress;
    }
    else
    {
        return;
    }
    
    _keyPresses++;

    _crystal->applyRotation(diffX, diffY, 0);
    
    if (_keyPresses > _keyPressSwitch)
    {
        _keyPresses = 0;
        _crystal->populateMillers();
    }
    
    _tinker->drawPredictions();
}

void PredictionView::mousePressEvent(QMouseEvent *e)
{
    if (_fixAxisStage >= 1)
    {
        vec3 position = make_vec3(e->x(), e->y(), 0);
        _fixAxisPoints[_fixAxisStage - 1] = position;
        
        _fixAxisStage++;
        
        if (_fixAxisStage > 2)
        {
            setFixAxisStage(0);
        }
        
        return;
    }
    
    if (_refineStage >= 1 || _identifyHklStage >= 1)
    {
        int x = e->x();
        int y = e->y();
        _tinker->transformToDetectorCoordinates(&x, &y);
        int num = _detector->positionNearCoord(x, y);
        
        if (num < 0)
        {
            std::cout << "Missed..." << std::endl;
            return;
        }
        
        if (_refineStage >= 1)
        {
            _crystal->toggleWatched(num);
            _tinker->drawPredictions();
            return;
        }
		

		if (_identifyHklStage >= 1)
		{
            //Create message box with miller.
            //QMessageBox *mssgBox = new QMessageBox(this);
            int h = 0;
            int k = 0;
            int l = 0;
            
            _crystal->getMillerHKL(num, &h, &k, &l);
            
            std::string hklMiller = i_to_str(h) + " " + i_to_str(k) + " " + i_to_str(l);
            
            QString qMiller = QString(hklMiller.c_str());
            
            
            QMessageBox msgBox;
            msgBox.setWindowTitle("Miller readout.");
            msgBox.setText("I think you'll find that the hkl value is...");
            msgBox.setInformativeText("Miller index: " + qMiller);

            msgBox.addButton(QMessageBox::Yes);
            msgBox.setStandardButtons(QMessageBox::Cancel);
            msgBox.setDefaultButton(QMessageBox::Cancel);
            msgBox.setWindowModality(Qt::NonModal);

            //msgBox->open(NULL, NULL);
            msgBox.exec();
			//return;
		}

    }
    
    if (_fixAxisStage == 0)
    {
        _lastX = -1; _lastY = -1;
        _crystal->populateMillers();
        _tinker->drawPredictions();
        
        return;
    }
    
}

void PredictionView::mouseMoveEvent(QMouseEvent *e)
{
    if (_refineStage >= 1 || _fixAxisStage >= 1)
    {
        e->ignore();
        return;
    }
    
    int newX = e->x();
    int newY = e->y();

	e->accept();

	int centreX = width() / 2;
	int centreY = height() / 2;
    
    bool first = (_lastX < 0) || (_lastY < 0);
    
    if (!first)
    {
        vec3 newVec = make_vec3(newX - centreX, newY - centreY, 0);
		vec3_set_length(&newVec, 1.);
		vec3 oldVec = make_vec3(_lastX - centreX, _lastY - centreY, 0);
		vec3_set_length(&oldVec, 1.);

		vec3 cross = vec3_cross_vec3(newVec, oldVec);
		double dot = vec3_angle_with_vec3(newVec, oldVec);
		if (cross.z > 0) dot *= -1;

		if (dot != dot) dot = 0;

        if (!_crystal)
        {
            std::cout << "No crystal set!" << std::endl;
        }

		std::cout << "Applying rotation " << dot << std::endl;
        _crystal->applyRotation(0, 0, dot);
        
        if (!_tinker)
        {
            std::cout << "No tinker set!" << std::endl;        
        }
        
        _tinker->drawPredictions();
    }
    
    _lastX = newX; _lastY = newY;

    QGraphicsView::mousePressEvent(e);
}

void PredictionView::setFixAxisStage(int stage)
{
    _fixAxisStage = stage;
    
    if (stage > 0)
    {
        setCursor(Qt::CrossCursor);
    }
    else
    {
        setCursor(Qt::ArrowCursor);
        
        /* Cancel */
        if (stage < 0)
        {
            _fixAxisStage = 0;
            return;
        }
        
        vec3 diff = vec3_subtract_vec3(_fixAxisPoints[0], _fixAxisPoints[1]);
        vec3_set_length(&diff, 1);
        _crystal->setFixedAxis(diff);
        _tinker->finishFixAxis();
    }
}

void PredictionView::setIdentifyHklStage(int stage)
{
	_identifyHklStage = stage;

	if (stage > 0)
	{
		setCursor(Qt::CrossCursor);
	}
	else
	{
		setCursor(Qt::ArrowCursor);

	}
}

void PredictionView::setRefineStage(int stage)
{
    _refineStage = stage;
    
    if (stage > 0)
    {
		_crystal->clearUpRefinement();
        setCursor(Qt::CrossCursor);
    }
    else
    {
        setCursor(Qt::ArrowCursor);
        
        /* Cancel */
        if (stage < 0)
        {
            _refineStage = 0;
            return;
        }
        
        _tinker->startRefinement();
    }
}

/* Internet fix for margin problem */
void PredictionView::fitInView(const QRectF &rect, Qt::AspectRatioMode aspectRatioMode)
{
    if (!scene() || rect.isNull())
        return;
    auto unity = transform().mapRect(QRectF(0, 0, 1, 1));
    if (unity.isEmpty())
        return;
    scale(1/unity.width(), 1/unity.height());
    auto viewRect = viewport()->rect();
    if (viewRect.isEmpty())
        return;
    auto sceneRect = transform().mapRect(rect);
    if (sceneRect.isEmpty())
        return;
    qreal xratio = viewRect.width() / sceneRect.width();
    qreal yratio = viewRect.height() / sceneRect.height();

    // Respect the aspect ratio mode.
    switch (aspectRatioMode) {
    case Qt::KeepAspectRatio:
        xratio = yratio = qMin(xratio, yratio);
        break;
    case Qt::KeepAspectRatioByExpanding:
        xratio = yratio = qMax(xratio, yratio);
        break;
    case Qt::IgnoreAspectRatio:
        break;
    }
    scale(xratio, yratio);
    centerOn(rect.center());
}
