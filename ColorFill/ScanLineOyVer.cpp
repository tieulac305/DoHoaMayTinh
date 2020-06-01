#include <graphics.h>

void HTCB(int xamin,int xdmax, int ya, int yb, int yc,int yd, int mt){
	//HTCB co day song song voi Oy, co diem AB xmin, CD xmax
	int y1=ya,y2=yb,x=xamin; //toa do 2 giao diem
	float m1=(float)(yd-ya)/(xdmax-xamin);
	float m2=(float)(yc-yb)/(xdmax-xamin);//nhin si da the nhe

	int c=getcolor();
	setcolor(mt);

	while(x<=xdmax){
		line(x,y1,x,y2);
		y1=(int)ya+m1*(x-xamin);
		y2=(int)yb+m2*(x-xamin);
		x+=1;
	}

	setcolor(c);
}

int main(){
	initwindow(640,480);

	circle(50,300,10);//A
	circle(50,100,10);//b
	circle(150,50,10);
	circle(300,150,10);
	circle(350,200,10);
	line(50,10,350,200);

//	HTCB(100,300,50,350,300,150,3);
//	HTCB(20,100,250,250,50,350,3);

	getch();
	closegraph();

	return 0;
}
