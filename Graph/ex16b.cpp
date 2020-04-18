# include <graphics.h>
# include <cmath>

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

void tructoado(){
  int m=getcolor();
  setcolor(WHITE);

  if(ywmax*ywmin<=0){
    chuyenden2D(xwmin,0);
    veden2D(xwmax,0);
  }
  if(xwmax*xwmin<=0){
    chuyenden2D(0,ywmin);
    veden2D(0,ywmax);
  }
  setcolor(m);
}

void vedothi(float xmin, float xmax){
  tructoado();
	float dx=0.01;
	float x=xmin;
	float y=x*x+1;
	chuyenden2D(x,y);
	while (x<=xmax){
		x=x+dx;
		y=x*x+1;
		veden2D(x,y);
	}
}

void tinhtien(float x, float y, float m, float n, float &x1, float &y1){
	x1=x+m;
	y1=y+n;
}

void quay90quanhO(float x, float y, float &x1, float &y1){
	x1=-y;
	y1=x;
}

void quay90quanhA(float x, float y, float xA, float yA, float &x1, float &y1){
	float x11, y11, x12, y12;
	tinhtien(x,y,-xA,-yA,x11,y11);
	quay90quanhO(x11,y11,x12,y12);
	tinhtien(x12,y12,xA,yA,x1,y1);
}

void veanhdothi(float xmin, float xmax){
  tructoado();
	float dx=0.01;
	float x=xmin;
	float y=x*x+1;
	float x1, y1;
	quay90quanhA(x, y, 0, 1, x1, y1);
	chuyenden2D(x1,y1);
	while (x<=xmax){
		x=x+dx;
		y=x*x+1;
		quay90quanhA(x, y, 0, 1, x1, y1);
		veden2D(x1,y1);
	}
}

int main(){
	int gd=0, gm;
	initgraph(&gd,&gm,"");
	cuaso(-5, -2, 3, 6);
	khungnhin(50,50,400,400);
	setcolor(RED);
	vedothi(-2,2);
	setcolor(YELLOW);
	veanhdothi(-2,2);
	getch();
	closegraph();
}
