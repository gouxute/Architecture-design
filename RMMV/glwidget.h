#pragma once

#include<qprinter.h>
#include<QPrintDialog>
#include<c:\Qt\Qt5.1.1\5.1.1\msvc2010_opengl\include\QtOpenGL\QGLWidget>
#include <QWheelEvent>
#include"Lines.h"
#include"Layout.h"
#include"Bodys.h"
#include"Surfaces.h"
#include"Points.h"
#include<string>
#include<vector>
#include <GL/GLU.H>
#include "glut.h"
#include<sstream>
#include<iostream>
#include <math.h>
#include <QMessageBox>
#include"saveProject.h"
#include"queryFormSurface.h"
class GLWidget: public QGLWidget
{
	Q_OBJECT
public:
	GLWidget(QWidget *parent = 0);
	~GLWidget(void);
public:
	GLint beginPos[2], endPos[2], curPos[2];
	GLint viewportSize[2];
	vector<Lines> face;
	vector<Lines> facetotal;
	bool SelectFace;
	int select_line;
	GLint select_line1[100];
	int select_d;
	bool multi;
	int swidth;
	int sheight;


protected:
	void initializeGL();
	void paintGL();
	void view_change();
	int ischanged;
	void resizeGL(int width, int height);
	void keyPressEvent(QKeyEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event); //mousePressEvent
	void mouseReleaseEvent(QMouseEvent *event);
	void wheelEvent(QWheelEvent  *event);
	void drawAxe();
	void draw();
	//select
	void processHits(GLint hits, GLuint buffer[]);
	void select(QPoint releasePos);
	vector<Lines> findFaceLine(int LineNo);
	vector<Lines> findSelectedLine(int LineNo);

public:
	GLfloat rotationX;
	GLfloat rotationY;
	GLfloat rotationZ;
	GLfloat trans_X,trans_Y,trans_Z;
	GLfloat scaling;
	bool isRight,isMid,isLeft;
	QPoint lastPos,lastPos1,lastPos2, releasePos;
	int view_choice;

public:
	void loadGraph();
	void saveGraph();
	void newProject();
public:
	Point3f tempStart;
	Point3f tempEnd;
	Layouts mlayout;
	saveFile mFile;
public:
	//¿ª¹Ø
	int drawingMode;
	bool enableLineDrawing;
	bool enableSurfaceDrawing;
	bool enablePartDrawing;
	bool enableBodyDrawing;
	bool endofDrawing;
	bool isToSelect;
};