#include <iostream>
#include <cstring>
#include "Rc4.h"
int main() {

    std::string str("titi");
//    Rc4 *rc4 = new Rc4("/home/robin/CLionProjects/RC4/testIn.txt", "/home/robin/CLionProjects/RC4/testOut.txt", (unsigned char*) str.c_str());
    Rc4 *rc5 = new Rc4("/home/robin/CLionProjects/RC4/testOut.txt", "/home/robin/CLionProjects/RC4/testOut2.txt", (unsigned char*) str.c_str());
//    rc4->ksa();
//    rc4->prga();
    rc5->ksa();
    rc5->prga();
    return 0;
}