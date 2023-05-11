#include "../headers/headers.h"
#include <mutex>

#define LIST_3_3
#include "headers_ch3.h"
#undef LIST_3_3

int
main()
{
  std::mutex mt, mt1;

  std::scoped_lock<std::mutex, std::mutex> sl{ mt, mt1 };

  std::mutex mt2;
  std::lock_guard<std::mutex> lg{ mt2 };

  std::cout << "hello, world" << std::endl;

  return 0;
}
