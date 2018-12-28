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
void GoToXY(int x, int y);
bool CheckOverRide(int matrix[3][3], int x, int y);
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

/* return true --- allow play at this index
*/
bool CheckOverRide(int matrix[3][3], int x, int y) {

	if (matrix[x / 9][y / 4] == 1 || matrix[x / 9][y / 4] == 0)
	{
		return false;
	}
	return true;
}

void GoToXY(int x, int y) {
	COORD cursor;
	cursor.X = x;
	cursor.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}

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

	GoToXY(X, Y);

	while (1)
	{
		if (GetAsyncKeyState(VK_UP))
		{
			if (Y == 12)
			{
				Y -= 1;
				GoToXY(X, Y);
			}

		}
		else if (GetAsyncKeyState(VK_DOWN))
		{
			if (Y == 11)
			{
				Y += 1;
				GoToXY(X, Y);
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

/*function draw matrix ^^
*/
void DrawMatrix() {
	// clear console
	system("cls");
	cout << " _____________________________\n";
	for (int i = 1; i < 13; i++)
	{
		if (i % 4 == 0 )
		{			
			cout << "|_________|_________|_________|";
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

/*dieu khien con tro va choi co*/
void MatrixKeyPress(int &X, int &Y, bool &player, int matrix[3][3], bool &press) {

	if (GetAsyncKeyState(VK_UP))
	{
		if (Y > 2)
		{
			Y -= 4;
			GoToXY(X, Y);
		}
	}
	else if (GetAsyncKeyState(VK_DOWN))
	{
		if (Y <= 6)
		{
			Y += 4;
			GoToXY(X, Y);
		}
	}
	else if (GetAsyncKeyState(VK_LEFT))
	{
		if (X > 5)
		{
			X -= 10;
			GoToXY(X, Y);
		}
	}
	else if (GetAsyncKeyState(VK_RIGHT))
	{
		if (X <= 15)
		{
			X += 10;
			GoToXY(X, Y);
		}
	}
	else if (GetAsyncKeyState(VK_SPACE))
	{
		if (CheckOverRide(matrix, X, Y))
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
			GoToXY(xx, yy);
		}
		else
		{
			return;
		}
	}
}

void SwitchPlayer(bool player) {
	COORD index;
	if (player)
	{
		GoToXY(5, 15);
		cout << "    ";
		GoToXY(5, 16);
		cout << "->>>";
	}
	else
	{
		GoToXY(5, 15);
		cout << "->>>";
		GoToXY(5, 16);
		cout << "    ";
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
	// check hang ngang
	for (int i = 0; i < 3; i++)
	{
		//int x = matrix[i][0];
		if (matrix[0][i] == check && matrix[1][i] == check && matrix[2][i] == check)
		{
			Winner(check);
			return 1;
		}
	}

	// check hang cheo
	if (matrix[1][1] == check)
	{
		if ((matrix[0][0] == check && matrix[2][2] == check) || (matrix[2][0] == check && matrix[0][2] == check))
		{
			Winner(check);
			return 1;
		}
	}




	//kiem tra hoa
	if (turns == 9)
	{
		GoToXY(50, 8);
		cout << "choi hay qua hoa roi " << endl;
		cout << "\t\t\t\t\t";
		return 1;
	}
	return 0;
}

void Winner(int player) {
	GoToXY(50, 8);
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
	GoToXY(X, Y);
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
