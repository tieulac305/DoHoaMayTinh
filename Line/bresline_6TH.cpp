#include <graphics.h>

void bresline1(int xa, int ya, int xb, int yb);
void bresline2(int xa, int ya, int xb, int yb);
void bresline3(int xa, int ya, int xb, int yb);
void bresline4(int xa, int ya, int xb, int yb);
void bresline5(int xa, int ya, int xb, int yb);
void bresline6(int xa, int ya, int xb, int yb);

int main(){
	initwindow(640, 480);
	setcolor(GREEN);
	
	bresline1(100,200,300,200);//TH1 if ya==yb
	bresline2(200,100,200,300);//TH2 else if xa==xb
	bresline3(300,250,100,150);//TH3 else if dx>dy -> toa do cung nho hon hoac lon hon
	bresline4(100,250,300,150);//TH4 else if dx>dy -> else
	bresline5(100,100,200,300);//TH5 else -> toa do cung nho hon hoac lon hon
	bresline6(200,300,300,100);//TH6 else -> else
	
	getch();
	closegraph();
	
	return 0;
}

void bresline1(int xa, int ya, int xb, int yb){
	//duong doc
	if(xa>xb) std::swap(xa,xb); //dam bao xa<=xb
	int c=getcolor();
	for(int x=xa ; x<=xb ; x++){
		putpixel(x,ya,c);
	}
}

void bresline2(int xa, int ya, int xb, int yb){
	//duong ngang
	if(ya>yb) std::swap(ya,yb); //dam bao ya<=yb
	int c=getcolor();
	for(int x=xa ; x<=xb ; x++){
		putpixel(xa,y,c);
	}
}

void bresline3(int xa, int ya, int xb, int yb){
	if(xa>xb){
		std::swap(xa,xb);
		std::swap(ya,yb);
	}
	
	int dx=xb-xa, dy=yb-ya;
	int const1 = 2*dy;
	int const2 = 2*dy - 2*dx;
	int p = 2*dy - dx;
	int x,y,c;
	y=ya;
	c=getcolor();
	for(x=xa ; x<=xb ; x++){
		putpixel(x,y,c);
		if(p<0){
			p+=const1;
		}
		else{
			p+=const2;
			y+=1;
		}
	}
	//TH base nen giong cai cho chung :3
}

void bresline4(int xa, int ya, int xb, int yb){
	if(xa>xb){
		std::swap(xa,xb);
		std::swap(ya,yb);
	}
	
	int dx=xb-xa, dy=yb-ya;
	int const1 = 2*dy;
	int const2 = 2*dy + 2*dx; // khac 3 cho nay
	int p = 2*dy - dx;
	int x,y,c;
	y=ya;
	c=getcolor();
	for(x=xa ; x<=xb ; x++){
		putpixel(x,y,c);
		if(p>=0){ // khac 3 cho nay
			p+=const1;
		}
		else{
			p+=const2;
			y-=1; // khac 3 cho nay
		}
	}
}

void bresline5(int xa, int ya, int xb, int yb){
	if(ya>yb){
		std::swap(xa,xb);
		std::swap(ya,yb);
	}
	
	int dx=xb-xa, dy=yb-ya;
	int const1 = 2*dx;
	int const2 = 2*dx - 2*dy;
	int p = 2*dx - dy;
	int x,y,c;
	x=xa;
	c=getcolor();
	for(y=ya ; y<=yb ; y++){
		putpixel(x,y,c);
		if(p<0){
			p+=const1;
		}
		else{
			p+=const2;
			x+=1;
		}
	}
	//van la 3 nhung trong hinh dang khac :v
}

void bresline6(int xa, int ya, int xb, int yb){
	if(ya>yb){
		std::swap(xa,xb);
		std::swap(ya,yb);
	}
	
	int dx=xb-xa, dy=yb-ya;
	int const1 = 2*dx;
	int const2 = 2*dx + 2*dy; // khac 5 cho nay
	int p = 2*dx - dy;
	int x,y,c;
	x=xa;
	c=getcolor();
	for(y=ya ; y<=yb ; y++){
		putpixel(x,y,c);
		if(p>=0){ // khac 5 cho nay
			p+=const1;
		}
		else{
			p+=const2;
			x-=1; // khac 5 cho nay
		}
	}
	//van la 4 nhung trong hinh dang khac :v
}
