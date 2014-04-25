#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h> 
#include <bits/stdc++.h>
using namespace std;

int N, M, K, player;
vector<string> board;

double player1 (vector<string> board, int turn){
	int i=0,j=0,x=0,c=0;
	int k= K;
	double score=0;
	for (i=0;i<N;i++)
	{
		for (j=0;j<M;j++)
		{
			if(board[i][j] == '.')
			continue;
			else if(board[i][j] == 'X')
			{
			int du=0,dd=0,down=0,right=0;
			int l_k = 0;
			//diagonally upwards
			if(i!=0 && j!=M-1)
			{
				
				for(;l_k < k; l_k++)
				{	if(i-l_k > 0 && j+l_k < M)
					if(board[i][j] != board[i-l_k][j+l_k])
					break;
				}
			}
			c = 0;
			for (x = 1; x<=K; x++)
				{
					if(board[i][j]== 'X')
						c=c+1;
				}
			if(l_k == K)
				du = 1000;
			else if (l_k == K-1 && turn ==1)
				du = 1000;
			else if(c==K-1 && turn == 1)
				du = 1000;
			else if (c==K-1 && turn == 2)
				du = 100;
			else if (l_k == K-1 && turn ==2)
				du = 100;
			else if (l_k == K-2)
				du == 10;
			else du == l_k;
			l_k=0;
			c=0;
			//rightside
			if(j!=M-1)
			{
				for(;l_k < k; l_k++)
		    		{	if(j+l_k < M)
		        		if(board[i][j] != board[i][j + l_k])
		            		break;
		    		}
			}
		//	cout<<"lk"<<l_k<<endl;
			c = 0;
			for (x = 1; x<=K; x++)
				{
					if(board[i][j]== 'X')
						c=c+1;
				}
			if(l_k == K)
				right = 1000;
			else if (l_k == K-1 && turn ==1)
				right = 1000;
			else if(c==K-1 && turn == 1)
				right = 1000;
			else if (c==K-1 && turn == 2)
				right = 100;
			else if (l_k == K-1 && turn ==2)
				right=100;
			else if (l_k == K-2)
				right == 10;
			else right == l_k;
			l_k=0;
			
			//diagonally downwards
			if(i!=N-1 && j != M-1)
			{
				for(;l_k < k; l_k++)
		    		{	if(i+l_k < N && j+l_k < M)
		        		if(board[i][j] != board[i+l_k][j + l_k])
		            		break;
		    		}
			}
			c = 0;
			for (x = 1; x<=K; x++)
				{
					if(board[i][j]== 'X')
						c=c+1;
				}
			if(l_k == K)
				dd = 1000;
			else if (l_k == K-1 && turn == 1)
				dd = 1000;
			else if(c==K-1 && turn == 1)
				dd = 1000;
			else if (c==K-1 && turn == 2)
				dd = 100;
			else if(l_k == K-1 && turn == 2)
				dd=100;
			else if (l_k == K-2)
				dd == 10;
			else dd == l_k;
			l_k=0;
			//downwards
			if(i!=N-1)
			{
				for(;l_k < k; l_k++)
		    		{	if(i+l_k < N)
		        		if(board[i][j] != board[i+l_k][j])
		            		break;
		    		}
			}
			c = 0;
			for (x = 1; x<=K; x++)
				{
					if(board[i][j]== 'X')
						c=c+1;
				}
			if(l_k == K)
				down = 1000;
			else if (l_k == K-1 && turn == 1)
				down = 1000;
			else if(c==K-1 && turn == 1)
				down = 1000;
			else if (c==K-1 && turn == 2)
				down = 100;
			else if (l_k == K-1 && turn ==2)
				down = 100;
			else if (l_k == K-2)
				down == 10;
			else down == l_k;
			l_k=0;
			score = score + du+dd+right+down;
			//cout<<"score of p1------->"<<score<<endl;
			}
			
		}		
	}
	return score;
}

