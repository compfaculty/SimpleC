#ifndef __INFRA_H__
#define __INFRA_H__

#include <stdio.h>
void iterArray(void* arr, int size, int sizeofItem, void(*cb)(void* itemPtr));

#endif