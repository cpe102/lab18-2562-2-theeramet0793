//Modify function overlap() form lab18_1.cpp by using pointers as input arguments



#include<iostream>
#include<cmath>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect *,Rect *);

int main(){
    double a,b,c,d;
	cout << "Please input Rect 1 (x y w h): ";
	cin>>a>>b>>c>>d;
	Rect A={a,b,c,d};
	cout << "Please input Rect 2 (x y w h): ";
	cin>>a>>b>>c>>d;
	Rect B={a,b,c,d};
	cout << "Overlap area = ";	
	cout<<overlap(&A,&B);
	return 0;
}

double overlap(Rect *A,Rect *B){
 double dot1_x,dot1_y,dot2_x,dot2_y;	
 double ax[4],check_one_in_all=0;
 ax[0]=A->x;
 ax[1]=A->x+A->w;
 ax[2]=A->x+A->w;
 ax[3]=A->x;
 double ay[4];
 ay[0]=A->y;
 ay[1]=A->y;
 ay[2]=A->y-A->h;
 ay[3]=A->y-A->h;

  double bx[4];
 bx[0]=B->x;
 bx[1]=B->x+B->w;
 bx[2]=B->x+B->w;
 bx[3]=B->x;
 double by[4];
 by[0]=B->y;
 by[1]=B->y;
 by[2]=B->y-B->h;
 by[3]=B->y-B->h;

 for (int i = 0; i < 4; i++)
 {
	 if((ax[i]>=B->x&&ax[i]<=B->x+B->w)&&(ay[i]<=B->y&&ay[i]>=B->y-B->h))
	 {//cout<<" G "<<ax[i]<<" "<<ay[i];
	 dot1_x=ax[i];
	 dot1_y=ay[i];
	 check_one_in_all+=1;}
 }
///////////////////////////////////////////SPECIAL CASE
if(check_one_in_all==4){
return A->h*A->w;
}
check_one_in_all=0;
///////////////////////////////////////////
for (int i = 0; i < 4; i++)
 {
	 if((bx[i]>=A->x&&bx[i]<=A->x+A->w)&&(by[i]<=A->y&&by[i]>=A->y-A->h))
	 {//cout<<"  K  "<<bx[i]<<" "<<by[i];
	 dot2_x=bx[i];
	 dot2_y=by[i];
	 check_one_in_all+=1;}
 }
 ///////////////////////////////////////////SPECIAL CASE
 if(check_one_in_all==4){
return B->h*B->w;
}
 ////////////////////////////////////////////
 return abs(dot2_x-dot1_x)*abs(dot2_y-dot1_y);
 
}