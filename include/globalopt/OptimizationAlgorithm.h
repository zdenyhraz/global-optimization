#pragma once
#include <string>
#include <vector>
#include <functional>
#include <limits>

#include <fmt/format.h>

template <typename ReturnValue = double, typename Parameters = std::vector<double>>
class OptimizationAlgorithm
{
public:
  using ObjectiveFunction = std::function<ReturnValue(const Parameters&)>;

  enum TerminationReason
  {
    Unknown,
    OptimalFunctionValueReached,
    MaximumFunctionEvaluationsReached,
    NoImprovementReached,
    ErrorOccured,
  };

  struct OptimizationResult
  {
    ReturnValue objectiveFunctionValue = std::numeric_limits<ReturnValue>::infinity();
    Parameters optimum;
    TerminationReason terminationReason = Unknown;
    std::string terminationMessage = "Unknown";
  };

  struct OptimizationOutputs
  {
    bool consoleOutput = false;
    bool plotOutput = false;
    bool fileOutput = false;
    bool saveProgress = false;
  };

  OptimizationAlgorithm(const std::string& name, const Parameters& lowerBounds, const Parameters& upperBounds)
      : mName(name), mDimensionality(lowerBounds.size()), mLowerBounds(lowerBounds), mUpperBounds(upperBounds)
  {
    if (lowerBounds.size() != upperBounds.size() or lowerBounds.empty() or upperBounds.empty())
      throw std::runtime_error(fmt::format("Bad lower/upper bounds dimensionality ({}/{})", lowerBounds.size(), upperBounds.size()));

    for (int dimension = 0; dimension < lowerBounds.size(); dimension++)
      if (lowerBounds[dimension] >= upperBounds[dimension])
        throw std::runtime_error(fmt::format("Bad lower/upper bounds values ({}/{}) for dimension {}", lowerBounds[dimension], upperBounds[dimension], dimension));
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

  const std::string& GetName() { return mName; }

protected:
  int mDimensionality;
  int mMaxFunctionEvaluations = std::numeric_limits<int>::infinity();
  ReturnValue mOptimalFunctionValue = -std::numeric_limits<ReturnValue>::infinity();
  Parameters mLowerBounds;
  Parameters mUpperBounds;
  OptimizationOutputs mOutputs;
  std::string mName;
  std::vector<std::string> mParameterNames;
};

template <typename T>
struct fmt::formatter<std::vector<T>>
{
  template <typename ParseContext>
  constexpr auto parse(ParseContext& ctx)
  {
    return ctx.begin();
  }

  template <typename FormatContext>
  constexpr auto format(const std::vector<T>& vec, FormatContext& ctx)
  {
    if (vec.empty())
      return fmt::format_to(ctx.out(), "[]");

    fmt::format_to(ctx.out(), "[");
    for (int i = 0; i < vec.size() - 1; ++i)
      fmt::format_to(ctx.out(), "{}, ", vec[i]);
    return fmt::format_to(ctx.out(), "{}]", vec[vec.size() - 1]);
  }
};
