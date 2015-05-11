#include<iostream>
#include<windows.h>
#include<conio.h>
#include<ctime>
#include<cstdlib>
#include<thread>
#include <process.h>
#include<string>
#include<fstream>
#include"graphics.h"
#include<stdlib.h>
using namespace std;

int bouble1, bouble2, state = 0, trave, dkdung = 0;
int buttonA;
int buttonB;
int score=0;
int buttonC, bienCorrect;
void InScore(int Sc);
int ChonKey(int &buttonA, int &buttonB, int &buttonC, int &bienCorrect, int &score);
//int inBouble(int &bouble1,int &bouble2);
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

void Nocursortype()//an dau nhay
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x - 1, y - 1 };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}


void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
void veKhung()
{
	resizeConsole(1500,450);

	for (int i = 1; i<35; i++)
	{
		textcolor(34);
		cout << "                                     \n";
	}
	gotoxy(5, 24);
	textcolor(38);
	cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
	textcolor(12);
	gotoxy(50,2);
	cout<<" ==>Game SumTime<==";
	textcolor(11);
	gotoxy(39,4);cout<<"Mis:Count two numbers in the shortest time";
	textcolor(14);
	gotoxy(39,6);cout<<"Press A or B or C to select the answer!";
	textcolor(9);
	gotoxy(39,5);cout<<"Tip: Only use A,B,C keys!";
	textcolor(7);
	gotoxy(42,10);cout<<"Rank:";

	textcolor(10);
	gotoxy(42,33);cout<<"Game Version Console by DuongKK";

}
void InScore(int Sc)
{
	gotoxy(25, 1);
	textcolor(39);
	cout << "Score:" << Sc;
	textcolor(12);
}
int HamBouble()
{

	if(state==0)
	{
	srand(time(0));
	bouble1 = rand() % (51);
	bouble2 = rand() % (51);
	trave = bouble1 + bouble2;
	}
	return trave;
}
int inBouble(int &bouble1,int &bouble2)
{
for (int i = 10; i < 24; i++)
	{
	gotoxy(10, i);
	textcolor(129);
	cout << "  " << bouble1 << "  ";
	textcolor(34);
	cout << "\t\t";
	textcolor(129);
	cout << "  " << bouble2 << "  ";
	gotoxy(10, i);
	Sleep(500);
	textcolor(34);
	cout<<"                         ";
	if ( GetAsyncKeyState(0x41) || GetAsyncKeyState(0x42) || GetAsyncKeyState(0x43) )
		{
			return 0;}
	if(i==23)
		{state=1;
		return 0;}
	}
return 0;
}


