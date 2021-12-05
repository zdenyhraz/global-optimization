#pragma once
#include "OptimizationAlgorithm.h"

namespace globalopt
{
template <typename ReturnValue = double, typename Parameters = std::vector<double>>
class MultilevelCoordinateSearch : public OptimizationAlgorithm<ReturnValue, Parameters>
{
public:
  using OptimizationResult = typename OptimizationAlgorithm<ReturnValue, Parameters>::OptimizationResult;
  using ObjectiveFunction = typename OptimizationAlgorithm<ReturnValue, Parameters>::ObjectiveFunction;

  MultilevelCoordinateSearch(const std::string& name, const Parameters& lowerBounds, const Parameters& upperBounds) : OptimizationAlgorithm<ReturnValue, Parameters>(name, lowerBounds, upperBounds) {}

  OptimizationResult Optimize(const ObjectiveFunction& f) override
  {
    fmt::print("MultilevelCoordinateSearch::Optimize()\n");
    return OptimizationResult();
  }

private:
};
}