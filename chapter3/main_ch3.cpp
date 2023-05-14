#include "../headers/headers.h"
#include <mutex>
#include <random>

#define LIST_3_3
#include "headers_ch3.h"
#undef LIST_3_3

class some_resource
{
  static int num;

public:

  void
  do_something()
  {
    std::cout << "hello"
              << ", "
              << "world" << std::endl;
  }
};

std::shared_ptr<some_resource> resource_ptr;
std::once_flag resource_flag; // 1

void
init_resource()
{
  resource_ptr.reset(new some_resource);
}

void
foo()
{
  std::call_once(resource_flag, init_resource); // 可以完整的进行一次初始化
  resource_ptr->do_something();
}

int
main()
{
  std::jthread th1([] { foo(); });
  std::jthread th2([] { foo(); });

  return 0;
}
