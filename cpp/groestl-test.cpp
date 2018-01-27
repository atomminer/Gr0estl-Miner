#include "groestl.h"

bool hex2bin(unsigned char *p, const char *hexstr, size_t len)
{
    char hex_byte[3];
    char *ep;

    hex_byte[2] = '\0';

    while (*hexstr && len) {
        if (!hexstr[1]) {
            return false;
        }
        hex_byte[0] = hexstr[0];
        hex_byte[1] = hexstr[1];
        *p = (unsigned char) strtol(hex_byte, &ep, 16);
        if (*ep) {
            return false;
        }
        p++;
        hexstr += 2;
        len--;
    }

    return(!len) ? true : false;
}

int main() {
	unsigned char data[80];

	uint32_t hash32[16];
	uint32_t t[8] = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
			0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
			0xFFFF0000};
	uint64_t endiandata[10];

	//correct nonce for this block is 0025ba7e
	hex2bin((uint8_t*)&endiandata[0], "000000200d5fccd9d5753089317306e2a5fb44f995727e305b65d2718b102c0000000000afa12cac0cb78f88593e3e07bce9d7ca6fc090ef0172bd06f8f35e20ccf5eef944310c5aecce301b0025ba70", 80);
	ap_int<1> tick;

	uint32_t nonce = groestl(endiandata[0], endiandata[1], endiandata[2],
				endiandata[3], endiandata[4], endiandata[5], endiandata[6],
				endiandata[7], endiandata[8], endiandata[9], 0x000000ff, 0xFFFFFFFF, 0x0025ba7b, &tick);

}
