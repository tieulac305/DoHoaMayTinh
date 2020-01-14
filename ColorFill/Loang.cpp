#include <graphics.h>

void loang(int x,int y, int mb, int mt){
	int cur=getpixel(x,y);
	if(cur!=mb&&cur!=mt){
		putpixel(x,y,mt);
		loang(x,y+1,mb,mt);
		loang(x,y-1,mb,mt);
		loang(x+1,y,mb,mt);
		loang(x-1,y,mb,mt);
	}
}

int main(){
	initwindow(640,480);
	setcolor(GREEN);
	
	circle(300,200,100);
	loang(300,200,GREEN,YELLOW);
	
	getch();
	closegraph();
	
	return 0;
}
