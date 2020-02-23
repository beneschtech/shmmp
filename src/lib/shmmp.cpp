#include <shmmp.h>

uint32_t F_CRC_CalculaCheckSum(uint8_t const AF_Datos[], uint16_t VF_nBytes);
key_t Shmmp::stringToKey(std::string s)
{
    return static_cast<key_t>(F_CRC_CalculaCheckSum(reinterpret_cast<const uint8_t *>(s.c_str()),s.length()));
}
