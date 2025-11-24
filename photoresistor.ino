const int led = 6;
const int ldr = A3;

const float max_value = 1023.0;
const float max_led = 255.0;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {

  int ldr_value = analogRead(ldr);

  float light_percent = (ldr_value / max_value) * 100.0;
  float darkness = 100.0 - light_percent;

  // Convert darkness to PWM value (0–255)
  int darkness_pwm = (darkness / 100.0) * max_led;

  Serial.print("LDR: ");
  Serial.print(ldr_value);
  Serial.print("  Light(%): ");
  Serial.print(light_percent);
  Serial.print("  PWM: ");
  Serial.println(darkness_pwm);

  analogWrite(led, darkness_pwm); // Use analogWrite for PWM pins

  delay(200);
}