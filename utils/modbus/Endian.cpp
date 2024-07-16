#include "Endian.h"
#include <algorithm>

void modbus::endian::reverse(void *data, int len)
{
    auto addr = static_cast<uint8_t *>(data);
    for (int i = 0; i < len / 2; ++i)
    {
        static uint8_t tmp;
        tmp = addr[i];
        addr[i] = addr[len - i - 1];
        addr[len - i - 1] = tmp;
    }
}

void modbus::endian::reverseByteArray(void *arr, const unsigned long len)
{
    auto byteArray = static_cast<char *>(arr);
    std::reverse(byteArray, byteArray + len);
}
