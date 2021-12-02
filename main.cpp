#include <fmt/format.h>

#include "OptimizationAlgorithm.h"
#include "MultilevelCoordinateSearch.h"

int main()
try
{
  const auto f = [](const std::vector<double>& params) { return params.size(); };
  const std::vector<double> lb = {};
  const std::vector<double> ub = {};

  MultilevelCoordinateSearch optimizer(lb, ub);
  const auto result = optimizer.Optimize(f);
}
catch (const std::exception& e)
{
  fmt::print("Error: {}\n", e.what());
}