import { calculateEstimate } from "./estimate.js";

const area = Number(process.argv[2] ?? "10");
const unitPrice = Number(process.argv[3] ?? "1000");

try {
  const total = calculateEstimate({ area, unitPrice });
  console.log(JSON.stringify({ area, unitPrice, total }));
} catch (e) {
  console.error((e as Error).message);
  process.exit(1);
}
