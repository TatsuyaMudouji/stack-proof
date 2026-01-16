package estimate

import "fmt"

type Params struct {
	Area      float64
	UnitPrice float64
}

func Calculate(p Params) (float64, error) {
	if p.Area <= 0 || p.UnitPrice <= 0 {
		return 0, fmt.Errorf("values must be greater than zero")
	}
	return p.Area * p.UnitPrice, nil
}
