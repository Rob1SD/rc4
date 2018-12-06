//
// Created by robin on 15/11/18.
//



#include "Rc4.h"
std::ifstream::pos_type filesize(const char* filename)
{
    std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
    return in.tellg();
}


Rc4::Rc4(char *filein, char *fileout, unsigned char *key) : filein(filein), fileout(fileout), key(key) {
//    std::ifstream fichier(filein);
//    std::string ligne;
//    std::stringstream tmpStream;
//    while (getline(fichier, ligne)) // attentions sur des gros fichier ca explose la ram mais ca ira pour demain;
//    {
//        unsigned char tmp[std::strlen((char *)inString) + ligne.length()];
//        unsigned long sizeLigne=ligne.length();
//        char tab[sizeLigne];
//        strcpy(tab,ligne.c_str());
//        std:strcat((char*)tmp, tab);
//        inString = tmp;
//        std::cout << "ligne" << std::endl;
//        std::cout << ligne << std::endl;
//        tmpStream << ligne << "\n";
//    }
//    std::cout << "fichier" << std::endl;
//    std::cout << tmpStream.str() << std::endl;
//    std::string tmpstr= tmpStream.str().substr(0, tmpStream.str().length());
//    std::cout << "tmpStream.str() : " << tmpStream.str() << std::endl;
//    std::cout << "tmpstr : " << tmpstr << std::endl;
//    inString=(unsigned char*)tmpstr.c_str();
//    std::cout << "inString0 : " << (std::string)((char*)inString) << std::endl;
    //prga();

    long long int fileSize = filesize(filein);
    FILE *fichier = fopen(filein, "rb");
    unsigned char content[fileSize];
    fread(content, sizeof(unsigned char), fileSize, fichier);
    std::cout << "content" << content << std::endl;
    inString=content;
//    prga();
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
    std::cout << "instring : " << inString << std::endl;
    long long int fileSize = filesize(filein);
    unsigned char out[fileSize];
    for (int k = 0; k < fileSize; ++k)
    {
        i = (i+1)%256;
        j = (j+s[i])%256;
        unsigned char tmp = s[i];
        std::cout << "'" << (int)((char)s[i]) << "'"<<std::endl;
        s[i] = s[j];
        s[j] = s[tmp];
        out[k]=s[(s[i]+s[j])%256]^inString[k];
        std::cout << "'" << (int)((char)out[k]) << "'"<<std::endl;
//        std::cout << "babibel" << std::endl;
//        std::cout << (int) out[k] << std::endl;
    }
    outString=out;
    std::string res((char*)out);
    std::cout << "conversion finie" << std::endl;
//    std::ofstream fichierOut(fileout);
//    for (int i = 0; i < 30; ++i)
//        std::cout << "'" << (int)((char)out[i]) << "'"<<std::endl;
//    fichierOut.write((char*)&out, sizeof out);
//    std::cout << res << std::endl;
//    long long int fileSize = filesize(filein);
    FILE *fichier = fopen(fileout, "wb");
    fwrite(outString, sizeof(unsigned char), fileSize, fichier);
}


