void TaoButton()
{
	bienCorrect = trave;
	srand(time(0));
	int buttonKey;
	buttonKey = (1 + rand() % (3));
	switch (buttonKey){

	case 1:
		buttonA = bienCorrect;
		buttonC = (rand() % (100));
		buttonB = (rand() % (100));
		break;
	case 2:

		buttonC = bienCorrect;
		buttonA = (rand() % (100));
		buttonB = (rand() % (100));
		break;
	case 3:
		buttonB = bienCorrect;
		buttonC = (rand() % (100));
		buttonA = (rand() % (100));
		break;
	default:
		break;
	}
	gotoxy(5, 25);
	textcolor(23);
	cout << "   A." << buttonA << "   ";
	cout << "   B." << buttonB << "   ";
	cout << "   C." << buttonC << "   ";
	textcolor(32);
}
/*int HamTime()
{
	gotoxy(23, 4);
	textcolor(218);
	cout << "Time:";
	textcolor(200);
	int i = 0;

	while (i<10)
	{
		cout << " ";
		i++;
		
		if (GetAsyncKeyState(0x41) || GetAsyncKeyState(0x42) || GetAsyncKeyState(0x43) || state ==1)
		{
			gotoxy(28, 4);
			textcolor(34);
			cout << "          ";
			dkdung = 1;		
			return 0;

		}
		if (i == 9)
		{
			state = 1;
			

		}
		Sleep(1000);
	}

	return 0;

}*/
int  ChonKey(int &buttonA, int &buttonB, int &buttonC, int &bienCorrect, int &score)
{
	//Chon Key

	//gotoxy(12,22);
	//cout<<"\nBan Chon : ";
	/*textcolor(0);
	//gotoxy(50, 12);
	//vì hk hiêu cở chế game đưa vô nên cout nó ra để nhìn thôi
	cout << buttonA << "\t" << buttonB << "\t" << buttonC;*/
	int key, kt = true;
	int c;
	int ketqua;
	for (; kt == true;)
	{
		//đợi người dùng ấn phím
		while (!_kbhit());
		//c đc gán lại bằng phím vừa ấn
		{c = getch();
		//và lấy giá trị trong các button đưa vào c để kiểm tra
		//bạn thấy mình chỉ cần 1 xét để đưa ra kết quả
		//test
		//ổn định. oke??/
		if (c == 'c') 
		{c = buttonC;}
		else if (c == 'b') 
		{c = buttonB;}
		else if (c == 'a') 
		{c = buttonA;}
		else continue;
		if (c == bienCorrect)
		{
			score++;

			InScore(score);
		}
		else 
		{
			gotoxy(12, 12);
			textcolor(14);
			state = 1;
			cout << "GAME OVER!";
				return 0;
		}
		
		break;}	//Chua hieu break de lam gi ? Nhung van chay bt
	}
	return 0;
}
struct Player
{
	string ten;
	int Score;
}player[100];
struct sl
{
	int soluong;
};
void Yescursortype()//hien dau nhay
{CONSOLE_CURSOR_INFO Info;
Info.bVisible = TRUE;
Info.dwSize=20;
SetConsoleCursorInfo (GetStdHandle (STD_OUTPUT_HANDLE), &Info);}
/*void sapxepplayer(Player player[])
{

Player tg;

	for(int i=0;i<soluong-1;i++)
	{
		for(int j=i+1;j<soluong;j++)
		{
			if(player[i].Score<player[j].Score)
				
			tg=player[j];
			player[j]=player[i];
			player[i]=tg;
		}

	}

}*/
Player Doc()
{
	Player A;
	fstream f;
	f.open("BangDiem.txt", ios::app | ios::binary);
	f.read((char *)&A, sizeof(A));
	f.flush();
	f.close();
	return A;
}
/*void inbangdiem(Player player[])
{
	for(int i=0;i<soluong;i++)
	{
		cout<<player[i].ten<<": "<<player[i].Score;
	}

}
*/
int main()
{

	//struct	Player player;
	SetConsoleTitle("Game Don Gian");
	int diembd = 0;
	veKhung();
	
	InScore(diembd);
	thread t;
	int i = 0;
	string tenplayer;
	while (true)
	{
		Nocursortype();
		player[i].Score=0;
		HamBouble();
		TaoButton();
		inBouble(bouble1,bouble2);
		Sleep(100);//Phai co ham sleep de ngung vong lap trong 0.1s		
		t = thread(ChonKey, buttonA, buttonB, buttonC, bienCorrect,score);		
		t.join();
		if (state == 1)		//Sau moi lan luot no se kiem tra state neu state =1 thi out
		{
			
			gotoxy(39, 10);
			textcolor(14);
			cout << "SCORE :" << score << endl;
			player[i].Score=score;
			gotoxy(42, 12);
			cout<<"Player's Name:";
			Yescursortype();//hien dau nhay
			getline(cin,player[i].ten);			
			/*fstream BangDiem;
			BangDiem.open("BangDiem.txt",ios::app | ios::binary);			
			BangDiem.write((char *)&player[i], sizeof(player[i]));
			BangDiem.flush();
			BangDiem.close();
			fstream BangDiem1;
		BangDiem1.open("BangDiem.txt", ios::app | ios::binary);
		BangDiem1.read((char *)&player[i], sizeof(player[i]));
		BangDiem1.flush();
		BangDiem1.close();
			sapxepplayer(player);
			inbangdiem(player);*/
			fstream BangDiem;
			BangDiem.open("BangDiem.txt",ios::app);
				BangDiem <<"+"<<player[i].ten <<":"<<player[i].Score<<endl;
			BangDiem.close();
			break;
		}
		else
		{
			;
		}	
		
		i++;
		if (i == 100)
			i = 0;
		score++;
	}
	getch();
}