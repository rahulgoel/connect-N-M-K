//Running format is: <object file> <ip of server> <port no>
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
/* Added Code */
#include <time.h> 
#include <sys/time.h> 
/* */

#define FOR(i,n) for (int i = 0; i < n; i++)
#define PB push_back
using namespace std;
/* Complete the function below to print 1 integer which will be your next move 
   */
int N, M, K, player;
vector<string> board;

/* Added Code */
double time_left = 0;
/* */

void update(int n, int player)
{
    for(int i = 0; i < N; i++)
        if(board[i][n] == '.')
        {
            if(player == 1)
              board[i][n] = 'X';
            else
              board[i][n] = 'O';
            return;
        }
}
vector<string>  updatestate(vector<string> board,int n,int mode)
{
    for(int i = 0; i < N; i++)
        if(board[i][n] == '.')
        {
            if(mode==1) board[i][n] = 'X';
	    else if(mode==0) board[i][n] = 'O';
            return board;
        };
  return board;
}

int MinValue(vector<string> s, int aplha, int beta, int depth);
int MaxValue(vector<string> s, int aplha, int beta, int depth);
double eval(vector<string> s);
int alphabeta(vector<string> s, int depth);

int nextMove()
{

   int temp;
  // iSecret = temp%v.size();
  // //cout << temp << " " << iSecret << " " << v[iSecret] << endl;
  // update(v[iSecret]);
  // return v[iSecret];
   temp= alphabeta(board,5);
  update(temp,0);
  return temp;
}
void printboard(vector<string> s){
  for( int i=0;i< N;i++){
    for (int j=0;j<M;j++){
      cout<<s[i][j]<<" ";
    }
    cout<<endl;
  }
}

// n m k - k together, m width, n height
int alphabeta(vector<string> s,int depth){
  int v;vector<int> action;int minv;
  // v=MaxValue(s,1000,-1000,depth);
  // cout<<"this is v(max value):"<<v<<endl;
  printboard(s);
  for(int i=0;i< M;i++){
       
    if(s[N-1][i] != '.'){action.PB(-100000);continue;}
    minv=MinValue(updatestate(s,i,1),-10000,10000,depth);
    cout<<"This is the minvalue:"<<minv<<endl;
    action.PB(minv);
    // if(v==(MinValue(updatestate(s,i),-1000,1000,(depth-1))))
    //   { cout<<"The value we are returning is:"<<i<<endl;
    // 	return i;
    //   }
    
  }
  int maxv=-100000;int maxindex;
  for(int i=0;i< action.size();i++){
    cout<<"sss:"<<action[i]<<endl;
    if(action[i]>maxv){
      maxv=action[i];
      maxindex=i;
    }
  }
  cout<<"The value we are returning is:"<<maxindex<<endl;
  // if(s[N-1][maxindex]!='.') return 0;
  // if(maxv==0){cout<<"exhausted all possi:\n";
  //    exit(1);
  //  }
  return maxindex;
}

int MaxValue(vector<string> s, int alpha, int beta, int depth){
  if(depth<=0) return eval(s);
  int v;
  v=-10000;
    for(int i=0;i<M;i++){
      v= max(v,MinValue(updatestate(s,i,1),alpha,beta,depth-1));
      if(v>= beta) 
	return v;
      alpha=max(alpha,v);
    }
    return v;
}

