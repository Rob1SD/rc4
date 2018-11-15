//
// Created by robin on 15/11/18.
//

#include <cstring>
#include <fstream>
#include <iostream>

#include "Rc4.h"

Rc4::Rc4(char *filein, char *fileout, unsigned char *key) : filein(filein), fileout(fileout), key(key) {
    std::ifstream fichier(filein);
    std::string ligne;
    while (getline(fichier, ligne)) // attentions sur des gros fichier ca explose la ram mais ca ira pour demain;
    {
        unsigned char tmp[std::strlen((char *)inString) + ligne.length()];
        unsigned long sizeLigne=ligne.length();
        char tab[sizeLigne];
        strcpy(tab,ligne.c_str());
        std:strcat((char*)tmp, tab);
        inString = tmp;
    }
}


void Rc4::ksa() {
    for (int i = 0; i < 256; ++i)
    {
        s[i]=(unsigned char) i;
    }
    int j = 0;
    for (int i = 0; i < 256; ++i)
    {
        j= (j + s[i] + key[i%std::strlen((char*)key)])%256;
        unsigned char tmp=s[i];
        s[i]=s[j];
        s[j] = tmp;

    }
    std::cout << "Key generated" << std::endl;
}

void Rc4::prga()
{
    int i = 0;
    int j = 0;
    unsigned char out[std::strlen((char*) inString)];
    for (int k = 0; k < std::strlen((char*)inString); ++k)
    {
        i = (i+1)%256;
        j = (j+s[i])%256;
        unsigned char tmp = s[i];
        s[i] = s[j];
        s[j] = s[tmp];
        out[k]=s[(s[i]+s[j])%256]^inString[k];
    }
    std::string res((char*)out);
    std::cout << res << std::endl;
}


































