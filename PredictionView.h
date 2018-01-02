//
//  PredictionView.h
//  Windexing
//
//  Created by Helen Ginn on 11/12/2016.
//  Copyright (c) 2017 Helen Ginn. All rights reserved.
//

#ifndef __Windexing__PredictionView__
#define __Windexing__PredictionView__

#include "Crystal.h"
#include "Detector.h"
#include "shared_ptrs.h"
#include <QtWidgets/qgraphicsview.h>

class Tinker;

class PredictionView : public QGraphicsView
{
    Q_OBJECT
    
public:
    PredictionView(QWidget *parent = 0);
    
    void setCrystal(Crystal *crystal)
    {
        _crystal = crystal;
    }

    void setDetector(Detector *det)
    {
        _detector = det;
    }

    void setTinker(Tinker *tinker)
    {
        _tinker = tinker;
    }
    
    void setRadiansPerKeyPress(double rad)
    {
        _radPerKeyPress = rad;
        _keyPressSwitch = deg2rad(0.5) / rad;
    }

    void setFixAxisStage(int stage);
    void setRefineStage(int stage);
	void setIdentifyHklStage(int stage);
    virtual void fitInView(const QRectF &rect, Qt::AspectRatioMode aspectRatioMode);
protected:
    virtual void mousePressEvent(QMouseEvent *e);
    virtual void mouseMoveEvent(QMouseEvent *e);
    virtual void keyPressEvent(QKeyEvent *event);
   
    Detector *_detector; 
    Crystal *_crystal;
    Tinker *_tinker;
    
    int _lastX;
    int _lastY;
    
    int _keyPresses;
    int _keyPressSwitch;
        
    int _fixAxisStage;
    int _refineStage;
	int _identifyHklStage;

    double _radPerKeyPress;
    
	int _singleWatch;
    
    vec3 _fixAxisPoints[2];
};

#endif 
