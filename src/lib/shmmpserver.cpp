#include <cstring>
#include <shmmp.h>

ShmmpServer::ShmmpServer(std::string name, size_t n_buffers, size_t bufferSize)
{
    myKey = Shmmp::stringToKey(name);
    myName = name;
    myBufferCnt = n_buffers;
    myBufferSz = bufferSize;
    myAllocaSz = 2 + name.length() + (sizeof(pthread_mutex_t)*n_buffers*2) + (bufferSize * n_buffers);
    int rv = shmget(myKey,myAllocaSz,IPC_CREAT | IPC_EXCL | 0666);
    if (rv == -1)
    {
        perror("shmget");
        ::exit(1);
    }
    myShmId = rv;
    void *shmp = shmat(rv,nullptr,0);
    if (shmp == (void *)-1)
    {
        perror("shmat()");
        ::exit(1);
    }
    uint8_t *u8p = reinterpret_cast<uint8_t *>(shmp);
    *u8p = name.length();
    strncpy(reinterpret_cast<char *>(&u8p[1]),name.c_str(),name.length());
    u8p += name.length()+1;
    *u8p = n_buffers;
}

key_t ShmmpServer::key() { return myKey; }
size_t ShmmpServer::shmSize() { return myAllocaSz; }

ShmmpServer::~ShmmpServer()
{
    struct shmid_ds d;
    if (shmctl(myShmId,IPC_RMID,&d) == -1)
        perror("shmctl");
}
