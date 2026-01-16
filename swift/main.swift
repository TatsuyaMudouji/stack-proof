import Foundation

func usage() {
    print("Usage:")
    print("  swift main.swift <area> <unit_price>")
    print("Example:")
    print("  swift main.swift 10 1000")
}

let args = CommandLine.arguments

guard args.count == 3 else {
    print("Error: area and unit_price are required.")
    usage()
    exit(1)
}

guard
    let area = Decimal(string: args[1]),
    let unitPrice = Decimal(string: args[2])
else {
    print("Error: area and unit_price must be numeric.")
    usage()
    exit(1)
}

guard area > 0, unitPrice > 0 else {
    print("Error: area and unit_price must be > 0.")
    usage()
    exit(1)
}

let total = area * unitPrice

// 表示形式を他言語と揃える
print("area=\(area) unit_price=\(unitPrice) total=\(total)")
