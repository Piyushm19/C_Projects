#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

#define MAXLINE 8192 /* Max text line length */

int open_clientfd(char *hostname, int port) {
  int clientfd;
  struct sockaddr_in serveraddr;

  printf("Echo Client is creating a socket.\n");
  if ((clientfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) return -1; 
  //if ((hp = gethostbyname(hostname)) == NULL) return -2; //// not needed as said on piazza
  bzero((char *)&serveraddr, sizeof(serveraddr));
  serveraddr.sin_family = AF_INET;
  serveraddr.sin_port = htons(port);
  printf("Echo Client is trying to connect to %s (%s:%d).\n", hostname,
         inet_ntoa(serveraddr.sin_addr), port);
  if (connect(clientfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0)
    return -1;
  printf("Echo Client connected.\n");
  return clientfd;
}  


int main(int argc, char **argv) {
  int clientfd;
  int port;
  char *host;
  char buf[MAXLINE];
  
  if(argc != 4) {
    fprintf(stderr, "usage: %s <host> <port>\n", argv[0]);
    exit(0);
  }
  host = argv[3];
  port = atoi(argv[2]);
  clientfd = open_clientfd(host, port);
  char* hellomsg = "cs230 HELLO pmakkapati@umass.edu\n";
  ssize_t ns = send(clientfd, hellomsg, strlen(hellomsg), 0);
  ssize_t nr;
 while (nr = recv(clientfd, buf, MAXLINE, 0) > 0) { 
    buf[strlen(buf)] = '\0';
    printf("%s", buf);
    int answer;
    int x, y;
    char* ptr = strtok(buf, " ");
    int i = 0;
    char* answermsg[5];
    answermsg[0] = ptr;
    ptr = strtok(NULL, " ");   
    answermsg[1] = ptr;
    ptr = strtok(NULL, " ");
    answermsg[2] = ptr;
    ptr = strtok(NULL, " ");
    answermsg[3] = ptr;
    ptr = strtok(NULL, " ");
    answermsg[4] = ptr;
    x = atoi(answermsg[2]);
    y = atoi(answermsg[4]);
    char op = *answermsg[3];
   switch(op) {
    case '+':
      answer = (x + y);
      break;
    case '-':
      answer = (x - y);
      break;
    case '*':
      answer = (x * y); 
      break;
    case '/':
      answer = (x / y); 
      break;
    case '%':
      answer = (x % y); 
      break; 
    default:
      break;
    }
   sprintf(buf, "cs230 %i\n", answer);
   ssize_t ns = send(clientfd, buf, strlen(buf), 0);
   buf[strlen(buf) + 1] = '\0';
   buf[strlen(buf)] = '\n';
   fputs(buf, stdout); 
 }
  close(clientfd);
  exit(0);
}

