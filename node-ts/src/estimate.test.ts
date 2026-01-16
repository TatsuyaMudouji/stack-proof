import { calculateEstimate } from "./estimate.js";

if (calculateEstimate({ area: 10, unitPrice: 1000 }) !== 10000) {
  throw new Error("Test failed: valid case");
}

let threw = false;
try {
  calculateEstimate({ area: 0, unitPrice: 1000 });
} catch {
  threw = true;
}
if (!threw) {
  throw new Error("Test failed: invalid case");
}

console.log("OK");
