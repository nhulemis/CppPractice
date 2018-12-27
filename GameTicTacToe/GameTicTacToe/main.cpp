#include <iostream>
#include <Windows.h>


using namespace std;
#pragma region declare function
void DrawMatrix();
void Matrix_Key_Press(int &X, int &Y, bool &player, int matrix[3][3], bool &press);
int CheckWin(int matrix[3][3], bool player);
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

/**
* return 1 da co nguoi chien thang
* return 0 chua co nguoi chien thang
*/
int CheckWin(int matrix[3][3], bool player) {
	int check = 1;

	if (player)
	{
		check = 0;
	}

	// check hang doc
	for (int i = 0; i < 3; i++)
	{
		//int x = matrix[i][0];
		if (matrix[i][0] == check && matrix[i][1] == check && matrix[i][2] == check)
		{
			COORD alert = { 20,20 };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), alert);
			cout << "Chien thang";
			return 1;
		}
	}

	// check hang ngan
	for (int i = 0; i < 3; i++)
	{
		//int x = matrix[i][0];
		if (matrix[0][i] == check && matrix[1][i] == check && matrix[2][i] == check)
		{
			COORD alert = { 20,20 };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), alert);
			cout << "Chien thang";
			return 1;
		}
	}


	if (matrix[1][1] == 0 || matrix[1][1] == 1)
	{
		check = matrix[1][1];
	}

	// check hang cheo
	if ((matrix[0][0] == check && matrix[2][2] == check) || (matrix[2][0] == check && matrix[0][2] == check))
	{
		COORD alert = { 20,20 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), alert);
		cout << "Chien thang";
		return 1;
	}

	return 0;
}
#pragma endregion
