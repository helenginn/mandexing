//
//  QTinker.h
//  Windexing
//
//  Created by Helen Ginn on 11/12/2016.
//  Copyright (c) 2017 Helen Ginn. All rights reserved.
//

#ifndef __Windexing__QTinker__
#define __Windexing__QTinker__

#include <stdio.h>

#include "shared_ptrs.h"
#include "Detector.h"
#include "Dialogue.h"
#include <QtWidgets/qwidget.h>
#include <QtCore/qglobal.h>
#include <QtWidgets/qapplication.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qlabel.h>
#include <QtGui/qpixmap.h>
#include <QtWidgets/qfiledialog.h>
#include <QtWidgets/qgraphicsview.h>
#include "Crystal.h"
#include "PredictionView.h"
#include <vector>
#include <QtCore/qsignalmapper.h>

class Tinker : public QMainWindow
{
    Q_OBJECT
    
public:
    Tinker(QWidget *parent = 0);

	/* Buttons down the side */
    QPushButton *bUnitCell;
    QPushButton *bAxisOnScreen;
    QPushButton *bBeamCentre;
    QPushButton *bFixAxis;
    QPushButton *bDetDist;
    QPushButton *bWavelength;
    QPushButton *bRlpSize;
    QPushButton *bRefine;
	QPushButton *bIdentifyHkl;
    QPushButton *bDegrees;
    QPushButton *bLatPrimitive, *bLatBody, *bLatFace, *bLatBase;
    QSignalMapper *latMapper;
    
    /* Beam centre adjust buttons */
    QPushButton *bBeamXPlus, *bBeamXMinus;
    QPushButton *bBeamYPlus, *bBeamYMinus;
    
    /* Image display */
    QPixmap blankImage;
    QGraphicsScene *overlay;
    PredictionView *overlayView;
    QLabel *imageLabel;
    
    Dialogue *myDialogue;
	QFileDialog *fileDialogue;
    
    void setup();

	void receiveDialogue(DialogueType type, std::string diagString);
	void drawPredictions();
	void finishFixAxis();
	void transformToDetectorCoordinates(int *x, int *y);
	void startRefinement();


    ~Tinker();
protected:
    virtual void resizeEvent(QResizeEvent *event);
private slots:
    void setUnitCellClicked();
	void setAxisOnScreenClicked();
	void setBeamCentreClicked();
	void setDetDistClicked();
	void setWavelengthClicked();
	void setRlpSizeClicked();
	void setDegreeStepClicked();
    void identifyHkl();
	
	/* Menu slots */
	
	void openImage();
	void saveMatrix();
	void loadMatrix();

	/* Beam centre adjustments */
	void beamXPlus();
	void beamYPlus();
	void beamXMinus();
	void beamYMinus();
	void fixAxisClicked();
	void refineClicked();
	void changeLattice(BravaisLatticeType type);

private:
	void changeBeamCentre(double deltaX, double deltaY);
	
	
	std::vector<double> _unitCell;
	Crystal _crystal;
	Detector _detector;

	int _identifyHklStage;
	int _fixAxisStage;
	int _refineStage;
};

#endif /* defined(__CaroCode__QTinker__) */
