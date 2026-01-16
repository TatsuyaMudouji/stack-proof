def calculate_estimate(area, unit_price)
  raise ArgumentError, "values must be greater than zero" if area <= 0 || unit_price <= 0
  area * unit_price
end
