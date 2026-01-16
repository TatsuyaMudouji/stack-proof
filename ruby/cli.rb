require_relative "estimate"

if ARGV.length < 2
  STDERR.puts "usage: ruby cli.rb <area> <unitPrice>"
  exit 1
end

begin
  area = Float(ARGV[0])
  unit_price = Float(ARGV[1])
rescue ArgumentError
  STDERR.puts "invalid number"
  exit 1
end

begin
  total = calculate_estimate(area, unit_price)
  puts({ area: area, unitPrice: unit_price, total: total }.to_json)
rescue ArgumentError => e
  STDERR.puts e.message
  exit 1
end
