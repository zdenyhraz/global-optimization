#include <thread>
#include <chrono>

#include <fmt/format.h>
#include <gopt/MultilevelCoordinateSearch.h>

int main()
try
{
  fmt::print("Running gopt test...\n");
  const auto f = [](const std::vector<double>& params) { return params.size(); };
  const std::vector<double> lb = {0, 0};
  const std::vector<double> ub = {0, 1};

  MultilevelCoordinateSearch optimizer(lb, ub);
  const auto result = optimizer.Optimize(f);
}
catch (const std::exception& e)
{
  fmt::print("Error: {}\n", e.what());
}