#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define taille 100


int randomGeneratorBomb()
{
	int randomnumber;
	randomnumber = rand() % 8;
	return(randomnumber);
}

void createTable(char t[taille])
{
	for (int i = 0; i < taille; i++)
	{
		int randomBomb = randomGeneratorBomb();
		if (randomBomb == 1)
		{
			t[i] = '*';
		}
		else
		{
			t[i] = 'X';
		}
	}
}



void createBombMask(char tmask[taille]) {
	for (int i = 0; i < taille; i++)
	{
		tmask[i] = '.';
	}
}


void afficherTable(char tableau[taille])
{
	int y = 10;
	printf(" 0  1  2  3  4  5  6  7  8  9 \n\n");
	for (int i = 0; i < taille; i++)
	{
		printf(" %c ", tableau[i]);
		if (((i + 1) % 10) == 0)
		{
			printf("\n");
		}

	}
}


void bombautour(char table[taille])
{
	for (int i = 0; i < taille; ++i)
	{
			int count = 0;
			if (table[i] == 'X')
			{

				// compter le nombre de bombe adjacente
				if (table[i] == '*')
				{
					count = ++count;
				}

				if (i != 0)
				{
					if (table[i - 1] == '*')
					{
						count = ++count;
					}
					if (table[i - 10] == '*')
					{
						count = ++count;
					}
				}

				if (i != taille - 1)
				{
					if (table[i + 1] == '*')
					{
						count = ++count;
					}
					if (table[i + 10] == '*')
					{
						count = ++count;
					}
				}
				// converion count en char ASCI	I
				table[i] = (char)(count + 48);
			}
		
	}
}

void safeZone(char tmask[taille], char t[taille])
{
	int random = rand() % 20;
	for (int i = 0; i < 8; i++)

	{
		if (t[i] == '0')
		{
			tmask[i + 1] = t[i +1];
			tmask[i + -1] = t[i + -1];
			tmask[i + 10] = t[i + 10];
			tmask[i + -10] = t[i + -10];

		}
	}
}

int main()
{
	srand(time(NULL));
	printf("   Bienvenue au demineur ! \n\n\n");
	char t[taille];
	char tmask[taille];
	createTable(t);
	createBombMask(tmask);
	afficherTable(tmask);
	bombautour(t);
	safeZone(tmask,t);
	int start = 0;
	int choiseCase = 0;
	while (start == 0) {
		int errorCase = 0;
		while (errorCase == 0)
		{
			
			printf("Choisie le numero de ta case :");
			scanf_s("%d", &choiseCase);

			if (choiseCase > taille)
			{
				printf("Nombre incorrect essaye encore !\n\n");
				
			}
			else if (choiseCase < 0) 
			{
				printf("Nombre incorrect essaye encore !\n\n");

			}
			else {
				errorCase = 1;
			}

		}
		tmask[choiseCase] = t[choiseCase];
		
		printf("\n Tu as joue la case:  %d \n \n", choiseCase);
		afficherTable(tmask);

		
		if (tmask[choiseCase] == '*')
		{
			printf("\n Tu as trouve une bombe, perdu :c");
			break;
		}
		else 
		{
			printf("\n \n");
		}					
	}	
}
