

/*
 * FUEL / BATTERY
 */

int FUEL_PWM_PIN = 2;
int FUEL_PWM_EMPTY = 5;
int FUEL_PWM_FULL = 40;
int FUEL_PWM_RANGE = FUEL_PWM_FULL - FUEL_PWM_EMPTY;

// Given a battery SOC (%) return the corresponding PWM value to display that on the gauge.
int battery_get_pwm_from_soc(int battery_soc) {
    int pwm = FUEL_PWM_EMPTY + ( FUEL_PWM_RANGE * ( battery_soc / 100.0 ) );
    return pwm;
}

/*
 * TEMPERATURE
 */


/*
 * MAIN
 */

void setup() {
    Serial.begin(9600);
    // Fuel gauges
    pinMode(FUEL_PWM_PIN, OUTPUT);
}

void loop() {
    int soc = 15;
    Serial.print("soc = ");
    Serial.println(soc);
    int p = battery_get_pwm_from_soc(soc);
    Serial.print("pwm = ");
    Serial.println(p);
    analogWrite(FUEL_PWM_PIN, p);
    delay(10000);
}
