#pragma once
#include<iostream>
#include"avltree.h"
#include"map.h"
#include<windows.h>
using namespace std;

void game_simulation(char** arr)
{
	int i = 0, j = 0, px = 0, py = 0;
	bool flag1 = true, flag2 = true;
	char inp = '\0', prev;
	node* TREE = nullptr;

	TREE = insert(TREE, 100, 1);


	while (flag1) {
		while (flag2) {
			if (arr[i][j] == '*')
			{
				flag1 = false;
				flag2 = false;
			}
			j++;
		}
		i++;
	}

	do
	{
		prev = arr[px][py];
		arr[px][py] = 'Q';
		cout << "\t\t\t";
		for (int i = 0; i < MAP_SIZE_SQRT; i++)
		{
			for (int j = 0; j < MAP_SIZE_SQRT; j++)
			{
				cout << arr[i][j] << "  ";
			}
			cout << endl << "\t\t\t";
		}

		cout << "INP: ";
		cin >> inp;

		if (inp == 'a')
		{
			if (py > 0)
			{
				arr[px][py] = prev;
				if (arr[px][py] == CLEAR_PATH)
				{
					TREE = insert(TREE, 100, 1);
				}
				else if (arr[px][py] == JEWEL)
				{
					TREE = insert(TREE, 10, 50);
				}
				else if (arr[px][py] == POTION)
				{
					TREE = insert(TREE, 20, 70);
				}
				else if (arr[px][py] == WEAPON)
				{
					TREE = insert(TREE, 30, 30);
				}
				else if (arr[px][py] == OBSTACLE)
				{
					TREE = insert(TREE, 110, -100);
				}
				else if (arr[px][py] == DRAGON)
				{
					TREE = insert(TREE, 120, -50);
				}
				else if (arr[px][py] == GOBLIN)
				{
					TREE = insert(TREE, 130, -30);
				}
				else if (arr[px][py] == WEREWOLF)
				{
					TREE = insert(TREE, 140, -70);
				}

				if (arr[px][py - 1] == CRYSTAL)
				{
					inp = 'e';
				}

				if (arr[px][py - 1] == DEATH_POINT)
				{
					inp = 'e';
				}
				py--;
			}
			else
			{
				cout << "\nInvalid Input: ";
			}
		}
		else if (inp == 'd')
		{
			if (py < 19)
			{
				arr[px][py] = prev;
				if (arr[px][py] == CLEAR_PATH)
				{
					TREE = insert(TREE, 100, 1);
				}
				else if (arr[px][py] == JEWEL)
				{
					TREE = insert(TREE, 10, 50);
				}
				else if (arr[px][py] == POTION)
				{
					TREE = insert(TREE, 20, 70);
				}
				else if (arr[px][py] == WEAPON)
				{
					TREE = insert(TREE, 30, 30);
				}
				else if (arr[px][py] == OBSTACLE)
				{
					TREE = insert(TREE, 110, -100);
				}
				else if (arr[px][py] == DRAGON)
				{
					TREE = insert(TREE, 120, -50);
				}
				else if (arr[px][py] == GOBLIN)
				{
					TREE = insert(TREE, 130, -30);
				}
				else if (arr[px][py] == WEREWOLF)
				{
					TREE = insert(TREE, 140, -70);
				}

				if (arr[px][py + 1] == CRYSTAL)
				{
					inp = 'e';
				}

				if (arr[px][py + 1] == DEATH_POINT)
				{
					inp = 'e';
				}
				py++;
			}
			else
			{
				cout << "\nInvalid Input: ";
			}
		}
		else if (inp == 'w')
		{
			if (px > 0)
			{
				arr[px][py] = prev;
				if (arr[px][py] == CLEAR_PATH)
				{
					TREE = insert(TREE, 100, 1);
				}
				else if (arr[px][py] == JEWEL)
				{
					TREE = insert(TREE, 10, 50);
				}
				else if (arr[px][py] == POTION)
				{
					TREE = insert(TREE, 20, 70);
				}
				else if (arr[px][py] == WEAPON)
				{
					TREE = insert(TREE, 30, 30);
				}
				else if (arr[px][py] == OBSTACLE)
				{
					TREE = insert(TREE, 110, -100);
				}
				else if (arr[px][py] == DRAGON)
				{
					TREE = insert(TREE, 120, -50);
				}
				else if (arr[px][py] == GOBLIN)
				{
					TREE = insert(TREE, 130, -30);
				}
				else if (arr[px][py] == WEREWOLF)
				{
					TREE = insert(TREE, 140, -70);
				}

				if (arr[px - 1][py] == CRYSTAL)
				{
					inp = 'e';
				}

				if (arr[px - 1][py] == DEATH_POINT)
				{
					inp = 'e';
				}
				px--;
			}
			else
			{
				cout << "\nInvalid Input: ";
			}
		}
		else if (inp == 's')
		{
			if (px < 19)
			{
				arr[px][py] = prev;
				if (arr[px][py] == CLEAR_PATH)
				{
					TREE = insert(TREE, 100, 1);
				}
				else if (arr[px][py] == JEWEL)
				{
					TREE = insert(TREE, 10, 50);
				}
				else if (arr[px][py] == POTION)
				{
					TREE = insert(TREE, 20, 70);
				}
				else if (arr[px][py] == WEAPON)
				{
					TREE = insert(TREE, 30, 30);
				}
				else if (arr[px][py] == OBSTACLE)
				{
					TREE = insert(TREE, 110, -100);
				}
				else if (arr[px][py] == DRAGON)
				{
					TREE = insert(TREE, 120, -50);
				}
				else if (arr[px][py] == GOBLIN)
				{
					TREE = insert(TREE, 130, -30);
				}
				else if (arr[px][py] == WEREWOLF)
				{
					TREE = insert(TREE, 140, -70);
				}

				if (arr[px + 1][py] == CRYSTAL)
				{
					inp = 'e';
				}

				if (arr[px + 1][py] == DEATH_POINT)
				{
					inp = 'e';
				}
				px++;
			}
			else
			{
				cout << "\nInvalid Input: ";
			}
		}

		if (inp != 'e') {
			Sleep(200);
			system("cls");
		}
	} while (inp != 'e');

	cout << "\nScore: ";
	PrintTree(TREE);
}