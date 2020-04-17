#include <graphics.h>
#include <cmath>

// <fixed>
float xwmin, ywmin, xwmax, ywmax;
int xvmin, yvmin, xvmax, yvmax;
float tlx, tly;

void setView(int x1, int y1, int x2, int y2){
  xvmin=x1, yvmin=y1;
  xvmax=x2, yvmax=y2;
}
void setWin(float x1, float y1, float x2, float y2){
  xwmin=x1, ywmin=y1;
  xwmax=x2, ywmax=y2;
}
void cal(){
  tlx=(xvmax-xvmin)/(xwmax-xwmin);
	tly=(yvmax-yvmin)/(ywmax-ywmin);
}
void shiftWV(float xw, float yw, int &xv, int &yv){
	xv=(int) (tlx*(xw-xwmin)+xvmin+0.5);
	yv=(int) (tly*(ywmax-yw)+yvmin+0.5);
}
void moveTo(float x, float y){
  int nx,ny;
  shiftWV(x,y,nx,ny);
  moveto(nx,ny);
}
void lineTo(float x, float y){
  int nx,ny;
  shiftWV(x,y,nx,ny);
  lineto(nx,ny);
}
// </fixed>

void xoayquanhO(float x, float y, double goc, float &a, float &b){
  a=cos(goc)*x-sin(goc)*y;
  b=sin(goc)*x+cos(goc)*y;
}
//hom nay hoi buon
//buon den noi viet xong dong tren ma em khoc luon
//chac co khong doc dau nhi

class Quat{
private:
  float l,x1,y1,x2,y2,x3,y3;
  void mo();
  void dong();
public:
  Quat(float x, float y, float z){
    x1=x2=x3=0;
    y1=-x;
    y2=y;
    y3=z;
    l=x+y+z;
  }
  void lifecycle();
};

void Quat::mo(){
  setcolor(12);
  //moi lqn chi ve phia tren
  float xt1=x1,yt1=y2,xt2=x2,yt2=y2,xt3=x3,yt3=y3;
  float xp1=x1,yp1=y2,xp2=x2,yp2=y2,xp3=x3,yp3=y3;
  for(int i=0 ; i<=80 ; i+=2){
    double goc=i*M_PI/180;
    moveTo(xt2,yt2);
    xoayquanhO(x2,y2,goc,xt2,yt2);
    lineTo(xt2,yt2);
    moveTo(xt3,yt3);
    xoayquanhO(x3,y3,goc,xt3,yt3);
    lineTo(xt3,yt3);
    if(i%10==0){
      xoayquanhO(x1,y1,goc,xt1,yt1);
      moveTo(xt1,yt1);
      lineTo(xt3,yt3);
    }
    moveTo(xp2,yp2);
    xoayquanhO(x2,y2,-goc,xp2,yp2);
    lineTo(xp2,yp2);
    moveTo(xp3,yp3);
    xoayquanhO(x3,y3,-goc,xp3,yp3);
    lineTo(xp3,yp3);
    if(i%10==0){
      xoayquanhO(x1,y1,-goc,xp1,yp1);
      moveTo(xp1,yp1);
      lineTo(xp3,yp3);
      delay(305);
    }
  }
}

void Quat::dong(){
  setcolor(getbkcolor());
  float xt1=x1,yt1=y2,xt2=x2,yt2=y2,xt3=x3,yt3=y3;
  float xp1=x1,yp1=y2,xp2=x2,yp2=y2,xp3=x3,yp3=y3;
  double goc=80*M_PI/180;
  xoayquanhO(x1,y1,goc,xt1,yt1);
  xoayquanhO(x2,y2,goc,xt2,yt2);
  xoayquanhO(x3,y3,goc,xt3,yt3);
  xoayquanhO(x1,y1,-goc,xp1,yp1);
  xoayquanhO(x2,y2,-goc,xp2,yp2);
  xoayquanhO(x3,y3,-goc,xp3,yp3);
  for(int i=80 ; i>=0 ; i-=2){
    double goc=i*M_PI/180;
    moveTo(xt2,yt2);
    xoayquanhO(x2,y2,goc,xt2,yt2);
    lineTo(xt2,yt2);
    moveTo(xt3,yt3);
    xoayquanhO(x3,y3,goc,xt3,yt3);
    lineTo(xt3,yt3);
    moveTo(xp2,yp2);
    xoayquanhO(x2,y2,-goc,xp2,yp2);
    lineTo(xp2,yp2);
    moveTo(xp3,yp3);
    xoayquanhO(x3,y3,-goc,xp3,yp3);
    lineTo(xp3,yp3);
    if(i%10==0&&i!=0){
      delay(305);
      xoayquanhO(x1,y1,goc,xt1,yt1);
      moveTo(xt1,yt1);
      lineTo(xt3,yt3);
      xoayquanhO(x1,y1,-goc,xp1,yp1);
      moveTo(xp1,yp1);
      lineTo(xp3,yp3);
    }
  }
}

void Quat::lifecycle(){
  setWin(-2*l/3,y1,2*l/3,2*l/3);
  setView(0,0,600,300);
  cal();
  mo();
  getch();
  dong();
}

void vequat(float x, float y, float z){
  //x a chan, y la nua nan, z la phan quat
  Quat iloveu= Quat(x,y,z);
  iloveu.lifecycle();
}

int main(){
  int gdriver = EGA, gmode = EGAHI;
  initgraph(&gdriver, &gmode, "");
  setbkcolor(3);
  cleardevice();

  vequat(2,8,15);

  getch();
  closegraph();

  return 0;
}
