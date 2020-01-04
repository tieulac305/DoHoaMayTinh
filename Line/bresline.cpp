#include <graphics.h>

void bresline(int x0, int y0, int x1, int y1){
	int dx=x1-x0, dy=y1-y0, xs=1, ys=1;
	int xx=0, xy=0, yx=0, yy=0;
	if(dx<0) xs=-1;
	if(dy<0) ys=-1;
	dx=abs(dx), dy=abs(dy);
	
	if(dx>dy){
		//TH3,4
		xx=xs;
		yy=ys;
	}
	else{
		std::swap(dx,dy);//TH5,6 (trao doi vai tro x,y)
		xy=ys;
		yx=xs;
	}
	
	int const1 = 2*dy;
	int const2 = 2*dy - 2*dx;
	int p = 2*dy - dx;
	int x,y,c;
	y=0;
	c=getcolor();
	for(x=0 ; x<=dx ; x++){
		putpixel(x0+ x*xx+ y*yx , y0+ x*xy+ y*yy, c);
		if(p<0){
			p+=const1;
		}
		else{
			p+=const2;
			y+=1;
		}
	}
}

int main(){
	initwindow(640, 480);
	setcolor(GREEN);
	
	bresline(100,200,300,200);//TH1
	bresline(200,100,200,300);//TH2
	bresline(300,250,100,150);//TH3
	bresline(100,250,300,150);//TH4
	bresline(100,100,200,300);//TH5
	bresline(200,300,300,100);//TH6
	
	getch();
	closegraph();
	
	return 0;
}
