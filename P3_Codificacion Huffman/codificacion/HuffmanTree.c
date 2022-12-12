
#ifndef __HuffmanTree__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long ll;

typedef struct{
    char* text;
    ll freq[256];
} HuffmanTree;

typedef HuffmanTree* HT;


HT buildHT(char *text, ll size){
    HT ht = (HT)malloc(sizeof(HuffmanTree));
    ht->text = text;

    //build frequency
    memset(ht->freq, 0, 256*sizeof(ll));
    for(ll i=0; i < size; i++){
        ll character = text[i];
        ht->freq[character]++;
    }
}

#endif