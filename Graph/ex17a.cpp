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
void chuyenden2D(float x, float y){
	int xm=(int)(tlx*(x-xwmin)+xvmin+0.5);
	int ym= (int)(tly*(ywmax-y)+yvmin+0.5);
	moveto(xm,ym);
}
void veden2D(float x, float y){
	int xm=(int)(tlx*(x-xwmin)+xvmin+0.5);
	int ym= (int)(tly*(ywmax-y)+yvmin+0.5);
	lineto(xm,ym);
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

int main(){
	int gd=0, gm;
	initgraph(&gd,&gm,"");
	cuaso(-M_PI/3, -3.5, M_PI/3, -0.5);
	khungnhin(50,50,500,400);
	setcolor(4);
	vedothi(-M_PI/4, M_PI/4);
	getch();
	closegraph();
}
