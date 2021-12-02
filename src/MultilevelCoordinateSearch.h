#pragma once
#include "OptimizationAlgorithm.h"

template <typename ReturnValue = double, typename Parameters = std::vector<double>>
class MultilevelCoordinateSearch : public OptimizationAlgorithm<ReturnValue, Parameters>
{
public:
  using OptimizationResult = typename OptimizationAlgorithm<ReturnValue, Parameters>::OptimizationResult;
  using ObjectiveFunction = typename OptimizationAlgorithm<ReturnValue, Parameters>::ObjectiveFunction;

  MultilevelCoordinateSearch(const Parameters& lowerBounds, const Parameters& upperBounds) : OptimizationAlgorithm<ReturnValue, Parameters>(lowerBounds, upperBounds) {}

  OptimizationResult Optimize(const ObjectiveFunction& f) override { return OptimizationResult(); }

private:
};