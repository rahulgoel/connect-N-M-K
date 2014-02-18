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

double eval(vector<string> board)
{	int i=0,j=0;
	double score1 = 0,score2=0, eval_score=0;
	int k=K;
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			if(board[i][j] == '.')
			continue;
			else if(board[i][j] == 'X')
			{
			int du1=0,dd1=0,down1=0,right1=0;
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
			du1=l_k;
			l_k=0;
			//rightside
			if(j!=M-1)
			{
				for(;l_k < k; l_k++)
		    		{
		        		if(board[i][j] != board[i][j + l_k])
		            		break;
		    		}
			}
			right1=l_k;
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
			dd1=l_k;
			l_k=0;
			//downwards
			if(i!=N-1)
			{
				for(;l_k < k; l_k++)
		    		{
		        		if(board[i][j] != board[i+l_k][j])
		            		break;
		    		}
			}
			down1=l_k;
			l_k=0;
			score1 = score1 + ((du1*du1+dd1*dd1+right1*right1+down1*down1)*100);
			//cout<<"Score for X -->"<<score1<<endl;
			}
			else if(board[i][j] == 'O')
			{
			int du2=0,dd2=0,down2=0,right2=0;
			int l_k = 0;
			//diagonally upwards
			if(i!=0 && j !=M-1)
			{
				
				for(;l_k < k; l_k++)
				{	if(i-l_k > 0 && j+l_k < M)
					if(board[i][j] != board[i-l_k][j+l_k])
					break;
				}
			}
			du2=l_k;
			l_k=0;
			//rightside
			if(j!=M-1)
			{
				for(;l_k < k; l_k++)
		    		{
		        		if(board[i][j] != board[i][j + l_k])
		            		break;
		    		}
			}
			right2=l_k;
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
			dd2=l_k;
			l_k=0;
			//downwards
			if(i!=N-1)
			{
				for(;l_k < k; l_k++)
		    		{
		        		if(board[i][j] != board[i+l_k][j])
		            		break;
		    		}
			}
			down2=l_k;
			l_k=0;
			score2 = score2 + ((du2*du2+dd2*dd2+right2*right2+down2*down2)*100);
			//cout<<"Score for 'O' -->"<<score2<<endl;
			}

		}
	}	
	eval_score = (score1 - score2)/(4*K);
	return eval_score;
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

