

#ifndef LEARN_PVM_BUFFEREDINPUTSTREAM_H
#define LEARN_PVM_BUFFEREDINPUTSTREAM_H

#include <cstdio>
#define buf_size 1 << 10

class BufferedInputStream {
 private:
     FILE* fp;
     char buf[buf_size]{};
     unsigned short idx;
 public:

     explicit BufferedInputStream(char* filename);

     ~BufferedInputStream();
     char read();

     int read_int();

     void close();

};


#endif //LEARN_PVM_BUFFEREDINPUTSTREAM_H
