

#ifndef _SHA1_H_
#define _SHA1_H

#include "Crypto.h"

//SHA1
#define SHA1_SIZE_BYTE 20
typedef struct SHAstate_st
{
	unsigned long h[SHA1_SIZE_BYTE / 4]; /* ���ժҪ���(32*5=160 bits)*/
	unsigned long Nl;
	unsigned long Nh;       /*�����Ϣ��λ����Nh����32λ��Nl����32λ*/
	unsigned long data[16]; /*���ݴӵ�0���ĸ�8λ��ʼ���η���*/
	int FlagInWord;     /*��ʶһ��dataԪ����ռ�õ��ֽ������Ӹ�->�ͣ���ȡֵ0,1,2,3*/
	int msgIndex;       /*��ǰ���������data����Ԫ������*/
	int isTooMang;      /*����Ϊ0�����������Ϣ����2^64 bitsʱΪ1��*/
} SHA1_Context;

#define INIT_DATA_h0 0x67452301U
#define INIT_DATA_h1 0xEFCDAB89U
#define INIT_DATA_h2 0x98BADCFEU
#define INIT_DATA_h3 0x10325476U
#define INIT_DATA_h4 0xC3D2E1F0U

#define SHA1CircularShift(bits, word) (((word) << (bits)) | ((word) >> (32 - (bits))))

typedef unsigned long(*SHA1_pFun)(unsigned long, unsigned long, unsigned long);

/*�����ĸ�����*/
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
* @param[in] inputString Ҫ���д�����޷����ַ���ָ��
* @param[in] len Ҫ�������Ϣ���ȣ�n<= strlen(p);
* @param[out] pOutSHA1Buf ���ժҪ��Ϣ������Ϊ20�� unsigned char ����160 bits
* @return int
*/
static int SHA1_String(const unsigned char* inputString, unsigned long len, unsigned char* pOutSHA1Buf);


#endif