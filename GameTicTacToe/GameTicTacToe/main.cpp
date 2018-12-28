#include <iostream>
#include <Windows.h>


using namespace std;
#pragma region declare function
char player1[20];
int turns = 0;
char player2[20];
void DrawMatrix();
void MatrixKeyPress(int &X, int &Y, bool &player, int matrix[3][3], bool &press);
int CheckWin(int matrix[3][3], bool player);
void SetUpAndPlayChess();
void ShowMenu();
void InputName();
void SwitchPlayer(bool player);
void Winner(int player);
int Enter_listener();
void SetMatrix();
#pragma endregion

int main() {
	int sc = 0;
	ShowMenu();
	cin >> sc;
	if (sc == 1)
	{
		InputName();
	///	fflush(stdin);
		GetAsyncKeyState(VK_SPACE);
		int replay;
		do
		{
			SetUpAndPlayChess();
			////Sleep(500);
			//fflush(stdin);
			//fflush(stdin);
			cout << "choi lai Y/N ?\n";
			cout << "\t\t\t\t\tYes" << endl;
			cout << "\t\t\t\t\tNo" << endl;
			replay = Enter_listener();
			//replay = 0;
		} while (replay == 1);
		exit;
	}
	else
	{
		exit;
	}

	//SetUpAndPlayChess();
	system("pause");

	return 0;
}

#pragma region function

void SetMatrix(int matrix[3][3]) {
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrix[i][j] = 100000;
		}
	}
}

int Enter_listener() {
	int X = 40;
	int Y = 11;

	COORD cursor;

	cursor.X = X;
	cursor.Y = Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);

	while (1)
	{
		if (GetAsyncKeyState(VK_UP))
		{
			if (Y == 12)
			{
				Y -= 1;
				cursor.X = X;
				cursor.Y = Y;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
			}

		}
		else if (GetAsyncKeyState(VK_DOWN))
		{
			if (Y == 11)
			{
				Y += 1;
				cursor.X = X;
				cursor.Y = Y;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
			}

		}
		else if (GetAsyncKeyState(VK_RETURN) & 0x8000)
		{
			cout << "\n\t\t\t\t\t\t";
			if (Y == 12)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}

	}
}

void SetMatrix()
{
}

void InputName() {

	cin.ignore();
	cout << "player 1 : ";
	cin.getline(player1, 20, '\n');


	cout << "player 2 : ";
	cin.getline(player2, 20, '\n');
	fflush(stdin);
	return;
}

void ShowMenu() {
	cout << "______________Wellcome to TIC-TAC-TOE Game!_______________" << endl;

	cout << "if you find any problem, please contact nhulemis@gmail.com" << endl << endl << endl;

	cout << "Select your mode (1 -play game Player vs Player, OTHERs - EXIT GAME) " << endl;

}

// ham va ban co
void DrawMatrix() {
	// clear console
	system("cls");

	for (int i = 0; i < 13; i++)
	{
		if (i % 4 == 0)
		{
			/*for (int j = 0; j < 10; j++)
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
			}*/
			cout << "_______________________________";
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
	cout << "\n\n\t" << "\t(O)" << player1 << endl;
	cout << "\t" << "\t(X)" << player2 << endl;


	// tutorial
	cout << "\nUse keys (UP DOWN LEFT RIGHT) for move cursor \nuse ENTER for play";
	SwitchPlayer(false);
}

//dieu khien con tro va choi co
void MatrixKeyPress(int &X, int &Y, bool &player, int matrix[3][3], bool &press) {
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
		turns++;
		int yy = Y;
		int xx = X;
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
		SwitchPlayer(player);
		cursor.X = xx;
		cursor.Y = yy;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
	}

}

void SwitchPlayer(bool player) {
	COORD index;
	if (player)
	{
		index.X = 5;
		index.Y = 15;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), index);
		cout << "  ";
		index.X = 5;
		index.Y = 16;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), index);
		cout << "->";
	}
	else
	{
		index.X = 5;
		index.Y = 16;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), index);
		cout << "  ";
		index.X = 5;
		index.Y = 15;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), index);
		cout << "->";
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
			Winner(check);

			return 1;
		}
	}

	// check hang ngan
	for (int i = 0; i < 3; i++)
	{
		//int x = matrix[i][0];
		if (matrix[0][i] == check && matrix[1][i] == check && matrix[2][i] == check)
		{
			Winner(check);

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
		Winner(check);

		return 1;
	}

	//kiem tra hoa
	if (turns == 9)
	{
		COORD alert = { 50,8 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), alert);
		cout << "choi hay qua hoa roi " << endl;
		cout << "\t\t\t\t\t";
		return 1;
	}
	return 0;
}

void Winner(int player) {
	COORD alert = { 50,8 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), alert);
	if (player == 1)
	{
		cout << player1 << " WIN \n\n";
		cout << "\t\t\t\t\t";
	}
	else
	{
		cout << player2 << " WIN \n\n";
		cout << "\t\t\t\t\t";
	}
}

void SetUpAndPlayChess() {
	int X = 5;
	int Y = 10;
	bool player = false; // false is player1 (O) value = 1 , true player2 (X) value = 0 =))))
	bool press = false;
	int matrix[3][3];
	turns = 0;
	SetMatrix(matrix);
	DrawMatrix();
	COORD cur = { X,Y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
	Sleep(1000);
	while (1)
	{
		
		if (press)
		{
			//	cout << matrix[X / 9][Y / 4];

			if (CheckWin(matrix, !player) == 1) {
				break;
			}
			press = false;
		}

		Sleep(300);
		MatrixKeyPress(X, Y, player, matrix, press);
	}
}
#pragma endregion
