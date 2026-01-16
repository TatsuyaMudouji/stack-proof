#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

static void usage(void) {
  printf("Usage:\n");
  printf("  ./estimate <area> <unit_price>\n");
  printf("Example:\n");
  printf("  ./estimate 10 1000\n");
}

static double parse_positive_double(const char *s, const char *name) {
  errno = 0;
  char *end = NULL;
  double v = strtod(s, &end);

  if (errno != 0 || end == s || *end != '\0') {
    fprintf(stderr, "Error: %s must be numeric.\n", name);
    usage();
    exit(1);
  }
  if (v <= 0) {
    fprintf(stderr, "Error: %s must be > 0.\n", name);
    usage();
    exit(1);
  }
  return v;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Error: area and unit_price are required.\n");
    usage();
    return 1;
  }

  double area = parse_positive_double(argv[1], "area");
  double unit_price = parse_positive_double(argv[2], "unit_price");

  // 合計は整数想定（10 * 1000 = 10000）に寄せて表示
  long long total = (long long)(area * unit_price + 0.5);

  printf("area=%g unit_price=%g total=%lld\n", area, unit_price, total);
  return 0;
}
