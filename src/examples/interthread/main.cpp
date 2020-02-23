#include <iostream>
#include <shmmp.h>

int main(int,char **)
{
    ShmmpServer srv("ExampleServer",3,4096);
    std::cout << "Shared memory server of size " << srv.shmSize() << " with key: " << std::hex << srv.key() << std::dec << std::endl;
}
