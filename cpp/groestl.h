#ifndef __GROESTL_H__
#define __GROESTL_H__

#include <cstdlib>
#include <stdint.h>
#include <ap_int.h>

void groestl(uint64_t data0, uint64_t data1, uint64_t data2, uint64_t data3, uint64_t data4,
		uint64_t data5, uint64_t data6, uint64_t data7, uint64_t data8, uint64_t data9, uint32_t target7, uint32_t target6, uint32_t startnonce,
		ap_int<32> *result, ap_int<1> *ticket);

#endif
