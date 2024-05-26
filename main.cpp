#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;
using vb = vector<bool>;

constexpr auto kMax = 1000000LL;

ll n;
vb sieve(kMax + 1, true);
vl primes{};

void Ready() {
  primes.reserve(kMax + 1);

  sieve[0] = false;
  sieve[1] = false;

  for (auto i = 2; i * i <= kMax; ++i) {
    if (!sieve[i]) continue;

    primes.push_back(i);

    for (auto j = i + i; j <= kMax; j += i) {
      sieve[j] = false;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  Ready();

  cin >> n;
  while (0 < n) {
    for (const auto& p : primes) {
      if (sieve[n - p]) {
        cout << n << " = " << p << " + " << n - p << '\n';
        break;
      }
    }

    cin >> n;
  }

  return 0;
}