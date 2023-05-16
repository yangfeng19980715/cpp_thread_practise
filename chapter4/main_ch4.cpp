#include "../headers/headers.h"

std::mutex mtx;

int
main()
{
  mtx.lock();
  std::cout << "lock()" << std::endl;

  std::cout << "hello, world" << std::endl;

  mtx.unlock();
  return 0;
}
