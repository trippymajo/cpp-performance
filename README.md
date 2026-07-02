# cpp-performance
Research over performance optimizations in C++. It will be a comprehensive cheat-sheet for C++ developers for using or not some micro-optimizations in their code with real benchmarks. The code will cover GCC, Clang, MSVC compilers and -O2 and -O3 optimizations in release with a help of Google benchmarks library.

## How to read table
Here lies information regarding intepretation of the cheat-sheat tables. You should take in considiration verdict and risks and feel free to dive in to exact tests with more information dedicated to exact performance optimization.

### Verdicts 
| Mark          | Explanation                       |
| ------------- | --------------------------------- | 
| Use by default | Feel free to use, it is idiomatic and safe |
| Use when semantic | Use when it is right semantic, not just for speed |
| Measure first | Consider using after performance analysis on real data |
| Avoid by default | Not useful/harmful/myth |
| Advanced/Hot-path | Only for performance critical code |
  
### Risks
| Risk | Explanation |
| ------------- | --------------------------------- |
| Low | Almost unreal to break corectness |
| Medium | Can affect readability or performance |
| High | Can lead to UB/race/lifetime |
| Very High | Only when understand compiler/hardware effects |
  
## Language/Idiomatic C++
| Optimization | Verdict | Risk | Link |
| ------------- | ------------- | ----- | ------------------- |
| Prefix --it or ++it | | | |
| std::move | | | |
| return std::move | | | |
| noexcept move | | | |
| parameters value vs reference vs move | | | |
| std::string_view | | | |
| std::span | | | |

## Allocations/Lifetime/Ownership
| Optimization | Verdict | Risk | Link |
| ------------- | ------------- | ----- | ------------------- |
| .resrve() | | | |
| std::pmr/arena| | | |
| memory pool | | | |
| stack vs heap | | | |
| shared_ptr by value | | | |
| Pointers | | | |
| Object reuse | | | |
  
## Containers/Data Sturtures
Use bigO notation.

## Data layout/Memory locality

## Branching/code layout

## Calls/Dispatch/Abstraction overhead

## Concurrency/Synchronization

## OS/Syscalls/IO

## CPU/Memory/Low-Level
