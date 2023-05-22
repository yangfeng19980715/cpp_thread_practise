#include "headers.h"

int
main()
{
  std::atomic<bool> ab;
  std::cout << std::boolalpha << ab.is_lock_free() << std::endl;

  std::cout << std::boolalpha << std::atomic_bool::is_always_lock_free
            << std::endl;
            
  std::cout << std::boolalpha << std::atomic<uintmax_t>::is_always_lock_free
            << std::endl;

  std::atomic_flag af = ATOMIC_FLAG_INIT;

  std::cout << __PRETTY_FUNCTION__ << std::endl;
  return 0;
}
