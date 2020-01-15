#include <graphics.h>

int kod(int x1,int y1, int x2, int y2, int x, int y){
	int k=0;
	if(x<x1) k=k*2;
	else k=k*2+1;
	if(x>x2) k=k*2;
	else k=k*2+1;
	if(y<y1) k=k*2;
	else k=k*2+1;
	if(y>y2) k=k*2;
	else k=k*2+1;
	return k;
}

int get(int x, int i){
	return ((x>>i)&1);
}

void swap(int &a,int &b){
	int tmp=a;
	a=b;
	b=tmp;
}

void clip(int x1, int y1, int x2, int y2, int xa, int ya, int xb, int yb){
	while(true){
		int a=kod(x1,y1,x2,y2,xa,ya);
		int b=kod(x1,y1,x2,y2,xa,ya);
		
		if(a==0&&b==0){
			//deu o trong
			line(xa,ya,xb,yb);
			return; //TH1
		}
		else if(a&b){
			return; //TH2
		}
		else{
			//TH3
			if(a==0){
				swap(xa,xb);
				swap(ya,yb);
				a=kod(x1,y1,x2,y2,xa,ya);
			}
			float m=(float)(yb-ya)/(xb-xa);//slope
			if(get(a,3)==1){
				ya=(int) (m*(x1-xa)+ya);
				xa=x1;
			}
			else if(get(a,2)==1){
				ya=(int) (m*(x2-xa)+ya);
				xa=x2;
			}
			else if(get(a,1)==1){
				xa=(int) (1/m*(y1-ya)+xa);
				ya=y1;
			}
			else if(get(a,0)==1){
				xa=(int) (1/m*(y2-ya)+xa);
				ya=y2;
			}
		}
	}
}

int main(){
	initwindow(640,480);
	rectangle(100,100,300,250);
	setcolor(GREEN);
	line(100,50,250,80);
	getch();
	
	setcolor(YELLOW);
	line(100,50,250,80);
	setcolor(RED);
	clip(100,100,300,250,100,50,250,80);
	//duong thang nua do o trong view, vang o ngoai view
	
	getch();
	closegraph();
	
	return 0;
}
