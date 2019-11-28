#include <cassert>

#include "example_lib.h"

int main(int argc, char **argv) {
  auto printme = example_lib::constructString();
  assert(printme == "Hello world! ");
  return 0;
}
