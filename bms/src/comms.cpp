

void startSlavePolling() {
    add_repeating_timer_ms(1000, callback, NULL, &timer)
}