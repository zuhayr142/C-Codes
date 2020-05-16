#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

class TicTacToe
{
	string p1_name,p2_name;
	char p1_logo=' ' , p2_logo=' ';
	char MAP[9]= {'1','2','3','4','5','6','7','8','9'};
	int game_m;
	Start()
	{
		p1_name.erase(0,'\0');
		p2_name.erase(0,'\0');
		p1_logo=' '; 
		p2_logo=' ';
		for(int i=0;i<9;i++)
		{
			MAP[i]=i + 49;
		}
	}
	public:
	int Input()
	{
		char mode;
		Start();
		system("cls");
		system("COLOR A0");
		cout<<"\t\t\t\t------- WELCOME TO TIC TAC TOE GAME -------\n\n";
		while(mode!='1' && mode!='2')
		{
			cout<<"Enter Mode :: (1) - COMPUTER VS HUMAN \t (2) - HUMAN VS HUMAN";
			mode=getche();
			if(mode == '1')
				game_m=1;
			else if(mode == '2')
				game_m=2;
		}

		cout<<"\n---------PLAYER 1---------\n";
		cout<<"\nEnter Your Name : ";
		getline(cin,p1_name);
		while(isspace(p1_logo) || isdigit(p1_logo))
		{
			cout<<"\nEnter Your Logo(Numbers & Spaces are not allowed) : ";
			p1_logo=getche();
			if(isspace(p1_logo) || isdigit(p1_logo))
				cout<<"\n\aInvalid Input!";
		}
		if(game_m==2)
		{
			cout<<"\n\n---------PLAYER 2---------\n";
			cout<<"\nEnter Your Name : ";
			getline(cin,p2_name);
			while(isspace(p2_logo) || p2_logo == p1_logo || isdigit(p2_logo))
			{
				cout<<"\nEnter Your Logo(Numbers & Spaces are not allowed) : ";
				p2_logo=getche();
				if(isspace(p2_logo) || isdigit(p2_logo))
					cout<<"\n\aInvalid Input!";
				else if(p2_logo == p1_logo)
					cout<<"\n\aLogos can not be same!";
			}
		}
		if(game_m==1)
		{
			if(p1_logo != 'X')
			p2_logo='X';
			else
			p2_logo='O';
			p2_name = "COMPUTER";
		}
		return game_m;
	}
		Map()
		{
			int i,j;
			int n1=0,n2=0;
			system("cls");
			system("COLOR A0");
			cout<<"\t\t\t\t\t---------- TIC TAC TOE ---------\n\n\n";
			cout<<"\t\t\t\t\t\t  ";
			for(i=1;i<=13;i++)
			{
				for(j=1;j<=13;j++)
				{
					if(i==1 && j==13) // top right corner
					cout<<char(187);
					else if(i==1 && j==1) // top left corner
					cout<<char(201);
					else if((i==5 || i==9)  && j==13) // right -|
					cout<<char(185);
					else if((i==5 || i==9)  && j==1) // left |-
					cout<<char(204);
					else if(i==13 && j==13) // bottom right corner
					cout<<char(188);
					else if(i==13 && j==1) // bottom left corner
					cout<<char(200);
					else if(i==1 && (j==5 || j==9)) // top middle
					cout<<char(203);
					else if((i==5 || i==9) && (j==5 || j==9)) // middle
					cout<<char(206);
					else if(i==13 && (j==5 || j==9)) // bottom middle
					cout<<char(202);
					else if((i==3 || i==7 || i==11 ) && ( j==3 || j==7 || j==11))
					{
						cout<<MAP[n1];
						n1++;
					}
					else if( i == 1 || i == 5 || i == 9 || i == 13 )
					cout<<char(205);
					else if(j == 1 || j == 5 || j == 9 || j == 13)
					cout<<char(186);
					else
					cout<<" ";
				}
				cout<<"\n\t\t\t\t\t\t  ";
			}
		}
		
		Turn(int p)
		{
			char move;
			int m;
			int flag=0;
			while(flag==0)
			{
				cout<<"\nEnter Your Move(1-9) : ";
				move=getche();
				m = move - '0';
				if(m<1 || m>9)
				{
					cout<<"\nWrong Move!\a";
				}
				else if(!isdigit(MAP[m-1]))
				{
					cout<<"\nOpps The Place is already Taken\a";
					cout<<"\nTry Again";
				}
				else
				{
					if(p==1)
					MAP[m-1]=p1_logo;
					else
					MAP[m-1]=p2_logo;
					flag=1;
				}
			}
		}
		Computer()
		{
			int c=1;
			int r;
			while(c==1)
			{
				r=rand()%9;
				if(isdigit(MAP[r]))
				{
					c=0;
					MAP[r]=p2_logo;
				}
			}
		}
		Result(int p)
		{
			int i;
			for(i=0;i<9;i+=3)
			{
				if((MAP[i] == MAP[i+1]) && (MAP[i] == MAP [i+2])) 
				{
					Display(p);
					return 1;
				}
			}
			for(i=0;i<3;i++)
			{
				if((MAP[i] == MAP[i+3]) && (MAP[i] == MAP [i+6])) 
				{
					Display(p);
					return 1;
				}
			}
			if(((MAP[0] == MAP[4]) && (MAP[4] == MAP [8])) ||
			((MAP[2] == MAP[4]) && (MAP[2] == MAP [6]))) 
			{
				Display(p);
				return 1;
			}
			for(i=0;i<9;i++)
			{
				if(isdigit(MAP[i]))
				{
					return 0;
				}
			}	
			cout<<"\n\n\n\t\t\t\t\t\t----WE HAVE A TIE----\n\t\t\t\t\t\t";
			return 1;	
		}
		Display(int p)
		{
					cout<<"\n\n\n\t\t\t\t\t\t----WE HAVE A WINNER----\n\t\t\t\t\t\tCONGRATS:";
					if(p==1)
					cout<<p1_name;
					else
					cout<<p2_name;
		}
}obj;
main()
{
	int p=2,end=0,flag=0;
	int m;
	srand(time(0));
	char choice;
	m=obj.Input();
	obj.Map();
	while(end==0)
	{
		while(flag==0)
		{
			if(m==2)
			{
				if(p==1)
					p=2;
				else if(p==2)
					p=1;
			}
			else 
				p=1;
			obj.Turn(p);
			obj.Map();
			flag = obj.Result(p);
			if(m==1 && flag ==0)
			{
				p=2;
				obj.Computer();
				obj.Map();
				flag=obj.Result(p);
				p=1;
			}
		}
		cout<<"\nDo You Want To Play Again ? (Y/N): ";
		choice=getch();
		if(toupper(choice)=='Y')
		{
			flag=0;
			m=obj.Input();
			p=2;
			obj.Map();
		}
		else if(toupper(choice)=='N')
		end=1;
	}
}
