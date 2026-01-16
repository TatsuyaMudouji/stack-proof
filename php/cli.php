<?php
declare(strict_types=1);

require_once __DIR__ . '/estimate.php';

if ($argc < 3) {
    fwrite(STDERR, "usage: php cli.php <area> <unitPrice>\n");
    exit(1);
}

$area = filter_var($argv[1], FILTER_VALIDATE_FLOAT);
$unitPrice = filter_var($argv[2], FILTER_VALIDATE_FLOAT);

if ($area === false) {
    fwrite(STDERR, "invalid area\n");
    exit(1);
}
if ($unitPrice === false) {
    fwrite(STDERR, "invalid unit price\n");
    exit(1);
}

try {
    $total = calculate_estimate((float)$area, (float)$unitPrice);
    echo json_encode([
        'area' => (float)$area,
        'unitPrice' => (float)$unitPrice,
        'total' => $total,
    ], JSON_UNESCAPED_UNICODE) . PHP_EOL;
} catch (InvalidArgumentException $e) {
    fwrite(STDERR, $e->getMessage() . "\n");
    exit(1);
}
