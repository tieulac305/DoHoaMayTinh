#include <graphics.h>

void put8pixel(int x0, int y0, int x, int y){
	int c=getcolor();
	putpixel(x0+x, y0+y, c);//1
	putpixel(x0+x, y0-y, c);//2
	putpixel(x0-x, y0+y, c);//3
	putpixel(x0-x, y0-y, c);//4
	putpixel(x0+y, y0+x, c);//5
	putpixel(x0+y, y0-x, c);//6
	putpixel(x0-y, y0+x, c);//7
	putpixel(x0-y, y0-x, c);//8
}

void brescircle(int x0, int y0 , int r){
	int x=0, y=r;
	int p=3-2*r;
	while(x<=y){
		put8pixel(x0,y0,x,y);
		if(p>0){
			y--;
			p=p+4*(x-y)+10;
		}
		else{
			p=p+4*x+6;
		}
		x++;
	}
}

int main(){
	initwindow(640,480);
	setcolor(GREEN);
	
	brescircle(300,200,100);
	
	getch();
	closegraph();
	
	return 0;
}
