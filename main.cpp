#include <iostream>
#include <vector>
#include <memory>
#include <map>

#include <fmt/core.h>
#include <fmt/format.h>

#include <globalopt/PatternSearch.h>
#include <globalopt/DifferentialEvolution.h>
#include <globalopt/MultilevelCoordinateSearch.h>

int main()
try
{
  fmt::print("[globalopt] Running tests...\n");

  const auto f = [](const std::vector<double>& params) { return params[0] * params[0] + params[1] * params[1]; };
  const std::vector<double> lb = {0, 0};
  const std::vector<double> ub = {1, 1};

  std::vector<std::unique_ptr<OptimizationAlgorithm<>>> optimizers;
  optimizers.push_back(std::make_unique<PatternSearch<>>("PatternSearch", lb, ub));
  optimizers.push_back(std::make_unique<DifferentialEvolution<>>("DifferentialEvolution", lb, ub));
  optimizers.push_back(std::make_unique<MultilevelCoordinateSearch<>>("MultilevelCoordinateSearch", lb, ub));

  std::map<std::string, OptimizationAlgorithm<>::OptimizationResult> results;
  for (const auto& optimizer : optimizers)
    results[optimizer->GetName()] = optimizer->Optimize(f);

  for (const auto& [optimizerName, result] : results)
  {
    fmt::print("[globalopt] {}:\n", optimizerName);
    fmt::print("[globalopt]   - Result: {}\n", result.objectiveFunctionValue);
    fmt::print("[globalopt]   - Optimum: {}\n", result.optimum);
    fmt::print("[globalopt]   - Termination reason: {}\n", result.terminationReason);
  }

  fmt::print("[globalopt] Tests finished successfully\n");
  return EXIT_SUCCESS;
}
catch (const std::exception& e)
{
  fmt::print("[globalopt] Error: {}\n", e.what());
  return EXIT_FAILURE;
}
catch (...)
{
  fmt::print("[globalopt] Unknown error\n");
  return EXIT_FAILURE;
}