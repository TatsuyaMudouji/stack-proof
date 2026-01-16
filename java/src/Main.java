import java.math.BigDecimal;
import java.math.RoundingMode;

public class Main {

  private static void usage() {
    System.out.println("Usage:");
    System.out.println("  java Main <area> <unit_price>");
    System.out.println("Example:");
    System.out.println("  java Main 10 1000");
  }

  public static void main(String[] args) {
    if (args.length != 2) {
      System.err.println("Error: area and unit_price are required.");
      usage();
      System.exit(1);
    }

    BigDecimal area;
    BigDecimal unitPrice;

    try {
      area = new BigDecimal(args[0]);
      unitPrice = new BigDecimal(args[1]);
    } catch (NumberFormatException e) {
      System.err.println("Error: area and unit_price must be numeric.");
      usage();
      System.exit(1);
      return;
    }

    if (area.compareTo(BigDecimal.ZERO) <= 0 || unitPrice.compareTo(BigDecimal.ZERO) <= 0) {
      System.err.println("Error: area and unit_price must be > 0.");
      usage();
      System.exit(1);
    }

    BigDecimal total = area.multiply(unitPrice).setScale(0, RoundingMode.HALF_UP);

    // 他ディレクトリと同様、結果が一行で分かる形に寄せる
    System.out.println("area=" + area.stripTrailingZeros().toPlainString()
      + " unit_price=" + unitPrice.stripTrailingZeros().toPlainString()
      + " total=" + total.toPlainString());
  }
}
