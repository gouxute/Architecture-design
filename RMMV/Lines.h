#ifndef LINES_H
#define LINES_H
#include"Points.h"
#include"glut.h"
#include<gl\GLU.h>
class Lines{
public:
	Lines(){
		st.setX(0);st.setY(0);st.setZ(0);
		et.setX(0);et.setY(0);et.setZ(0);
		R = G = 0.0f;
		B = 1.0f;
		//_(:з」∠)_ _(:з」∠)_ _(:з」∠)_ _(:з」∠)_ _(:з」∠)_ _(:з」∠)_ _(:з」∠)_ _(:з」∠)_
		isMove = false;
		isRotate = false;
		isScale = false;
		isSelect = false;
		isStarttoDrawLine = false;
	}
	//*_(:з」∠)_ _(:з」∠)_ _(:з」∠)_ _(:з」∠)_ _(:з」∠)_ _(:з」∠)_ _(:з」∠)_ _(:з」∠)_
	bool getIsMove() { return isMove; }
	void setIsMove( bool newIsMove ) { isMove = newIsMove; }
	bool getIsRotate() { return isRotate; }
	void setIsRotate( bool newIsRotate ) { isRotate = newIsRotate; }
	bool getIsScale() { return isScale; }
	void setIsScale( bool newIsScale ) { isScale = newIsScale; }
	
	int getNumber(){
		return number;
	}
	void SetNumber(int LineNum){
		number=LineNum;
	}
	void SetStartPoint(Point3f temp){
		st=temp;
	}
	void SetEndPoint(Point3f temp){
		et=temp;
	}
	Point3f getStartPoint(){
		return st;
	}
	Point3f getEndPoint(){
		return et;
	}
	//设置线的颜色
	void setRGB(GLfloat r,GLfloat g,GLfloat b){
		R=r;G=g;B=b;
	}
	//画线
	void drawLine(){
		glColor3f(R, G, B);
		glLineWidth(3.0);
		glBegin(GL_LINES);
		glVertex3f(st.getX(), st.getY(), st.getZ());
		glVertex3f(et.getX(), et.getY(), et.getZ());
		glEnd();
	}
	//线正交
	void orthoLine(Point3f &st, Point3f &et){
		double x, y;
		x = et.getX() - st.getX();
		y = et.getY() - st.getY();
		if (x >= -0.3&&x <= 0.3){
			et.setX(st.getX());
		}
		if (y >= -0.3&&y <= 0.3){
			et.setY(st.getY());
		}
	}
	//移动线
	void moveLine(double dx, double dy, double dz){
		st.movePoint(dx, dy, dz);
		et.movePoint(dx, dy, dz);
	}
public:
	bool isStarttoDrawLine;
	bool isSelect;
	int number;
	GLfloat R, G, B;
	Point3f st;
	Point3f et;
	bool isMove, isRotate, isScale;
};
#endif LINES_H