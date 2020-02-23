#ifndef SHMPP_H
#define SHMPP_H

#include <shmmpserver.h>

typedef uint64_t shmmp_connection_id;

namespace Shmmp
{
    key_t stringToKey(std::string);
    shmmp_connection_id nextConnectionId();
    struct shmmpConnectionRequest {
        shmmp_connection_id id;
        pid_t process_id;
    };
}

#endif // SHMPP_H
