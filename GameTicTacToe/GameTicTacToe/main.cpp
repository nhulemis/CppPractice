#include <iostream>
#include <Windows.h>


using namespace std;
#pragma region declare function
void DrawMatrix();
void Matrix_Key_Press(int &X, int &Y, bool &player, int matrix[3][3], bool &press);
#pragma endregion

int main() {


	getchar();
	return 0;
}

#pragma region function

// ham va ban co
void DrawMatrix() {
	for (int i = 0; i < 13; i++)
	{
		if (i % 4 == 0)
		{
			for (int j = 0; j < 10; j++)
			{
				if (i != 0 && j % 3 == 0)
				{
					cout << "|";
				}
				if (j == 9 && i != 0)
				{
					break;
				}
				cout << "___";
			}
		}
		else
		{
			for (int j = 0; j < 13; j++)
			{
				if (j % 4 == 0)
				{
					cout << "|";
				}
				else
				{
					cout << "   ";
				}
			}
		}
		cout << endl;
	}
}

//dieu khien con tro va choi co
void Matrix_Key_Press(int &X, int &Y, bool &player, int matrix[3][3], bool &press) {
	COORD cursor;

	if (GetAsyncKeyState(VK_UP))
	{
		if (Y > 2)
		{
			Y -= 4;
			cursor.X = X;
			cursor.Y = Y;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
		}

	}
	else if (GetAsyncKeyState(VK_DOWN))
	{
		if (Y <= 6)
		{
			Y += 4;
			cursor.X = X;
			cursor.Y = Y;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
		}

	}
	else if (GetAsyncKeyState(VK_LEFT))
	{
		if (X > 5)
		{
			X -= 10;
			cursor.X = X;
			cursor.Y = Y;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
		}

	}
	else if (GetAsyncKeyState(VK_RIGHT))
	{

		if (X <= 15)
		{
			X += 10;
			cursor.X = X;
			cursor.Y = Y;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
		}

	}
	else if (GetAsyncKeyState(VK_SPACE))
	{

		if (player)
		{
			cout << "X ";
			matrix[X / 9][Y / 4] = 0;
		}
		else
		{
			//cout << "O";
			cout << "O ";
			matrix[X / 9][Y / 4] = 1;
		}
		press = true;
		player = !player;
	}

}
#pragma endregion
