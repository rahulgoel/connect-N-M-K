connect-N-M-K
=============

AI player for generalized connect 4

The question statement:
Random walk player, with mininax and alpha beta pruning implemented as a solution.Implements hashmap to save time and ignore redundant solutions.


Server .cpp is the server which takes 2 bots 
The server compilation that you would be given would be able to run as ./server <portno>
<total_time_for_each_player> <N> <M> <K> <mode>. After this you can do a “sudo netstat -ntlp” to check if the
server is listening on the port you have provided. Then you can run the first client using ./client <ip_of_server>
<port_no> (for localhost you need to put in 127.0.0.1). Following which you need to start the second client in the
similar manner. The server then sends initialization information to both the clients and the client that connects first
becomes the first player (The one you start first). After that the clients and the server will exchange the game
information. You will only need to fill in the nextMove() function provided in the client's code. This function will
make use of the board state that in the random bot is stored in vector<string> board. nextMove() function returns
the column number (0-indexed from the left) for which you want to place the next move. Note you might not want
to play into a column number >= M (NO_OF_COLUMNS) or else you may lose the game. Also you may not want to
play in a column that is already full (else you will lose the game). There is a total time assigned to you that gets
decremented when your turn is going on (else you will lose the game). You might not want to exhaust the same.
Finally you can write any auxillary code that you want in the client that we are providing just make sure you maintain
a somewhat similar protocol (as there is present in the random bot) to interact with the server.
The mode argument with server lets you run on a bot vs bot mode or a human vs bot mode. Mode = 0 is the bot vs
bot mode(explained above). Mode 1 allows you to play in the other mode in which you will have to play when your
turn comes by entering a column number at the terminal where you run the server.
