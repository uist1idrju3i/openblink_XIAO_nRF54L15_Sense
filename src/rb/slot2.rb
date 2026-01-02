puts ("Hello Ruby")

# LEDの設定
NUM_LEDS = 60
BRIGHTNESS_DIVISOR = 100  # 明るさを 1/100 にする (数値が大きいほど暗くなる)

# 0〜255の数値を受け取り、虹色のRGB(配列)を返すメソッド
# Arduinoなどでよく使われる「Wheel」関数の移植です
def color_wheel(pos)
  pos = pos % 255 # 0-255の範囲に収める
  
  if pos < 85
    r = 255 - pos * 3
    g = 0
    b = pos * 3
  elsif pos < 170
    pos -= 85
    r = 0
    g = pos * 3
    b = 255 - pos * 3
  else
    pos -= 170
    r = pos * 3
    g = 255 - pos * 3
    b = 0
  end

  # 明るさ調整をして返す
  [r / BRIGHTNESS_DIVISOR, g / BRIGHTNESS_DIVISOR, b / BRIGHTNESS_DIVISOR]
end

offset = 0

while true do
  if Input.pressed?(part: :sw1)
    puts ("SW1 pressed")
  end
  
  # 60個のLED全てに色をセット
  (0...NUM_LEDS).each do |i|
    # LEDの位置(i)と、時間の経過(offset)を足して色を決める
    # 255.0 / NUM_LEDS は、虹色を60個で一周させるための係数(約4.25)
    wheel_pos = ((i * 4) + offset)
    
    # RGBを取得
    r, g, b = color_wheel(wheel_pos)

    # LEDにセット
    PIXELS.set(i, r, g, b)
  end

  # LEDを点灯更新
  PIXELS.update
  
  # 色をずらす（流れるアニメーション）
  offset += 2
  
  # 少し待つ（0.01秒）
  sleep 0.01
end
