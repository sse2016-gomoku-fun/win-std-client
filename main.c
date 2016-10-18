#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 20
#define EMPTY 0
#define ME 1
#define OTHER 2

#define TRUE 1
#define FALSE 0

#define MAX_BYTE 10000

#define START "START"
#define PLACE "PLACE"
#define DONE  "DONE"
#define TURN  "TURN" 
#define BEGIN "BEGIN"
#define END   "END"

struct Position
{
	int x;
	int y;
}; 

char buffer[MAX_BYTE] = {0};
char board[BOARD_SIZE][BOARD_SIZE] = {0};

struct Position ai(const char board[BOARD_SIZE][BOARD_SIZE])
{
	/*
	 * TODO: Write your own ai here!
	 * Here is a simple ai which just put chess at empty position!
	 */
	int i, j;
	struct Position preferedPos;
	
	for (i = 0; i < BOARD_SIZE; i++)
		for (j = 0; j < BOARD_SIZE; j++)
		{
			if (EMPTY == board[i][j])
			{
				preferedPos.x = i;
				preferedPos.y = j;
				return preferedPos;
			}
		}
	
	
	return preferedPos;
}

void start()
{
	memset(board, 0, sizeof(board));
}

void place(int x, int y, int z)
{
	board[x][y] = z;
}

void done()
{
	printf("OK\n");
}

void turn(int x, int y)
{
	board[x][y] = OTHER;
	
	// AI
	struct Position pos = ai(board);
	printf("%d %d\n", pos.x, pos.y);
}

void end(x)
{
	
}

void loop()
{
	while (TRUE)
	{
		memset(buffer, 0, sizeof(buffer));
		scanf("%s", buffer);
		
	    if (strstr(buffer, START))
	    {
	    	start();
		}
		else if (strstr(buffer, PLACE))
		{
			char tmp[MAX_BYTE] = {0};
			int x,  y, z;
			sscanf(buffer, "%s %d %d %d", tmp, &x, &y, &z);
			place(x, y, z);
		}
	    else if (strstr(buffer, DONE))
	    {
	    	done();
		}
		else if (strstr(buffer, TURN))
		{
			char tmp[MAX_BYTE] = {0};
			int x,  y;
			sscanf(buffer, "%s %d %d", tmp, &x, &y);
			turn(x, y);
		}
		else if (strstr(buffer, END))
		{
			char tmp[MAX_BYTE] = {0};
			int x;
			sscanf(buffer, "%s %d", tmp, &x);
			end(x);
		}
	}
}


int main(int argc, char *argv[]) {
	loop();
	return 0;
}
