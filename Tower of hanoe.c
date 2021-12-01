#include<stdio.h>
void clear();
int input();
	char disk[5][14]={"      |      ","     =|=     ","    ==|==    ","   ===|===   ","  ====|====  "};
	int t[3][5]={{1,2,3,4,5},{0,0,0,0,5},{0,0,0,0,5}};
	int s,r,u,v,x;
	
int main()
{
	int i=0,j=3;
	printf("		  Tower Of Hanoe \n\n");
	printf("        |               |               |\n");
	printf("  %s   %s   %s\n",disk+t[0][0],disk+t[1][0],disk+t[2][0]);
	printf("  %s   %s   %s\n",disk+t[0][1],disk+t[1][1],disk+t[2][1]);
	printf("  %s   %s   %s\n",disk+t[0][2],disk+t[1][2],disk+t[2][2]);
	printf("  %s   %s   %s\n",disk+t[0][3],disk+t[1][3],disk+t[2][3]);
	printf("  ------+------	  ------+------	  ------+------\n");
	printf("     Tower 1         Tower 2         Tower 3\n");
	
	if((t[2][0]==1 && t[2][1]==2) && (t[2][2]==3 && t[2][3]==4)) {
		printf("\n\n         **** GAME WON ****\n");
		getch();
		exit(0);
		}
		
	printf("\nChoose a tower to pick a ring from (1/2/3) ");
	s=getche();
	x=s;
	s=input();
	
	while(t[s][i]==0) { i++; //scanning for a disk to pick up 
	if(i==4){
		printf("\nNo disk in the Tower!!!");
		getch();
		clear();
	}}
	u=t[s][i];     //storing disk size in u
	
	printf("\nChoose a tower to put the ring on (1/2/3)  ");
	r=getche();  
	x=r;                
	r=input();
	if(s==r){ clear(); }  //if user chooses same tower both times
	
	while(t[r][j]!=0)  j--;  //scanning tower for bigger disk below of no disk
	if(t[r][j+1]<u){
		printf("\nInvalid Move - bigger disk can't be on top of smaller one");
		getch();
		clear();
	}
	t[s][i]=0;          //removing disk for first tower
	t[r][j]=u;			//putting disk stored in u
	clear();
}

void clear(){
	system("cls");
	main();
}

int input(){
	if((int)x==49) return 0;  
	else if((int)x==50) return 1;
	else if((int)x==51) return 2;
	else {
	printf("\nWrong input try again!!");
	getch();
	clear();
	}
}
