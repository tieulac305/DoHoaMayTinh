#include <graphics.h>
#include <cmath>

float xwmin, ywmin, xwmax, ywmax;
float tlx, tly;
int xvmin, yvmin, xvmax, yvmax;

void cuaso(float x1, float y1, float x2, float y2){
	xwmin=x1; ywmin=y1;
	xwmax=x2; ywmax=y2;
}
void khungnhin(int x1, int y1, int x2, int y2){
	xvmin=x1; yvmin=y1;
	xvmax=x2; yvmax=y2;
	tlx=(xvmax-xvmin)/(xwmax-xwmin);
	tly=(yvmax-yvmin)/(ywmax-ywmin);
}
void chuyentoado(float &x, float &y){
  int xm=(int)(tlx*(x-xwmin)+xvmin+0.5);
	int ym= (int)(tly*(ywmax-y)+yvmin+0.5);
	x=xm,y=ym;
}

void chuyenden2D(float x, float y){
	chuyentoado(x,y);
	moveto(x,y);
}
void veden2D(float x, float y){
	chuyentoado(x,y);
	lineto(x,y);
}

void vetructoado(){
  int m=getcolor();
  setcolor(WHITE);
  float x1=xwmin,x2=xwmax,y1=0,y2=0;
  float x3=0,y3=ywmin,x4=0,y4=ywmax;
  //dung line luon cho nhanh
  chuyentoado(x1,y1);
  chuyentoado(x2,y2);
  chuyentoado(x3,y3);
  chuyentoado(x4,y4);
  if(ywmax*ywmin<0){
    line(x1,y1,x2,y2);
    line(x2-5,y2-5,x2,y2);
    line(x2-5,y2+5,x2,y2);
  }
  if(xwmax*xwmin<0){
    line(x3,y3,x4,y4);
    line(x4-5,y4+5,x4,y4);
    line(x4+5,y4+5,x4,y4);
  }
  setcolor(m);
}
void vedothi(float xmin, float xmax){
	float dx=0.01;
	float x=xmin;
	float y=tan(x)-2;
	chuyenden2D(x,y);
	while (x<=xmax){
		x=x+dx;
		y=tan(x)-2;
		veden2D(x,y);
	}
}

void tinhtien(float x, float y, float m, float n, float &x1, float &y1){
	x1=x+m;
	y1=y+n;
}

void doixungtamO(float x, float y, float &x1, float &y1){
	x1=-x;
	y1=-y;
}

void doixungtamA(float x, float y, float xA, float yA, float &x1, float &y1){
	float x11, y11, x12, y12;
	tinhtien(x,y,-xA,-yA,x11,y11);
	doixungtamO(x11,y11,x12,y12);
	tinhtien(x12,y12,xA,yA,x1,y1);
}

void veanhdothi(float xmin, float xmax){
  vetructoado();
	float dx=0.01;
	float x=xmin;
	float y=tan(x)-2;
	float x1, y1;
	doixungtamA(x, y, 0, -2, x1, y1);
	chuyenden2D(x1,y1);
	while (x<=xmax){
		x=x+dx;
		y=tan(x)-2;
		doixungtamA(x, y, 0, -2, x1, y1);
		veden2D(x1,y1);
	}
	//same do thi :v
}

int main(){
	int gd=0, gm;
	initgraph(&gd,&gm,"");
	cuaso(-M_PI/2, -3.5, M_PI/2, -0.5);
	khungnhin(50,50,300,300);
	setcolor(4);
	veanhdothi(-M_PI/4, M_PI/4);
	getch();
	closegraph();
}
