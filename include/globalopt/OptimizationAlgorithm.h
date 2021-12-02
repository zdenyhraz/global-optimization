#pragma once
#include <string>
#include <vector>
#include <functional>
#include <limits>

#include <fmt/format.h>

template <typename ReturnValue, typename Parameters>
class OptimizationAlgorithm
{
public:
  using ObjectiveFunction = std::function<ReturnValue(const Parameters&)>;

  enum TerminationReason
  {
    NotTerminated,
    NoImprovementReached,
    OptimalFunctionValueReached,
    MaximumFunctionEvaluationsReached,
    UnexpectedErrorOccured,
  };

  struct OptimizationResult
  {
    Parameters optimum;
    ReturnValue objectiveFunctionValue;
    TerminationReason terminationReason;
  };

  struct OptimizationOutputs
  {
    bool consoleOutput = true;
    bool plotOutput = false;
    bool fileOutput = false;
    bool saveProgress = false;
  };

  OptimizationAlgorithm(const Parameters& lowerBounds, const Parameters& upperBounds) : mDimensionality(lowerBounds.size()), mLowerBounds(lowerBounds), mUpperBounds(upperBounds)
  {
    if (lowerBounds.empty() or upperBounds.empty())
      throw std::runtime_error(fmt::format("Bad lower/upper bounds dimensionality ({}/{})", lowerBounds.size(), upperBounds.size()));

    if (lowerBounds.size() != upperBounds.size())
      throw std::runtime_error(fmt::format("Lower/upper bounds dimension mismatch ({}/{})", lowerBounds.size(), upperBounds.size()));
  }

  virtual ~OptimizationAlgorithm() = default;

  virtual OptimizationResult Optimize(const ObjectiveFunction& f) = 0;

  void SetConsoleOutput(bool consoleOutput) { mOutputs.consoleOutput = consoleOutput; }
  void SetPlotOutput(bool plotOutput) { mOutputs.plotOutput = plotOutput; }
  void SetFileOutput(bool fileOutput) { mOutputs.fileOutput = fileOutput; }
  void SetSaveProgress(bool saveProgress) { mOutputs.saveProgress = saveProgress; }
  void SetName(const std::string& name) { mName = name; }
  void SetOptimalFunctionValue(ReturnValue optimalFunctionValue) { mOptimalFunctionValue = optimalFunctionValue; }
  void SetMaxFunctionEvaluations(int maxFunctionEvaluations) { mMaxFunctionEvaluations = maxFunctionEvaluations; }
  void SetParameterNames(const std::vector<std::string>& parameterNames) { mParameterNames = parameterNames; }

protected:
  int mDimensionality;
  int mMaxFunctionEvaluations = std::numeric_limits<int>::max();
  ReturnValue mOptimalFunctionValue = std::numeric_limits<ReturnValue>::lowest();
  Parameters mLowerBounds;
  Parameters mUpperBounds;
  OptimizationOutputs mOutputs;
  std::string mName;
  std::vector<std::string> mParameterNames;
};
