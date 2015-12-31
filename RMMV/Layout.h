#ifndef LAYOUTS_H
#define LAYOUTS_H
#include"Bodys.h"
#include"sharedata.h"
class Layouts{
public:
	Layouts(){
		lineNum = surfaceNum = bodyNum = 0;
	}
	int getSurfaceNum(){
		return Sur.size();
	}
	void addSurface(Surfaces temp){
		Sur.push_back(temp);
	}
	int getBodysCount(){
		return Pob.size();
	}
	void addBodys(Bodys temp){
		Pob.push_back(temp);
	}
	Bodys getBodys(int num){
		return Pob[num];
	}
	Surfaces getSurface(int temp){
		return Sur.at(temp);
	}
	void removeSurface(int tmp){
		if (!Sur.empty()){
			vector<Surfaces>::iterator f = Sur.begin();
			for (int i = 0; i <= Sur.size() - 1; i++,f++){
				Lines temp;
				if (Sur[i].findLine(tmp, temp) != -1){
					Sur.erase(f);
					break;
				}
			}
			return;
		}
		if (!Pob.empty())
		for (int i = 0; i <= Pob.size() - 1; i++){
			Pob[i].removeSurface(tmp);
		}
	}
	void removeLine(int num){
		if (Sur.empty())return;
		for (int i = 0; i <= Sur.size() - 1; i++){
			Sur[i].removeLine(num);
		}
	}
	void tabSurface(int tmp){
		for (int i = 0; i <= Pob.size() - 1; i++){
			Pob[i].tabSurface(tmp);
			int tt = 0;
		}
	}
	int formSurface(int num,int l, int s, int o){
		int tp1 = l; int tp2 = s; int tp3 = o;
		if (sharedData::formBodyFlag){
			if (sharedData::formType == 2){
				if(!Pob.empty())
				for (int i = 0; i <= Pob.size() - 1; i++){
					if (Pob[i].number == num){
						Surfaces sur;
						for (int j = 0; j <= Pob[i].parts.size() - 1; j++){
							Lines tline = Pob[i].parts[j].line[0];
							tline.number = tp1++;
							sur.addLines(tline);
						}
						sur.number = tp2++;
						Pob[i].parts.push_back(sur);
							sur.clearAllLines();
						for (int j = 0; j <= Pob[i].parts.size() - 2; j++){
							Lines tline = Pob[i].parts[j].line[0];
							Point3f st, et;
							st = tline.getStartPoint();
							et = tline.getEndPoint();
							st.setZ(3 + st.getZ());
							et.setZ(3 + et.getZ());
							tline.SetStartPoint(st);
							tline.SetEndPoint(et);
							tline.number = tp1++;
							sur.addLines(tline);
						}
						sur.number = tp2++;
						Pob[i].parts.push_back(sur);
						sur.clearAllLines();
						return Pob[i].parts.size();
					}
				}
			}
		}
		return 0;
	}
	void drawLayout(){
		mBody.drawBody();
		mSur.drawSurface();


		

		if (!Pob.empty()){
			for (int i = 0; i <= Pob.size() - 1; i++){
				Pob[i].drawBody();
			}
		}
		if (!Sur.empty()){
			for (int i = 0; i <= Sur.size() - 1; i++){
				Sur[i].drawSurface();
			}
		}
		if (!Lin.empty()){
			for (int i = 0; i <= Lin.size() - 1; i++){
				Lin[i].drawLine();
				
			}
		}
	}
	void  getLine(QMouseEvent* event,bool &End){
		if (End){
			mline.isStarttoDrawLine = false;
			End = false;
		}
		if (!mline.isStarttoDrawLine){
			Point3f st;
			st.setXYZ(event->x(), event->y());
			mline.SetStartPoint(st);
			mline.isStarttoDrawLine = true;
		}
		else{
			Point3f et;
			Point3f st = mline.getStartPoint();
			et.setXYZ(event->x(), event->y());
			mSur.getLine(st, et, mSur, lineNum);
			mline.SetStartPoint(et);
		}
	}
	void getSurface(QMouseEvent* event, bool &End){
		if (End){
			mline.isStarttoDrawLine = false;
			End = false;
		}
		if (!mline.isStarttoDrawLine){
			Point3f st;
			st.setXYZ(event->x(), event->y());
			mline.SetStartPoint(st);
			mline.isStarttoDrawLine = true;
		}
		else{
			Point3f et;
			Point3f st = mline.getStartPoint();
			et.setXYZ(event->x(), event->y());
			mBody.getSurface(st, et, mBody, lineNum, surfaceNum);
			mline.SetStartPoint(et);
		}
	}
	void drawAssisitLine(Point3f start,Point3f end, int mode,bool End){
		if (End){
			mSur.finishDraw(end, mode, mSur, lineNum);
			mSur.number = surfaceNum++;
			Sur.push_back(mSur);
			mSur.line.clear();
			return;
		}
		if (!mline.isStarttoDrawLine)return;
		mSur.drawTempLine(start, end, mode);
	}
	void drawAssisitSurface(Point3f start, Point3f end, int mode, bool End){
		if (End){
			mBody.finishDraw(end, mode, mBody,surfaceNum, lineNum);
			mBody.number = bodyNum++;
			Pob.push_back(mBody);
			mBody.parts.clear();
			return;
		}
		if (!mline.isStarttoDrawLine)return;
		mBody.drawTempSurface(start, end, mode, lineNum);
	}
	void cut(int num, int type){
		if (type == 0){//line
			Lines tmp;
			if (Sur.empty())return;
			for (int i = 0; i <= Sur.size() - 1; i++){
				Sur[i].findLine(num,tmp);
			}
			removeLine(num);
			copyLine = tmp;
		}
		if (type == 1){//surface
			Surfaces tmp;
			if (Pob.empty())return;
			for (int i = 0; i <= Pob.size() - 1; i++){
				Pob[i].findSurface(num, tmp,lineNum);
			}
			removeSurface(num);
			copySurface = tmp;
		}
		if (type == 2){//body

		}
	}
	void copy(int num, int type){
		if (type == 0){//line
			Lines tmp;
			if (Sur.empty())return;
			for (int i = 0; i <= Sur.size() - 1; i++){
				Sur[i].findLine(num, tmp);
			}
			copyLine = tmp;
		}
		if (type == 1){//surface
			Surfaces tmp;
			if (Pob.empty())return;
			for (int i = 0; i <= Pob.size() - 1; i++){
				Pob[i].findSurface(num, tmp, lineNum);
			}
			copySurface = tmp;
		}
		if (type == 2){//body

		}
	}
	void paste(int num, int type){
		if (type == 0){
			if (copyLine.number == -1)return;
			copyLine.number = lineNum++;
			copyLine.moveLine(3, 3, 0);
			Lin.push_back(copyLine);
		}
		if (type == 1){
			if (copySurface.number == -1)return;
			copySurface.number = surfaceNum++;
			copySurface.moveSurface(3, 3, 0);
			Sur.push_back(copySurface);
		}
	}
public:
	Lines mline;
	Surfaces mSur;
	Bodys mBody;
	vector<Bodys> Pob;// store the bodys
	vector<Surfaces> Sur;// store the surfaces
	vector<Lines> Lin;// store the independent lines
	vector<Point3f> Poi;// store the single points
	Lines copyLine;
	Surfaces copySurface;
	int lineNum;
	int surfaceNum;
	int bodyNum;
};
#endif LAYOUTS_H