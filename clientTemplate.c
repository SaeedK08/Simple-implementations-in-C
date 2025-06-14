#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
// The client should try to send a WebService json msg to the client...
// WebService request uses HTTP explained in lecture 8...
// String constants ROW1 to 6 below must be populated with the
// right content to create a well formed WebService request!
// Remember that each row must end with \r\n according to the HTTP protocol.
// #define ROW1 " method \r\n" 
// #define ROW2 " from\r\n"
// #define ROW3 " what \r\n"            
// #define ROW4 " reply \r\n"
// #define ROW5 "\r\n"
// #define ROW6 "json ssnb last 4 diggits or first name \r\n"
#define ROW1 " POST /AndersCajander HTTP/1.1 \r\n" 
#define ROW2 " 130.229.175.91 \r\n"
#define ROW3 "Content-Type: application/json\r\n"
#define ROW4 "Accept: application/json\r\n"
#define ROW5 "\r\n"
#define ROW6 "{\"name\" : \"Kassab.S\"} \r\n"

int main(int argc, char **argv)
{
	printf("Web Client 0.1\n");
	    int sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        return 1;
    }

   printf("*** SOCKET Established...\n");
   
   struct sockaddr_in addr = {0};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ROW2);            // Host IP-adress
    addr.sin_port = htons(8080);                       // Host port number
	if (connect(sock, (const struct sockaddr *)&addr, sizeof(addr)) == -1) {
        return 2;
    }

	printf("*** CONNECT Success...\n");

    char buf[1024]; sprintf(buf, "%s%s%s%s%s%s", ROW1, ROW2, ROW3, ROW4, ROW5, ROW6);
    printf("*** SENDING \n[%s]\n",buf);
    size_t len = strlen(buf);
	send(sock, buf, len, 0);
	printf("*** SEND Success...\n");

    printf("*** RECEIVING...\n");
	len = recv(sock, buf, sizeof(buf), 0);
	buf[len]='\0';
	if (len)
		printf("***[%s](%d)\n", buf,(int)len);
	
	close(sock);
	printf("*** CONNECTION CLOSED!\n");	
	
	printf("*** DONE...\n");
}

