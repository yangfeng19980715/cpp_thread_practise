#include "../headers/headers.h"
#include <chrono>
#include <thread>

int
find_the_answer_to_ltuae()
{
  std::vector<int> v(10, 1);
  return std::accumulate(v.begin(), v.end(), 0);
}

void
do_other_stuff()
{
  std::this_thread::sleep_for(std::chrono::seconds(5));
}

int
main()
{
  std::future<int> the_answer = std::async(find_the_answer_to_ltuae);
  do_other_stuff();
  std::cout << "The answer is " << the_answer.get() << std::endl;

  return 0;
}
