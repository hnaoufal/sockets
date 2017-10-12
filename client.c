#include <stdio.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

int main() {

  int clientSocket;
  char buffer[1024];
  struct sockaddr_in serverAddr;
  socklen_t addr_size;

  /* Create the socket */
  clientSocket = socket(PF_INET, SOCK_STREAM, 0);

  /* Setting Server Informations */
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(7891);
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);


  /* Connect the socket to the server using the address */
  addr_size = sizeof serverAddr;
  connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);

  /* Read the message from the server into the buffer */

    recv(clientSocket, buffer, 1024, 0);

    printf("Data received: %s", buffer);

  return 0;
}
