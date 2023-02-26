
#include "BufferedInputStream.h"
#include <iostream>
#include <cstdio>

using std::cout;
using std::cerr;

void BufferedInputStream::close()
{
   if(fp != nullptr)
   {
      fflush(fp);
      fclose(fp);
      fp = nullptr;
   }
}

int BufferedInputStream::read_int()
{
   int b1 = read() & 0xff;
   int b2 = read() & 0xff;
   int b3 = read() & 0xff;
   int b4 = read() & 0xff;
   return b4 << 24 | b3 << 16 | b2 << 8 | b1;
}

char BufferedInputStream::read()
{
   if(idx < BUFSIZ)
      return buf[idx++];
   else
   {
      idx = 0;
      if (fread(buf, BUFSIZ, 1, fp))
         return buf[idx++];
      else
      {
         cerr << "have reached EOF\n";
         return -1;
      }
   }
}

BufferedInputStream::BufferedInputStream(char* filename)
{
   fp = fopen(filename, "rb");
   fread(buf, BUFSIZ, 1, fp);
   idx = 0;
}

BufferedInputStream::~BufferedInputStream()
{
   close();
}