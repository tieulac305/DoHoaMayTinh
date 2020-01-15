#include <graphics.h>

void langbat(int x1, int y1, int x2, int y2, int xa, int ya, int xb, int yb){
	int dx=xb-xa,dy=yb-ya;
	int p[]={-dx,dx,-dy,dy};
	int q[]={xa-x1,-ax+x2,ya-y1,-ya+y2};
	float t1=1,t2=0,t;
	
	for(int i=0 ; i<4 ; i++){
		t=(float) q[i]/p[i];
		if(p[i]>0) t1=std::min(t,t1);
		if(p[i]<0) t2=std::max(t,t2);
	}
	if(t1>=t2){
		int xa1=(int) (xa+t1*dx+0.5); // round
		int ya1=(int) (ya+t1*dy+0.5);
		int xa2=(int) (xa+t2*dx+0.5);
		int ya2=(int) (ya+t2*dy+0.5);
		line(xa1,ya1,xa2,ya2);
	}
}

int main(){
	initwindow(640,480);
	rectangle(100,100,300,250);
	setcolor(GREEN);
	line(100,50,250,200);
	getch();
	setcolor(RED);
	langbat(100,100,300,250,100,50,250,200);
	//duong thang nua do o trong view, vang o ngoai view
	
	getch();
	closegraph();
	
	return 0;
}
