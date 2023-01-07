#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/dma.h"
#include "hardware/irq.h"
#include "hardware/pwm.h"
#include "hardware/sync.h"
#include "hardware/adc.h"

#define AUDIO_PIN 2
#define ADC_CHANNEL 2

//#define AUDIO_SAMPLES 62294
#define AUDIO_SAMPLES 2560

//#include "rock.h"

// 130MHz

int cur_sample = 0;
int EngineRpm = 1000;
int sine_step = 0;
int pwm_counter = 0;

const unsigned char sine[50] = {
    52,57,62,66,70,74,77,80,82,84,85,86,86,
    86,85,83,81,78,75,72,69,65,61,56,52,
    48,44,39,35,31,28,25,22,19,17,15,14,14,
    14,15,16,18,20,23,26,30,34,38,43,48
};

const unsigned char sinetable[256] = {
128,131,134,137,140,143,146,149,152,156,159,162,165,168,171,174,
176,179,182,185,188,191,193,196,199,201,204,206,209,211,213,216,
218,220,222,224,226,228,230,232,234,236,237,239,240,242,243,245,
246,247,248,249,250,251,252,252,253,254,254,255,255,255,255,255,
255,255,255,255,255,255,254,254,253,252,252,251,250,249,248,247,
246,245,243,242,240,239,237,236,234,232,230,228,226,224,222,220,
218,216,213,211,209,206,204,201,199,196,193,191,188,185,182,179,
176,174,171,168,165,162,159,156,152,149,146,143,140,137,134,131,
128,124,121,118,115,112,109,106,103,99, 96, 93, 90, 87, 84, 81,
79, 76, 73, 70, 67, 64, 62, 59, 56, 54, 51, 49, 46, 44, 42, 39,
37, 35, 33, 31, 29, 27, 25, 23, 21, 19, 18, 16, 15, 13, 12, 10,
9, 8, 7, 6, 5, 4, 3, 3, 2, 1, 1, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 1, 1, 2, 3, 3, 4, 5, 6, 7, 8,
9, 10, 12, 13, 15, 16, 18, 19, 21, 23, 25, 27, 29, 31, 33, 35,
37, 39, 42, 44, 46, 49, 51, 54, 56, 59, 62, 64, 67, 70, 73, 76,
79, 81, 84, 87, 90, 93, 96, 99, 103,106,109,112,115,118,121,124
};

uint8_t getPitch(uint8_t cur_sample) {
    return ( cur_sample + 10 ) / 50;
}


void pwm_irh() {
    pwm_clear_irq(pwm_gpio_to_slice_num(AUDIO_PIN));
    pwm_counter++;
    if ( pwm_counter > 500 ) {
        pwm_counter = 0;
        sine_step++;
    }
    if ( sine_step > 50 ) {
        sine_step = 0;
    }
    pwm_set_gpio_level(AUDIO_PIN, sinetable[sine_step]);
}

int main(void) {
    stdio_init_all();
    set_sys_clock_khz(176000, true); 
    gpio_set_function(AUDIO_PIN, GPIO_FUNC_PWM);
    int audio_pin_slice = pwm_gpio_to_slice_num(AUDIO_PIN);

    // Setup PWM interrupt to fire when PWM cycle is complete
    pwm_clear_irq(audio_pin_slice);
    pwm_set_irq_enabled(audio_pin_slice, true);
    irq_set_exclusive_handler(PWM_IRQ_WRAP, pwm_irh);
    irq_set_enabled(PWM_IRQ_WRAP, true);

    // Setup PWM for audio output
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, 4.0f);
    pwm_config_set_wrap(&config, 250);
    pwm_init(audio_pin_slice, &config, true);

    pwm_set_gpio_level(AUDIO_PIN, 0);

    while(1) {
        __wfi();
    }
}
