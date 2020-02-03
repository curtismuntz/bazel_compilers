#include <chrono>
#include <iostream>
#include <thread>
#include <boost/thread/thread.hpp>

#include "example_lib.h"

int main(int argc, char **argv) {
  auto kMaxPrints = 5;
  auto printme = example_lib::constructString();

  for (auto i = 0; i < kMaxPrints; ++i) {
    std::cout << printme << i << std::endl;
    // std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    boost::this_thread::sleep_for(boost::chrono::milliseconds(1000));
  }

  return 0;
}
