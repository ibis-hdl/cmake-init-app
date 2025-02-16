#include <catch2/catch_test_macros.hpp>

#include "lib.hpp"

TEST_CASE("Name is app", "[library]")
{
  auto const lib = library {};
  REQUIRE(lib.name == "app");
}

TEST_CASE("Sanitize Leak Test", "[detected memory leaks]")
{
  int* x = new int;
  REQUIRE(x != nullptr);
}

TEST_CASE("Sanitize Test", "[heap-use-after-free]")
{
  int* x = new int;
  delete x;
  REQUIRE(*x == 42);
}
