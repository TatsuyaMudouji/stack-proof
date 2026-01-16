package estimate

import "testing"

func TestCalculateOK(t *testing.T) {
	got, err := Calculate(Params{Area: 10, UnitPrice: 1000})
	if err != nil {
		t.Fatalf("expected nil error, got %v", err)
	}
	if got != 10000 {
		t.Fatalf("expected 10000, got %v", got)
	}
}

func TestCalculateNG(t *testing.T) {
	_, err := Calculate(Params{Area: 0, UnitPrice: 1000})
	if err == nil {
		t.Fatalf("expected error")
	}
}
