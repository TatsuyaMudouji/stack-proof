package main

import (
	"fmt"
	"os"
	"strconv"

	"stack-proof/go/estimate"
)

func main() {
	area := 10.0
	unitPrice := 1000.0

	if len(os.Args) >= 3 {
		a, err := strconv.ParseFloat(os.Args[1], 64)
		if err != nil {
			fmt.Fprintln(os.Stderr, "invalid area")
			os.Exit(1)
		}
		u, err := strconv.ParseFloat(os.Args[2], 64)
		if err != nil {
			fmt.Fprintln(os.Stderr, "invalid unit price")
			os.Exit(1)
		}
		area = a
		unitPrice = u
	}

	total, err := estimate.Calculate(estimate.Params{Area: area, UnitPrice: unitPrice})
	if err != nil {
		fmt.Fprintln(os.Stderr, err.Error())
		os.Exit(1)
	}

	fmt.Printf("{\"area\":%.2f,\"unitPrice\":%.2f,\"total\":%.2f}\n", area, unitPrice, total)
}
