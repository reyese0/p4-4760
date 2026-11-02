#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>

#define SHM_KEY 1234
#define MSG_KEY 2345
#define OSS_MESSAGE_TYPE 1

typedef struct {
    unsigned int seconds;
    unsigned int nanoseconds;
} MyClock;

typedef struct {
    long mtype;
    int quantumNs;
} DispatchMessage;

typedef struct {
    long mtype;
    pid_t pid;
    int usedNs;
} ReportMessage;

int main(int argc, char *argv[]) {
    int shmId;
    int msgId;
    MyClock *myClock;

    shmId = shmget(SHM_KEY, sizeof(MyClock), 0666);
    if (shmId == -1) {
        perror("user shmget");
        return EXIT_FAILURE;
    }

    myClock = (MyClock *)shmat(shmId, NULL, 0);
    if (myClock == (void *)-1) {
        perror("user shmat");
        return EXIT_FAILURE;
    }

    msgId = msgget(MSG_KEY, 0666);
    if (msgId == -1) {
        perror("msgget in child");
        shmdt(myClock);
        return EXIT_FAILURE;
    }

    shmdt(myClock);
    return 0;
}