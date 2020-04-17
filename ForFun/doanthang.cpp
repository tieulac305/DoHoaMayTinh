#include <iostream>
#include <graphics.h>
#include <cmath>
#include <vector>

class Diem{
public:
  int x,y;
  Diem(int x1,int y1){
    x=x1,y=y1;
  }
  void show();
};

class Duong{
public:
  double s,a,b,c;
  int h,x,y;
  int x1,x2,y1,y2;
  Duong(double ss, int xx, int yy){
    //qua diem x,y
    //y=ax+b
    //xuat phat tu a=-1: -1->1, sau do di tu 1 ve -1
    s=ss,x=xx,y=yy;
    //tinh a, b, c khi co s
    a=sin(s);
    b=-cos(s);
    c=-(a*x+b*y);
    std::vector < Diem > hi;
    int xc,yc;
    xc=0;
    yc=-(int)(c/b);
    if(0<=yc&&yc<480){
      hi.push_back(Diem(xc,yc));
    }
    xc=639;
    yc=-(int)((c+639*a)/b);
    if(0<=yc&&yc<480){
      hi.push_back(Diem(xc,yc));
    }
    yc=0;
    xc=-(int)((c+b*yc)/a);
    if(0<=xc&&xc<640){
      hi.push_back(Diem(xc,yc));
    }
    yc=479;
    xc=-(int)((c+b*yc)/a);
    if(0<=xc&&xc<640){
      hi.push_back(Diem(xc,yc));
    }
    x1=hi[0].x,y1=hi[0].y,x2=hi[1].x,y2=hi[1].y;
    //a=y1-y2,b=x2-x1,c=-a*x1-b*y1;
  }
  bool has(Diem A);
  void del();
  void show();
};

void Diem::show(){
  setcolor(3);
  setfillstyle(1,3);
  circle(x,y,2);
  floodfill(x, y, 3);
}

void Duong::show(){
  setcolor(15);
  line(x1,y1,x2,y2);
  setcolor(3);
  setfillstyle(1,3);
  circle(x,y,3);
  floodfill(x,y, 3);
}

void Duong::del(){
  setcolor(getbkcolor());
  line(x1,y1,x2,y2);
  setcolor(3);
  setfillstyle(1,3);
  circle(x,y,2);
  floodfill(x,y,3);
}

bool Duong::has(Diem A){
  double qq=a*A.x+b*A.y+c;
//  if(qq>=-10.0&&qq<=10.0){
//    std::cout << qq << std::endl;
//  }
  return qq>=-5.0&&qq<=5.0;
}

void quay(std::vector <Diem> x, int i){
  int a,b,a1,b1;
  a=x[i].x,a1=a;
  b=x[i].y,b1=b;
  double g=0;
  Duong d=Duong(g,a,b);
  d.show();
  delay(50);

  double dg=0.005;
  double dgg=0;
  bool sw=false;
  int n=x.size();
  while(!kbhit()){
    g+=dg;
    d.del();
    d=Duong(g,a,b);
    if(sw==true&&dgg<0.2){
      dgg+=0.005;
      Diem tmp(a1,b1);
      tmp.show();
    }
    else sw=false,dgg=0;
    for(int i=0 ; i<n ; i+=1){
      if(sw&&x[i].x==a1&&x[i].y==b1) continue;
      if(x[i].x==a&&x[i].y==b) continue;
      if(d.has(x[i])){
        a1=a,b1=b;
        a=x[i].x;
        b=x[i].y;
        sw=true;
        break;
      }
    }
    d.show();
    delay(10);
  }
}

void vediem(std::vector < Diem > diem){
  for(unsigned int i=0 ; i<diem.size() ; i+=1){
    diem[i].show();
  }
}

int main()
{
  int gd=0, gm;
  initgraph(&gd,&gm,"");

  std::vector < Diem > diem;

  int n;
  std::cout << "Nhap vao so diem: ";
  std::cin >> n;
  std::cout << "Chon cua so graphics va nhan phim bat ki de dung chuong trinh.";

  for(int i=0 ; i<n ; i+=1){
    int x,y;
    x=rand()%640;
    y=rand()%480;
    diem.push_back(Diem(x,y));
  }

  vediem(diem);
  quay(diem,0);

  getch();
  closegraph();
  return 0;
}
