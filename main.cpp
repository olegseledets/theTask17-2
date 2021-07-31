#include <iostream>


void inputCoord (char field [][3], char ch)
{
	int x = 0, y = 0;
	do {
		std::cout << "\nХод " << ch << ". Введите координаты:\n X: ";
		std::cin >> x;
    std::cout << "Y: ";
    std::cin >> y;
	} while ((x < 0 || x > 2) || (y < 0 || y > 2) || (field[x][y] != '-'));

	field[x][y] = ch;
}

void showField (char field [][3])
{
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			std::cout << field[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

bool isWin (char field[][3])
{
	for (int i = 0; i < 3; ++i)
	{
		bool matchHorizont = false;
		bool matchVertical = false;
		for (int j = 0; j < 2; ++j)
		{
			if ((field[i][j] == field[i][j+1]) && (field[i][j] != '-') && matchHorizont) 
				return true;
			else 
				if ((field[i][j] == field[i][j+1]) && (field[i][j] != '-'))
					matchHorizont = true;
			
			if ((field[j][i] == field[j+1][i]) && (field[j][i] != '-') && matchVertical) 
				return true;
			else 
				if ((field[j][i] == field[j+1][i]) && (field[j][i] != '-'))
					matchVertical = true;
		}
	}

	bool matchMainDiag = false;
	bool matchSideDiag = false;
	for (int i = 0; i < 2; ++i)
	{
		if ((field[i][i] == field[i+1][i+1]) && (field[i][i] != '-') && matchMainDiag)
			return true;
		else
			if ((field[i][i] == field[i+1][i+1]) && (field[i][i] != '-'))
				matchMainDiag = true;

		if ((field[i][2-i] == field[i+1][2-(i+1)]) && (field[i][2-i] != '-') && matchSideDiag)
			return true;
		else
			if ((field[i][2-i] == field[i+1][2-(i+1)]) && (field[i][2-i] != '-'))
				matchSideDiag = true;
	}

	return false;
}


int main() 
{
	char playingField [3][3] = {'-', '-', '-',
															'-', '-', '-',
															'-', '-', '-'};

	for (int i = 1; (i <= 9) && !(isWin(playingField)); ++i) {
		inputCoord(playingField,((i % 2 == 0) ? 'X' : 'O'));
		showField(playingField);
		if (isWin (playingField))
			std::cout << "\n" << ((i % 2 == 0) ? 'X' : 'O') << " Победа! <<<";
	}
	if (!isWin(playingField)) 
		std::cout << "\nНичья\n";
}
/*
Задача 2. Крестики-нолики

Старинная-добрая игра на страницах всех школьных тетрадей. Поле размером 3х3 представлено в виде двумерного массива с типом элементов char. Помните тот символьный тип из предыдущего модуля? Теперь он нам и пригодится. Участвуют два игрока, которые ходят по очереди и ставят в указанные ими в стандартном вводе координаты свой символ - ‘X’ или ‘O’ (буквы латинского алфавита). Как только у одного из игроков будет установлено подряд три крестика или три нолика - он побеждает. Если свободных клеток не осталось, а трёх совпадающих элементов не найдено - объявляется ничья. Для простоты, мы не будем рассматривать диагональные совпадения, а только строго вертикальные либо строго горизонтальные.

Изначально всё поле инициализируется символом пробела - ‘ ‘. Это можно сделать сразу при объявлении, либо с помощью вложенного цикла. На каждом ходе, при занятой клетке или при неверных координатах этой клетки должно быть выведено сообщение и игрок должен указать координаты клетки повторно. После каждого хода надо выводить в консоль текущее состояние всего игрового поля, для наглядности.

Сделаю ещё одну небольшую подсказку. Проверку на победу игрока, которую надо осуществлять после каждого хода, можно сделать с помощью вложенного цикла, сразу проверяя и вертикаль и горизонталь а как именно - попробуйте догадаться сами.
*/