#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include"Points.h"
#include"Bodys.h"
#include"Surfaces.h"
#include"Lines.h"
#include"Layout.h"
#include"fileBrowser.h"
using namespace std;
class saveFile{
public:
	saveFile(){
		path="pro.extangle";
	}
	void saveProject(Layouts mLayout){
		mDlg.show();
		if (mDlg.exec() == QDialog::Accepted){
			path = mDlg.getPath();
			if (path != ""){
				myf.open(path, ios::out);
				myf << "Surfaces:" << endl;
				if (!mLayout.Sur.empty())
				for (int i = 0; i <= mLayout.Sur.size() - 1; i++){
					Surfaces tmp = mLayout.Sur[i];
					for (int j = 0; j <= tmp.line.size() - 1; j++){
						Lines tmpLine = tmp.line[j];
						myf << tmpLine.number << endl;
						myf << tmpLine.getStartPoint().getX() << " " << tmpLine.getStartPoint().getY() << " " << tmpLine.getStartPoint().getZ() << endl;
						myf << tmpLine.getEndPoint().getX() << " " << tmpLine.getEndPoint().getY() << " " << tmpLine.getEndPoint().getZ() << endl;
					}
					myf << "end" << endl;
				}
				myf << "Bodys:" << endl;
				if (!mLayout.Pob.empty())
				for (int i = 0; i <= mLayout.Pob.size() - 1; i++){
					Bodys tbody = mLayout.Pob[i];
					if (!tbody.parts.empty()){
						myf << tbody.number << endl;
						for (int j = 0; j <= tbody.parts.size() - 1; j++){
							Surfaces tsur = tbody.parts[j];
							myf << tsur.number << endl;
							myf << tsur.TextureID1 << " " << tsur.TextureID2 << endl;
							for (int k = 0; k <= tsur.line.size() - 1; k++){
								Lines tl = tsur.line[k];
								myf << tl.number << endl;
								myf << tl.getStartPoint().getX() << " " << tl.getStartPoint().getY() << " " << tl.getStartPoint().getZ() << endl;
								myf << tl.getEndPoint().getX() << " " << tl.getEndPoint().getY() << " " << tl.getEndPoint().getZ() << endl;
								myf << "LEnd" << endl;
							}
							if (!tsur.subSurface.empty())
							for (int k = 0; k <= tsur.subSurface.size() - 1; k++){
								myf << "sS:" << endl;
								myf << tsur.subSurface[k].number << endl;
								myf << tsur.subSurface[k].subSurfaceType << endl;
								if (!tsur.subSurface[k].line.empty())
								for (int kk = 0; kk <= tsur.subSurface[k].line.size() - 1; kk++){
									Lines tl = tsur.subSurface[k].line[kk];
									myf << tl.number << endl;
									myf << tl.getStartPoint().getX() << " " << tl.getStartPoint().getY() << " " << tl.getStartPoint().getZ() << endl;
									myf << tl.getEndPoint().getX() << " " << tl.getEndPoint().getY() << " " << tl.getEndPoint().getZ() << endl;
									myf << "sLEnd" << endl;
								}
								myf << "sSEnd" << endl;
							}
							myf << "SEnd" << endl;
						}
						myf << "BEnd" << endl;
					}
				}
				myf << "FEnd" << endl;
				myf.close();
			}
		}
	}
	void readfromFile(Layouts &mLayout){
		mDlg.show();
		if (mDlg.exec() == QDialog::Accepted){
			mLayout.Pob.clear();
			mLayout.Sur.clear();
			mLayout.surfaceNum = 0;
			mLayout.bodyNum = 0;
			path = mDlg.getPath();
			mLayout.Sur.clear();
			mLayout.Pob.clear();
			myf.open(path, ios::in);
			string str;
			stringstream ss;
			myf >> str;
			myf >> str;
			Point3f st;
			Point3f et;
			float axi;
			int n = 0;
			while (str != "Bodys:"){
				int number = atof(str.c_str());
				tmpLine.SetNumber(number);
				myf >> str;
				axi = atof(str.c_str()); st.setX(axi); n++;
				myf >> str; axi = atof(str.c_str()); st.setY(axi); n++;
				myf >> str; axi = atof(str.c_str()); st.setZ(axi); n++;
				myf >> str; axi = atof(str.c_str()); et.setX(axi); n++;
				myf >> str; axi = atof(str.c_str()); et.setY(axi); n++;
				myf >> str; axi = atof(str.c_str()); et.setZ(axi); n++;
				tmpLine.SetStartPoint(st);
				tmpLine.SetEndPoint(et);
				myf >> str;
				tmpSurface.addLines(tmpLine);
				if (str == "end"){

					mLayout.Sur.push_back(tmpSurface);
					tmpSurface.clearAllLines();
					myf >> str;
				}
				n++;
			}
			myf >> str;
			while (str != "FEnd"){
				while (str != "BEnd"){
					int bnum = atof(str.c_str());
					tmpBodys.number = bnum;
					myf >> str;
					tmpSurface.clearAllLines();
					while (str != "SEnd"){
						int snum = atof(str.c_str());
						tmpSurface.number = snum;
						myf >> str;
						tmpSurface.TextureID1 = atof(str.c_str());
						myf >> str;
						tmpSurface.TextureID2 = atof(str.c_str());
						myf >> str;
						while (str != "LEnd"){
							int lnum = atof(str.c_str());
							tmpLine.number = lnum;
							myf >> str; axi = atof(str.c_str()); st.setX(axi);
							myf >> str; axi = atof(str.c_str()); st.setY(axi);
							myf >> str; axi = atof(str.c_str()); st.setZ(axi);
							myf >> str; axi = atof(str.c_str()); et.setX(axi);
							myf >> str; axi = atof(str.c_str()); et.setY(axi);
							myf >> str; axi = atof(str.c_str()); et.setZ(axi);
							tmpLine.SetStartPoint(st);
							tmpLine.SetEndPoint(et);
							tmpSurface.addLines(tmpLine);
							myf >> str;
							if (str == "LEnd"){
								myf >> str;
								if (str == "sS:"){
									myf >> str;
									while (str != "SEnd"){
										if (str == "sS:")myf >> str;
										int ssnum = atof(str.c_str());
										Surfaces tmpss;
										tmpss.number = ssnum;
										myf>>str;
										tmpss.subSurfaceType=atof(str.c_str());
										myf >> str;
										while (str != "sLEnd"){
											int slnum = atof(str.c_str());
											tmpLine.number = slnum;
											myf >> str; axi = atof(str.c_str()); st.setX(axi);
											myf >> str; axi = atof(str.c_str()); st.setY(axi);
											myf >> str; axi = atof(str.c_str()); st.setZ(axi);
											myf >> str; axi = atof(str.c_str()); et.setX(axi);
											myf >> str; axi = atof(str.c_str()); et.setY(axi);
											myf >> str; axi = atof(str.c_str()); et.setZ(axi);
											tmpLine.SetStartPoint(st);
											tmpLine.SetEndPoint(et);
											tmpss.addLines(tmpLine);
											myf >> str;
											if (str == "sLEnd"){
												myf >> str;
												if (str == "sSEnd"){
													tmpSurface.subSurface.push_back(tmpss);
													tmpss.clearAllLines();
													myf >> str;
													break;
												}
											}
										}

									}
								}
								if (str == "SEnd"){
									tmpBodys.parts.push_back(tmpSurface);
									tmpSurface.line.clear();
									myf >> str;
									break;
								}
							}
						}
						if (str == "BEnd"){
							mLayout.Pob.push_back(tmpBodys);
							tmpBodys.parts.clear();
							myf >> str;
							break;
						}

					}
					if (str == "FEnd"){
						break;
					}
				}

			}
			myf.close();
		}
		
	}

public:
	Bodys tmpBodys;
	Surfaces tmpSurface;
	Lines tmpLine;
	string path;
	fstream myf;
	fileBrowser mDlg;
};