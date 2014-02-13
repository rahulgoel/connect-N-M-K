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
#define FOR(i,n) for (int i = 0; i < n; i++)
#define PB push_back
using namespace std;
/* Complete the function below to print 1 integer which will be your next move 
   */
int N, M, K, player;
vector<string> board;

void update(int n)
{
    for(int i = 0; i < N; i++)
        if(board[i][n] == '.')
        {
            board[i][n] = 'X';
            return;
        }
}

int nextMove()
{
/*
  for(int j = 0; j< M; j++)
  {
    for(int i = 0; i<N; i++)
      if(board[i][j] == '.')
      {
	       board[i][j] = 'O';
           cout << j << endl;
        return j;
      }
  }
  */
  
	int iSecret;
	vector<int> v;
  for(int j = 0; j< M; j++)
  {
    //for(int i = 0; i<N; i++)
      if(board[N-1][j] == '.')
      {
        //return j;
        //cout << j << endl;
        v.push_back(j);
      }
  }
  int temp = rand();
  iSecret = temp%v.size();
  //cout << temp << " " << iSecret << " " << v[iSecret] << endl;
  update(v[iSecret]);
  return v[iSecret];
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
        recvBuff[n] = 0;
        sscanf(recvBuff, "%d", &nextColumn);
        //cout << "Rec: "<< nextColumn << endl;
	    update(nextColumn);

	    cout << nextColumn << endl;
	    
        memset(sendBuff, '0', sizeof(sendBuff)); 
        int temp = nextMove();
        //cout << "temp" << endl;
        snprintf(sendBuff, sizeof(sendBuff), "%d", temp);
        write(sockfd, sendBuff, strlen(sendBuff));
    }

    return 0;
}
