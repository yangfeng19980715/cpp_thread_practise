#include "../../headers/headers.h"

#define LIST_3_3
#include "headers_ch3.h"
#undef LIST_3_3

#include "fmt/format.h"

int main()
{

    std::jthread t{[] { std::cout << fmt::format("hello, {0}{1}", "world", '\n'); }};

    return 0;
}
