export type EstimateParams = {
  area: number;
  unitPrice: number;
};

export function calculateEstimate(params: EstimateParams): number {
  const { area, unitPrice } = params;

  if (!Number.isFinite(area) || !Number.isFinite(unitPrice)) {
    throw new Error("Invalid input type");
  }
  if (area <= 0 || unitPrice <= 0) {
    throw new Error("Values must be greater than zero");
  }

  return area * unitPrice;
}
