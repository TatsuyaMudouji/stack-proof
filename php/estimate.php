<?php
declare(strict_types=1);

function calculate_estimate(float $area, float $unitPrice): float {
    if ($area <= 0 || $unitPrice <= 0) {
        throw new InvalidArgumentException('values must be greater than zero');
    }
    return $area * $unitPrice;
}
