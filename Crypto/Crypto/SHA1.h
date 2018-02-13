

#ifndef _SHA1_H_
#define _SHA1_H

#include "Crypto.h"

//SHA1
#define SHA1_SIZE_BYTE 20
typedef struct SHAstate_st
{
	unsigned long h[SHA1_SIZE_BYTE / 4]; /* 存放摘要结果(32*5=160 bits)*/
	unsigned long Nl;
	unsigned long Nh;       /*存放信息总位数，Nh：高32位，Nl：低32位*/
	unsigned long data[16]; /*数据从第0个的高8位开始依次放置*/
	int FlagInWord;     /*标识一个data元素中占用的字节数（从高->低），取值0,1,2,3*/
	int msgIndex;       /*当前已填充满的data数组元素数。*/
	int isTooMang;      /*正常为0，当处理的信息超过2^64 bits时为1；*/
} SHA1_Context;

#define INIT_DATA_h0 0x67452301U
#define INIT_DATA_h1 0xEFCDAB89U
#define INIT_DATA_h2 0x98BADCFEU
#define INIT_DATA_h3 0x10325476U
#define INIT_DATA_h4 0xC3D2E1F0U

#define SHA1CircularShift(bits, word) (((word) << (bits)) | ((word) >> (32 - (bits))))

typedef unsigned long(*SHA1_pFun)(unsigned long, unsigned long, unsigned long);

/*定义四个函数*/
static unsigned long SHA1_ft0_19(unsigned long b, unsigned long c, unsigned long d)
{
	return (b&c) | ((~b)&d);
}

static unsigned long SHA1_ft20_39(unsigned long b, unsigned long c, unsigned long d)
{
	return b ^ c ^ d;
}

static unsigned long SHA1_ft40_59(unsigned long b, unsigned long c, unsigned long d)
{
	return (b&c) | (b&d) | (c&d);
}

static unsigned long SHA1_ft60_79(unsigned long b, unsigned long c, unsigned long d)
{
	return b ^ c ^ d;
}

static int SHA1_Init(SHA1_Context *c);
static int SHA1_GetMsgBits(SHA1_Context *c);
static int SHA1_Clear_data(SHA1_Context *c);
static int SHA1_One(SHA1_Context *c);
static int SHA1_PadMessage(SHA1_Context *c);
static int SHA1_Update(SHA1_Context *c, const unsigned char *chBuff, unsigned int n);
static int SHA1_Final(SHA1_Context *c, unsigned char * md);
/**
* @brief SHA1_String
*
* Detailed description.
* @param[in] inputString 要进行处理的无符号字符串指针
* @param[in] len 要处理的信息长度，n<= strlen(p);
* @param[out] pOutSHA1Buf 输出摘要信息，长度为20的 unsigned char ，共160 bits
* @return int
*/
static int SHA1_String(const unsigned char* inputString, unsigned long len, unsigned char* pOutSHA1Buf);


#endif