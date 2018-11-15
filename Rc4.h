//
// Created by robin on 15/11/18.
//

#ifndef RC4_RC4_H
#define RC4_RC4_H


class Rc4 {
private:
    char *filein;
    char *fileout;
    unsigned char *inString;
    unsigned char *outString;
    unsigned char *key;
    unsigned char s[256];

public:
    Rc4(char *filein, char *fileout, unsigned char *key);
    void ksa();
    void prga();




};


#endif //RC4_RC4_H
