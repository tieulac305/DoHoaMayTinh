#include <graphics.h>

void bienxnua(int x, int y, int mb, int mt, int i){
	int c=getcolor();//de tra lai mau sau khi to
	setcolor(mt);
	int x1,x2;
	do{
		x1=x,x2=x;
		while(getpixel(x1-1,y)!=mb) x1=x1-1;
		while(getpixel(x2+1,y)!=mb) x2=x2+1;
		line(x1,y,x2+1,y);
		/*
		khong hieu sao cho nay ve bi thieu 1 pixel
		phai viet thanh ntn moi kin:
		line(x1,y,x2+1,y);
		*/
		while(getpixel(x1,y+i)==mb) x1=x1+1;
		x=x1;
		y=y+i;
	}while(x1<=x2);
	
	setcolor(c);
}

void bienx(int x, int y, int mb, int mt){
	bienxnua(x,y,mb,mt,1);
	bienxnua(x,y,mb,mt,-1);
}


int main(){
	initwindow(640,480);
	setcolor(GREEN);
	
	circle(300,200,100);
	bienx(300,200,GREEN,YELLOW);
	
	getch();
	closegraph();
	
	return 0;
}
