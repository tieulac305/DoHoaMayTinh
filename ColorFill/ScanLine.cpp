//ScanLine kho, HTCB thoi
//code theo code mau cua co

#include <graphics.h>

void HTCB(int xa, int xb, int xc, int xd, int yamin, int ydmax, int mt){
	//HTCB co day song song voi Ox, co diem AB ymin, CD ymax
	int x1=xa,x2=xb,y=yamin; //toa do 2 giao diem
	float m1=(float)(xd-xa)/(ydmax-yamin);
	float m2=(float)(xc-xb)/(ydmax-yamin);//he so goc
	
	int c=getcolor();
	setcolor(mt);
	
	while(y<=ydmax){
		line(x1,y,x2,y);
		x1=(int)xa+m1*(y-yamin);
		x2=(int)xb+m2*(y-yamin);
		y+=1;
	}
	
	setcolor(c);
}

int main(){
	initwindow(640,480);
	
	HTCB(200,350,550,130,100,300,5);
	
	getch();
	closegraph();
	
	return 0;
}
