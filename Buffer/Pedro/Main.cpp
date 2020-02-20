#include<iostream>
#include<Windows.h>
#define dfSCREEN_WIDTH		71
#define dfSCREEN_HEIGHT	20
using namespace std;


//HANDLE WScreen[2]; 
//char MainBuffer[dfSCREEN_HEIGHT][dfSCREEN_WIDTH] = {0,};
//int Index = 0;
//void cs_Initial()
//{
//	WScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
//		0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
//	WScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
//		0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
//
//	CONSOLE_CURSOR_INFO stConsoleCursor;
//	stConsoleCursor.bVisible = FALSE;
//	stConsoleCursor.dwSize = 1;
//	//SetConsoleCursorInfo(, &stConsoleCursor);
//	SetConsoleCursorInfo(WScreen[0], &stConsoleCursor);
//	SetConsoleCursorInfo(WScreen[1], &stConsoleCursor);
//}
//
//void cs_MoveCursor(int iPosX, int iPosY, int index)
//{
//	COORD stCoord;
//	stCoord.X = iPosX;
//	stCoord.Y = iPosY;
//	SetConsoleCursorPosition(WScreen[index], stCoord);
//}
//
//void cs_ClearScreen(int index)
//{
//	DWORD dw; // unsigned long 
//	for (short i = 0; i < dfSCREEN_HEIGHT; i++)
//	{
//		FillConsoleOutputCharacter(WScreen[index], ' ', dfSCREEN_WIDTH - 1, { 0, i }, &dw);
//	}
//}
//
//void ScreenFlipping()
//{
//	SetConsoleActiveScreenBuffer(WScreen[Index]);
//	Index = !Index;
//}
//
//void ScreenClear()
//{
//	cs_ClearScreen(Index);
//}
//
//void DrawBuffer()
//{
//	DWORD dw;
//	int Iy = 0;
//
//	while (Iy < dfSCREEN_HEIGHT)
//	{
//		cs_MoveCursor(0, Iy, Index);
//		WriteFile(WScreen[Index], MainBuffer[Iy], dfSCREEN_WIDTH - 1, &dw, NULL);
//		Iy++;
//	}
//}
//
//void ScreenRelease()
//{
//	CloseHandle(WScreen[0]);
//	CloseHandle(WScreen[1]);
//}
//
//void Run()
//{
//	while (1)
//	{
//		ScreenClear();
//
//		DrawBuffer();
//		ScreenFlipping();
//	}
//}


//============================================================
//�̵��� ����ū ��������  ���۸� 2���� ����ϳ� 1���� ����ϳ� �����ε�
//2���� ����ϴ°��� ������۸��ε� ���� �������̰� ����...
//�׸��� 1���� ����ϸ� �������� �ᱹ ����ԵǾ��ִ�.
//�ϳ�������ҋ����� ���۸� �����ϱ⺸�� STD_OUTPUT_HANDLE������ �ڵ鰪���� ����Ѵ�.


HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//�̰��� ���� ���ȭ�� �ڵ鰪�� �������°�����..... ȭ����۶�°��� ��������°��� �ƴϴ�.
char MainBuffer[dfSCREEN_HEIGHT][dfSCREEN_WIDTH];
int Index = 0;
void cs_Initial()
{

	CONSOLE_CURSOR_INFO stConsoleCursor;
	stConsoleCursor.bVisible = FALSE;
	stConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(hConsole, &stConsoleCursor);
}

void cs_MoveCursor(int iPosX, int iPosY)
{
	COORD stCoord;
	stCoord.X = iPosX;
	stCoord.Y = iPosY;
	SetConsoleCursorPosition(hConsole, stCoord);
}

void cs_ClearScreen()
{
	DWORD dw; // unsigned long 
	for (short i = 0; i < dfSCREEN_HEIGHT; i++)
	{
		FillConsoleOutputCharacter(hConsole, ' ', dfSCREEN_WIDTH - 1, { 0, i }, &dw);
	}
}

void ScreenFlipping()
{
	SetConsoleActiveScreenBuffer(hConsole);
}

void ScreenClear()
{ 
	cs_ClearScreen();
}

void DrawBuffer()
{
	DWORD dw;
	int Iy = 0;

	while (Iy < dfSCREEN_HEIGHT)
	{
		cs_MoveCursor(0, Iy);
		WriteFile(hConsole, MainBuffer[Iy], dfSCREEN_WIDTH - 1, &dw, NULL);
		//cout << MainBuffer[Iy];
		cout << 3;
		Iy++;
	}
}

void ScreenRelease()
{

}

void Run()
{
	while (1)
	{
		ScreenClear();
		DrawBuffer();
		//ScreenFlipping();
		Sleep(33); 
	}
}



int main()
{
	system(" mode  con lines=20   cols=72 ");
	for (int y = 0; y < dfSCREEN_HEIGHT; y++)
	{
		for (int x = 0; x < dfSCREEN_WIDTH - 1; x++)
		{
			MainBuffer[y][x] = ' ';
		}
		MainBuffer[y][dfSCREEN_WIDTH - 1] = '\0';
	}

	MainBuffer[19][40] = 'M';//������ġ

	cs_Initial();

	Run();

}