double player2 (vector<string> board, int turn){
	int i=0,j=0,x=0,c=0;
	double score=0;
	int k= K;
	
	for (i=0;i<N;i++)
	{
		for (j=0;j<M;j++)
		{
			if(board[i][j] == '.')
			continue;
			else if(board[i][j] == 'O')
			{
			int du=0,dd=0,down=0,right=0;
			int l_k = 0;
			//diagonally upwards
			if(i!=0 && j!=M-1)
			{
				
				for(;l_k < k; l_k++)
				{	if(i-l_k > 0 && j+l_k < M)
					if(board[i][j] != board[i-l_k][j+l_k])
					break;
				}
			}
			c = 0;
			for (x = 1; x<=K; x++)
				{
					if(board[i][j]== 'X')
						c=c+1;
				}
			if(l_k == K)
				du = 1000;
			else if (l_k == K-1 && turn ==1)
				du = 1000;
			else if(c==K-1 && turn == 1)
				du = 1000;
			else if (c==K-1 && turn == 2)
				du = 100;
			else if (l_k == K-1 && turn ==2)
				du = 100;
			else if (l_k == K-2)
				du == 10;
			else du == l_k;
			l_k=0;
			c=0;
			//rightside
			if(j!=M-1)
			{
				for(;l_k < k; l_k++)
		    		{	if(j+l_k < M)
		        		if(board[i][j] != board[i][j + l_k])
		            		break;
		    		}
			}
		//	cout<<"lk"<<l_k<<endl;
			c = 0;
			for (x = 1; x<=K; x++)
				{
					if(board[i][j]== 'X')
						c=c+1;
				}
			if(l_k == K)
				right = 1000;
			else if (l_k == K-1 && turn ==1)
				right = 1000;
			else if(c==K-1 && turn == 1)
				right = 1000;
			else if (c==K-1 && turn == 2)
				right = 100;
			else if (l_k == K-1 && turn ==2)
				right=100;
			else if (l_k == K-2)
				right == 10;
			else right == l_k;
			l_k=0;
			
			//diagonally downwards
			if(i!=N-1 && j != M-1)
			{
				for(;l_k < k; l_k++)
		    		{	if(i+l_k < N && j+l_k < M)
		        		if(board[i][j] != board[i+l_k][j + l_k])
		            		break;
		    		}
			}
			c = 0;
			for (x = 1; x<=K; x++)
				{
					if(board[i][j]== 'X')
						c=c+1;
				}
			if(l_k == K)
				dd = 1000;
			else if (l_k == K-1 && turn == 1)
				dd = 1000;
			else if(c==K-1 && turn == 1)
				dd = 1000;
			else if (c==K-1 && turn == 2)
				dd = 100;
			else if(l_k == K-1 && turn == 2)
				dd=100;
			else if (l_k == K-2)
				dd == 10;
			else dd == l_k;
			l_k=0;
			//downwards
			if(i!=N-1)
			{
				for(;l_k < k; l_k++)
		    		{	if(i+l_k < N)
		        		if(board[i][j] != board[i+l_k][j])
		            		break;
		    		}
			}
			c = 0;
			for (x = 1; x<=K; x++)
				{
					if(board[i][j]== 'X')
						c=c+1;
				}
			if(l_k == K)
				down = 1000;
			else if (l_k == K-1 && turn == 1)
				down = 1000;
			else if(c==K-1 && turn == 1)
				down = 1000;
			else if (c==K-1 && turn == 2)
				down = 100;
			else if (l_k == K-1 && turn ==2)
				down = 100;
			else if (l_k == K-2)
				down == 10;
			else down == l_k;
			l_k=0;
			score = score + du+dd+right+down;
			//cout<<"score of p1------->"<<score<<endl;
			}
		}
	}

	return score;
}

static double eval(vector<string> board, int turn)
{	//int turn =1;
	double p1 = player1(board, turn);
	cout<<"p1-->"<<p1<<endl;
	double p2 = player2(board, turn);
	cout<<"p2-->"<<p2<<endl;
	double score =  p1-p2;	
	cout<<"score of eval-->"<<score;	
	return score;
}

int main(int argc, char *argv[])
{	
	cout <<"Enter nmk"<<endl;
	cin >> N>>M>>K;
std::vector<std::string> a;
a.push_back("XXXXX.");
a.push_back("......");
a.push_back("...X..");
a.push_back("...OO.");
a.push_back("......");
a.push_back("......");

	double x = eval(a);
	cout<<"Eval function-->"<<x<<endl;
	return 0;
}


