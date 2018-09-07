/*
 * inthash.h
 *
 *	A simple hash, which only stores an integer id.
 *
 *  Created on: 18 Sep 2014
 *      Author: mrpivello
 *
 *
 */

#ifndef INT_HASH_H
#define INT_HASH_H

#include <stdio.h>
#include <stdlib.h>
#include "mftl.h"

typedef struct
{
	int id;
	UT_hash_handle hh;
} IntHash;


IntHash* IntHashAddData(IntHash **hash, int data);
void IntHashFree(IntHash **hash);
int IntHashIdSort(IntHash *a, IntHash *b);
void IntHashShowSummary(IntHash *hash, FILE *fp, const char *msg);



#endif /* INTHASH_H_ */
