#pragma once
#include "OptimizationAlgorithm.h"

template <typename ReturnValue = double, typename Parameters = std::vector<double>>
class PatternSearch : public OptimizationAlgorithm<ReturnValue, Parameters>
{
public:
  using OptimizationResult = typename OptimizationAlgorithm<ReturnValue, Parameters>::OptimizationResult;
  using ObjectiveFunction = typename OptimizationAlgorithm<ReturnValue, Parameters>::ObjectiveFunction;

  PatternSearch(const std::string& name, const Parameters& lowerBounds, const Parameters& upperBounds) : OptimizationAlgorithm<ReturnValue, Parameters>(name, lowerBounds, upperBounds) {}

  OptimizationResult Optimize(const ObjectiveFunction& f) override
  {
    fmt::print("PatternSearch::Optimize()\n");
    return OptimizationResult();
  }

private:
};