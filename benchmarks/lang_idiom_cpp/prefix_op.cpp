#include <benchmark/benchmark.h>

#include <vector>
#include <numeric>

using std::vector;
using std::iota;
using std::int64_t;

static vector<int> make_vector(std::size_t size)
{
  vector<int> v(size);
  iota(v.begin(), v.end(), 1);
  return v;
}

// for (size_t i = 0; i < vec.size(); ++i)
static void BM_Prefix_Operator(benchmark::State& state)
{
  const auto vec = make_vector(static_cast<std::size_t>(state.range(0)));

  for (auto _ : state)
  {
    int64_t sum = 0;

    for (size_t i = 0; i < vec.size(); ++i)
    {
      sum += vec[i];
    }

    benchmark::DoNotOptimize(sum);
  }
}

// for (size_t i = 0; i < vec.size(); i++)
static void BM_Postfix_Operator(benchmark::State& state)
{
  const auto vec = make_vector(static_cast<std::size_t>(state.range(0)));

  for (auto _ : state)
  {
    int64_t sum = 0;

    for (size_t i = 0; i < vec.size(); i++)
    {
      sum += vec[i];
    }

    benchmark::DoNotOptimize(sum);
  }
}

// for (it = begin; it != end; ++it)
static void BM_VectorIterator_Prefix(benchmark::State& state)
{
    const auto vec = make_vector(static_cast<std::size_t>(state.range(0)));

    for (auto _ : state)
    {
        std::int64_t sum = 0;

        for (auto it = vec.begin(); it != vec.end(); ++it)
        {
            sum += *it;
        }

        benchmark::DoNotOptimize(sum);
    }
}

// for (it = begin; it != end; it++)
static void BM_VectorIterator_Postfix(benchmark::State& state)
{
    const auto vec = make_vector(static_cast<std::size_t>(state.range(0)));

    for (auto _ : state)
    {
        std::int64_t sum = 0;

        for (auto it = vec.begin(); it != vec.end(); it++)
        {
            sum += *it;
        }

        benchmark::DoNotOptimize(sum);
    }
}
BENCHMARK(BM_Prefix_Operator)->Arg(1000)->Arg(100000)->Arg(1000000);
BENCHMARK(BM_Postfix_Operator)->Arg(1000)->Arg(100000)->Arg(1000000);
BENCHMARK(BM_VectorIterator_Prefix)->Arg(1000)->Arg(100000)->Arg(1000000);
BENCHMARK(BM_VectorIterator_Postfix)->Arg(1000)->Arg(100000)->Arg(1000000);
