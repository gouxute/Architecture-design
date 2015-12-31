#include"glwidget.h"
GLenum mode1;
GLWidget::GLWidget(QWidget *parent)
	: QGLWidget (QGLFormat(QGL::SampleBuffers), parent)
{
	setFocusPolicy(Qt::StrongFocus);
	setMouseTracking(true);

	rotationX = -80;
	rotationY = -54;
	rotationZ=0;

	trans_X=-5.15;
	trans_Y=0.05;
	trans_Z=-10;
	scaling = 0.5;
	viewportSize[0]=width();  //get GLwidget's width
	viewportSize[1]=height();  //get GLwidget's height
	isRight=false;
	isMid=false;
	isLeft=false;
	view_choice = 1;
	view_change();
	view_choice = 0;
	view_change();
	//开关
	drawingMode = -1;
	enableLineDrawing = false;
	enableSurfaceDrawing = false;
	enablePartDrawing = false;
	enableBodyDrawing = false;
	endofDrawing = false;
	multi=false;
	isToSelect=false;
	tempStart.setX(0);
	tempStart.setY(0);
	tempStart.setZ(0);
	tempEnd.setX(0);
	tempEnd.setY(0);
	tempEnd.setZ(0);

	//计数器
	select_line=100;
	for (int i=0;i<=99;i++)
	{
		select_line1[100]=-1;
	}

	select_d=0;
	mode1=GL_RENDER;
	
	swidth=0;sheight=0;
}
GLWidget::~GLWidget(void)
{
}
void GLWidget::initializeGL()
{
	glClearColor(0,0,0,1);
	glEnable(GL_CULL_FACE);
	glShadeModel(GL_FLAT);
	
	glutInitDisplayMode(GLUT_DEPTH);
	glEnable(GL_DEPTH_TEST);  //启用深度缓存
}
void GLWidget::resizeGL(int width, int height)  
{
	// Sets up the OpenGL viewport, projection, etc.
	// Sets up the OpenGL viewport, projection, etc.
	glViewport(0,0,width,height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	GLfloat x = GLfloat(width) / height;
	GLfloat y = GLfloat( height) /width;
	glFrustum(-x, +x, -y, +y, 0.0, 1000.0);   //near and far must be positive

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	viewportSize[0] = width;
	viewportSize[1] = height;

}
void GLWidget::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
	mode1=GL_RENDER;
    draw();
}
void GLWidget::view_change(){
	if (view_choice == 0){
		if (ischanged != 0){
			ischanged = 0;
			rotationX = -60, rotationY = 0, rotationZ = -60;
			trans_X = -5.0, trans_Y = 1.0, trans_Z = -10.0;
			scaling = 0.4;
		}
	}
	if (view_choice == 1){
		if (ischanged != 1){
			ischanged = 1;
			rotationX = 0, rotationY = 0, rotationZ = 0;
			trans_X = -5.0, trans_Y = 1.0, trans_Z = -10.0;
			scaling = 0.4;
		}
	}
	if (view_choice == 2){
		if (ischanged != 2){
			ischanged = 2;
			rotationX = -90, rotationY = 0, rotationZ = 0;
			trans_X = -5.0, trans_Y = 1.0, trans_Z = -10.0;
			scaling = 0.4;
		}
	}
	if (view_choice == 3){
		if (ischanged != 3){
			ischanged = 3;
			rotationX = -90, rotationY = 0, rotationZ = 90;
			trans_X = -5.0, trans_Y = 1.0, trans_Z = -10.0;
			scaling = 0.4;
		}
	}
}
void GLWidget::draw()
{
	view_change();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(trans_X,trans_Y,trans_Z);
	glRotatef(rotationX, 1.0, 0.0, 0.0);
	glRotatef(rotationY, 0.0, 1.0, 0.0);
	glRotatef(rotationZ, 0.0, 0.0, 1.0);
	/*scaling = 0.1;*/
	glScalef(scaling, scaling, scaling);
	glMatrixMode(GL_PROJECTION);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); 
	//glLoadIdentity();

	if(view_choice)glOrtho(-10.0,10.0,-10.0,10.0,1,100);
	else gluPerspective(90, 1,0.1,100);
	drawAxe();

	if (enableLineDrawing){
		mlayout.drawAssisitLine(tempStart, tempEnd, 0, endofDrawing);
	}
	if (enableSurfaceDrawing){
		mlayout.drawAssisitLine(tempStart, tempEnd, 1, endofDrawing);
	}
	if (enablePartDrawing){
		mlayout.drawAssisitSurface(tempStart, tempEnd, 0, endofDrawing);
	}
	if (enableBodyDrawing){
		mlayout.drawAssisitSurface(tempStart, tempEnd, 1, endofDrawing);
	}
	mlayout.drawLayout();
	
	int s4=4;
}
void GLWidget::drawAxe()
{
	//画坐标平面
	glLineStipple (1, 0xCCCC); 
	glPointSize(0.1);
	glEnable(GL_LINE_STIPPLE);
	glLoadName(50);
	glLineWidth(1.0);
    glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	for(int i = 1; i <=20; ++i)
	{
		glVertex3f(i,0,0);
		glVertex3f(i,20,0);
	}
	for(int i = 1; i <=20; ++i)
	{
		glVertex3f(0,i,0);
		glVertex3f(20,i,0);
	}
	glEnd();
	//画直角坐标系
	//glLineWidth(4) ;
	glDisable(GL_LINE_STIPPLE);
	glBegin(GL_LINES);
	//X Axis
	glColor3f(1.0,0.0,0.0);
	glVertex3f(0,0,0);
	glVertex3f(6,0,0);
	//-----------绘制箭头
	glVertex3f(6,0,0);
	glVertex3f(4.5,0.2,0);
	glVertex3f(6,0,0);
	glVertex3f(4.5,-0.2,0);
	//Y  Axis
	glColor3f(0,1,0);
	glVertex3f(0,0,0);
	glVertex3f(0,6,0);
	//-----------绘制箭头
	glVertex3f(0,6,0);
	glVertex3f(-0.2,4.5,0);
	glVertex3f(0,6,0);
	glVertex3f(0.2,4.5,0);
	//Z  Axis
	glColor3f(0,0,1);
	glVertex3f(0,0,0);
	glVertex3f(0,0,4);
	//-----------绘制箭头
	glVertex3f(0,0,4);
	glVertex3f(0,-0.2,3);
	glVertex3f(0,0,4);
	glVertex3f(0,0.2,3);
	glEnd();
}
void GLWidget::mousePressEvent(QMouseEvent *event)
{
	/*emit distance1("0");
	emit distance2("0");*/
	lastPos=event->pos();

	
	if (event->buttons() & Qt::RightButton ) 
	{
		//rotationX += 180 * dy;  //rotationX += 180 * dy;
		//rotationY += 180 * dx;  //rotationY += 180 * dx; 
		//rotationZ += 180* dx;  //rotationZ +=  180 * dz; 
		endofDrawing = true;
		isRight=true;
	}
	if (event->buttons()&Qt::MidButton)
	{
		isMid=true;
	}
	if (event->buttons() & Qt::LeftButton ){
	   lastPos1=lastPos;
	   tempStart.setXYZ(lastPos1.x(), lastPos1.y());
	   if (enableLineDrawing || enableSurfaceDrawing){
		   mlayout.getLine(event,  endofDrawing);
	   }
	   if (enablePartDrawing || enableBodyDrawing){
		   mlayout.getSurface(event, endofDrawing);
	   }
	   isLeft=true;
	}
	this->updateGL();
}
void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
	lastPos2=event->pos();
	//跟踪鼠标移动，获取当前鼠标在Z=0平面的坐标
	GLfloat dx = GLfloat(event->x() - lastPos.x()) / width();
	GLfloat dy = GLfloat(event->y() - lastPos.y()) / height();
	lastPos = event->pos();
	tempEnd.setXYZ(event->x(), event->y());
	curPos[0]=event->pos().x();
	curPos[1]=viewportSize[1] - event->pos().y();
 //   //---------------旋转操作-------------------
	if (event->buttons() & Qt::RightButton)
	{
		rotationX += 80 * dy;
		rotationY += 80 * dy;
		rotationZ += 80 * dx;
	}
	else if (event->buttons() & Qt::MidButton)
	{
		trans_X +=8*dx;  // 加快移动速度 8+
		trans_Y -=8*dy;
	}
	if (event->buttons() & Qt::LeftButton){
	}
	this->updateGL();
}
void GLWidget::mouseReleaseEvent(QMouseEvent *event){
    releasePos=event->pos(); 
	if(isToSelect==true&&(event->button() == Qt::LeftButton ))
	 select(releasePos);
}
void GLWidget::wheelEvent(QWheelEvent *event)  //mouseWheelEvent
{
	double numDegrees = -event->delta() / 8.0;
	double numSteps = numDegrees / 15.0;
	scaling *= std::pow(2, numSteps);  //1.125
	update();
}
void GLWidget::keyPressEvent(QKeyEvent *event){
}
void GLWidget::saveGraph(){
	mFile.saveProject(mlayout);
}
void GLWidget::loadGraph(){
	mFile.readfromFile(mlayout);
	mlayout.surfaceNum = mlayout.Sur.size();
	mlayout.bodyNum = mlayout.Pob.size();
}
void GLWidget::newProject(){
	mlayout.Pob.clear();
	mlayout.Sur.clear();
	mlayout.Lin.clear();
	mlayout.lineNum = 0;
	mlayout.surfaceNum = 0;
	mlayout.bodyNum = 0;
}

