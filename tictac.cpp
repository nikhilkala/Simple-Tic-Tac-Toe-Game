#include<stdio.h>
#include<stdlib.h>
int board[3][3]={2,2,2,2,2,2,2,2,2};
int turn,win,check;
void display();
bool player1();
void player2();
int *make2();
void test();
int *posswin(char s);
void checkwin();
int main()
{
	int i,j,ch,option;
	bool flag;
	printf("\n\t\t\t\t tic tac");

	printf("\n press 1: to start the game");
	printf("\n press 2 :to quit the game");

	printf("\n enter option::");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			win=0;
			check=0;
			printf("press 1 :if you want to play first\n");
			printf("press 2 if you want to play second");
printf("\n enter option::");

			scanf("%d",&option);
			if(option==1)
			{
			for(i=1;i<10;i++)
			{
				if(win==1)
				break;				
				if(i%2!=0)
				{
					turn++;				
				    printf("\nturn for player1");
				    flag=player1();
				    while(flag!=true)
				    {
				    	flag=player1();
					}
			    test();
				if(check==9)
				{
					printf("\n match drawn");
					break;

				}
			         }
				else
			{
				if(win==1)
				break;
				
					turn++;
					printf("\n turn for computer");
					player2();
				test();
			    if(check==9)
				{
					printf("\n match drawn");
					break;
				}
			}
		}
		}
		else if(option==2)
			{
			
			for(int i=1;i<10;i++)
			{
				if(win==1)
				break;
				
				if(i%2!=0)
				{
					turn++;
					printf("\n turn for computer");
					player2();
					test();
				if(check==9)
				{
					printf("\n match drawn");
					break;
				}
			}
				else
			{
				if(win==1)
				break;
				turn++;				
				    printf("\nturn for player1");
				    flag=player1();
				    while(flag!=true)
				    {
				    	flag=player1();
					}
				test();
			    if(check==9)
				{
					printf("\n match drawn");
					break;
				}
			}
		}
		}
			break;
	    case 2:
	    	printf("\n thanks for playing game ");
	    	break;
	}
}
void display()
{
	int i,j;
	printf("\n\n\n");
	printf("\n\t\t\t    1\t      2\t        3");
	for(i=0;i<=2;i++)
	{
		printf("\n \t\t\t _____________________________");
		printf("\n \t\t\t \t  |\t   |\t     ");
		printf("\n\t\t%d\t",i+1);
		for(j=0;j<=2;j++)
		{
			if(board[i][j]==3)
			{
				printf("  X");
				printf("         ");
				
			}
			else if(board[i][j]==5)
			{
				printf("  O");
				printf("         ");
			}
			else
			{
				printf("            ");
				continue;
			}
		}
		printf("\n\t\t\t \t  |\t   |\t     ");
	}
	printf("\n\t\t\t------------------------------");
	checkwin();
}
void checkwin()
{
		int i,j;
	for(i=0;i<=2;i++)
	{
		if(board[i][0]==3&&board[i][1]==3&&board[i][2]==3)
		{
			win=1;
		printf("\n\nRESULT user wins!!");
			return;
		}
   }
		for(i=0;i<=2;i++)
	{
		if(board[1][i]==3 && board[2][i]==3 && board[0][i]==3)
		{
			win=1;
		printf("\n\nRESULT user wins!!");
			return;
		}
	}
	if(board[1][1]==3 && board[2][2]==3 && board[0][0]==3)
	{
		win=1;
		printf("\n\nRESULT user wins!!");
		return;
	}
	else if(board[0][2]==3 && board[1][1]==3 && board[2][0]==3)
	{
        	win=1;
		printf("\n\nRESULT user wins!!");
		return;
	}
        for(i=0;i<=2;i++)
	{
		if(board[i][1]==5 && board[i][2]==5 && board[i][0]==5)
		{
			win=1;
		printf("\n\nRESULT user wins!!");
			return;
		}
	}
	for(i=0;i<=2;i++)
	{
		if(board[1][i]==5 && board[2][i]==5 && board[0][i]==5)
		{
			win=1;
		printf("\n\nRESULT computer wins!!");
			return;
		}
	}
	if(board[1][1]==5 && board[2][2]==5 && board[0][0]==5)
	{
		win=1;
		printf("\n\nRESULT computer wins!!");
		return;
	}
	else if(board[0][2]==5 && board[1][1]==5 && board[2][0]==5)
	{
        	win=1;
		printf("\n\nRESULT computer wins!!");
		return;
	}
}
int* posswin(char s)
{
	int *arr,i;
	arr=(int*)calloc(2,sizeof(int*));
	if(s=='X')
	{
	if(board[0][0]*board[0][1]*board[0][2]==18)
		{
			if(board[0][0]==2)
			{
				arr[0]=0;arr[1]=0;return arr;
			}
			else if(board[0][1]==2)
			{
				arr[0]=0;arr[1]=1;return arr;
			}
			else if(board[0][2]==2)
			{
				arr[0]=0;arr[1]=2;return arr;
			}
		}
	else if(board[1][0]*board[1][1]*board[1][2]==18)
		{
			if(board[1][0]==2)
			{
				arr[0]=1;arr[1]=0;return arr;
			}
			else if(board[1][1]==2)
			{
				arr[0]=1;arr[1]=1;return arr;
			}
			else if(board[1][2]==2)
			{
				arr[0]=1;arr[1]=2;return arr;
			}
		}
		else if(board[2][0]*board[2][1]*board[2][2]==18)
		{
			if(board[2][0]==2)
			{
				arr[0]=2;arr[1]=0;return arr;
			}
			else if(board[2][1]==2)
			{
				arr[0]=2;arr[1]=1;return arr;
			}
			else if(board[2][2]==2)
			{
				arr[0]=2;arr[1]=2;return arr;
			}
		}
		else if(board[0][0]*board[1][0]*board[2][0]==18)
		{
			if(board[0][0]==2)
			{
				arr[0]=0;arr[1]=0;return arr;
			}
			else if(board[1][0]==2)
			{
				arr[0]=1;arr[1]=0;return arr;
			}
			else if(board[2][0]==2)
			{
				arr[0]=2;arr[1]=0;return arr;
			}
		}
		else if(board[0][1]*board[1][1]*board[2][1]==18)
		{
			if(board[0][1]==2)
			{
				arr[0]=0;arr[1]=1;return arr;
			}
			else if(board[1][1]==2)
			{
				arr[0]=1;arr[1]=1;return arr;
			}
			else if(board[2][1]==2)
			{
				arr[0]=2;arr[1]=1;return arr;
			}
		}
		else if(board[0][2]*board[2][2]*board[1][2]==18)
		{
			if(board[0][2]==2)
			{
				arr[0]=0;arr[1]=2;return arr;
			}
			else if(board[1][2]==2)
			{
				arr[0]=1;arr[1]=2;return arr;
			}
			else if(board[2][2]==2)
			{
				arr[0]=2;arr[1]=2;return arr;
			}
		}
		else if(board[1][1]*board[2][2]*board[0][0]==18)
	{
		if(board[0][0]==2)
		{
			arr[0]=0;arr[1]=0;return arr;
		}
		else if(board[1][1]==2)
		{
			arr[0]=1;arr[1]=1;return arr;
		}
		else if(board[2][2]==2)
		{
			arr[0]=2;arr[1]=2;return arr;
		}
	}
	else if(board[0][2]*board[1][1]*board[2][0]==18)
	{
        	if(board[0][2]==2)
		{
			arr[0]=0;arr[1]=2;return arr;
		}
		else if(board[1][1]==2)
		{
			arr[0]=1;arr[1]=1;return arr;
		}
		else if(board[2][0]==2)
		{
			arr[0]=2;arr[1]=0;return arr;
		}
	}
	else
	{
		arr[0]=3;arr[1]=3;return arr;
	}
}
else
{
		if(board[0][0]*board[0][1]*board[0][2]==50)
		{
			if(board[0][0]==2)
			{
				arr[0]=0;arr[1]=0;return arr;
			}
			else if(board[0][1]==2)
			{
				arr[0]=0;arr[1]=1;return arr;
			}
			else if(board[0][2]==2)
			{
				arr[0]=0;arr[1]=2;return arr;
			}
		}
	else if(board[1][0]*board[1][1]*board[1][2]==50)
		{
			if(board[1][0]==2)
			{
				arr[0]=1;arr[1]=0;return arr;
			}
			else if(board[1][1]==2)
			{
				arr[0]=1;arr[1]=1;return arr;
			}
			else if(board[1][2]==2)
			{
				arr[0]=1;arr[1]=2;return arr;
			}
		}
		else if(board[2][0]*board[2][1]*board[2][2]==50)
		{
			if(board[2][0]==2)
			{
				arr[0]=2;arr[1]=0;return arr;
			}
			else if(board[2][1]==2)
			{
				arr[0]=2;arr[1]=1;return arr;
			}
			else if(board[2][2]==2)
			{
				arr[0]=2;arr[1]=2;return arr;
			}
		}
		else if(board[0][0]*board[1][0]*board[2][0]==50)
		{
			if(board[0][0]==2)
			{
				arr[0]=0;arr[1]=0;return arr;
			}
			else if(board[1][0]==2)
			{
				arr[0]=1;arr[1]=0;return arr;
			}
			else if(board[2][0]==2)
			{
				arr[0]=2;arr[1]=0;return arr;
			}
		}
		else if(board[0][1]*board[1][1]*board[2][1]==50)
		{
			if(board[0][1]==2)
			{
				arr[0]=0;arr[1]=1;return arr;
			}
			else if(board[1][1]==2)
			{
				arr[0]=1;arr[1]=1;return arr;
			}
			else if(board[2][1]==2)
			{
				arr[0]=2;arr[1]=1;return arr;
			}
		}
		else if(board[0][2]*board[2][2]*board[1][2]==50)
		{
			if(board[0][2]==2)
			{
				arr[0]=0;arr[1]=2;return arr;
			}
			else if(board[1][2]==2)
			{
				arr[0]=1;arr[1]=2;return arr;
			}
			else if(board[2][2]==2)
			{
				arr[0]=2;arr[1]=2;return arr;
			}
		}
		else if(board[1][1]*board[2][2]*board[0][0]==50)
	{
		if(board[0][0]==2)
		{
			arr[0]=0;arr[1]=0;return arr;
		}
		else if(board[1][1]==2)
		{
			arr[0]=1;arr[1]=1;return arr;
		}
		else if(board[2][2]==2)
		{
			arr[0]=2;arr[1]=2;return arr;
		}
	}
	else if(board[0][2]*board[1][1]*board[2][0]==50)
	{
        	if(board[0][2]==2)
		{
			arr[0]=0;arr[1]=2;return arr;
		}
		else if(board[1][1]==2)
		{
			arr[0]=1;arr[1]=1;return arr;
		}
		else if(board[2][0]==2)
		{
			arr[0]=2;arr[1]=0;return arr;
		}
	}
	else
	{
		arr[0]=3;arr[1]=3;return arr;
	}
}
}
bool player1()
{
	int row,col;
	printf("\nEnter the row no. : ");
	scanf("%d",&row);
	printf("Enter the column no. : ");
	scanf("%d",&col);
	if(board[row-1][col-1]==3||board[row-1][col-1]==5 || row<1 || row>3 || col<1 || col>3)
	{
		printf("\nWRONG POSITION!! Press any key....");	
		display();
		return false;
	}
	else
	{
		board[row-1][col-1]=3;
		display();
		return true;
	}
}
void test()
{
	int i,j;
	check=0;
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
		{
			if(board[i][j]!=2)
			{
				check++;
			}
		}
	}
}
void player2()
{
	int l,k;
	int *array,*array1,*array2;
	array=(int*)calloc(2,sizeof(int*));
	array1=(int*)calloc(2,sizeof(int*));
	array2=(int*)calloc(2,sizeof(int*));
	if(turn==1)
	{
		board[0][0]=5;
	}
	else if(turn==2)
	{
		if(board[1][1]==2)
		board[1][1]=5;
		else
		board[0][0]=5;
	}
	else if(turn==3)
	{
		if(board[2][2]==2)
		board[2][2]=5;
		else
		board[0][2]=5;
	}
	else if(turn==4)
	{
		if(board[0][1]==3 &&board[1][0]==3)
		{
			board[0][0]=5;
		}
		else if( board[1][2]==3 &&board[2][1]==3)
		{
			board[2][2]=5;
		}
		else if(board[1][0]==3 &&board[2][1]==3)
		{
			board[2][0]=5;
		}
		else if(board[0][1]==3 && board[1][2]==3)
		{
			board[0][2]=5;
		}
		else if(board[0][0]==5 &&board[1][1]==3&&board[2][2]==3)
		{
			board[0][2]=5;
		}
	       else if(board[0][0]==3&& board[2][1]==3)
		{
			board[1][2]=5;
		}
		else if(board[0][2]==3&&board[2][1]==3)
		{	
			board[1][0]=5;
		}

		else
		{
		array=posswin('o');
		array1=make2();
		array2=posswin('X');
		if(array[0]!=3&&array[1]!=3)
	{
			board[array[0]][array[1]]=5;
		}
		else if(array2[0]!=3&&array2[1]!=3)
		{
			board[array2[0]][array2[1]]=5;
		}
		else
		{
			board[array1[0]][array1[1]]=5;
		}
	}
	}
	else if(turn==5)
	{
		array=posswin('o');
		array2=posswin('X');
		if(array[0]!=3&&array[1]!=3)
	{
			board[array[0]][array[1]]=5;
		}
		else if(array2[0]!=3&&array2[1]!=3)
		{
			board[array2[0]][array2[1]]=5;
		}
		else if(board[2][0]==2)
		{
			board[2][0]=5;
		}
		else
		{
			board[0][2]=5;
		}
	}
	else if(turn==6)
	{
		array=posswin('o');	
		array1=make2();
		array2=posswin('X');
		if(array[0]!=3&&array[1]!=3)
		{
			board[array[0]][array[1]]=5;
		}
		else if(array2[0]!=3&&array2[1]!=3)
		{
			board[array2[0]][array2[1]]=5;
		}
		else
		{
			board[array1[0]][array1[1]]=5;
		}
	}
	else if(turn==7)
	{
		array=posswin('o');
		array2=posswin('X');
		if(array[0]!=3&&array[1]!=3)
	{
			board[array[0]][array[1]]=5;
		}
		else if(array2[0]!=3&&array2[1]!=3)
		{
			board[array2[0]][array2[1]]=5;
		}
		else
		{
			for(k=0;k<=2;k++)
			{
				for(l=0;l<=2;l++)
				{
					if(board[k][l]==2)
					{
						board[k][l]=5;
						break;
					}
				}
			}
		}
	}
	else if(turn==8)
	{
		array=posswin('o');
		array1=make2();
		array2=posswin('X');
		if(array[0]!=3&&array[1]!=3)
		{
			board[array[0]][array[1]]=5;
		}
		else if(array2[0]!=3&&array2[1]!=3)
		{
			board[array2[0]][array2[1]]=5;
		}
		else
		{
			board[array1[0]][array1[1]]=5;
		}
	}
	else if(turn==9)
	{
		array=posswin('o');
		array2=posswin('X');
		if(array[0]!=3&&array[1]!=3)
	{
			board[array[0]][array[1]]=5;
		}
		else if(array2[0]!=3&&array2[1]!=3)
		{
			board[array2[0]][array2[1]]=5;
		}
		else
		{
			for(k=0;k<=2;k++)
			{
				for(l=0;l<=2;l++)
				{
					if(board[k][l]==2)
					{
						board[k][l]=5;
						break;
					}
				}
			}
		}
	}
	display();
}
int* make2()
{
	int *arr;
	arr=(int*)calloc(2,sizeof(int*));
	if(board[1][1]==2)
	{
		arr[0]=1;arr[1]=1;
		return arr;
	}
	else if(board[0][1]==2)
	{
		arr[0]=0;arr[1]=1;
		return arr;
	}
	else if(board[1][0]==2)
	{
		arr[0]=1;arr[1]=0;
		return arr;
	}
	else if(board[1][2]==2)
	{
		arr[0]=1;arr[1]=2;
		return arr;
	}
	else if(board[2][1]==2)
	{
		arr[0]=2;arr[1]=1;
		return arr;
	}
}


