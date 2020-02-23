#ifndef SHMMPSERVER_H
#define SHMMPSERVER_H

#include <config.h>
#include <string>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <pthread.h>

class ShmmpServer
{
public:
    ShmmpServer(std::string name,size_t n_buffers,size_t bufferSize);
    ~ShmmpServer();
    key_t key();
    size_t shmSize();

private:
    key_t myKey;
    size_t myBufferCnt;
    size_t myBufferSz;
    size_t myAllocaSz;
    std::string myName;
    int myShmId;
};

#endif // SHMMPSERVER_H
