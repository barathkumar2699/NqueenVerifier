#include<stdio.h>
#include<conio.h>
#define LT 218
#define RT 191
#define CROSS 197
#define HL 196
#define VL 179
#define TT 194
#define BT 193
#define LST 195
#define RST 180
#define LB 192
#define RB 217
#define BS 8
#define SPACE 32
#define WIDTH 7
#define HEIGHT 1
#define DIM 8

int qmat[DIM][DIM];

void drawBox()
{
 int bcol,brow;
 int ctr1,ctr2,ctr3;
 bcol = (80 - (DIM*WIDTH + DIM +1 ))/2;
 brow = (25 - (DIM*HEIGHT + DIM +1 ))/2;
   gotoxy(bcol,brow);
   printf("%c",LT);
  for(ctr2=1;ctr2<=DIM;ctr2++)
  {
   for(ctr1=1;ctr1<=WIDTH;ctr1++)
    printf("%c",HL);
   printf("%c",TT);
  }
  printf("%c%c",BS,RT);
  //end of first line
 for(ctr3=1;ctr3<=DIM;ctr3++)
 {
 gotoxy(bcol,++brow);
 for(ctr2=1;ctr2<=DIM+1;ctr2++)
 {
  printf("%c",VL);
  for(ctr1=1;ctr1<=WIDTH;ctr1++)
    printf("%c",SPACE);
  }
 gotoxy(bcol,++brow);
 printf("%c",LST);
  for(ctr2=1;ctr2<=DIM;ctr2++)
  {
   for(ctr1=1;ctr1<=WIDTH;ctr1++)
    printf("%c",HL);
   printf("%c",CROSS);
 }
  printf("%c%c",BS,RST);
 }
 //end of mid part
    gotoxy(bcol,brow);
   printf("%c",LB);
  for(ctr2=1;ctr2<=DIM;ctr2++)
  {
   for(ctr1=1;ctr1<=WIDTH;ctr1++)
    printf("%c",HL);
   printf("%c",BT);
  }
  printf("%c%c",BS,RB);

}


int verifyQ(){
 int row, col, ind, ind1, ind2;
 for( row =0; row<DIM; row++){
   for(col=0; col<DIM; col++){
     if(qmat[row][col]==1){
	for(ind=col+1;ind<DIM;ind++)
	 if(qmat[row][ind]==1)
	  return 0;
	for(ind=row+1;ind<DIM;ind++)
	  if(qmat[ind][col]==1)
	   return 0;
	for(ind1=row+1, ind2=col+1; ind1<DIM && ind2<DIM; ind1++,ind2++)
	  if(qmat[ind1][ind2]==1)
	   return 0;
	for(ind1=row+1, ind2=col-1; ind1<DIM && ind2>=0; ind1++, ind2--)
	  if(qmat[ind1][ind2]==1)
	    return 0;
     }
   }
 }
 return 1;
}




#define Q 4177
#define q 4209
#define BSPACE 3592
#define ENTER 7181
#define LEFT 19200
#define RIGHT 19712
#define UP 18432
#define  DOWN  20480
#define ESC 283
#define r 4978
#define R 4976
int main()
{
 int key;
 int count,check;
 //int qmat[DIM][DIM];
 int row,col;
 int bcol, brow;
 clrscr();
L1:
 count=0;
 drawBox();
 for(row=0;row<DIM;row++)
	for(col=0;col<DIM;col++)
		qmat[row][col]=0;
 bcol = (80 - (DIM*WIDTH + DIM +1-7 ))/2;
 brow = (25 - (DIM*HEIGHT + DIM +1-2 ))/2;
 gotoxy(bcol,brow);

 do
 {
 while(bioskey(1)==0);//wait &*watch
 key =bioskey(0); //receptionist enquire
// printf("%d",key);
 switch(key)
 {
  case LEFT:


		if(bcol >= (80 - (DIM*WIDTH ))/2 ){
		 bcol-=8;
		 gotoxy(bcol,brow);
		}
		break;
  case RIGHT:
		if(bcol <= (80-(DIM+WIDTH)) ){
		 bcol+=8;
		 gotoxy(bcol,brow);
		}
		break;
  case UP:
		if(brow >= (25 - (DIM*HEIGHT+4 ))/2 ){
		 brow-=2;
		 gotoxy(bcol,brow);
		}
		break;
  case DOWN:
		if(brow <= (25 - DIM+HEIGHT )){
		 brow+=2;
		 gotoxy(bcol,brow);
		}
		break;

  case ENTER:
	       //	check=verifyQ(qmat);
		gotoxy(20,3);
	       //	printf("%d",count);
		if(count!=DIM){
		  printf("	   Try Again			");
		  goto L1;
		}
		else
		{
		  check=verifyQ();
		  if(check)
		  printf("Congradulations! You are correct...");
		  else{
		    printf("	   Try again			");
		    goto L1;
		  }
		}
	       bcol = (80 - (DIM*WIDTH + DIM +1-7 ))/2;
	       brow = (25 - (DIM*HEIGHT + DIM +1-2 ))/2;
	       gotoxy(bcol,brow);
	       break;
  case BSPACE:
	count--;
	qmat[(brow-((25 - (DIM*HEIGHT + DIM +1-2 ))/2))/2][(bcol-((80 - (DIM*WIDTH + DIM +1-7 ))/2))/8] = 0;
	gotoxy(bcol,brow);
	printf(" ");
	gotoxy(bcol,brow);
	break;


  case Q:
  case q:
	if(qmat[(brow-((25 - (DIM*HEIGHT + DIM +1-2 ))/2))/2][(bcol-((80 - (DIM*WIDTH + DIM +1-7 ))/2))/8] ==0){
	printf("Q");
	count++;
	qmat[(brow-((25 - (DIM*HEIGHT + DIM +1-2 ))/2))/2][(bcol-((80 - (DIM*WIDTH + DIM +1-7 ))/2))/8] = 1;
       //	printf("%d %d",(brow-((25 - (DIM*HEIGHT + DIM +1-2 ))/2))/2,(bcol-((80 - (DIM*WIDTH + DIM +1-7 ))/2))/8)(brow-((25 - (DIM*HEIGHT + DIM +1-2 ))/2))/2,(bcol-((80 - (DIM*WIDTH + DIM +1-7 ))/2))/8);
	}
	break;
 }

 }while(key!=ESC);


 getch();
 return 0 ;
}
