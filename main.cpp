#include <iostream>
#include <cstring>
#include "Rc4.h"
int main(int argc, char *argv[]) {

    std::string str("titi");
//    FILE *fichier = fopen("/home/robin/CLionProjects/RC4/testin.txt", "wb");
//    fwrite("toto", sizeof(char), 4, fichier);

//    Rc4 *rc4 = new Rc4("/home/robin/CLionProjects/RC4/testin.txt", "/home/robin/CLionProjects/RC4/testOut.txt", (unsigned char*) str.c_str());
//    rc4->ksa();
//    rc4->prga();
//
    Rc4 *rc5 = new Rc4("/home/robin/CLionProjects/RC4/testOut.txt", "/home/robin/CLionProjects/RC4/testOut2.txt", (unsigned char*) str.c_str());
    rc5->ksa();
    rc5->prga();
    return 0;
}