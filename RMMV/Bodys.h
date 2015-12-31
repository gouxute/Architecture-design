#ifndef BODYS_H
#define BODYS_H
#include"Surfaces.h"
#include"subSur.h"
#include<vector>
using namespace std;
class Bodys{
public:
	Bodys(){
		height=3;//initialize the height of the body
		StartDrawPartofBody=false;// forbid the drawing function of body
		closeornot=false;
	}
	void setHeight(double i){// set the height of the body
		height=i;
	}
	double getHeight(){// get the height of the body
		return height;
	}
	//移除体内的面
	void removeSurface(int tmp){
		if (parts.size() == 1 && parts[0].number == tmp){
			parts.clear();
			return;
		}
		if (!parts.empty()){
			vector<Surfaces>::iterator i = parts.begin();
			for (int j = 0; i != parts.end(); j++, i++){
				if (parts[j].number == tmp){
					parts[j].subSurface.clear();
					parts.erase(i);
					break;
				}
				//移除子面
				if (!parts[j].subSurface.empty()){
					vector<Surfaces>::iterator f = parts[j].subSurface.begin();
					for (int k = 0; k <= parts[j].subSurface.size() - 1; k++,f++){
						if (parts[j].subSurface[k].number == tmp){
							parts[j].subSurface[k].subSurface.clear();
							parts[j].subSurface.erase(f);
							break;
						}
					}
				}
			}
		}
	}
	//改变面的排序
	void tabSurface(int tmp){
		vector<Surfaces>::iterator i = parts.begin();
		Surfaces tmpSS;
		for (int j = 0; i != parts.end();  j++, i++){
			if (parts[j].number == tmp){
				tmpSS = parts[j];
				parts.erase(i);
				break;
			}
		}
		parts.push_back(tmpSS);
		int ttt = 0;
	}
	//画体
	void drawBody(){
		if (!parts.empty()){
			for (int i = 0; i <= parts.size() - 1; i++){
				parts[i].drawSurface();
			}
		}
	}
	//获得体内的面
	void getSurface(Point3f st,Point3f et,Bodys &body,int &lineNum,int &surfaceNum){
		Surfaces tmp;
		//tmp.buildSurface(st, et, tmp, height, lineNum,true);
		tmp.buildSurface(st, et, tmp, height, lineNum, false);
		tmp.number = surfaceNum++;
		body.parts.push_back(tmp);
	}
	//画体辅助线
	void drawTempSurface(Point3f st,Point3f et,int mode,int &lineNum){
		int num=0;
		Surfaces tmp;
		if (parts.empty()){
			tmp.buildSurface(st, et, tmp, height, num,true);
			tmp.setSurfaceRGB(1);
			tmp.drawSurface();
		}
		else{
			if (mode == 0 || mode == 1){
				Point3f tP = parts[parts.size() - 1].line[0].getEndPoint();
				tmp.buildSurface(tP,et,tmp,height,num,true);
				tmp.setSurfaceRGB(1);
				tmp.drawSurface();
			}
			if (mode == 1){
				Point3f tP = parts[0].line[0].getStartPoint();
				tmp.buildSurface(et, tP, tmp, height, num,false);
				tmp.setSurfaceRGB(2);
				tmp.drawSurface();
			}
		}
	}
	//结束画体
	void finishDraw(Point3f et,int mode,Bodys &body,int &surfaceNum,int &lineNum){
		Surfaces tmp;
		if (parts.empty())return;
		if (mode == 0 || mode == 1){
			Point3f tP = parts[parts.size() - 1].line[0].getEndPoint();
			tmp.buildSurface(tP, et, tmp, height, lineNum,true);
			tmp.number = surfaceNum++;
			body.parts.push_back(tmp);
		}
		if (mode == 1){
			Point3f tP = parts[0].line[0].getStartPoint();
			tmp.buildSurface(et, tP, tmp, height, lineNum,false);
			tmp.number = surfaceNum++;
			body.parts.push_back(tmp);
		}
	}
	//根据线找体，找不到返回-1，找到返回体序号
	int findSurface(int num,Surfaces &tmp,int &lineNum){
		Lines tmpLine;
		for (int i = 0; i <= parts.size() - 1; i++){
			if (parts[i].findLine(num,tmpLine) == num){
				tmp = parts[i];
				tmp.resetLineNum(lineNum);
				return number;
			}
		}
		return -1;
	}
	//移动面
	void moveBody(double dx, double dy, double dz){
		for (int i = 0; i <= parts.size() - 1; i++){
			parts[i].moveSurface(dx, dy, dz);
		}
	}
	/////拉升功能
	void buildBody(int h,Surfaces tmp,Bodys &body,int &lineNum,int &surfaceNum){
		if (tmp.line.size() == 0)return;
		for (int i = 0; i <= tmp.line.size() - 1; i++){
			Surfaces sur;
			sur.buildSurface(tmp.line[i].getStartPoint(), tmp.line[i].getEndPoint(),
				sur, h, lineNum, false);
			sur.number = surfaceNum++;
			body.parts.push_back(sur);
		}
		body.parts.push_back(tmp);
		tmp.number = surfaceNum++;
		tmp.moveSurface(0, 0, h);
		body.parts.push_back(tmp);
	}
public:
	vector<Surfaces> parts;//store the surfaces in the body
	bool closeornot;// indicate whether the body is closed or not
	int number;
private:
	
	double height;// store the height
	bool StartDrawPartofBody;// check whether it's anble to draw a body
};
#endif BODYS_H