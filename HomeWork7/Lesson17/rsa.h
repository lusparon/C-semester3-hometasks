#ifndef RSA_H
#define RSA_H
#include <iostream>
#include <assert.h>
#include <NTL/ZZ.h>
using namespace NTL;
using namespace std;

struct PubKey
{
	ZZ e;
	ZZ n;
};

struct PrivateKey
{
	ZZ d;
	ZZ n;
};

struct Params
{
	PubKey pub;
	PrivateKey priv;
};


#endif RSA_H

