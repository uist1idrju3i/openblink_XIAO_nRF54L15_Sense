led = true

puts "Hello World!"

while true

  led = !led
  LED.set(part: :led1, state: led)

  
  if Input.pressed?(part: :sw1)
    puts ("SW1 pressed")
  end
  
  sleep_ms 500

end
