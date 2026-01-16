import sys
from decimal import Decimal, InvalidOperation, ROUND_HALF_UP


def usage() -> None:
    print("Usage:")
    print("  python main.py <area> <unit_price>")
    print("Example:")
    print("  python main.py 10 1000")


def parse_positive_decimal(value: str, name: str) -> Decimal:
    try:
        d = Decimal(value)
    except (InvalidOperation, ValueError):
        print(f"Error: {name} must be numeric.", file=sys.stderr)
        usage()
        sys.exit(1)

    if d <= 0:
        print(f"Error: {name} must be > 0.", file=sys.stderr)
        usage()
        sys.exit(1)

    return d


def main() -> int:
    if len(sys.argv) != 3:
        print("Error: area and unit_price are required.", file=sys.stderr)
        usage()
        return 1

    area = parse_positive_decimal(sys.argv[1], "area")
    unit_price = parse_positive_decimal(sys.argv[2], "unit_price")

    total = (area * unit_price).quantize(Decimal("1"), rounding=ROUND_HALF_UP)

    # 他言語と同様、1行で見える形式
    def fmt(d: Decimal) -> str:
        s = format(d, "f")
        if "." in s:
            s = s.rstrip("0").rstrip(".")
        return s

    print(f"area={fmt(area)} unit_price={fmt(unit_price)} total={fmt(total)}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
