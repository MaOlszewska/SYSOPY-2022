#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include "common.h"

int queue_s;
int queue_c;
int current_ID;

void init(){
    messagebuf message;
    message.messagetype = INIT;
    message.clientKey = queue_c;

    if(msgsnd(queue_s, &message, size, 0) != 0){
        printf("Nie udało się odesłać wiadomości :(");
        exit(1);
    }
    messagebuf recive_message;
    if(msgrcv(queue_s, &message, size, INIT,0) == -1){
        perror("Nie udało się odebrać wiadomości :( ");
        exit(1);
    }
    current_ID = recive_message.idClient;
    printf("MOJE ID to: %d", current_ID);
}

void stop(){
    messagebuf message;
    message.messagetype = STOP;
    message.idClient = current_ID;
    if(msgsnd(queue_s, &message, size, 0) == -1){
        printf("Nie udało się odesłać wiadomości :(");
        exit(1);
    }
}
void list(){
    messagebuf message;
    message.messagetype = LIST;
    if(msgsnd(queue_s, &message, size, 0) != 0){
        printf("Nie udało się odesłać wiadomości :(");
        exit(1);
    }
}


int main(int argc, char* argv[]) {

    char * path = getenv("HOME");
    key_t key = ftok(path, 'A');
    if(key == -1){  // tworzę sobie unikalny klucz na podstawie ścieżki HOME dla kolejki
        perror("Nie udało się stworzyć unikalnego klucza :( ");
        exit(1);
    }
    // kolejka serwera
    queue_s = msgget(key, IPC_CREAT); //IPC_CREATE - tworzy kolejke w przypadku jej braku o takim kluczu
    key_t key_c = ftok(path, getpid());
    if(key_c == -1){  // tworzę sobie unikalny klucz na podstawie ścieżki HOME dla kolejki
        perror("Nie udało się stworzyć unikalnego klucza :( ");
        exit(1);
    }
    // kolejka serwera
    queue_c = msgget(key_c, IPC_CREAT); //IPC_CREATE - tworzy kolejke w przypadku jej braku o takim kluczu
    printf("CLIENT ID: %d", key_c);
    init();
    char line[256];
    char buff[256];
    int tmpid;
    while(true){
        fgets(line, 256, stdin);
        line[strcspn(line, "\n")] = '\0';

        if(strcmp(line, "STOP") == 0){
            stop();
        }
        else if(strcmp(line, "LIST") == 0){
            list();
        }
        else if(strcmp(line, "ALL") == 0){
            messagebuf message;
            message.messagetype = ALL;
            message.idClient = current_ID;

            printf("PODAJ TREŚĆ WIADOMOŚCI: \n");
            scanf("%c ", buff);
            strcpy(message.messagetext, buff);
            if(msgsnd(queue_s, &message, size, 0) != 0){
                printf("Nie udało się odesłać wiadomości :(");
                exit(1);
            }
            printf("WYSŁAŁEM WIADOMOŚĆ DO WSZYSTKICH");
        }
        else if(strcmp(line, "ONE") == 0){
            printf("PODAJ TREŚĆ WIADOMOŚCI: \n");
            scanf("%c ", buff);
            printf("PODAJ NUMER ID KLIENTA \n");
            scanf("%s ", buff);
            tmpid = atoi(buff);
            messagebuf message;
            message.messagetype = ONE;
            message.idClient = current_ID;
            message.to_send = tmpid;
            strcpy(message.messagetext, buff);
            if(msgsnd(queue_s, &message, size, 0) != 0){
                printf("Nie udało się odesłać wiadomości :(");
                exit(1);
            }
        }
        else{
            printf("Nie dostałem nic");
        }
    }

}