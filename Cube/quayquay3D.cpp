#include <graphics.h>
#include <cmath>
#include <iostream>

struct Diem3D {float x, y, z;};
struct Diem2Di {int x, y;};
struct Diem2Df {float x, y;};
struct Canh {Diem3D d1, d2;};

float R, phi, teta, D, tlx, tly;
int phepchieu;
Diem2Di o;
Diem3D a[8];
Canh c[12];

void chuyenhqs(Diem3D m, Diem3D &mv )
{
  mv.x= -m.x*sin(teta)+m.y*cos(teta);
  mv.y= -m.x*cos(teta)*sin(phi)-m.y*sin(teta)*sin(phi)+m.z*cos(phi);
  mv.z= -m.x*sin(teta)*cos(phi) - m.y*cos(teta)*sin(phi)-m.z*sin(phi)+R;
}
void chieu3D_2D (Diem3D mv, Diem2Df &mp )
{
  if (phepchieu==1) mp.x=D*mv.x/mv.z, mp.y=D*mv.y/mv.z;
  else mp.x=mv.x, mp.y=mv.y;
}
void chuyenmh(Diem2Df mp, Diem2Di &mm)
{
  mm.x= (int) (tlx*mp.x+o.x+0.5);
  mm.y= (int) (-tly*mp.y +o.y+0.5);
}

void chuyenden3D(Diem3D m)
{
  Diem3D mv; Diem2Df mp; Diem2Di mm;
  chuyenhqs(m,mv);
  chieu3D_2D(mv,mp);
  chuyenmh(mp,mm);
  moveto(mm.x,mm.y);
}
void veden3D(Diem3D m)
{
  Diem3D mv; Diem2Df mp; Diem2Di mm;
  chuyenhqs(m,mv);
  chieu3D_2D(mv,mp);
  chuyenmh(mp,mm);
  lineto(mm.x,mm.y);
}
void khoitao(float r, float p, float t, float d)
{
  R=r; phi=p; teta=t; D=d; tlx=100; tly=100;
  teta=teta*M_PI/180; phi=phi*M_PI/180;
  phepchieu=1;
  o.x=getmaxx()/2;
  o.y=getmaxy()/2;
}
void khoitaoHLP()
{
  a[0].x=1; a[0].y=0; a[0].z=1;
  a[1].x=0; a[1].y=0; a[1].z=1;
  a[2].x=0; a[2].y=1; a[2].z=1;
  a[3].x=1; a[3].y=1; a[3].z=1;
  a[4].x=1; a[4].y=1; a[4].z=0;
  a[5].x=1; a[5].y=0; a[5].z=0;
  a[6].x=0; a[6].y=0; a[6].z=0;
  a[7].x=0; a[7].y=1; a[7].z=0;

  c[0].d1=a[0]; c[0].d2=a[1];
  c[1].d1=a[1]; c[1].d2=a[2];
  c[2].d1=a[2]; c[2].d2=a[3];
  c[3].d1=a[3]; c[3].d2=a[0];
  c[4].d1=a[3]; c[4].d2=a[4];
  c[5].d1=a[2]; c[5].d2=a[7];
  c[6].d1=a[1]; c[6].d2=a[6];
  c[7].d1=a[0]; c[7].d2=a[5];
  c[8].d1=a[5]; c[8].d2=a[6];
  c[9].d1=a[5]; c[9].d2=a[4];
  c[10].d1=a[4]; c[10].d2=a[7];
  c[11].d1=a[7]; c[11].d2=a[6];
}
void veHLP(int m)
{
  setcolor(m);
  for(int i=0; i<12; i++)
  {
    chuyenden3D(c[i].d1);
    veden3D(c[i].d2);
  }
}
int main()
{
  int gd=0, gm;
  initgraph(&gd, &gm, "");
  float r=7,d=4,t=60,p=30;
  bool ok=true;

  while(ok){
    khoitao(r,p,t,d);
    khoitaoHLP();
    veHLP(3);
    char q=getch();
    switch(q){
      case 'a': t-=10; break;
      case 'd': t+=10; break;
      case 's': p-=10; break;
      case 'w': p+=10; break;
      case 'q': r-=0.2; break;
      case 'e': r+=0.2; break;
      case 'r': d-=0.2; break;
      case 'f': d+=0.2; break;
      default: ok=false; break;
    }
    veHLP(getbkcolor());
  }
  closegraph();
  return 0;
}

