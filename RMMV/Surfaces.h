#ifndef SURFACES_H
#define SURFACES_H
#include<iostream>
#include<string>
#include"Lines.h"
#include"subSur.h"
#include<vector>
using namespace std;
class Surfaces{
public:
	
	Surfaces(){
		StartDrawSurface=false;
		TextureID1=-1;
	    TextureID2=-1;
	}
	void addLines(Lines temp){
		line.push_back(temp);
	}
	void removeLastLine(){
		line.pop_back();
	}
	int getCount(){
		return line.size();
	}
	void clearAllLines(){
		line.clear();
	}
	//画面和子面
	void drawSurface(){
		extern GLenum mode1;//-----------------------------

		if (!line.empty())
			for (int i = 0; i <= line.size() - 1; i++){
				line[i].drawLine();

			}
			if (!subSurface.empty()){
				for (int i = 0; i <= subSurface.size() - 1; i++){
					subSurface[i].drawSurface();
				}
			}
	}
	//画辅助线
	void drawTempLine(Point3f st,Point3f et,int mode){
		Lines tmp;
		if (line.empty()){
			tmp.orthoLine(st, et);
			tmp.SetStartPoint(st);
			tmp.SetEndPoint(et);
			tmp.setRGB(1.0, 0.0, 0.0);
			tmp.drawLine();
		}
		else {
			if (mode == 0 || mode == 1){
				tmp.SetStartPoint(line[line.size() - 1].getEndPoint());
				tmp.orthoLine(line[line.size() - 1].getEndPoint(), et);
				tmp.SetEndPoint(et);
				tmp.setRGB(1.0, 0.0, 0.0);
				tmp.drawLine();
			}
			if (mode == 1){
				tmp.SetEndPoint(line[0].getStartPoint());
				tmp.SetStartPoint(et);
				tmp.setRGB(1.0, 1.0, 0.0);
				tmp.drawLine();
			}
		}
	}
	///结束画面
	void finishDraw(Point3f et,int mode,Surfaces& tmpSur,int &lineNum){
		Lines tmp;
		if (tmpSur.line.empty())return;
		if (mode == 0 || mode == 1){
			tmp.SetStartPoint(tmpSur.line[line.size() - 1].getEndPoint());
			tmp.orthoLine(tmpSur.line[line.size() - 1].getEndPoint(), et);
			tmp.SetEndPoint(et);
			tmp.number = lineNum++;
			tmpSur.line.push_back(tmp);
		}
		if (mode == 1){
			tmp.SetEndPoint(tmpSur.line[0].getStartPoint());
			tmp.SetStartPoint(et);
			tmp.number = lineNum++;
			tmpSur.line.push_back(tmp);
		}
	}
	//获取面的线
	void getLine(Point3f st, Point3f et, Surfaces& tmp,int &lineNum){
		Lines line1;
		line1.SetStartPoint(st);
		//line1.orthoLine(st, et);
		line1.SetEndPoint(et);
		line1.number = lineNum++;
		tmp.line.push_back(line1);
	}
	//根据两个点建立一个面
	void buildSurface(Point3f st,Point3f et, Surfaces &tmp,int height,int &lineNum,bool ortho){
		Lines line1;
		if (ortho)
		line1.orthoLine(st, et);
		line1.SetStartPoint(st); line1.SetEndPoint(et);
		line1.number = lineNum++;
		tmp.line.push_back(line1);
		line1.SetStartPoint(et);
		et.setZ(height+et.getZ());
		line1.SetEndPoint(et);
		line1.number = lineNum++;
		tmp.line.push_back(line1);
		line1.SetStartPoint(et);
		st.setZ(height+st.getZ());
		line1.SetEndPoint(st);
		line1.number = lineNum++;
		tmp.line.push_back(line1);
		line1.SetStartPoint(st);
		st.setZ(st.getZ() - height);
		line1.SetEndPoint(st);
		line1.number = lineNum++;
		tmp.line.push_back(line1);
	}
	//设置面的边框颜色
	void setSurfaceRGB(int color){//0.White 1.Red 2.Yellow 3.Blue 4.Green
		if (line.empty()) return;
		float r, g, b;
		switch (color)
		{
		case 0:
			r = 1.0; g = 1.0; b = 1.0;
			break;
		case 1:
			r = 1.0; g = 0.0; b = 0.0;
			break;
		case 2:
			r = 1.0; g = 1.0; b = 0.0;
			break;
		case 3:
			r = 0.0; g = 0.0; b = 1.0;
			break;
		case 4:
			r = 0.0; g = 1.0; b = 0.0;
			break;
		default:
			break;
		}
		for (int i = 0; i <= line.size() - 1; i++){
			line[i].setRGB(r, g, b);
		}
	}
	//插入子面
	void insertSubSurface(double length,double height,double horizon,double vertical,int type, int &lineNum,int &surfaceNum){
		if (line.empty())return;
			Point3f st, et;
			Surfaces tmpSub;
			st = line[0].getStartPoint();
			et = line[0].getEndPoint();
			bool inverse = false;
			double dis1 = pow(st.getX(), 2) + pow(st.getY(), 2);
			double dis2 = pow(et.getX(), 2) + pow(et.getY(), 2);
			if (dis2 < dis1){
				inverse = true;
				Point3f tmp;tmp = st;st = et;et = tmp;
			}
			double angle = atan2(et.getY() - st.getY(), et.getX() - st.getX());
			/*double s1, s2, s3, s4, s5;
			s1 = msub.getheigth().toDouble() / 1000;
			s2 = msub.getlength().toDouble() / 1000;
			s3 = msub.gethorizon().toDouble() / 1000;
			s4 = msub.getvertical().toDouble() / 1000;
			s5 = msub.getType();*/
			tmpSub.number = surfaceNum++;
			st.setX(st.getX() + horizon*cos(angle));
			st.setY(st.getY() + horizon*sin(angle));
			st.setZ(st.getZ() + vertical);
			et.setX(st.getX() + length*cos(angle));
			et.setY(st.getY() + length*sin(angle));
			et.setZ(st.getZ());
			buildSurface(st, et, tmpSub, height, lineNum, false);
			subSurface.push_back(tmpSub);
	}
	//根据线序号找面，找不到返回-1，找到返回面序号
	int findLine(int num,Lines &tmp){
		for (int i = 0; i <= line.size() - 1; i++){
			if (line[i].number == num){
				tmp = line[i];
				return number;
			}
		}
		return -1;
	}
	//移动面
	void moveSurface(double dx, double dy, double dz){
		for (int i = 0; i <= line.size() - 1; i++){
			line[i].moveLine(dx, dy, dz);
		}
	}
	//重置线序号
	void resetLineNum(int &lineNum){
		for (int i = 0; i <= line.size() - 1; i++){
			line[i].number = lineNum++;
		}
	}
	//移除面内的线
	void removeLine(int num){
		vector<Lines>::iterator f = line.begin();
		for (int i = 0; i <= line.size() - 1; i++,f++){
			if (line[i].number == num){
				line.erase(f);
				break;
			}
		}
	}
public:
	bool closeornot;// indicate whether the surface is closed or not 
	int number;
	vector<Lines> line;
	vector<Surfaces> subSurface;
	int subSurfaceType;//0.Normal;1.Window;2.Hole;3.Module;4.Door
	int TextureID1;
	int TextureID2;
private:
	bool StartDrawSurface;
};
#endif