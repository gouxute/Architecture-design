#ifndef POINT3F
#define POINT3F
#pragma once
#include<vector>
#include<iostream>
#include<gl\GLU.h>
#include<gl\GL.h>
#include"glut.h"
class Point3f{
public:
	Point3f(){ x = 0; y = 0; z = 0; };
	Point3f(GLdouble x,GLdouble y,GLdouble z):x(x),y(y),z(z){};
	void setX(GLfloat tempX){
		x=tempX;
	}
	void setY(GLfloat tempY){
		y=tempY;
	}
	void setZ(GLfloat tempZ){
		z=tempZ;
	}
	GLfloat getX(){
		return x;
	}
	GLfloat getY(){
		return y;
	}
	GLfloat getZ(){
		return z;
	}
	void setXYZ(float mouse_x,float mouse_y) {//鼠标位置
		GLdouble nearPointX;
		GLdouble nearPointY;
		GLdouble nearPointZ;
		GLdouble farPointX;
		GLdouble farPointY;
		GLdouble farPointZ;
		double modelview[16],projection[16];
		int viewport[4];
		float winX,winY,winZ;
		double object_x = 0,object_y = 0,object_z = 0;     //3D坐标
		glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
		glGetDoublev(GL_PROJECTION_MATRIX, projection);
		glGetIntegerv(GL_VIEWPORT, viewport);
		winX=(float)mouse_x;
		winY=(float)viewport[3]-(float)mouse_y;
		glReadPixels(mouse_x, int(winY),1,1,GL_DEPTH_COMPONENT,GL_FLOAT, &winZ);
		gluUnProject((GLdouble)winX,(GLdouble)winY,(GLdouble)winZ,modelview,projection,viewport,&x,&y,&z);
		//获得近交点
		gluUnProject((GLdouble)winX,(GLdouble)winY,0.0,modelview,projection,viewport,&nearPointX,&nearPointY,&nearPointZ);
		//获得远交点
		gluUnProject((GLdouble)winX,(GLdouble)winY,1.0,modelview,projection,viewport,&farPointX,&farPointY,&farPointZ);
		GLdouble disforZ=farPointZ-nearPointZ;
		GLdouble disforY=farPointY-nearPointY;
		GLdouble disforX=farPointX-nearPointX;
		
		//计算投影到Z=0平面的坐标
		double tempX,tempY;
		tempX=nearPointX-disforX*nearPointZ/disforZ;
		tempY=nearPointY-disforY*nearPointZ/disforZ;
		x=tempX;
		y=tempY;
		z=0;
	}
	void movePoint(GLdouble dx, GLdouble dy, GLdouble dz){
		x += dx;
		y += dy;
		z += dz;
	}
	
private:
	GLdouble x;
	GLdouble y;
	GLdouble z;
};
#endif