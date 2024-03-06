#include <stdio.h>
#include <string.h>

char board[]= {'0','1', '2', '3', '4', '5', '6', '7', '8','9'};

void printBord()
{
	printf("**** Tic Tac Toe ****\n");
	printf("\n");
	printf("   |   |\n");
	printf(" %c | %c | %c\n",board[1],board[2],board[3]);
	printf("___|___|___\n");
	printf("   |   |\n");
	printf(" %c | %c | %c\n",board[4],board[5],board[6]);
	printf("___|___|___\n");
	printf("   |   |  \n");
	printf(" %c | %c | %c\n",board[7],board[8],board[9]);
	printf("\n");

}

int checkWin()
{
	if(board[1]== board[2] && board[2]== board[3])
		return 1;
	if(board[1]== board[4] && board[4]== board[7])
		return 1;
	if(board[7]== board[8] && board[8]== board[9])
		return 1;
	if(board[3]== board[6] && board[6]== board[9])
		return 1;
	if(board[1]== board[5] && board[5]== board[9])
		return 1;
	if(board[3]== board[5] && board[5]== board[7])
		return 1;
	if(board[2]== board[5] && board[5]== board[8])
		return 1;
	if(board[4]== board[5] && board[5]== board[6])
		return 1;
	int count =0;
	for(int i = 0; i <= 9; i++)
	{
		if(board[i]== 'x'|| board[i]== 'o')
			count++;
	}
	
	if(count == 9)
		return 0;
	return -1;
}




int main()
{
	int player=1, input, status =-1;
	
	printBord();	
	
	while(status == -1)
	{
		player = (player%2== 0)? 2:1;
		char mark =(player==1)? 'x' :'o';
		printf("Enter number for player %d\n", player );
		scanf("%d", &input);
		if(input < 1 || input > 9)
			printf("invalid input\n");
		board[input]=mark;
		printBord();
		
		int result = checkWin();
		if(result == 1)
		{
			printf("player %i winner\n", player);
			return 0;
		}
		else if(result == 0)
		{
			printf("draw\n");
			return 0;
		}		
		player++;
	}
}