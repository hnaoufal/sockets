#include <stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>


int main() {
  int welcomeSocket, newSocket;
  char buffer[1024];
  struct sockaddr_in serverAddr;
  struct sockaddr_storage serverStorage;
  socklen_t addr_size;

  /* Create a Socket */

  welcomeSocket = socket(PF_INET, SOCK_STREAM, 0);
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(7891);
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

  bind(welcomeSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

  if(listen(welcomeSocket, 5)==0) {
    printf("Listening\n");
  }else {
    printf("Error\n");
  }

  addr_size = sizeof serverStorage;
  newSocket = accept(welcomeSocket, (struct sockaddr  *) &serverStorage, &addr_size);

  strcpy(buffer, "bums\n");
  send(newSocket, buffer, 13, 0);

  return 0;
}

/*
 
    while ((new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size)) > 0)
    {
        inet_ntop(their_addr.ss_family,
                get_in_addr((struct sockaddr *)&their_addr),
                s, sizeof s);
        printf("server: got connection from %s\n", s);

        if (fork() == 0)
        {
            close(sockfd);
            char input[] = "This is the response!";
            if (send(new_fd, input, strlen(input), 0) == -1)
                perror("send");
            close(new_fd);
            exit(0);
        }

        close(new_fd);
    }
        */
