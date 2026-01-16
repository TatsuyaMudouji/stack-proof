#include <iostream>
#include <string>
#include <cstdlib>

static void usage() {
  std::cout << "Usage:\n";
  std::cout << "  ./estimate <area> <unit_price>\n";
  std::cout << "Example:\n";
  std::cout << "  ./estimate 10 1000\n";
}

static double parse_positive_double(const std::string& s, const char* name) {
  try {
    size_t idx = 0;
    double v = std::stod(s, &idx);
    if (idx != s.size()) throw std::invalid_argument("trailing");
    if (v <= 0) {
      std::cerr << "Error: " << name << " must be > 0.\n";
      usage();
      std::exit(1);
    }
    return v;
  } catch (...) {
    std::cerr << "Error: " << name << " must be numeric.\n";
    usage();
    std::exit(1);
  }
}

int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cerr << "Error: area and unit_price are required.\n";
    usage();
    return 1;
  }

  double area = parse_positive_double(argv[1], "area");
  double unit_price = parse_positive_double(argv[2], "unit_price");

  long long total = static_cast<long long>(area * unit_price + 0.5);

  std::cout << "area=" << area
            << " unit_price=" << unit_price
            << " total=" << total
            << "\n";
  return 0;
}