int MinValue(vector<string> s, int alpha, int beta, int depth){
  if(depth<=0) return eval(s);
  int v;
  v=10000;
  for(int i=0;i<M;i++){
    v= min(v,MaxValue(updatestate(s,i,0),alpha,beta,depth-1));
    if(v<= alpha) 
      return v;
    beta=min(beta,v);
  }
  return v;
}

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
		    {	if(j+l_k < M)
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
		    {	if(i+l_k < N)
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
		    {	if(j+l_k < M)
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
		    {	if(i+l_k < N)
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
  srand (time(NULL));
  int sockfd = 0, n = 0;
  char recvBuff[1024];
  char sendBuff[1025];
  struct sockaddr_in serv_addr; 

  if(argc != 3)
    {
      printf("\n Usage: %s <ip of server> <port no> \n",argv[0]);
      return 1;
    } 

    
  if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
      printf("\n Error : Could not create socket \n");
      return 1;
    } 

  memset(&serv_addr, '0', sizeof(serv_addr)); 

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(atoi(argv[2])); 

  if(inet_pton(AF_INET, argv[1], &serv_addr.sin_addr)<=0)
    {
      printf("\n inet_pton error occured\n");
      return 1;
    } 

  if( connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
      printf("\n Error : Connect Failed \n");
      return 1;
    } 

  cout<<"Connect(N,M,K) will start"<<endl;

  memset(recvBuff, '0',sizeof(recvBuff));
  n = read(sockfd, recvBuff, sizeof(recvBuff)-1);
  recvBuff[n] = 0;
  sscanf(recvBuff, "%d", &N);

  cout<<"N: "<<N<<endl;
  memset(recvBuff, '0',sizeof(recvBuff));
  n = read(sockfd, recvBuff, sizeof(recvBuff)-1);
  recvBuff[n] = 0;
  sscanf(recvBuff, "%d", &M);

  cout<<"M: "<<M<<endl;
  memset(recvBuff, '0',sizeof(recvBuff));
  n = read(sockfd, recvBuff, sizeof(recvBuff)-1);
  recvBuff[n] = 0;
  sscanf(recvBuff, "%d", &K);    
    
  cout<<"K: "<<K<<endl;

  /* Added code */
  int TL;
  memset(recvBuff, '0',sizeof(recvBuff));
  n = read(sockfd, recvBuff, sizeof(recvBuff)-1);
  recvBuff[n] = 0;
  sscanf(recvBuff, "%d", &TL);    
    
  cout<<"Time Limit: "<<TL<<endl;    
  time_left = TL;

  /* */

  memset(recvBuff, '0',sizeof(recvBuff));
  n = read(sockfd, recvBuff, sizeof(recvBuff)-1);
  recvBuff[n] = 0;
  sscanf(recvBuff, "%d", &player);  

  cout<<"Player "<<player<<endl;

  string temp = "";
  for(int j = 0; j< M; j++)
    temp += ".";
  FOR(i, N)
    board.PB(temp);

  if(player == 1)
    {
      //cout << "hello" << endl;
      memset(sendBuff, '0', sizeof(sendBuff)); 
      int temp = nextMove();
      //cout << "temp" << endl;
      snprintf(sendBuff, sizeof(sendBuff), "%d", temp);
      write(sockfd, sendBuff, strlen(sendBuff));
    }

  while(1)
    {
      int nextColumn;

      memset(recvBuff, '0',sizeof(recvBuff));
      n = read(sockfd, recvBuff, sizeof(recvBuff)-1);

      /* Added Code */
      struct timeval  tv1, tv2;
      gettimeofday(&tv1, NULL);
      /* */

      recvBuff[n] = 0;
      sscanf(recvBuff, "%d", &nextColumn);
      //cout << "Rec: "<< nextColumn << endl;
      if(player == 1)
	update(nextColumn, 2);
      else 
	update(nextColumn, 1);

      cout << nextColumn << endl;
	    
      memset(sendBuff, '0', sizeof(sendBuff)); 
      int temp = nextMove();
      //cout << "temp" << endl;
      snprintf(sendBuff, sizeof(sendBuff), "%d", temp);

      /** Added Code */
      gettimeofday(&tv2, NULL);
      double time_spent = (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 + (double) (tv2.tv_sec - tv1.tv_sec);
      time_left -= time_spent;
      /* */

      write(sockfd, sendBuff, strlen(sendBuff));
    }

  return 0;
}
