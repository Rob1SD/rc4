#include <iostream>
#include <cstring>
#include "Rc4.h"
int main() {

    std::string str("titi");
    Rc4 *rc4 = new Rc4("testIn.txt", "testOut.txt", (unsigned char*) str.c_str());

    rc4->ksa();
    rc4->prga();
    return 0;
}