void GLWidget::processHits(GLint hits, GLuint buffer[])
{
	unsigned int i=0;
	GLuint name;///////////////////////////////////-----------------------------------------------------------------------
	for(i=0;i<=hits;i++)
		if(buffer[3+i*4]!=50)
		{ 
			select_line1[select_d] = buffer[3+i*4];
			if(multi) select_d++;
			break;}
}
void GLWidget::select(QPoint releasePos)
{
	GLfloat  xx= releasePos.x();
	GLfloat yy =releasePos.y();
	int N1=5,N2=5,SIZE=500;

	//	select_line1[0]=100;
	GLuint selectBuffer[500];//存放物体名称的栈
	GLint hits;//存放被选中对象个数
	GLint viewport[4];//存放可视区参数
	glGetIntegerv(GL_VIEWPORT,viewport);//获取当前视口坐标参数
	glSelectBuffer(SIZE,selectBuffer);//选择名称栈存放被选中的名称
	glRenderMode(GL_SELECT);//设置当前为 选择模式
	//初始化名称栈
	glInitNames();
	glPushName(0);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();/////////

	gluPickMatrix(xx,viewport[3]-yy+viewport[1],N1,N2,viewport);//创建用于选择的投影矩阵栈
	GLfloat  x = GLfloat(swidth) / sheight;
	GLfloat y = GLfloat(sheight) /swidth;
	glFrustum(-x, +x, -y, +y, 0.0, 1000.0);   //near and far must be positive
	mode1=GL_SELECT;

	draw();//绘制场景
	glPopMatrix();
	glFlush();
	hits = glRenderMode(GL_RENDER);
	glMatrixMode(GL_MODELVIEW);
	if(hits > 0) processHits(hits,selectBuffer);
	paintGL(); 
	// display();   与下条一样效果
	//    glutPostRedisplay();
	int ss=1;
}
/*
vector<Lines> GLWidget::findFaceLine(int LineNo){
	vector<Lines> tp;
	bool findflag=false;

	for(int i=0; i <= planes.getSurfaceNum()-1; i++){
		if(findflag) break;
		Surfaces tempSur= planes.getSurface(i);
		for( int j=0; j<=tempSur.getCount()-1; j++)
			if( tempSur.getLine(j).getNumber()==LineNo)
			{			for (int k = 0; k <= tempSur.getCount() - 1; k++){
				planes.getSurface(i).line[k].setRGB(1,0,0);
				tp.push_back(planes.getSurface(i).line[k]);

			}
			findflag=true; break;
			}
	}
	return tp;
}
vector<Lines> GLWidget::findSelectedLine(int LineNo){
	bool findFlag = false;
	vector<Lines> tp;
	if (!planes.Sur.empty())
		for (int i = 0; i <= planes.Sur.size() - 1; i++){
			Surfaces tempSur = planes.Sur[i];
			if (!tempSur.line.empty())
				for (int j = 0; j <= tempSur.line.size() - 1; j++){
					if (tempSur.line[j].number == LineNo){
						for (int k = 0; k <= tempSur.line.size() - 1; k++){
							findFlag = true;
							tp.push_back(tempSur.line[k]);
						}
						selectedSurfaceNumber = tempSur.number;
						return tp;
					}
				}
		}
		if (!planes.Pob.empty())
			for (int i = 0; i <= planes.getBodysCount() - 1; i++){
				Bodys tempPob = planes.getBodys(i);
				if (!findFlag)
					for (int j = 0; j <= tempPob.parts.size() - 1; j++){
						Surfaces tempSur = tempPob.parts.at(j);
						if (!findFlag){
							if (!tempSur.subSurface.empty()){
								for (int z = 0; z <= tempSur.subSurface.size() - 1; z++)
									if (!tempSur.subSurface[z].line.empty())
									{
										for (int pc = 0; pc <= tempSur.subSurface[z].line.size() - 1; pc++){
											Lines tempL = tempSur.subSurface[z].line[pc];
											if (tempL.getNumber() == LineNo){
												findFlag = true;

												for (int k = 0; k <= tempSur.subSurface[z].line.size() - 1; k++){
													planes.getBodys(i).parts.at(j).subSurface[z].line[pc].setRGB(1, 0, 0);
													tp.push_back(planes.getBodys(i).parts.at(j).subSurface[z].line[k]);

												}
												selectedSurfaceNumber = planes.Pob[i].parts[j].subSurface[z].number;
												sharedData::selectSurfaceNumber = selectedSurfaceNumber;
												break;

											}

										}

									}

							}
							for (int z = 0; z <= tempSur.getCount() - 1; z++){
								Lines tempL = tempSur.getLine(z);
								if (tempL.getNumber() == LineNo){
									findFlag = true;
									for (int k = 0; k <= tempSur.getCount() - 1; k++){
										planes.getBodys(i).parts.at(j).getLine(k).setRGB(1, 0, 0);
										tp.push_back(planes.getBodys(i).parts.at(j).getLine(k));

									}
									selectedSurfaceNumber = planes.Pob[i].parts[j].number;
									sharedData::selectSurfaceNumber = selectedSurfaceNumber;
									break;
								}
							}
						}
					}
			}
			return tp;
}
*/
